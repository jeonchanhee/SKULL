#pragma once
#include "gameNode.h"
#include"skullFox.h"
#include"mapLoad.h"
#include"door.h"

class townScene : public gameNode
{
private:
	skullFox* _skullFox;
	tagTile _tiles[TILEX * TILEY];
	mapLoad* _load;
	door* _door;

public:
	townScene();
	~townScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void setNpc();
};

