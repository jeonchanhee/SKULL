#include "stdafx.h"
#include "storeScene.h"

storeScene::storeScene()
{
}

storeScene::~storeScene()
{
}

HRESULT storeScene::init()
{
	_load = new mapLoad;
	_load->storeLoad();

	setNpc();

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		_tiles[i] = _load->getTiles(i);
	}

	_door = new door;
	_door->init("던전문", WINSIZEX / 2 + 1300, WINSIZEY / 2 + 220, true);

	_skullgive = new skullGiveNpc;
	_skullgive->init(500, 640);

	_itemNpc = new itemNpc;
	_itemNpc->init(1100, 640);

	return S_OK;
}

void storeScene::release()
{

}

void storeScene::update()
{
	_load->objectUpdate();

	PLAYER->update(_tiles);
	_door->update();


	RECT temp;
	if (IntersectRect(&temp, &_door->getRc(), &PLAYER->getRc()))
	{
		if (KEYMANAGER->isOnceKeyDown('E'))
		{
			SCENEMANAGER->changeScene("던전1");
		}
	}

	_skullgive->update();
	_itemNpc->update();
}

void storeScene::render()
{
	_load->render();
	_door->render();

	_skullgive->render();
	_itemNpc->render();

	PLAYER->render(getMemDC());
}

void storeScene::setNpc()
{
}
