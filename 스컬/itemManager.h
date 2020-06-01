#pragma once
#include"gameNode.h"
#include"item.h"
#include"head.h"
#include"equipment.h"

class itemManager : public gameNode
{
private:
	vector<item*> _vItem;
	vector<item*>::iterator _viItem;

	head* _head;
	equipment* _equi;

public:
	itemManager();
	~itemManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void setHead();				//�Ӹ� ����
	void setEquipment();		//��� ����
};

