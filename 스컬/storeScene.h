#pragma once
#include "gameNode.h"
#include"mapLoad.h"
#include"door.h"
#include"skullGiveNpc.h"
#include"itemNpc.h"

class storeScene :
	public gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];
	mapLoad* _load;
	door* _door;

	skullGiveNpc* _skullgive;
	itemNpc* _itemNpc;

public:
	storeScene();
	~storeScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void setNpc();
};

