#pragma once
#include"gameNode.h"
#include"head.h"
#include"item.h"

class inven : public gameNode
{
private:
	vector<item*> _vItem;

	image* _invenImg;
	image* _selectImg;
	image* _img;

	RECT* _rc;
	RECT* _invenRc[9];
	RECT* _selectRc;
	RECT* _imgRc;

	int _x, _y;
	int _selectX, _selectY;
	int _imgX, _imgY;
	int num;

	bool _isOpen;

	head* _head;
	head* _secondHead;

public:
	inven();
	~inven();

	HRESULT init();
	void release();
	void update();
	void render();

	void open();
	void close();
	void sethead();

	bool getOpen() { return _isOpen; }
	void setOpne(bool open) { _isOpen = open; }

	void itemPush(item* items);

	vector<item*> getItem() { return _vItem; }
};

