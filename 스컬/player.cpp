#include "stdafx.h"
#include "player.h"

player::player(){}

player::~player(){}

HRESULT player::init()
{
	playerImages();

	_move = RIGHT_STOP;
	_skull = WARRIOR;
	_speed = 5;

	headType();

	x = WINSIZEX / 2;
	y = WINSIZEY / 2;

	imgRc = RectMakeCenter(x, y, img->getFrameWidth(), img->getFrameHeight());

	frameIndex = 0;
	count = 0;
	jumpTime = 0;

	_isJump = false;
	_isAtt = false;
	_isAilve = true;
	_deletRc = false;
	_FirstHit = false;

	money = 0;
	attCount = 0;

	_ui = new UI;
	_ui->init();

	_inven = new inven;
	_inven->init();
	
	_secondSkull = WARRIOR2;

	_hp = 100;
	_att = 5;

	return S_OK;
}

void player::release(){}

void player::update(tagTile tiles[])
{
	count++;

	keyControl(tiles);

	if (_inven->getOpen()) _inven->update();
	else
	{
		playerFrame();
		downTileDetection(tiles);

		if (x > WINSIZEX / 2)
		{
			CAMERAMANAGER->setCameraCenter(PointMake(x, CAMERAMANAGER->getCameraCenter().y));
		}

		if (y > WINSIZEY / 2)
		{
			CAMERAMANAGER->setCameraCenter(PointMake(CAMERAMANAGER->getCameraCenter().x, y));
		}

		if (_headChage) headType();
		imgRc = RectMakeCenter(x, y, img->getFrameWidth(), img->getFrameHeight());
		hitRcMove();
		playerJump();

		_ui->update();

		if (_isAtt)
		{
			switch (_move)
			{
			case LEFT_ATT:
				attRc = new RECT;
				*attRc = RectMake(hitRc.left - 20, hitRc.top, 50, 80);
				break;
			case RIGHT_ATT:
				attRc = new RECT;
				*attRc = RectMake(hitRc.right, hitRc.top, 50, 80);
				break;
			
			}
		}

		if (_deletRc)
		{
			delete attRc;
			_deletRc = false;
		}
	}
}

void player::update()
{
	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		if (_inven->getOpen())
		{
			_inven->close();
			_inven->setOpne(false);
		}
		else
		{
			_inven->open();
			_inven->setOpne(true);
		}
	}

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		if (_secondSkull == EMPTY) return;

		SKULL temp;

		temp = _skull;
		_skull = _secondSkull;
		_secondSkull = temp;
		_headChage = true;
	}

	if (_headChage)
	{
		headType();
	}

	if (_inven->getOpen()) _inven->update();
	_ui->update();
}

void player::render(HDC hdc)
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		Rectangle(hdc, hitRc.left, hitRc.top, hitRc.right, hitRc.bottom);
		Rectangle(hdc, rcDownColl.left, rcDownColl.top, rcDownColl.right, rcDownColl.bottom);
		Rectangle(hdc, rcCollision.left, rcCollision.top, rcCollision.right, rcCollision.bottom);

		if (_isAtt) Rectangle(hdc, attRc->left, attRc->top, attRc->right, attRc->bottom);
	}
	img->frameRender(hdc, imgRc.left, imgRc.top);
	_ui->render();
	_inven->render();
}

