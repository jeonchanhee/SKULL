#pragma once
#include "enemy.h"
class cherryBlossoms : public enemy
{
private:
	image* _attImg;

	int attFrameX;

public:
	cherryBlossoms();
	~cherryBlossoms();


	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void attack();
};

