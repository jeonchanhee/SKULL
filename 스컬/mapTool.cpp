#include "stdafx.h"
#include "mapTool.h"

mapTool::mapTool(){}

mapTool::~mapTool(){}

HRESULT mapTool::init()
{
	setTiles();

	_sampleBook = new sampleBook;
	_sampleBook->init();

	return S_OK;
}

void mapTool::release(){}

void mapTool::update()
{
	cameraMove();

	_sampleBook->update();

	if (_sampleBook->getOpen() && PtInRect(&_sampleBook->getImgRc(), MOUSE->getPoint()))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_sampleBook->setCarrentTile();
		}
	}
	else
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (PtInRect(_sampleBook->getChecRc(), MOUSE->getPoint()))
			{
				_sampleBook->setOpen(true);
			}
			else
			{
				start.x = MOUSE->getPoint().x;
				start.y = MOUSE->getPoint().y;

				setMap();
			}
		}

		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			end.x = MOUSE->getPoint().x;
			end.y = MOUSE->getPoint().y; 

			drag();
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		save();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F2))
	{
		load();
	}

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 50 < _tiles[i].x && CAMERAX + WINSIZEX + 50 > _tiles[i].x && CAMERAY - 50 < _tiles[i].y && CAMERAY + WINSIZEY + 50 > _tiles[i].y)
		{
			if(_tiles[i].isObj)	_tiles[i].object->update();		
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		CAMERAMANAGER->setCameraCenter(PointMake(WINSIZEX / 2, WINSIZEY / 2));
		SCENEMANAGER->changeScene("인트로");
	}
}

