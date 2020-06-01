#pragma once
#include"object.h"

//Ÿ�ϰ���(50, 50)
#define TILEX 100
#define TILEY 100

//Ÿ�� ������
#define TILESIZE 50

// Ÿ�� �� ������
#define TILESIZEX TILESIZE * TILEX
#define TILESIZEY TILESIZE * TILEY

enum SELECT
{
	TRRAINDRAW,
	OBJDRAW,
	ERASER
};

enum TERRAIN
{
	//������,	��	,	��	,	���������ִ¶�
	TR_NULL, TR_WALL, TR_GROUND, TR_FALLING_GROUND
};

enum OBJECTS
{
	OBJ_NULL, OBJ_TREE, OBJ_BIGTREE, OBJ_FLAG, OBJ_FLAG2, OBJ_TOWER, OBJ_STONETOWER, OBJ_FIRE, OBJ_TENT
};

enum PAGECHECK
{
	P_TERRAIN, P_TREE, P_BIGTREE, P_FLAG, P_FLAG2, P_TOWER, P_STONETOWER, P_FIRE, P_TENT
};

struct tagTile
{
	TERRAIN terrain[2];
	OBJECTS obj;
	RECT rc;
	object* object;
	int terrainFrameX[2];
	int terrainFrameY[2];
	int objFrameX;
	int objFrameY;
	int x, y;
	int index;
	bool isOnMouse;
	bool isObj = false;
};

struct tagSampleTIle
{
	RECT rcTile;
	int frameX;
	int frameY;
};

struct carrentTile
{
	int x;
	int y;
	PAGECHECK check;
};


struct SMAPLE
{
	image* img;
	image* Rectimg;
	RECT* rc;
	int x, y;
};

struct BOOK
{
	image* img;
	RECT imgRc;
	RECT* checkRc;
	int x, y;
};

struct BUTTON
{
	image* img;
	RECT* rc;
	int x, y;
};