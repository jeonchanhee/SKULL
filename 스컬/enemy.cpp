#include "stdafx.h"
#include "enemy.h"

enemy::enemy()
{
}

enemy::~enemy()
{
}

HRESULT enemy::init(int x, int y)
{
	return S_OK;
}

void enemy::release(){}

void enemy::update()
{

}

void enemy::render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(getMemDC(), _hitRc.left, _hitRc.top, _hitRc.right, _hitRc.bottom);
		Rectangle(getMemDC(), rcColl.left, rcColl.top, rcColl.right, rcColl.bottom);
	}

	_img->frameRender(getMemDC(), _imgRc.left, _imgRc.top);
}

void enemy::move(tagTile tiles[])
{
	if (_state != E_LEFT && _state != E_RIGHT) return;


	int tileIndex[2];
	int tileX, tileY;

	tileX = _x / TILESIZE;
	tileY = _y / TILESIZE;

	switch (_state)
	{
	case E_LEFT:
		rcColl = RectMake(_hitRc.left - 10, _hitRc.top, 4, 50);

		tileIndex[0] = (tileX + tileY * TILEX) - 1;
		tileIndex[1] = tileX + (tileY + 1) * TILEX;
		break;
	case E_RIGHT:
		rcColl = RectMake(_hitRc.right, _hitRc.top, 4, 50);

		tileIndex[0] = (tileX + tileY * TILEX) + 1;
		tileIndex[1] = (tileX + (1 + tileY) * TILEX) + 1;
		break;
	}

	for (int i = 0; i < 2; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &rcColl, &tiles[tileIndex[i]].rc) && tiles[tileIndex[i]].terrain[i] == TR_WALL)
		{
			if (_state == E_LEFT) _state = E_RIGHT;
			else if (_state == E_RIGHT) _state = E_LEFT;
		}
	}

	switch (_state)
	{
	case E_LEFT:
		_x -= 2;
		break;
	case E_RIGHT:
		_x += 2;
		break;
	}
}


void enemy::frame(int frameY, int maxFrameX)
{
	//_img->setFrameY(frameY);

	//if (_count % 10 == 0)
	//{
	//	_frameX++;

	//	if (_frameX > maxFrameX) _frameX = 0;
	//}


	_frameY = frameY;

	if (_count % 10 == 0)
	{
		_frameX++;

		if (_frameX > maxFrameX) _frameX = 0;
	}

	_img->setFrameX(_frameX);
}

void enemy::downTileDetection(tagTile tiles[])
{
	RECT rcColl = RectMakeCenter(_x, _hitRc.bottom, 10, 4);

	int tileIndex[2];
	int tileX, tileY;

	tileX = _x / TILESIZE;
	tileY = _y / TILESIZE;

	for (int i = 0; i < 2; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &rcColl, &tiles[tileIndex[i]].rc) && (tiles[tileIndex[i]].terrain[i] != TR_GROUND || tiles[tileIndex[i]].terrain[i] != TR_FALLING_GROUND))
		{
			return;
		}
	}

	_y -= 5;
}
