#pragma once
#include"gameNode.h"
#include"tileNode.h"

class page3 : public gameNode
{
private:
	SMAPLE _sample[18];
	PAGECHECK _check;
	
public:
	page3();
	~page3();

	HRESULT init(int left, int top);
	void release();
	void update(int left, int top);
	void render();

	void removeRect();

	SMAPLE getSample();
	PAGECHECK getCheck() {	return _check;	}
};

