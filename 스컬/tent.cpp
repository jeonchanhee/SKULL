#include "stdafx.h"
#include "tent.h"

tent::tent()
{
}

tent::~tent()
{
}

HRESULT tent::init()
{
	_isFrame = false;

	_img = IMAGEMANAGER->findImage("ลูฦฎ");


	return S_OK;
}

void tent::release()
{
}

void tent::update()
{
}

void tent::render()
{
	object::render();
}
