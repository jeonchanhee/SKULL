#include "stdafx.h"
#include "door.h"

door::door(){}

door::~door(){}

HRESULT door::init(const char* fileName, int x, int y, bool open)
{
	_img = IMAGEMANAGER->findImage(fileName);

	_x = x;
	_y = y;

	_rc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

	_open = open;

	return S_OK;
}

void door::release()
{
}

void door::update()
{
	frame();
}

void door::render()
{
	_img->frameRender(getMemDC(), _rc.left, _rc.top);
}

void door::frame()
{
	if (!_open)
	{
		_img->setFrameX(0);
	}
	else
	{
		_count++;

		if (_count % 10 == 0)
		{
			_frameX++;

			if (_frameX > _img->getMaxFrameX()) _frameX = 1;
		}

		_img->setFrameX(_frameX);
	}
}
