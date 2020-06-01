#include "stdafx.h"
#include "page8.h"

page8::page8(){}

page8::~page8(){}

HRESULT page8::init()
{
	for (int i = 0; i < 3; i++)
	{
		_sample[i].img = new image;
		_sample[i].Rectimg = IMAGEMANAGER->findImage("셈플북렉트");

		_sample[i].rc = new RECT;

		if (i < 2)
		{
			_sample[i].img->init("images/MapTool/Obj/오브젝트(돌탑).bmp", 300, 170, 2, 1, true, RGB(255, 0, 255));
			_sample[i].img->setFrameX(i);
		}
		else
		{
			_sample[i].img->init("images/MapTool/Obj/오브젝트(텐트).bmp", 600, 100, 3, 1, true, RGB(255, 0, 255));
		}
			_sample[i].img->setFrameY(0);
	}


	return S_OK;
}

void page8::release()
{
}

void page8::update(int left, int top)
{
	for (int i = 0; i < 3; i++)
	{
		if (i < 2)
		{
			_sample[i].x = (left + 210) + i * 200;
			_sample[i].y = top + 280;

			_sample[i].img->setX((left + 128) + i * 210);
			_sample[i].img->setY(top + 200);

			*_sample[i].rc = RectMakeCenter(_sample[i].x, _sample[i].y, 170, 240);
		}
		else
		{
			_sample[i].x = (left + 210) + i * 210;
			_sample[i].y = top + 280;

			_sample[i].img->setX((left + 128) + i * 200);
			_sample[i].img->setY(top + 250);

			*_sample[i].rc = RectMakeCenter(_sample[i].x, _sample[i].y, 180, 240);
		}
	}
	check();
}

void page8::render()
{
	IMAGEMANAGER->findImage("오브젝트버튼")->render(getMemDC(), CAMERAX + WINSIZEX / 2 - 120, CAMERAY + WINSIZEY / 2 - 200);

	for (int i = 0; i < 3; i++)
	{

		if(i < 2) _sample[i].Rectimg->render(getMemDC(), _sample[i].rc->left, _sample[i].rc->top, 170, 250);
		else _sample[i].Rectimg->render(getMemDC(), _sample[i].rc->left, _sample[i].rc->top, 180, 250);
		_sample[i].img->frameRender(getMemDC(), _sample[i].img->getX(), _sample[i].img->getY());
		
		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), _sample[i].rc->left, _sample[i].rc->top, _sample[i].rc->right, _sample[i].rc->bottom);
		}
	}
}

void page8::check()
{
	for(int i = 0; i < 3; i++)
	{
		if (PtInRect(_sample[i].rc, MOUSE->getPoint()))
		{
			if (i < 2) _check = P_STONETOWER;
			else _check = P_TENT;
		}
	}
}

SMAPLE page8::getSample()
{
	for (int i = 0; i < 3; i++)
	{
		if (PtInRect(_sample[i].rc, MOUSE->getPoint()))
		{
			return _sample[i];
		}
	}
}