void mapTool::render()
{
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 50 < _tiles[i].x && CAMERAX + WINSIZEX + 50 > _tiles[i].x && CAMERAY - 50 < _tiles[i].y && CAMERAY + WINSIZEY + 50 > _tiles[i].y)
		{
			if (_tiles[i].index == 0)
			{
				Rectangle(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].rc.right, _tiles[i].rc.bottom);
			}
			else if (_tiles[i].index == 2)
			{
				IMAGEMANAGER->findImage("지형")->frameRender(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX[0], _tiles[i].terrainFrameY[0]);
				IMAGEMANAGER->findImage("지형")->frameRender(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX[1], _tiles[i].terrainFrameY[1]);
			}
			else if(_tiles[i].index == 1)
			{
				IMAGEMANAGER->findImage("지형")->frameRender(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX[0], _tiles[i].terrainFrameY[0]);
			}
			
			if (KEYMANAGER->isToggleKey(VK_TAB))
			{
				SetBkMode(getMemDC(), TRANSPARENT);

				SetTextColor(getMemDC(), RGB(255, 0, 0));

				char str[128];
				sprintf_s(str, "%d", i);
				TextOut(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, str, strlen(str));
			}
		}
		
	}

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 50 < _tiles[i].x && CAMERAX + WINSIZEX + 50 > _tiles[i].x && CAMERAY - 50 < _tiles[i].y && CAMERAY + WINSIZEY + 50 > _tiles[i].y)
		{

			if (_tiles[i].isObj)
			{
				_tiles[i].object->render();
			}
		}
	}

	if (_sampleBook->getCarrentTile().check == P_TREE)
	{
		RECT temp;
		temp = RectMakeCenter(MOUSE->getPoint().x, MOUSE->getPoint().y, IMAGEMANAGER->findImage("나무")->getFrameWidth(), IMAGEMANAGER->findImage("나무")->getFrameHeight());
		IMAGEMANAGER->findImage("나무")->frameRender(getMemDC(), temp.left, temp.top, _sampleBook->getCarrentTile().x, 0);
	}

	if (_sampleBook->getCarrentTile().check == P_BIGTREE)
	{
		RECT temp;
		temp = RectMakeCenter(MOUSE->getPoint().x, MOUSE->getPoint().y, IMAGEMANAGER->findImage("큰나무")->getFrameWidth(), IMAGEMANAGER->findImage("큰나무")->getFrameHeight());
		IMAGEMANAGER->findImage("큰나무")->frameRender(getMemDC(), temp.left, temp.top, _sampleBook->getCarrentTile().x, 0);
	}

	if (_sampleBook->getCarrentTile().check == P_FLAG)
	{
		RECT temp;
		temp = RectMakeCenter(MOUSE->getPoint().x, MOUSE->getPoint().y, IMAGEMANAGER->findImage("깃발")->getFrameWidth(), IMAGEMANAGER->findImage("깃발")->getFrameHeight());
		IMAGEMANAGER->findImage("깃발")->frameRender(getMemDC(), temp.left, temp.top, _sampleBook->getCarrentTile().x, 0);
	}

	if (_sampleBook->getCarrentTile().check == P_FLAG2)
	{
		RECT temp;
		temp = RectMakeCenter(MOUSE->getPoint().x, MOUSE->getPoint().y, IMAGEMANAGER->findImage("깃발2")->getFrameWidth(), IMAGEMANAGER->findImage("깃발2")->getFrameHeight());
		IMAGEMANAGER->findImage("깃발2")->frameRender(getMemDC(), temp.left, temp.top, _sampleBook->getCarrentTile().x, 0);
	}

	if (_sampleBook->getCarrentTile().check == P_TOWER)
	{
		RECT temp;
		temp = RectMakeCenter(MOUSE->getPoint().x, MOUSE->getPoint().y, IMAGEMANAGER->findImage("타워")->getFrameWidth(), IMAGEMANAGER->findImage("타워")->getFrameHeight());
		IMAGEMANAGER->findImage("타워")->frameRender(getMemDC(), temp.left, temp.top, _sampleBook->getCarrentTile().x, 0);
	}

	if (_sampleBook->getCarrentTile().check == P_STONETOWER)
	{
		RECT temp;
		temp = RectMakeCenter(MOUSE->getPoint().x, MOUSE->getPoint().y, IMAGEMANAGER->findImage("돌탑")->getFrameWidth(), IMAGEMANAGER->findImage("돌탑")->getFrameHeight());
		IMAGEMANAGER->findImage("돌탑")->frameRender(getMemDC(), temp.left, temp.top, _sampleBook->getCarrentTile().x, 0);
	}

	if (_sampleBook->getCarrentTile().check == P_FIRE)
	{
		RECT temp;
		temp = RectMakeCenter(MOUSE->getPoint().x, MOUSE->getPoint().y, IMAGEMANAGER->findImage("화로")->getFrameWidth(), IMAGEMANAGER->findImage("화로")->getFrameHeight());
		IMAGEMANAGER->findImage("화로")->frameRender(getMemDC(), temp.left, temp.top, _sampleBook->getCarrentTile().x, 0);
	}

	if (_sampleBook->getCarrentTile().check == P_TENT)
	{
		RECT temp;
		temp = RectMakeCenter(MOUSE->getPoint().x, MOUSE->getPoint().y, IMAGEMANAGER->findImage("텐트")->getFrameWidth(), IMAGEMANAGER->findImage("텐트")->getFrameHeight());
		IMAGEMANAGER->findImage("텐트")->frameRender(getMemDC(), temp.left, temp.top, _sampleBook->getCarrentTile().x, 0);
	}

	_sampleBook->render();
}

void mapTool::cameraMove()
{
	
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && CAMERAMANAGER->getCameraXY().x > 0)
	{
		CAMERAMANAGER->setCameraCenter(PointMake(CAMERAMANAGER->getCameraCenter().x - 50, CAMERAMANAGER->getCameraCenter().y));
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && CAMERAMANAGER->getCameraCenter().x + WINSIZEX / 2 < TILESIZEX)
	{
		CAMERAMANAGER->setCameraCenter(PointMake(CAMERAMANAGER->getCameraCenter().x + 50, CAMERAMANAGER->getCameraCenter().y));
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP) && CAMERAMANAGER->getCameraCenter().y - WINSIZEY / 2 > 0)
	{
		CAMERAMANAGER->setCameraCenter(PointMake(CAMERAMANAGER->getCameraCenter().x, CAMERAMANAGER->getCameraCenter().y - 50));
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN) && CAMERAMANAGER->getCameraCenter().y + WINSIZEY / 2 < TILESIZEY)
	{
		CAMERAMANAGER->setCameraCenter(PointMake(CAMERAMANAGER->getCameraCenter().x, CAMERAMANAGER->getCameraCenter().y + 50));
	}
}

