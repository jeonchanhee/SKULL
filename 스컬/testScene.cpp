#include "stdafx.h"
#include "testScene.h"

testScene::testScene()
{
}

testScene::~testScene()
{
}

HRESULT testScene::init()
{
	IMAGEMANAGER->addFrameImage("����", "images/MapTool/Terrain/��������.bmp", 300, 250, 6, 5, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����ִ³���", "images/enemy/Tree/�����ִ³���.bmp", 1200, 800, 6, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�⺻����", "images/enemy/Tree/����(�⺻).bmp", 500 * 1.5f, 800 * 1.5f, 5, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���ɳ���", "images/enemy/Tree/����(���).bmp", 500 * 1.5f, 800 * 1.5f, 10, 8, true, RGB(255, 0, 255));

	test = new embeddedTree;
	test->init(WINSIZEX / 2, WINSIZEY / 2);

	_vEnemys.push_back(test);

	test2 = new basicTree;
	test2->init(WINSIZEX / 2 + 100, WINSIZEY / 2);

	_vEnemys.push_back(test2);

	test3 = new cherryBlossoms;
	test3->init(WINSIZEX / 2 + 200, WINSIZEY / 2);

	_vEnemys.push_back(test3);
	mapLoad();

	_h = new head;

	_h->create("������Ӹ�", WINSIZEX / 2 - 100, WINSIZEY / 2);

	return S_OK;
}

void testScene::release()
{
}

void testScene::update()
{
	PLAYER->update();

	for (int i = 0; i < _vEnemys.size(); i++)
	{
		_vEnemys[i]->update();
		_vEnemys[i]->move(_tiles);
	}
	_h->update();

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (_tiles[i].isObj)
		{
			_tiles[i].object->update();
		}
	}
}

void testScene::render()
{
	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 50 < _tiles[i].x && CAMERAX + WINSIZEX + 50 > _tiles[i].x && CAMERAY - 50 < _tiles[i].y && CAMERAY + WINSIZEY + 50 > _tiles[i].y)
		{
			if (_tiles[i].index == 2)
			{
				IMAGEMANAGER->findImage("����")->frameRender(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX[0], _tiles[i].terrainFrameY[0]);
				IMAGEMANAGER->findImage("����")->frameRender(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX[1], _tiles[i].terrainFrameY[1]);
			}
			else if (_tiles[i].index == 1)
			{
				IMAGEMANAGER->findImage("����")->frameRender(getMemDC(), _tiles[i].rc.left, _tiles[i].rc.top, _tiles[i].terrainFrameX[0], _tiles[i].terrainFrameY[0]);
			}
		}

	}

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (CAMERAX - 50 < _tiles[i].x && CAMERAX + WINSIZEX + 50 > _tiles[i].x && CAMERAY - 50 < _tiles[i].y && CAMERAY + WINSIZEY + 50 > _tiles[i].y)
		{
			if (_tiles[i].isObj) _tiles[i].object->render();
		}

	}

	for (int i = 0; i < _vEnemys.size(); i++)
	{
		_vEnemys[i]->render();
	}

	if(_h->getCreate()) _h->render();

	PLAYER->render(getMemDC());
}

void testScene::mapLoad()
{

	HANDLE	file;
	DWORD	load;

	ZeroMemory(&_tiles, sizeof(tagTile) * TILEX * TILEY);

	file = CreateFile("test.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	ReadFile(file, _tiles, sizeof(tagTile) * TILEX * TILEY, &load, NULL);

	CloseHandle(file);

	for (int i = 0; i < TILEX * TILEY; i++)
	{
		if (_tiles[i].isObj)
		{
			_tiles[i].object = new flag;
			_tiles[i].object->init();
		}
	}
}
