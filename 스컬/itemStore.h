#pragma once
#include "Store.h"
#include "equipment.h"

class itemStore : public Store
{
private:
	vector<item> _vItem;
	vector<item>::iterator _viItem;

	int randNum;


public:
	itemStore();
	~itemStore();

	HRESULT init();
	void release();
	void update();
	void render();

	void setItem();

	vector<item> getVItem() { return _vItem; };
	vector<item>::iterator getViItem() { return _viItem; };
};

