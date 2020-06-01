#pragma once
#include "gameNode.h"
class door : public gameNode
{
private:
	image*	_img;
	RECT	_rc;

	int _x, _y;
	int _frameX;
	int _count;

	bool _open;

public:
	door();
	~door();

	HRESULT init(const char* fileName, int x, int y, bool open);
	void release();
	void update();
	void render();
	void frame();

	RECT getRc() { return _rc; }

	void setOpen(bool open) { _open = open; }
};

