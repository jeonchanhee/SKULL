#pragma once
#include "enemy.h"
class Wizard :	public enemy
{
private:
public:
	Wizard();
	~Wizard();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void attack();
};

