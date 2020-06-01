#pragma once
#include"gameNode.h"


class item : public gameNode
{
protected:
	image* _img;
	RECT* _imgRc;

	int _x, _y;
	int price;

	bool _isCreate;

public:
	item();
	~item();

	HRESULT init();
	void release();
	void update();
	void render();

	void render(int left, int top);

	void setCreate(bool create) { _isCreate = create; }
	void setXY(POINT XY)
	{
		_x = XY.x;
		_y = XY.y;
	}

	RECT* getRc() { return _imgRc; }
};

