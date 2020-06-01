#include "stdafx.h"
#include "object.h"

object::object()
{
}

object::~object()
{
}

HRESULT object::init()
{
	return S_OK;
}

void object::release()
{
}

void object::update()
{
}

void object::render()
{
	if (_isFrame) _img->frameRender(getMemDC(), _rc.left, _rc.top);
	else _img->frameRender(getMemDC(), _rc.left, _rc.top, _frameX, 0);

}

void object::setObject(int x, int y)
{
	 _rc = RectMakeCenter(x, y, _img->getFrameWidth(), _img->getFrameHeight());
}

void object::frame()
{
	_count++;

	_img->setFrameY(0);

	if (_count % 10 == 0)
	{
		_frameX++;

		if (_frameX > _img->getMaxFrameX()) _frameX = 0;
	}

	_img->setFrameX(_frameX);
}
