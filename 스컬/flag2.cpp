#include "stdafx.h"
#include "flag2.h"

flag2::flag2()
{
}

flag2::~flag2()
{
}

HRESULT flag2::init()
{
	_isFrame = true;

	_img = IMAGEMANAGER->findImage("���2");

	return S_OK;
}

void flag2::release()
{
}

void flag2::update()
{
	frame();
}

void flag2::render()
{
	object::render();
}
