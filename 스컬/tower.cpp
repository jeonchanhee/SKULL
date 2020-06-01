#include "stdafx.h"
#include "tower.h"

tower::tower()
{
}

tower::~tower()
{
}

HRESULT tower::init()
{
	_isFrame = true;

	_img = IMAGEMANAGER->findImage("Å¸¿ö");

	return S_OK;
}

void tower::release()
{
}

void tower::update()
{
	frame();
}

void tower::render()
{
	object::render();
}
