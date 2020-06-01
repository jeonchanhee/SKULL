#pragma once
#include"Store.h"
#include"head.h"
class skullFox : public Store
{
private:
	head* _head;

	int randNum;
	int index;

	int _skullX, _skullY;

	bool _give;

public:
	skullFox();
	~skullFox();

	HRESULT init();
	void release();
	void update();
	void render();
		
	void giveSkull();
};