void player::playerImages()
{
	IMAGEMANAGER->addFrameImage("기본", "images/player/플레이어(기본).bmp", 2340 * 2, 2340 * 2, 9, 9, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("기본(머리없)", "images/player/플레이어(기본 머리 없을때).bmp", 405 * 2, 320 * 2, 9, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("워리어", "images/player/플레이어(워리어).bmp", 5200 * 2, 2340 * 2, 20, 9, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("워리어2", "images/player/플레이어(워리어2).bmp", 3900 * 2, 2600 * 2, 15, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("궁수", "images/player/플레이어(활).bmp", 2340 * 2, 2600 * 2, 9, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("검병", "images/player/플레이어(검).bmp", 4160 * 2, 2340 * 2, 16, 9, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("창병", "images/player/플레이어(창병).bmp", 2860 * 2, 2340 * 2, 11, 9, true, RGB(255, 0, 255));
}

void player::keyControl(tagTile tiles[])
{
	if (!_inven->getOpen())
	{
		if (!_isAtt)
		{
			if (KEYMANAGER->isStayKeyDown('A'))
			{
				_move = LEFT;
				tileDetection(tiles);
			}

			if (KEYMANAGER->isStayKeyDown('D'))
			{
				_move = RIGHT;

				tileDetection(tiles);
			}

			if (KEYMANAGER->isOnceKeyUp('A')) _move = LEFT_STOP;

			if (KEYMANAGER->isOnceKeyUp('D')) _move = RIGHT_STOP;
		}
		if (KEYMANAGER->isStayKeyDown('K'))
		{
			_isAtt = true;
			_deletRc = true;
			_FirstHit = false;

			if (attCount == 0) attCount++;

			if (_move == LEFT || _move == LEFT_STOP)_move = LEFT_ATT;
			else if (_move == RIGHT || _move == RIGHT_STOP)_move = RIGHT_ATT;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_isJump = true;
			jumpTime = TIMEMANAGER->getWorldTime();

			if (_move == LEFT || _move == LEFT_STOP)_move = LEFT_JUMP;
			else if (_move == RIGHT || _move == RIGHT_STOP)_move = RIGHT_JUMP;
		}

		if (KEYMANAGER->isOnceKeyDown('C'))
		{
			if (_secondSkull == EMPTY) return;

			SKULL temp;

			temp = _skull;
			_skull = _secondSkull;
			_secondSkull = temp;
			_headChage = true;

		}
	}

	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		if (_inven->getOpen())
		{
			_inven->close();
			_inven->setOpne(false);
		}
		else
		{
			_inven->open();
			_inven->setOpne(true);
		}
	}

}

void player::playerFrame()
{
	switch (_move)
	{
	case LEFT:
		switch (_skull)
		{
		case BASICS: case WARRIOR: case WARRIOR2: case SWORD: case SPEAR:
			imageFrame(3, 7);
			break;
		case ARCHER:
			imageFrame(3, 6);
			break;
		}
		break;
	case LEFT_STOP:
		switch (_skull)
		{
		case BASICS: case WARRIOR: case SWORD: case ARCHER: case SPEAR:
			imageFrame(1, 3);
			break;
		case WARRIOR2:
			imageFrame(1, 5);
			break;
		}
		break;
	case LEFT_JUMP:
		switch (_skull)
		{
		case BASICS: case SPEAR:
			imageFrame(7, 6);
			break;
		case WARRIOR:case WARRIOR2:
			imageFrame(7, 7);
			break;
		case SWORD:
			imageFrame(7, 4);
			break;
		case ARCHER:
			imageFrame(7, 5);
			break;
		}
		break;
	case RIGHT:
		switch (_skull)
		{
		case BASICS: case WARRIOR: case WARRIOR2: case SWORD: case SPEAR:
			imageFrame(2, 7);
			break;
		case ARCHER:
			imageFrame(2, 6);
			break;
		}
		break;
	case RIGHT_STOP:
		switch (_skull)
		{
		case BASICS: case WARRIOR: case SWORD: case ARCHER: case SPEAR:
			imageFrame(0, 3);
			break;
		case WARRIOR2:
			imageFrame(0, 5);
			break;
		}
		break;
	case RIGHT_JUMP:
		switch (_skull)
		{
		case BASICS: case SPEAR:
			imageFrame(6, 6);
			break;
		case WARRIOR: case WARRIOR2:
			imageFrame(6, 7);
			break;
		case SWORD:
			imageFrame(6, 3);
			break;
		case ARCHER:
			imageFrame(6, 5);
			break;
		}
		break;
	case LEFT_ATT:
		imageFrame(5, img->getMaxFrameX());
		break;
	case RIGHT_ATT:
		imageFrame(4, img->getMaxFrameX());
		break;
	}
}

void player::headType()
{
	switch (_skull)
	{
	case BASICS:
		img = IMAGEMANAGER->findImage("기본");
		break;
	case WARRIOR:
		img = IMAGEMANAGER->findImage("워리어");
		break;
	case WARRIOR2:
		img = IMAGEMANAGER->findImage("워리어2");
		break;
	case ARCHER:
		img = IMAGEMANAGER->findImage("궁수");
		break;
	case SWORD:
		img = IMAGEMANAGER->findImage("검병");
		break;
	case SPEAR:
		img = IMAGEMANAGER->findImage("창병");
		break;
	}
	_headChage = false;
}

void player::hitRcMove()
{
	hitRc = RectMakeCenter(x, y, 50, 80);
}

void player::tileDetection(tagTile tiles[])
{
	

	int tileIndex[2];	// 이동 방향에 따른 타일속성을 검출하기 위한 타일 인덱스 값 계산용 배열
	int tileX, tileY;	// 이동 방향에 따라 검출하기 위한 인덱스 계산용 변수


	tileX = x / TILESIZE;
	tileY = y / TILESIZE;

	// 좌우 검출
	switch (_move)
	
	{
	case LEFT:
		rcCollision = RectMake(hitRc.left, hitRc.top, 4, 50);
		break;
	case RIGHT:
		rcCollision = RectMake(hitRc.right + 1, hitRc.top, 4, 50);
		break;
	}

	switch (_move)
	{
	case LEFT:
		tileIndex[0] = (tileX + tileY * TILEX) - 1;
		tileIndex[1] = tileX + (tileY + 1) * TILEX;
		break;
	case RIGHT:
		tileIndex[0] = (tileX + tileY * TILEX) + 1;
		tileIndex[1] = (tileX + (1 + tileY) * TILEX) + 1;
		break;
	}

	  
	for (int i = 0; i < 2; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &rcCollision, &tiles[tileIndex[i]].rc) && tiles[tileIndex[i]].terrain[i] == TR_WALL)
		{
			return;
		}
	}

	switch (_move)
	{
	case LEFT:
		x -= 5;
		break;
	case RIGHT:
		x += 5;
		break;
	}
}

void player::downTileDetection(tagTile tiles[])
{
	int tileIndex[2];
	int tileX, tileY;	// 이동 방향에 따라 검출하기 위한 인덱스 계산용 변수

	tileX = x / TILESIZE;
	tileY = y / TILESIZE;

	// 아래 검출
	rcDownColl = RectMakeCenter(x, hitRc.bottom + 1, 10, 4);

	tileIndex[0] = (tileX + tileY * TILEX) + TILEX;
	tileIndex[1] = (tileX + 1 + tileY * TILEX) + TILEX;

	for (int i = 0; i < 2; i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &rcDownColl, &tiles[tileIndex[i]].rc) && (tiles[tileIndex[i]].terrain[i] == TR_GROUND || tiles[tileIndex[i]].terrain[i] == TR_FALLING_GROUND))
		{
			return;
		}
	}

	if(!_isJump) y += 5;
}

void player::playerJump()
{
	if (!_isJump) return;

	if (TIMEMANAGER->getWorldTime() - jumpTime < 0.5f) y -= 5;
	else
	{
		_isJump = false;
		
		if (_move == LEFT_JUMP) _move = LEFT_STOP;
		if (_move == RIGHT_JUMP) _move = RIGHT_STOP;
	}

}

void player::imageFrame(int frameY, int maxFrame)
{
	img->setFrameY(frameY);

	if (count % 10 == 0)
	{
		frameIndex++;

		if (frameIndex > maxFrame)
		{

			frameIndex = 0;
			
			if (_isAtt)
			{
				_isAtt = false;

				if (_move == LEFT_ATT) _move = LEFT_STOP;
				if (_move == RIGHT_ATT) _move = RIGHT_STOP;
			}
		}
	}

	img->setFrameX(frameIndex);
}
