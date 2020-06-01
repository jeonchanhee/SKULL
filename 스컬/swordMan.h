#pragma once
#include "enemy.h"
class swordMan : public enemy
{
private:
public:
	swordMan();
	~swordMan();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void attack();
};

