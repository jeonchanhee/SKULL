#pragma once
#include "enemy.h"
class basicTree : public enemy
{
private:

public:
	basicTree();
	~basicTree();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void attack();

	//void frame(int frameY, int maxFrameX);


};

