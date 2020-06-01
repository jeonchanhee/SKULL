#pragma once
#include "item.h"

class equipment : public item
{
public:
	equipment();
	~equipment();

	HRESULT init();
	void release();
	void update();
	void render();

	void create(const char* imgName, int x, int y);
	RECT* getRc() { return _imgRc; }
};

 