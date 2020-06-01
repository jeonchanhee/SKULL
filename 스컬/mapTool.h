#pragma once
#include"gameNode.h"
#include"tileNode.h"
#include"sampleBook.h"
#include"flag.h"
#include"tree.h"
#include"bigTree.h"
#include"flag2.h"
#include"stoneTower.h"
#include"tower.h"
#include"fire.h"
#include"tent.h"

class mapTool : public gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];

	sampleBook* _sampleBook;

	POINT start, end;

public:
	mapTool();
	~mapTool();

	HRESULT init();
	void release();
	void update();
	void render();

	void cameraMove();
	void setTiles();
	void setMap();
	void drag();
	void save();
	void load();
	void selectObject();

	void mapToolImages();

	TERRAIN setTerrain(int frameX, int frameY);

	
};

