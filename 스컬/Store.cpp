#include "stdafx.h"
#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
}

HRESULT Store::init()
{

	return S_OK;
}

void Store::release()
{
}

void Store::update()
{

}

void Store::render()
{
	_img->frameRender(getMemDC(), _imgRc.left, _imgRc.top);
}

void Store::open()
{
	RECT temp;

	if (IntersectRect(&temp, &PLAYER->getRc(), &_collRect))
	{
		if (KEYMANAGER->isOnceKeyDown('E'))
		{
			if (_isOpen) _isOpen = false;
			else _isOpen = true;
		}
	}
}

void Store::frame()
{
	_count++;

	if (_count % 10 == 0)
	{
		_frameX++;

		if (_frameX > _img->getMaxFrameX()) _frameX = 0;
	}

	_img->setFrameX(_frameX);
}
