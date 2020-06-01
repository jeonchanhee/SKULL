#pragma once
#include "gameNode.h"


class UI :	public gameNode
{
private:
	image* _img;
	image* _headImg;

	RECT	_rc;
	RECT	_headRc;

	int _x, _y;
	int _headX, _headY;

public:
	UI();
	~UI();

	HRESULT init();
	void release();
	void update();
	void render();

	void headUIrender();
};

