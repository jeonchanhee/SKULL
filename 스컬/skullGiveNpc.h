#pragma once
#include"Store.h"
#include"head.h"

class skullGiveNpc : public Store
{
private:
	head* _head;

	int randNum;
	bool _give;
public:
	skullGiveNpc();
	~skullGiveNpc();

	HRESULT init(int x, int y);
	void release();
	void update();
	void render();

	void give();

};

