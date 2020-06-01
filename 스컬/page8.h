#pragma once
#include"gameNode.h"
#include"tileNode.h"

class page8 : public gameNode
{
private:
	SMAPLE _sample[3];
	PAGECHECK _check;
public:
	page8();
	~page8();

	HRESULT init();
	void release();
	void update(int left, int top);
	void render();

	void check();

	PAGECHECK getCheck() { return _check; }
	SMAPLE getSample();
};

