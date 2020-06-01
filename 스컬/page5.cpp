#include "stdafx.h"
#include "page5.h"

page5::page5()
{
}

page5::~page5()
{
}

HRESULT page5::init()
{
	for (int i = 0; i < 2; i++)
	{
		_sample[i].img = new image;
		_sample[i].img->init("images/MapTool/Obj/오브젝트(나무).bmp", 1000, 250, 5, 1, true, RGB(255, 0, 255));

		_sample[i].Rectimg = IMAGEMANAGER->findImage("셈플북렉트");

		_sample[i].img->setFrameX(i + 3);
		_sample[i].img->setFrameY(0);

		_sample[i].rc = new RECT;
	}

	_check = P_TREE;

	return S_OK;
}

void page5::release()
{
}

void page5::update(int left, int top)
{
	for (int i = 0; i < 2; i++)
	{
		_sample[i].x = (left + 200) + i * 250;
		_sample[i].y = (top + 285);

		_sample[i].img->setX((left + 100) + i * 250);
		_sample[i].img->setY(top + 150);

		*_sample[i].rc = RectMakeCenter(_sample[i].x, _sample[i].y, 200, _sample[i].img->getFrameHeight() + 20);
	}
}

void page5::render()
{
	IMAGEMANAGER->findImage("오브젝트버튼")->render(getMemDC(), CAMERAX + WINSIZEX / 2 - 120, CAMERAY + WINSIZEY / 2 - 200);

	for (int i = 0; i < 2; i++)
	{
		_sample[i].Rectimg->render(getMemDC(), _sample[i].rc->left, _sample[i].rc->top, 200, _sample[i].img->getFrameHeight() + 20);
		_sample[i].img->frameRender(getMemDC(), _sample[i].img->getX(), _sample[i].img->getY());
	}
}

SMAPLE page5::getSample()
{
	for (int i = 0; i < 2; i++)
	{
		if (PtInRect(_sample[i].rc, MOUSE->getPoint()))
		{
			return _sample[i];
		}
	}
}
