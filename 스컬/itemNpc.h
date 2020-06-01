#pragma once
#include"Store.h"
#include"equipment.h"

class itemNpc : public Store
{
private:
	equipment* _equipment1;
	equipment* _equipment2;
	equipment* _equipment3;

	int randNum;
	int giveNum;
public:
	itemNpc();
	~itemNpc();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void giveSkull();
};

