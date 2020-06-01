#include "stdafx.h"
#include "skullFox.h"

skullFox::skullFox()
{
}

skullFox::~skullFox()
{
}

HRESULT skullFox::init()
{
	_img = IMAGEMANAGER->findImage("머리주는여우");

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	_imgRc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	

	index = 0;
	
	_head = new head;
	
	_give = false;

	return S_OK;
}

void skullFox::release()
{
}

void skullFox::update()
{
	open();
	frame();

	if (_isOpen)
	{
		if (index >= 2) return;
		index++;
		_isOpen = false;
		_give = true;
	}

	if (_give)
	{
		randNum = RND->getFromIntTo(0, 4);
		giveSkull();
	}

	_head->update();

	_imgRc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	_collRect = RectMakeCenter(_x + 50, _y, 150, 150);
}

void skullFox::render()
{
	Store::render();
	_head->render();
}

void skullFox::giveSkull()
{
	switch (randNum)
	{
	case 0:
		if (PLAYER->getSkull() == WARRIOR || PLAYER->getSecondSkull() == WARRIOR) break;
		_head->create("배치워리어머리", _x - 90, _y + 30);
		_give = false;
		break;
	case 1:
		if (PLAYER->getSkull() == WARRIOR2 || PLAYER->getSecondSkull() == WARRIOR2) break;
		_head->create("배치워리어2머리", _x - 90 , _y + 30);
		_give = false;
		break;
	case 2:
		if (PLAYER->getSkull() == ARCHER || PLAYER->getSecondSkull() == ARCHER) break;
		_head->create("배치궁수머리", _x - 90, _y + 30);
		_give = false;
		break;
	case 3:
		if (PLAYER->getSkull() == SWORD || PLAYER->getSecondSkull() == SWORD) break;
		_head->create("배치검병머리", _x - 90, _y + 30);
		_give = false;
		break;
	case 4:
		if (PLAYER->getSkull() == SPEAR || PLAYER->getSecondSkull() == SPEAR) break;
		_head->create("배치창병머리", _x - 90, _y + 30);
		_give = false;
		break;
	}
}
