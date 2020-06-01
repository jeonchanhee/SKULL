#pragma once
#include "enemy.h"
class boss :
	public enemy
{
private:
public:
	boss();
	~boss();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void attack();
};

