#include "stdafx.h"
#include "bigTree.h"

bigTree::bigTree()
{
}

bigTree::~bigTree()
{
}

HRESULT bigTree::init()
{
	_isFrame = false;

	_img = IMAGEMANAGER->findImage("Å«³ª¹«");

	return S_OK;
}

void bigTree::release()
{
}

void bigTree::update()
{
}

void bigTree::render()
{
	object::render();
}
