#pragma once
#include"enemy.h"

class embeddedTree : public enemy
{
private:
public:
	embeddedTree();
	~embeddedTree();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void attack();
};

