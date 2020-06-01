#include "stdafx.h"
#include "itemManager.h"

itemManager::itemManager()
{
}

itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{
	setHead();
	setEquipment();

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
}

void itemManager::render()
{
}

void itemManager::setHead()
{
	for (int i = 0; i < 6; i++)
	{
		_head = new head;
		switch (i)
		{
		case 0:
			_head->create("워리어머리",0, 0);
			break;
		case 1:
			_head->create("워리어2머리", 0,0);
			break;
		case 2:
			_head->create("궁수머리",0,0);
			break;
		case 3:
			_head->create("검병머리", 0,0);
			break;
		case 4:
			_head->create("창병머리",0,0);
			break;
		}

		_vItem.push_back(_head);
	}


}

void itemManager::setEquipment()
{
	for (int i = 0; i < 6; i++)
	{
		_equi = new equipment;
		switch (i)
		{
		case 0:
			_equi->create("워리어머리", 0, 0);
			break;
		case 1:
			_equi->create("워리어2머리", 0, 0);
			break;
		case 2:
			_equi->create("궁수머리", 0, 0);
			break;
		case 3:
			_equi->create("검병머리", 0, 0);
			break;
		case 4:
			_equi->create("창병머리", 0, 0);
			break;
		}

		_vItem.push_back(_equi);
	}

}
