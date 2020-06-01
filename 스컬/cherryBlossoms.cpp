#include "stdafx.h"
#include "cherryBlossoms.h"

cherryBlossoms::cherryBlossoms(){}

cherryBlossoms::~cherryBlossoms(){}

HRESULT cherryBlossoms::init(int x, int y)
{
	_img = IMAGEMANAGER->findImage("孩采唱公");

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

	_attImg = IMAGEMANAGER->findImage("孩采唱公傍拜");

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

	_hp = 10;

	return S_OK;
}

void cherryBlossoms::release(){}

void cherryBlossoms::update()
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
		frame(5, 9);
		break;
	case E_RIHGT_ATTACK:
		frame(4, 9);
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
	 
	attack();
	_imgRc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());
	_hitRc = RectMakeCenter(_x, _y, 100, 100);

	if (_imgRc.left <= 0) _state = E_RIGHT;

	if (_isAttack)
	{
		if (_count % 5 == 0)
		{
			attFrameX++;

			if (attFrameX > _attImg->getMaxFrameX()) attFrameX = 0;

			_attImg->setFrameX(attFrameX);
		}
	}

}

void cherryBlossoms::render()
{
	_img->frameRender(getMemDC(), _imgRc.left, _imgRc.top, _frameX, _frameY);

	if (_isAttack) _attImg->frameRender(getMemDC(), _attRc->left, _attRc->top);
}

void cherryBlossoms::attack()
{
	if (_attImg->getFrameX() == _attImg->getMaxFrameX() && _isAttack)
	{
		if (!_isAttack) return;

		_isAttack = false;

		if (_state == E_LEFT_ATTACK) _state = E_LEFT_STOP;
		if (_state == E_RIHGT_ATTACK) _state = E_RIGHT_STOP;

		delete _attRc;
	}


	if (getDistance(_x, _y, PLAYER->getX(), PLAYER->getY()) > _attRange) return;


	if (_isAttack) return;

	_attCount++;

	if (_attCount % 100 == 0)
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
