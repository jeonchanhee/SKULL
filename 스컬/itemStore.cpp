#include "stdafx.h"
#include "itemStore.h"

itemStore::itemStore()
{
}

itemStore::~itemStore()
{
}

HRESULT itemStore::init()
{
	for (int i = 0; i < 3; i++)
	{
		randNum = RND->getInt(6);
		setItem();

	}



	return S_OK;
}

void itemStore::release()
{
}

void itemStore::update()
{
}

void itemStore::render()
{
}

void itemStore::setItem()
{
	
}
