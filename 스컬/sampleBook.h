#pragma once
#include"gameNode.h"
#include"tileNode.h"

#include"page2.h"
#include"page3.h"
#include"page4.h"
#include"page5.h"
#include"page6.h"
#include"page7.h"
#include"page8.h"

class sampleBook : public gameNode
{
private:
	BOOK _sampleBook;
	carrentTile _carrentTile;

	SELECT _select;
	BUTTON _button[3];

	int page;

	bool _open;

	image* test;
private:
	page2* _page2;
	page3* _page3;
	page4* _page4;
	page5* _page5;
	page6* _page6;
	page7* _page7;
	page8* _page8;


public:
	sampleBook();
	~sampleBook();

	HRESULT init();
	void relaese();
	void update();
	void render();

	// ¼³Á¤
	void setButton();

	// ¼ÀÇÃºÏ ÄÁÆ®·Ñ
	void bookControl();
	void keyControl();
	void pageControl();

	// ¼ÀÇÃºÏ ¼³Á¤
	void onSampleBook();
	void offSampleBook();

	void setCarrentTile();

	bool getOpen() { return _open; }
	void setOpen(bool open) { _open = open; }

	carrentTile getCarrentTile() { return _carrentTile; }

	int getPage() { return page; }

	image* getTest() { return test; }

	RECT getImgRc() { return _sampleBook.imgRc; }
	RECT* getChecRc() { return _sampleBook.checkRc; }

	int getX() { return _sampleBook.x; }
	int getY() { return _sampleBook.y; }

	void setXY(POINT XY)
	{
		_sampleBook.x = XY.x;
		_sampleBook.y = XY.y;
	}
};

