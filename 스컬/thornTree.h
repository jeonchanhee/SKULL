#pragma once
#include"enemy.h"
class thornTree : public enemy
{
private:

public:
	thornTree();
	~thornTree();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void attack();
};

