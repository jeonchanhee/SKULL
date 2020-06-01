#include "stdafx.h"
#include "flag.h"

flag::flag()
{
}

flag::~flag()
{
}

HRESULT flag::init()
{
	_isFrame = true;

	_img = IMAGEMANAGER->findImage("±ê¹ß");

	return S_OK;
}

void flag::release()
{

}

void flag::update()
{
	frame();

}

void flag::render()
{
	object::render();
}
