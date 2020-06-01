#include "stdafx.h"
#include "archer.h"

archer::archer()
{
}

archer::~archer()
{
}

HRESULT archer::init(int x, int y)
{
	_img = IMAGEMANAGER->findImage("ÀÎ°£±Ã¼ö");

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

	_state = E_LEFT;

	return S_OK;
}

void archer::release(){}

void archer::update()
{
	_count++;

	switch (_state)
	{
	case E_LEFT:
		frame(3, 5);
		break;
	case E_LEFT_STOP:
		frame(1, 4);
		break;
	case E_RIGHT:
		frame(2, 5);
		break;
	case E_RIGHT_STOP:
		frame(0, 4);
		break;
	case E_LEFT_ATTACK:
		frame(5, 2);
		break;
	case E_RIHGT_ATTACK:
		frame(4, 2);
		break;
	}

	//attack();
	_imgRc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	_hitRc = RectMakeCenter(_x, _y, 100, 100);

	if (_imgRc.left <= 0) _state = E_RIGHT;
}

void archer::render()
{
	enemy::render();
}

void archer::attack()
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
