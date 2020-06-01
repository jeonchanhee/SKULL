#include "stdafx.h"
#include "dungeonScene.h"

dungeonScene::dungeonScene()
{
}

dungeonScene::~dungeonScene()
{
}

HRESULT dungeonScene::init()
{
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		_tiles[i] = _load->getTiles(i);
	}

	return S_OK;
}

void dungeonScene::release()
{

}

void dungeonScene::update(tagTile tiles[])
{
	for (int i = 0; i < _vEnemey.size(); i++)
	{
		if(!_vEnemey[i]->getIsAttac()) _vEnemey[i]->move(tiles);
		_vEnemey[i]->update();
	}

	_load->update();
	hitMonseter();
	hitPlayer();

}

void dungeonScene::render()
{
	_load->render();

	for (_viEnemey = _vEnemey.begin(); _viEnemey != _vEnemey.end(); ++_viEnemey)
	{
		(*_viEnemey)->render();
	}
}

void dungeonScene::setBasicTree(int x, int y)
{
	basicTree* _enemy = new basicTree;
	_enemy->init(x, y);
	_vEnemey.push_back(_enemy);
}

void dungeonScene::setCherryBlossoms(int x, int y)
{
	cherryBlossoms* _enemy = new cherryBlossoms;
	_enemy->init(x, y);
	_vEnemey.push_back(_enemy);
}

void dungeonScene::setEmbeddedTree(int x, int y)
{
	embeddedTree* _enemy = new embeddedTree;
	_enemy->init(x, y);
	_vEnemey.push_back(_enemy);
}

void dungeonScene::setThornTree(int x, int y)
{
	thornTree* _enemy = new thornTree;
	_enemy->init(x, y);
	_vEnemey.push_back(_enemy);
}

void dungeonScene::setAcher(int x, int y)
{
	archer* _enemy = new archer;
	_enemy->init(x, y);
	_vEnemey.push_back(_enemy);
}

void dungeonScene::setHammer(int x, int y)
{
	hammer* _enemy = new hammer;
	_enemy->init(x, y);
	_vEnemey.push_back(_enemy);
}

void dungeonScene::setSwordMan(int x, int y)
{
	swordMan* _enemy = new swordMan;
	_enemy->init(x, y);
	_vEnemey.push_back(_enemy);
}

void dungeonScene::setWizard(int x, int y)
{
	Wizard* _enemy = new Wizard;
	_enemy->init(x, y);
	_vEnemey.push_back(_enemy);
}

void dungeonScene::hitPlayer()
{
	/*RECT temp;

	for (int i = 0; i < _vEnemey.size(); i++)
	{
		if (IntersectRect(&temp, _vEnemey[i]->getAttRc(), &PLAYER->getHitRc()))
		{
			PLAYER->setHp(PLAYER->getHp() - _vEnemey[i]->getDmg());

			if (PLAYER->getHp() <= 0)
			{
				PLAYER->setHp(0);
				PLAYER->setAilve(false);
			}
			break;
		}
	}*/
}

void dungeonScene::hitMonseter()
{
	RECT temp;

	for (_viEnemey = _vEnemey.begin(); _viEnemey != _vEnemey.end(); _viEnemey++)
	{
		if (IntersectRect(&temp, &(*_viEnemey)->getHitRc(), PLAYER->getAttRc()) && !PLAYER->getFirstHit())
		{
			PLAYER->setFirstHit(true);

			(*_viEnemey)->setHp((*_viEnemey)->getHp() - PLAYER->getDmg());

			if ((*_viEnemey)->getHp() <= 0)
			{
				(*_viEnemey)->setHp(0);
				(*_viEnemey)->setAilve(false);
				remove();
			}

			break;
		}
	}
}

void dungeonScene::remove()
{
	for (int i = 0; i < _vEnemey.size(); i++)
	{
		if (!_vEnemey[i]->getAilve())
		{
			_vEnemey.erase(_vEnemey.begin() + i);
		}
	}
}