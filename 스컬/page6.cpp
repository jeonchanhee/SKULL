#include "stdafx.h"
#include "page6.h"

page6::page6()
{
}

page6::~page6()
{
}

HRESULT page6::init()
{
	for (int i = 0; i < 2; i++)
	{
		_sample[i].img = new image;
		_sample[i].img->init("images/MapTool/Obj/오브젝트(큰나무).bmp", 800, 400, 2, 1, true, RGB(255, 0, 255));

		_sample[i].Rectimg = IMAGEMANAGER->findImage("셈플북렉트");

		_sample[i].img->setFrameX(i);
		_sample[i].img->setFrameY(0);

		_sample[i].rc = new RECT;
	}

	_check = P_BIGTREE;
	return S_OK;
}

void page6::release()
{
}

void page6::update(int left, int top)
{
	for (int i = 0; i < 2; i++)
	{
		_sample[i].x = (left + 250) + i * 400;
		_sample[i].y = top + 300;

		_sample[i].img->setX((left + 100) + i * 400);
		_sample[i].img->setY(top + 100);

		*_sample[i].rc = RectMakeCenter(_sample[i].x, _sample[i].y, 305, 290);
	}


}

void page6::render()
{
	IMAGEMANAGER->findImage("오브젝트버튼")->render(getMemDC(), CAMERAX + WINSIZEX / 2 - 120, CAMERAY + WINSIZEY / 2 - 200);

	for (int i = 0; i < 2; i++)
	{
		_sample[i].Rectimg->render(getMemDC(), _sample[i].rc->left, _sample[i].rc->top, 305, 290);
		_sample[i].img->frameRender(getMemDC(), _sample[i].img->getX(), _sample[i].img->getY(), _sample[i].img->getFrameX(), _sample[i].img->getFrameY(), 300, 300);
	}

}
SMAPLE page6::getSample()
{
	for (int i = 0; i < 2; i++)
	{
		if (PtInRect(_sample[i].rc, MOUSE->getPoint()))
		{
			return _sample[i];
		}
	}
}
