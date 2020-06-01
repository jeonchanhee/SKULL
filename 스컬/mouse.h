#pragma once
#include"singletonBase.h"

class mouse : public singletonBase<mouse>
{
private:
	image* _mouse;
	RECT   rc;
	int x, y;

	POINT mousePoint;

public:
	mouse();
	~mouse();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	POINT getPoint() { return mousePoint; }
	RECT getRc() { return rc; }
};

