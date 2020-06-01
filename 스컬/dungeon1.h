#pragma once
#include "dungeonScene.h"
class dungeon1 : public dungeonScene
{
private:
public:
	dungeon1();
	~dungeon1();

	HRESULT init();
	void release();
	void update();
	void render();

	void setMonster();
};

