#include "stdafx.h"
#include "page2.h"

page2::page2(){}

page2::~page2(){}

HRESULT page2::init(int left, int top)
{
	for (int i = 0; i < 18; i++)
	{
		_sample[i].img = new image;
		_sample[i].img->init("images/MapTool/Terrain/¸ÊÅøÁöÇü.bmp", 300, 250, 6, 5, true, RGB(255, 0, 255));

		_sample[i].Rectimg = IMAGEMANAGER->findImage("¼ÀÇÃºÏ·ºÆ®");
		
		if (i < 6)
		{
			_sample[i].img->setFrameX(i);
			_sample[i].img->setFrameY(0);
		}
		else if (i > 5 && i < 12)
		{
			_sample[i].img->setFrameX(i - 6);
			_sample[i].img->setFrameY(1);
		}
		else
		{
			_sample[i].img->setFrameX(i - 12);
			_sample[i].img->setFrameY(2);
		}


		if (i < 6)
		{
			_sample[i].x = (left + 200) + i * 100;
			_sample[i].y = top + 200;
		}
		else if (i > 5 && i < 12)
		{
			_sample[i].x = (left + 200) + (i - 6) * 100;
			_sample[i].y = (top + 300);
		}
		else
		{
			_sample[i].x = (left + 200) + (i - 12) * 100;
			_sample[i].y = (top + 400);
		}

		_sample[i].rc = new RECT;
		*_sample[i].rc = RectMakeCenter(_sample[i].x, _sample[i].y, 55, 55);

		_check = P_TERRAIN;
	}


	return S_OK;
}

void page2::release()
{
	for (int i = 0; i < 18; i++)
	{
		delete _sample[i].rc;
		SAFE_DELETE(_sample[i].img);
		SAFE_DELETE(_sample[i].Rectimg);
	}
}

void page2::update(int left, int top)
{
	for (int i = 0; i < 18; i++)
	{
		if (i < 6)
		{
			_sample[i].x = (left + 200) + i * 100;
			_sample[i].y = top + 200;
		}
		else if (i > 5 && i < 12)
		{
			_sample[i].x = (left + 200) + (i - 6) * 100;
			_sample[i].y = (top + 300);
		}
		else
		{
			_sample[i].x = (left + 200) + (i - 12) * 100;
			_sample[i].y = (top + 400);
		}

		*_sample[i].rc = RectMakeCenter(_sample[i].x, _sample[i].y, 55, 55);
	}
}

void page2::render()
{
	IMAGEMANAGER->findImage("ÁöÇü¹öÆ°")->render(getMemDC(),CAMERAX +   WINSIZEX / 2 - 90, CAMERAY + WINSIZEY / 2 - 200);

	for (int i = 0; i < 18; i++)
	{

		_sample[i].Rectimg->render(getMemDC(), _sample[i].rc->left - 5, _sample[i].rc->top - 5);
		_sample[i].img->frameRender(getMemDC(), _sample[i].rc->left, _sample[i].rc->top);

		if (KEYMANAGER->isToggleKey(VK_TAB))
		{
			Rectangle(getMemDC(), _sample[i].rc->left, _sample[i].rc->top, _sample[i].rc->right, _sample[i].rc->bottom);
		}
	}
}

void page2::removeRect()
{
	for (int i = 0; i < 18; i++)
	{
		delete _sample[i].rc;
	}
}

SMAPLE page2::getSample()
{
	for (int i = 0; i < 18; i++)
	{
		if (PtInRect(_sample[i].rc, MOUSE->getPoint()))
		{
			return _sample[i];
		}
	}
}
