#include "stdafx.h"
#include "tree.h"

tree::tree()
{
}

tree::~tree()
{
}

HRESULT tree::init(int frameX)
{
	_isFrame = false;

	_img = IMAGEMANAGER->findImage("나무");

	_frameX = frameX;

	return S_OK;
}

HRESULT tree::init()
{
	_isFrame = false;

	_img = IMAGEMANAGER->findImage("나무");
	return S_OK;
}

void tree::release()
{
}

void tree::update()
{
}

void tree::render()
{
	object::render();
}