void mapTool::setTiles()
{
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			SetRect(&_tiles[i * TILEX + j].rc, j * TILESIZE, i * TILESIZE, j * TILESIZE + TILESIZE, i * TILESIZE + TILESIZE);
		}
	}

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			_tiles[i].x = _tiles[i].rc.left + (_tiles[i].rc.right - _tiles[i].rc.left) / 2;
			_tiles[i].y = _tiles[i].rc.top + (_tiles[i].rc.bottom - _tiles[i].rc.top) / 2;

			_tiles[i].terrain[j] = TR_NULL;
			_tiles[i].terrainFrameX[j] = 0;
			_tiles[i].terrainFrameY[j] = 0;

			_tiles[i].obj = OBJ_NULL;
			_tiles[i].objFrameX = 0;
			_tiles[i].objFrameY = 0;

			_tiles[i].index = 0;
		}
	}
}


void mapTool::setMap()
{
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (PtInRect(&_tiles[i].rc, MOUSE->getPoint()))
		{
			if (_sampleBook->getCarrentTile().check == P_TERRAIN)
			{
				if (_tiles[i].index == 2) _tiles[i].index = 1;

				_tiles[i].terrainFrameX[_tiles[i].index] = _sampleBook->getCarrentTile().x;
				_tiles[i].terrainFrameY[_tiles[i].index] = _sampleBook->getCarrentTile().y;

				_tiles[i].terrain[_tiles[i].index] = setTerrain(_sampleBook->getCarrentTile().x, _sampleBook->getCarrentTile().y);

				if (_tiles[i].index < 2)
				{
					_tiles[i].index++;
				}

				break;
			}
			else selectObject();
		}	
	}
}

void mapTool::drag()
{
	if (start.x == NULL && start.y == NULL) return;

	if (start.x > end.x)
	{
		int temp;
		temp = start.x;
		start.x = end.x;
		end.x = temp;
	}

	if (start.y > end.y)
	{
		int temp;
		temp = start.y;
		start.y = end.y;
		end.y = temp;
	}

	RECT dragRc;
	RECT temp;
	SetRect(&dragRc, start.x, start.y, end.x, end.y);

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (_sampleBook->getCarrentTile().check == P_TERRAIN)
		{
			if (IntersectRect(&temp, &_tiles[i].rc, &dragRc))
			{
				if (_tiles[i].index == 2) _tiles[i].index = 1;

				_tiles[i].terrainFrameX[_tiles[i].index] = _sampleBook->getCarrentTile().x;
				_tiles[i].terrainFrameY[_tiles[i].index] = _sampleBook->getCarrentTile().y;

				_tiles[i].terrain[_tiles[i].index] = setTerrain(_sampleBook->getCarrentTile().x, _sampleBook->getCarrentTile().y);

				if (_tiles[i].index < 2)
				{
					_tiles[i].index++;
				}
			}
		}
	}

	start.x = NULL;
	start.y = NULL;
	end.x = NULL;
	end.y = NULL;
}

void mapTool::save()
{
	HANDLE	file;
	DWORD	save;

	file = CreateFile("던전2.map", GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	WriteFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &save, NULL);

	CloseHandle(file);
}

void mapTool::load()
{

	HANDLE	file2;
	DWORD	load;

	ZeroMemory(&_tiles, sizeof(tagTile) * TILEX * TILEY);

	file2 = CreateFile("던전2.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file2, _tiles, sizeof(tagTile) * TILEX * TILEY, &load, NULL);

	CloseHandle(file2);

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (_tiles[i].obj == OBJ_TREE)
		{
			_tiles[i].object = new tree;
			_tiles[i].object->init();
			_tiles[i].object->setFrameX(_tiles[i].objFrameX);
			_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y);
		}

		if (_tiles[i].obj == OBJ_BIGTREE)
		{
			_tiles[i].object = new bigTree;
			_tiles[i].object->init();
			_tiles[i].object->setFrameX(_tiles[i].objFrameX);
			_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y);
		}

		if (_tiles[i].obj == OBJ_FLAG)
		{
			_tiles[i].object = new flag;
			_tiles[i].object->init();
			_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y + 15);
		}

		if (_tiles[i].obj == OBJ_FLAG2)
		{
			_tiles[i].object = new flag2;
			_tiles[i].object->init();
			_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y + 5);
		}

		if (_tiles[i].obj == OBJ_TOWER)
		{
			_tiles[i].object = new tower;
			_tiles[i].object->init();
			_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y);
		}

		if (_tiles[i].obj == OBJ_STONETOWER)
		{
			_tiles[i].object = new stoneTower;
			_tiles[i].object->init();
			_tiles[i].object->setFrameX(_tiles[i].objFrameX);
			_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y);
		}

		if (_tiles[i].obj == OBJ_FIRE)
		{
			_tiles[i].object = new fire;
			_tiles[i].object->init();
			_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y + 10);
		}

		if (_tiles[i].obj == OBJ_TENT)
		{
			_tiles[i].object = new tent;
			_tiles[i].object->init();
			_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y - 10);
		}

	}
}

