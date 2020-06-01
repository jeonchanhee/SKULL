#include "stdafx.h"
#include "mapLoad.h"

mapLoad::mapLoad()
{
	
}

mapLoad::~mapLoad()
{
}

void mapLoad::townLoad()
{
	HANDLE	file;
	DWORD	load;

	ZeroMemory(&_tiles, sizeof(tagTile) * TILEX * TILEY);

	file = CreateFile("던전1.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &load, NULL);

	CloseHandle(file);

	setObject();

	for (int i = 0; i < 4; i++)
	{
		_back[i] = new image;
		_back[i]->init("images/던전배경.bmp", WINSIZEX * 4, 1382, 2, 2, true, RGB(255, 0, 255));

		if (i < 2)
		{
			_back[i]->setFrameY(0);
			_back[i]->setFrameX(i);
		}
		else
		{
			_back[i]->setFrameY(1);
			_back[i]->setFrameX(i - 2);
		}
	}
}

void mapLoad::dungeonLoad()
{
	HANDLE	file;
	DWORD	load;

	ZeroMemory(&_tiles, sizeof(tagTile) * TILEX * TILEY);
	file = CreateFile("던전2.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &load, NULL);

	CloseHandle(file);

	setObject();

	for (int i = 0; i < 4; i++)
	{
		_back[i] = new image;
		_back[i]->init("images/던전배경.bmp", WINSIZEX * 4, 1400, 2, 2, true, RGB(255, 0, 255));

		if (i < 2)
		{
			_back[i]->setFrameY(0);
			_back[i]->setFrameX(i);
		}
		else
		{
			_back[i]->setFrameY(1);
			_back[i]->setFrameX(i - 2);
		}
	}
}

void mapLoad::storeLoad()
{
	HANDLE	file;
	DWORD	load;

	ZeroMemory(&_tiles, sizeof(tagTile) * TILEX * TILEY);

	file = CreateFile("상점.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &load, NULL);

	CloseHandle(file);

	setObject();

	for (int i = 0; i < 4; i++)
	{
		_back[i] = new image;
		_back[i]->init("images/던전배경.bmp", WINSIZEX * 5, 1500, 2, 2, true, RGB(255, 0, 255));

		if (i < 2)
		{
			_back[i]->setFrameY(0);
			_back[i]->setFrameX(i);
		}
		else
		{
			_back[i]->setFrameY(1);
			_back[i]->setFrameX(i - 2);
		}
	}
}

void mapLoad::render()
{
	for (int i = 0; i < 4; i++)
	{
		_back[2]->frameRender(getMemDC(), 0, 0);
	}

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 50 < _tiles[i].x && CAMERAX + WINSIZEX + 50 > _tiles[i].x && CAMERAY - 50 < _tiles[i].y && CAMERAY + WINSIZEY + 50 > _tiles[i].y)
		{
			if (_tiles[i].index == 2)
			{
				IMAGEMANAGER->findImage("지형")->frameRender(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX[0], _tiles[i].terrainFrameY[0]);
				IMAGEMANAGER->findImage("지형")->frameRender(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX[1], _tiles[i].terrainFrameY[1]);
			}
			else if (_tiles[i].index == 1)
			{
				IMAGEMANAGER->findImage("지형")->frameRender(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX[0], _tiles[i].terrainFrameY[0]);
			}

			if (_tiles[i].isObj)
			{
				_tiles[i].object->render();
			}
		}
	}
}

void mapLoad::objectUpdate()
{
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 50 < _tiles[i].x && CAMERAX + WINSIZEX + 50 > _tiles[i].x && CAMERAY - 50 < _tiles[i].y && CAMERAY + WINSIZEY + 50 > _tiles[i].y)
		{
			if (_tiles[i].isObj)	_tiles[i].object->update();
		}
	}
}

void mapLoad::setObject()
{

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
