#pragma once
#include"gameNode.h"
#include"embeddedTree.h"
#include"basicTree.h"
#include"cherryBlossoms.h"
#include"head.h"
#include"flag.h"

class testScene : public gameNode
{
private:
	tagTile _tiles[TILEX * TILEY];

	embeddedTree* test;
	basicTree* test2;
	cherryBlossoms* test3;

	vector<enemy*> _vEnemys;
	vector<enemy*>::iterator _viEnemys;

	head* _h;

public:
	testScene();
	~testScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void mapLoad();
};

