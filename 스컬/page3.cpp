#include "stdafx.h"
#include "page3.h"

page3::page3()
{
}

page3::~page3()
{
}

HRESULT page3::init(int left, int top)
{
	for (int i = 0; i < 18; i++)
	{
		_sample[i].img = new image;
		_sample[i].img->init("images/MapTool/Terrain/¸ÊÅøÁöÇü.bmp", 300, 250, 6, 5, true, RGB(255, 0, 255));

		_sample[i].Rectimg = IMAGEMANAGER->findImage("¼ÀÇÃºÏ·ºÆ®");

		if (i < 6)
		{
			_sample[i].img->setFrameY(3);
			_sample[i].img->setFrameX(i);
		}
		else
		{
			_sample[i].img->setFrameY(4);
			_sample[i].img->setFrameX(i - 6);
		}

		if (i < 6)
		{
			_sample[i].x = (left + 200) + i * 100;
			_sample[i].y = top + 200;
		}
		else if (i > 5 && i < 12)
		{
			_sample[i].x = (left + 200) + (i - 6) * 100;
			_sample[i].y = top + 300;
		}
		else
		{
			_sample[i].x = (left + 200) + (i - 12) * 100;
			_sample[i].y = top + 400;
		}

		_sample[i].rc = new RECT;
		*_sample[i].rc = RectMakeCenter(_sample[i].x, _sample[i].y, 55, 55);
	}

	_check = P_TERRAIN;

	return S_OK;
}

void page3::release()
{
	for (int i = 0; i < 18; i++)
	{
		delete _sample[i].rc;
	}
}

void page3::update(int left, int top)
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
			_sample[i].y = top + 300;
		}
		else
		{
			_sample[i].x = (left + 200) + (i - 12) * 100;
			_sample[i].y = top + 400;
		}

		*_sample[i].rc = RectMakeCenter(_sample[i].x, _sample[i].y, 55, 55);
	}
}

void page3::render()
{
	IMAGEMANAGER->findImage("ÁöÇü¹öÆ°")->render(getMemDC(), CAMERAX + WINSIZEX / 2 - 90, CAMERAY + WINSIZEY / 2 - 200);

	for (int i = 0; i < 18; i++)
	{
		_sample[i].Rectimg->render(getMemDC(), _sample[i].rc->left - 5, _sample[i].rc->top - 5);

		if (i < 12)
		{
			_sample[i].img->frameRender(getMemDC(), _sample[i].rc->left, _sample[i].rc->top);
		}
	}
}

void page3::removeRect()
{
	for (int i = 0; i < 18; i++)
	{
		delete _sample[i].rc;
	}
}

SMAPLE page3::getSample()
{
	for (int i = 0; i < 18; i++)
	{
		if (PtInRect(_sample[i].rc, MOUSE->getPoint()))
		{
			return _sample[i];
		}
	}
}
