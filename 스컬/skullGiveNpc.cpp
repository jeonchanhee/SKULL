#include "stdafx.h"
#include "skullGiveNpc.h"

skullGiveNpc::skullGiveNpc()
{
}

skullGiveNpc::~skullGiveNpc()
{
}

HRESULT skullGiveNpc::init(int x, int y)
{
	_img = IMAGEMANAGER->findImage("�����Ӹ�");

	_x = x;
	_y = y;

	_imgRc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

	_head = new head;
	_give = true;
	return S_OK;
}

void skullGiveNpc::release()
{
}

void skullGiveNpc::update()
{
	if (_give)
	{
		give();
	}
	
	frame();
	_head->update();
}

void skullGiveNpc::render()
{
	Store::render();
	_head->render();
}

void skullGiveNpc::give()
{
	randNum = RND->getFromIntTo(0, 4);

	switch (randNum)
	{
	case 0:
		if (PLAYER->getSkull() == WARRIOR || PLAYER->getSecondSkull() == WARRIOR) break;
		_head->create("��ġ������Ӹ�", _x - 80, _y + 30);
		_give = false;
		break;
	case 1:
		if (PLAYER->getSkull() == WARRIOR2 || PLAYER->getSecondSkull() == WARRIOR2) break;
		_head->create("��ġ������2�Ӹ�", _x - 80, _y + 30);
		_give = false;
		break;
	case 2:
		if (PLAYER->getSkull() == ARCHER || PLAYER->getSecondSkull() == ARCHER) break;
		_head->create("��ġ�ü��Ӹ�", _x - 80, _y + 30);
		_give = false;
		break;
	case 3:
		if (PLAYER->getSkull() == SWORD || PLAYER->getSecondSkull() == SWORD) break;
		_head->create("��ġ�˺��Ӹ�", _x - 80, _y + 30);
		_give = false;
		break;
	case 4:
		if (PLAYER->getSkull() == SPEAR || PLAYER->getSecondSkull() == SPEAR) break;
		_head->create("��ġâ���Ӹ�", _x - 80, _y + 30);
		_give = false;
		break;
	}
}
