#include "stdafx.h"
#include "item.h"

item::item()
{
}

item::~item()
{
}

HRESULT item::init()
{

	return S_OK;
}

void item::release()
{
}

void item::update()
{
}

void item::render()
{
	_img->frameRender(getMemDC(), _imgRc->left, _imgRc->top);
}

void item::render(int left, int top)
{
	_img->render(getMemDC(), left, top);
}
