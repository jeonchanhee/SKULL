#pragma once
#include"gameNode.h"
#include"basicTree.h"
#include"cherryBlossoms.h"
#include"embeddedTree.h"
#include"thornTree.h"
#include"archer.h"
#include"hammer.h"
#include"swordMan.h"
#include"Wizard.h"
#include"door.h"
#include"mapLoad.h"

class dungeonScene : public gameNode
{
protected:
	vector<enemy*> _vEnemey;
	vector<enemy*>::iterator _viEnemey;

	door* _door;
	mapLoad* _load;
	tagTile _tiles[TILEX * TILEY];

public:
	dungeonScene();
	~dungeonScene();

	HRESULT init();
	void release();
	void update(tagTile tiles[]);
	void render();

	void setBasicTree(int x, int y);
	void setCherryBlossoms(int x, int y);
	void setEmbeddedTree(int x, int y);
	void setThornTree(int x, int y);
	void setAcher(int x, int y);
	void setHammer(int x, int y);
	void setSwordMan(int x, int y);
	void setWizard(int x, int y);

	void hitPlayer();

	void hitMonseter();

	void remove();


};

