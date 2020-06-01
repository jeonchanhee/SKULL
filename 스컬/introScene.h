#pragma once
#include "gameNode.h"


struct INTROBUTTON
{
	image* img;
	RECT rc;
	int x, y;
	bool isOnMouse;

};


class introScene :	public gameNode
{
private:
	image* _img;
	INTROBUTTON _button[4];


public:
	introScene();
	~introScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

