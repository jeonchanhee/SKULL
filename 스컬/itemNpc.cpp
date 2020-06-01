#include "stdafx.h"
#include "itemNpc.h"

itemNpc::itemNpc()
{
}

itemNpc::~itemNpc()
{
}

HRESULT itemNpc::init(int x, int y)
{
	_img = IMAGEMANAGER->findImage("¹«±â»óÀÎ");

	_x = x;
	_y = y;

	_imgRc = RectMakeCenter(_x, _y, _img->getFrameWidth(), _img->getFrameHeight());

	
	
	_equipment1 = new equipment;
	_equipment2 = new equipment;
	_equipment3 = new equipment;

	giveNum = 0;

	return S_OK;
}

void itemNpc::release(){}

void itemNpc::update()
{
	if(giveNum == 0) giveSkull();

	_equipment1->update();
	_equipment2->update();
	_equipment3->update();

	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		RECT temp;

		if (IntersectRect(&temp, _equipment1->getRc(), &PLAYER->getHitRc()))
		{
			PLAYER->getIven()->itemPush(_equipment1);
			_equipment1->setCreate(false);
		}

		if (IntersectRect(&temp, _equipment2->getRc(), &PLAYER->getHitRc()))
		{
			PLAYER->getIven()->itemPush(_equipment2);
			_equipment2->setCreate(false);
		}

		if (IntersectRect(&temp, _equipment3->getRc(), &PLAYER->getHitRc()))
		{
			PLAYER->getIven()->itemPush(_equipment3);
			_equipment3->setCreate(false);
		}
	}

}

void itemNpc::render()
{
	Store::render();
	_equipment1->render();
	_equipment2->render();
	_equipment3->render();
}

void itemNpc::giveSkull()
{
	for (int i = 0; i < 3; i++)
	{
		randNum = RND->getFromIntTo(0, 4);

		int temp[3];

		if (temp[i - 1] != randNum)	temp[i] = randNum;
		else continue;

		switch (randNum)
		{
		case 0:
			if(i  == 0)	_equipment1->create("°©¿Ê", _x - 230, _y - 20);
			if (i == 1)	_equipment2->create("°©¿Ê", _x - 100, _y - 20);
			if (i == 2)	_equipment3->create("°©¿Ê", _x, _y - 20);
			break;							 
		case 1:								 
			if (i == 0)	_equipment1->create("¸Þ´Þ", _x - 230, _y - 20);
			if (i == 1)	_equipment2->create("¸Þ´Þ", _x - 100, _y - 20);
			if (i == 2)	_equipment3->create("¸Þ´Þ", _x, _y - 20);
			break;							
		case 2:								
			if (i == 0)	_equipment1->create("°Ë", _x - 230, _y - 20);
			if (i == 1)	_equipment2->create("°Ë", _x - 100, _y - 20);
			if (i == 2)	_equipment3->create("°Ë", _x, _y - 20);
			break;							
		case 3:								
			if (i == 0)	_equipment1->create("È°", _x - 230, _y - 20);
			if (i == 1)	_equipment2->create("È°", _x - 100, _y - 20);
			if (i == 2)	_equipment3->create("È°", _x, _y - 20);
			break;							 
		case 4:								 
			if (i == 0)	_equipment1->create("È°2", _x - 230, _y - 20);
			if (i == 1)	_equipment2->create("È°2", _x - 100, _y - 20);
			if (i == 2)	_equipment3->create("È°2", _x, _y - 20);
			break;
		}
	}
	giveNum++;
}
