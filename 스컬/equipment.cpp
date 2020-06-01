#include "stdafx.h"
#include "equipment.h"

equipment::equipment()
{
}

equipment::~equipment()
{
}

HRESULT equipment::init()
{
	return S_OK;
}

void equipment::release()
{

}

void equipment::update()
{

}

void equipment::render()
{
	if(_isCreate) _img->render(getMemDC(), _imgRc->left, _imgRc->top);
}

void equipment::create(const char* imgName, int x, int y)
{

	_img = IMAGEMANAGER->findImage(imgName);

	_x = x;
	_y = y;

	_imgRc = new RECT;
	*_imgRc = RectMakeCenter(_x, _y, _img->getWidth(), _img->getHeight());

	_isCreate = true;

}
