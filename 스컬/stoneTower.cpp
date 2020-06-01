#include "stdafx.h"
#include "stoneTower.h"

stoneTower::stoneTower()
{
}

stoneTower::~stoneTower()
{
}

HRESULT stoneTower::init()
{
	_isFrame = false;

	_img = IMAGEMANAGER->findImage("µ¹Å¾");


	return S_OK;
}

void stoneTower::release()
{
}

void stoneTower::update()
{
}

void stoneTower::render()
{
	object::render();
}
