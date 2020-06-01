#include "stdafx.h"
#include "page7.h"

page7::page7()
{
}

page7::~page7()
{
}

HRESULT page7::init()
{
	for (int i = 0; i < 4; i++)
	{
		_sample[i].img = new image;
		_sample[i].Rectimg = IMAGEMANAGER->findImage("셈플북렉트");

		_sample[i].rc = new RECT;
	}
	_sample[0].img->init("images/MapTool/Obj/오브젝트(깃발).bmp", 250, 150, 5, 1, true, RGB(255, 0, 255));
		_sample[1].img->init("images/MapTool/Obj/오브젝트(깃발2).bmp", 350, 150, 7, 1, true, RGB(255, 0, 255));
		_sample[2].img->init("images/MapTool/Obj/오브젝트(불).bmp", 350, 150, 7, 1, true, RGB(255, 0, 255));
		_sample[3].img->init("images/MapTool/Obj/오브젝트(타워).bmp", 840, 214, 7, 1, true, RGB(255, 0, 255));
	

	return S_OK;
}

void page7::release()
{
}

void page7::update(int left, int top)
{
	for (int i = 0; i < 4; i++)
	{
		_sample[i].x = (left + 200) + i * 160;
		_sample[i].y = top + 290;

		if (i < 3)
		{
			_sample[i].img->setX((left + 150) + i * 170);
			_sample[i].img->setY(top + 240);
		}
		else
		{
			_sample[i].img->setX((left + 150) + i * 160);
			_sample[i].img->setY(top + 180);
		}
		*_sample[i].rc = RectMakeCenter(_sample[i].x, _sample[i].y, 140, 245);
	}
	check();
}

void page7::render()
{
	IMAGEMANAGER->findImage("오브젝트버튼")->render(getMemDC(), CAMERAX + WINSIZEX / 2 - 120, CAMERAY + WINSIZEY / 2 - 200);

	for (int i = 0; i < 4; i++)
	{
		_sample[i].Rectimg->render(getMemDC(),_sample[i].rc->left, _sample[i].rc->top, 140, 245);
		_sample[i].img->frameRender(getMemDC(), _sample[i].img->getX(), _sample[i].img->getY());
	}
}

void page7::check()
{
	for (int i = 0; i < 4; i++)
	{
		if (PtInRect(_sample[i].rc, MOUSE->getPoint()))
		{
			if (i == 0) _check = P_FLAG;
			else if (i == 1) _check = P_FLAG2;
			else if (i == 2) _check = P_FIRE;
			else if (i == 3) _check = P_TOWER;
		}
	}

}

SMAPLE page7::getSample()
{
	for (int i = 0; i < 4; i++)
	{
		if (PtInRect(_sample[i].rc, MOUSE->getPoint()))
		{
			return _sample[i];
		}
	}
}
