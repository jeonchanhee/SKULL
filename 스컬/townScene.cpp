#include "stdafx.h"
#include "townScene.h"

townScene::townScene()
{
}

townScene::~townScene()
{
}

HRESULT townScene::init()
{
	_load = new mapLoad;
	_load->townLoad();

	setNpc();

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		_tiles[i] = _load->getTiles(i);
	}

	_skullFox = new skullFox;
	_skullFox->init();
	_skullFox->setXY(WINSIZEX / 2, WINSIZEY / 2 + 200);


	_door = new door;
	_door->init("던전문", WINSIZEX / 2 + 800, WINSIZEY / 2 + 175, true);

	PLAYER->setPoint(PointMake(100, 600));

	return S_OK;
}

void townScene::release(){}

void townScene::update()
{
	_load->objectUpdate();

	PLAYER->update(_tiles);
	_skullFox->update();
	_door->update();


	RECT temp;
	if (IntersectRect(&temp, &_door->getRc(), &PLAYER->getRc()))
	{
		if (KEYMANAGER->isOnceKeyDown('E'))
		{
			SCENEMANAGER->changeScene("던전1");
		}
	}
}

void townScene::render()
{
	_load->render();
	_skullFox->render();
	_door->render();

	PLAYER->render(getMemDC());
}


void townScene::setNpc()
{

}
