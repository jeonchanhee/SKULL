#pragma once
#include"gameNode.h"
#include"tileNode.h"

class page5 : public gameNode
{
private:
	SMAPLE _sample[2];
	PAGECHECK _check;

public:
	page5();
	~page5();

	HRESULT init();
	void release();
	void update(int left, int top);
	void render();

	SMAPLE getSample();
	PAGECHECK getCheck() { return _check; }
};

