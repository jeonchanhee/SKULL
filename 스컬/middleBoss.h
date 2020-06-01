#pragma once
#include "enemy.h"
class middleBoss :	public enemy
{
private:
public:
	middleBoss();
	~middleBoss();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void attack();
};