void mapTool::selectObject()
{
	if (_sampleBook->getCarrentTile().check == P_TERRAIN) return;

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (PtInRect(&_tiles[i].rc, MOUSE->getPoint()))
		{
			if (_sampleBook->getCarrentTile().check == P_TREE)
			{
				_tiles[i].obj = OBJ_TREE;
				_tiles[i].isObj = true;
				_tiles[i].object = new tree;
				_tiles[i].object->init();
				_tiles[i].objFrameX = _sampleBook->getCarrentTile().x;
				_tiles[i].object->setFrameX(_tiles[i].objFrameX);
				_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y);
				break;
			}

			if (_sampleBook->getCarrentTile().check == P_BIGTREE)
			{
				_tiles[i].obj = OBJ_BIGTREE;
				_tiles[i].isObj = true;
				_tiles[i].object = new bigTree;
				_tiles[i].object->init();
				_tiles[i].objFrameX = _sampleBook->getCarrentTile().x;
				_tiles[i].object->setFrameX(_sampleBook->getCarrentTile().x);
				_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y);
				break;
			}

			if (_sampleBook->getCarrentTile().check == P_FLAG)
			{
				_tiles[i].obj = OBJ_FLAG;
				_tiles[i].object = new flag;
				_tiles[i].object->init();
				_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y + 15);
				_tiles[i].isObj = true;
				break;
			}

			if (_sampleBook->getCarrentTile().check == P_FLAG2)
			{
				_tiles[i].obj = OBJ_FLAG2;
				_tiles[i].object = new flag2;
				_tiles[i].object->init();
				_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y + 5);
				_tiles[i].isObj = true;
				break;
			}

			if (_sampleBook->getCarrentTile().check == P_TOWER)
			{
				_tiles[i].obj = OBJ_TOWER;
				_tiles[i].object = new tower;
				_tiles[i].object->init();
				_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y);
				_tiles[i].isObj = true;
				break;
			}

			if (_sampleBook->getCarrentTile().check == P_STONETOWER)
			{
				_tiles[i].obj = OBJ_STONETOWER;
				_tiles[i].object = new stoneTower;
				_tiles[i].object->init();
				_tiles[i].objFrameX = _sampleBook->getCarrentTile().x;
				_tiles[i].object->setFrameX(_sampleBook->getCarrentTile().x);
				_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y);
				_tiles[i].isObj = true;
				break;
			}

			if (_sampleBook->getCarrentTile().check == P_FIRE)
			{
				_tiles[i].obj = OBJ_FIRE;
				_tiles[i].object = new fire;
				_tiles[i].object->init();
				_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y + 10);
				_tiles[i].isObj = true;
				break;
			}

			if (_sampleBook->getCarrentTile().check == P_TENT)
			{
				_tiles[i].obj = OBJ_TENT;
				_tiles[i].object = new tent;
				_tiles[i].object->init();
				_tiles[i].object->setFrameX(0);
				_tiles[i].object->setObject(_tiles[i].x, _tiles[i].y - 10);
				_tiles[i].isObj = true;
				break;
			}
		}
	}
}

TERRAIN mapTool::setTerrain(int frameX, int frameY)
{
	for (int i = 0; i < 3; i++)
	{
		if (frameX == i && frameY == 0) return TR_FALLING_GROUND;
	}

	for (int i = 0; i < 4; i++)
	{
		if (frameX == i && frameY == 1) return TR_GROUND;

		for (int j = 2; j < 5; j++)
		{
			if (frameX == i && frameY == j) return TR_WALL;
		}
	}

	for (int i = 4; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (frameX == i && frameY == j) return TR_WALL;
		}
	}
}
