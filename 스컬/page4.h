#pragma once
#include"gameNode.h"
#include"tileNode.h"

class page4 : public gameNode
{
private:
	SMAPLE _sample[3];
	PAGECHECK _check;

public:
	page4();
	~page4();

	HRESULT init(int left, int top);
	void release();
	void update(int left, int top);
	void render();

	void removeRect();

	SMAPLE getSample();
	PAGECHECK getCheck() { return _check; }
};

