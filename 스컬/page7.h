#pragma once
#include"gameNode.h"
#include"tileNode.h"

class page7 : public gameNode
{
private:
	SMAPLE _sample[4];
	PAGECHECK _check;
public:
	page7();
	~page7();

	HRESULT init();
	void release();
	void update(int left, int top);
	void render();

	void check();

	PAGECHECK getCheck() { return _check; }
	SMAPLE getSample();
};

