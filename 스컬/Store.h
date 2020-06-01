#pragma once
#include"gameNode.h"

class Store : public gameNode
{
protected:
	image*	_img;
	RECT	_imgRc;
	RECT	_collRect;

	int _x, _y;
	int _frameX;
	int _count;
	bool _isOpen;

public:
	Store();
	~Store();

	HRESULT init();
	void release();
	void update();
	void render();

	void open();
	void frame();

	void setXY(int x, int y) { _x = x; _y = y; }
};

class store :
	public gameNode
{
};

