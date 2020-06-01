#pragma once

#include "gameNode.h"
#include"tree.h"
#include"bigTree.h"
#include"tower.h"
#include"flag.h"
#include"flag2.h"
#include"stoneTower.h"
#include"fire.h"
#include"tent.h"


class mapLoad :	public gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];

	image* _back[4];

public:
	mapLoad();
	~mapLoad();

	void townLoad();
	void dungeonLoad();
	void storeLoad();
	void render();
	void objectUpdate();
	

	void setObject();
	tagTile getTiles(int i) { return _tiles[i]; }
};

