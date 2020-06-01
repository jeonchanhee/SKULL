#pragma once
#include "enemy.h"
class hammer :	public enemy
{
private:
public:
	hammer();
	~hammer();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void attack();
};

