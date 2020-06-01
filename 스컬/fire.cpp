#include "stdafx.h"
#include "fire.h"

fire::fire()
{
}

fire::~fire()
{
}

HRESULT fire::init()
{
	_isFrame = true;

	_img = IMAGEMANAGER->findImage("È­·Î");

	return S_OK;
}

void fire::release()
{
}

void fire::update()
{
	frame();
}

void fire::render()
{
	object::render();
}
