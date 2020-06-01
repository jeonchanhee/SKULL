#pragma once
#include "enemy.h"
class archer : public enemy
{
private:
public:
	archer();
	~archer();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void attack();
};

