#pragma once
#include "gameNode.h"
class object :	public gameNode
{
protected:
	image*	_img;
	RECT	_rc;

	int _x, _y;
	int _frameX;
	int _count;

	bool _iscreate;
	bool _isFrame;

public:
	object();
	~object();

	HRESULT init();
	void release();
	void update();
	void render();

	void setObject(int x, int y);
	void frame();

	void setFrameX(int frameX) { _frameX = frameX; }
	image* getImg() { return _img; }
};

