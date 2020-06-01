#include "stdafx.h"
#include "thornTree.h"

thornTree::thornTree()
{
}

thornTree::~thornTree()
{
}

HRESULT thornTree::init(int x, int y)
{
	_img = IMAGEMANAGER->findImage("가시나무");

	_x = x;
	_y = y;

	_imgRc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

	_hitRc = RectMakeCenter(_x, _y, 100, 100);

	_count = 0;
	_attCount = 0;

	_attCount = 0;

	_exploreRange = 20;
	_attRange = 100;

	_isAlive = true;
	_isAttack = false;

	_randNum = RND->getInt(4);

	switch (_randNum)
	{
	case 0:
		_state = E_LEFT;
		break;
	case 1:
		_state = E_LEFT_STOP;
		break;
	case 2:
		_state = E_RIGHT;
		break;
	case 3:
		_state = E_RIGHT_STOP;
		break;
	}

	return S_OK;
}

void thornTree::release()
{
}

void thornTree::update()
{
	_count++;

	switch (_state)
	{
	case E_LEFT:
		frame(3, 3);
		break;
	case E_LEFT_STOP:
		frame(1, 4);
		break;
	case E_RIGHT:
		frame(2, 3);
		break;
	case E_RIGHT_STOP:
		frame(0, 4);
		break;
	case E_LEFT_ATTACK:
		frame(5, 7);
		break;
	case E_RIHGT_ATTACK:
		frame(4, 7);
		break;
	}

	if (_count % 50 == 0)
	{
		_randNum = RND->getInt(4);

		switch (_randNum)
		{
		case 0:
			_state = E_LEFT;
			break;
		case 1:
			_state = E_LEFT_STOP;
			break;
		case 2:
			_state = E_RIGHT;
			break;
		case 3:
			_state = E_RIGHT_STOP;
			break;
		}
	}
	//attack();
	_imgRc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	_hitRc = RectMakeCenter(_x, _y, 100, 100);

	if (_imgRc.left <= 0) _state = E_RIGHT;
}

void thornTree::render()
{
	_img->frameRender(getMemDC(), _imgRc.left, _imgRc.top, _frameX, _frameY);
}

void thornTree::attack()
{
	if (_img->getFrameX() >= 3)
	{
		_isAttack = false;

		if (_state == E_LEFT_ATTACK) _state = E_LEFT_STOP;
		if (_state == E_RIHGT_ATTACK) _state = E_RIGHT_STOP;
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
	}
}
