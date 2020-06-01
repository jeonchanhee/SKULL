#include "stdafx.h"
#include "dungeon1.h"

dungeon1::dungeon1()
{
}

dungeon1::~dungeon1()
{
}

HRESULT dungeon1::init()
{
	_load = new mapLoad;
	_load->dungeonLoad();

	setMonster();

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		_tiles[i] = _load->getTiles(i);
	}

	PLAYER->setPoint(PointMake(100, 400));
	CAMERAMANAGER->setCameraCenter(PointMake(WINSIZEX / 2, WINSIZEY / 2));

	_door = new door;
	_door->init("상점문", WINSIZEX / 2 + 2200, WINSIZEY / 2 + 70, false);

	return S_OK;
}

void dungeon1::release()
{
}

void dungeon1::update()
{
	dungeonScene::update(_tiles);
	_load->objectUpdate();

	_door->update();
	PLAYER->update(_tiles);

	if (_vEnemey.empty())
	{
		_door->setOpen(true);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		_vEnemey.clear();
	}

	RECT temp;
	if (IntersectRect(&temp, &_door->getRc(), &PLAYER->getRc()))
	{
		if (KEYMANAGER->isOnceKeyDown('E'))
		{
			SCENEMANAGER->changeScene("상점");
		}
	}

	if (!PLAYER->getAilve())
	{
		SCENEMANAGER->changeScene("인트로");
	}

}

void dungeon1::render()
{
	dungeonScene::render();

	_door->render();

	PLAYER->render(getMemDC());
}

void dungeon1::setMonster()
{
	
	setBasicTree((WINSIZEX / 2 + 100), WINSIZEY / 2 + 260);
	setSwordMan(WINSIZEX / 2 + 500, WINSIZEY / 2 + 110);
	setCherryBlossoms(WINSIZEX / 2 + 1100, WINSIZEY / 2 - 40);
}
