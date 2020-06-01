#include "stdafx.h"
#include "embeddedTree.h"

embeddedTree::embeddedTree()
{
}

embeddedTree::~embeddedTree()
{
}

HRESULT embeddedTree::init(int x, int y)
{
	_img = IMAGEMANAGER->findImage("박혀있는나무");
	_x = x;
	_y = y;
	
	_imgRc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameWidth());
	_hitRc = RectMakeCenter(_x, _y, 100, 100);

	_isAlive = true;
	_isAttack = false;

	_state = E_IDLE;

	_exploreRange = 100;
	_attRange = 50;

	return S_OK;
}

void embeddedTree::release()
{
}

void embeddedTree::update()
{
	_count++;

	switch (_state)
	{
	case E_DIE:
		frame(3, 0);
		break;
	case E_IDLE:
		frame(0, 5);
		break;
	case E_ATTACK:

		break;
	}
}

void embeddedTree::render()
{
	enemy::render();
}

void embeddedTree::attack()
{
	if (_img->getFrameX() >= 3)
	{
		_isAttack = false;

		delete _attRc;
	}


	if (getDistance(_x, _y, PLAYER->getX(), PLAYER->getY()) > _attRange) return;

	_attCount++;

	if (_attCount % 20 == 0)
	{
		_isAttack = true;

		if (_state == E_LEFT || _state == E_LEFT_STOP)
		{
			_state = E_LEFT_ATTACK;

		}
		else if (_state == E_RIGHT || _state == E_RIGHT_STOP)
		{
			_state = E_RIHGT_ATTACK;
		}
		_attRc = new RECT;

		*_attRc = RectMakeCenter(_x, _y, _attImg->getFrameWidth(), _attImg->getFrameHeight());
	}
}
