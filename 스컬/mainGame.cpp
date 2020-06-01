#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}

HRESULT mainGame::init()
{
	gameNode::init(true);
	imageInit();
	PLAYER->init();

	SCENEMANAGER->addScene("��Ʈ��", new introScene);
	SCENEMANAGER->addScene("����", new mapTool);
	SCENEMANAGER->addScene("������", new townScene);
	SCENEMANAGER->addScene("����1", new dungeon1);
	SCENEMANAGER->addScene("����", new storeScene);

	SCENEMANAGER->changeScene("����1");

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SCENEMANAGER->release();
}

void mainGame::update()
{
	gameNode::update();

	//PLAYER->update();
	SCENEMANAGER->update();
}

void mainGame::render(/*HDC hdc*/)
{
	//��� ��Ʈ��
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(getMemDC(), CAMERAMANAGER->getCameraCenter().x - WINSIZEX / 2, CAMERAMANAGER->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(CAMERAMANAGER->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=====================================================

	TIMEMANAGER->render(CAMERAMANAGER->getCameraDC());
	SCENEMANAGER->render();
	//PLAYER->render(getMemDC());
	MOUSE->render(getMemDC());

	//=====================================================
	//������� ������ HDC�� �׸���.(��������!!)
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERAMANAGER->render(this->getBackBuffer());
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERAMANAGER->getCameraCenter().x - WINSIZEX / 2, CAMERAMANAGER->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY);
}

void mainGame::imageInit()
{
	IMAGEMANAGER->addImage("UI", "images/UI/UI.bmp", 167 * 2, 68 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�⺻�Ӹ�UI", "images/UI/�⺻�Ӹ�UI.bmp", 64 * 1.7f, 64 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ӹ�UI", "images/UI/������UI.bmp", 64 * 1.7f, 64 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ӹ�2UI", "images/UI/������2UI.bmp", 64 * 2, 74 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�˺�UI", "images/UI/�˺�UI.bmp", 64 * 1.7f, 64 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ü�UI", "images/UI/�ü�UI.bmp", 64 * 1.7f, 64 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("â��UI", "images/UI/â��UI.bmp", 95 * 2, 64 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("�⺻�Ӹ�UI2", "images/UI/�⺻�Ӹ�UI2.bmp", 46 * 2, 45 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ӹ�UI2", "images/UI/������UI2.bmp", 46 * 2, 43 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ӹ�2UI2", "images/UI/������2UI2.bmp", 50 * 2, 51 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ü�UI2", "images/UI/�ü�UI2.bmp", 43 * 2, 43 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("â��UI2", "images/UI/â��UI2.bmp", 43 * 2, 43 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("�κ��丮", "images/UI/�κ��丮.bmp", 599 * 1.6f, 276 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "images/�κ���Ʈ����.bmp", 40, 55, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("�⺻�Ӹ�", "images/item/�Ӹ�/�⺻�Ӹ�.bmp", 15 * 2, 13 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ӹ�", "images/item/�Ӹ�/������Ӹ�.bmp", 15 * 2, 13 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������2�Ӹ�", "images/item/�Ӹ�/������2�Ӹ�.bmp", 15 * 2, 13 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("â���Ӹ�", "images/item/�Ӹ�/â���Ӹ�.bmp", 15 * 2, 13 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�ü��Ӹ�", "images/item/�Ӹ�/�ü��Ӹ�.bmp", 15 * 2, 13 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�˺��Ӹ�", "images/item/�Ӹ�/�˺��Ӹ�.bmp", 15 * 2, 13 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("��ġ�⺻�Ӹ�", "images/item/�Ӹ�/�⺻�Ӹ�.bmp", 15 * 2.5f, 13 * 2.5f, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ġ������Ӹ�", "images/item/�Ӹ�/������Ӹ�.bmp", 15 * 2.5f, 13 * 2.5f, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ġ������2�Ӹ�", "images/item/�Ӹ�/������2�Ӹ�.bmp", 15 * 2.5f, 13 * 2.5f, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ġâ���Ӹ�", "images/item/�Ӹ�/â���Ӹ�.bmp", 15 * 2.5f, 13 * 2.5f, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ġ�ü��Ӹ�", "images/item/�Ӹ�/�ü��Ӹ�.bmp", 15 * 2.5f, 13 * 2.5f, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��ġ�˺��Ӹ�", "images/item/�Ӹ�/�˺��Ӹ�.bmp", 15 * 2.5f, 13 * 2.5f, true, RGB(255, 0, 255));

	
	IMAGEMANAGER->addFrameImage("����", "images/MapTool/Terrain/��������.bmp", 300, 250, 6, 5, true, RGB(255, 0, 255));

	// ������Ʈ
	IMAGEMANAGER->addFrameImage("���", "images/MapTool/Obj/������Ʈ(���).bmp", 250 * 1.5f, 150 * 1.5f, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���2", "images/MapTool/Obj/������Ʈ(���2).bmp", 350 * 1.7f, 100 * 1.7f, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("����", "images/MapTool/Obj/������Ʈ(����).bmp", 1000 * 1.5f, 250 * 1.5f, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ž", "images/MapTool/Obj/������Ʈ(��ž).bmp", 300, 170, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ȭ��", "images/MapTool/Obj/������Ʈ(��).bmp", 350 * 1.5f, 100 * 1.5f, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("ū����", "images/MapTool/Obj/������Ʈ(ū����).bmp", 800, 400, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Ÿ��", "images/MapTool/Obj/������Ʈ(Ÿ��).bmp", 840 * 1.3f, 214 * 1.3f, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��Ʈ", "images/MapTool/Obj/������Ʈ(��Ʈ).bmp", 600, 100, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������", "images/MapTool/obj/����������.bmp", 1548 * 1.8f, 124 * 1.8f, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������", "images/MapTool/obj/������.bmp", 1620 * 1.8f, 133 * 1.8f, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�߰�������", "images/MapTool/obj/�߰�������.bmp", 2034, 171, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������", "images/MapTool/obj/������.bmp", 2790, 178, 9, 1, true, RGB(255, 0, 255));


	//���ú�
	IMAGEMANAGER->addFrameImage("���ú�", "images/MapTool/���ú�.bmp", 1800 * 1.5f, 300 * 1.5f, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���úϷ�Ʈ", "images/MapTool/���úϷ�Ʈ.bmp", 60, 60, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("�Ӹ��ִ¿���", "images/NPC/�Ӹ��ִ¾�.bmp", 2400 * 2, 200 * 2, 8, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("�⺻����", "images/enemy/Tree/����(�⺻).bmp", 500 * 1.9f, 800 * 1.9f, 5, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�����ִ³���", "images/enemy/Tree/�����ִ³���.bmp", 1200 * 2, 800 * 2, 6, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���ɳ���", "images/enemy/Tree/����(���).bmp", 1000 * 1.9f, 800 * 1.9f, 10, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���ó���", "images/enemy/Tree/����(����).bmp", 800 * 1.9f, 800 * 1.9f, 8, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ΰ���", "images/enemy/human/�ΰ�(�˺�).bmp", 700 * 2, 800 * 2, 7, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�ΰ��ü�", "images/enemy/human/�ΰ�(�ü�).bmp", 600, 800, 6, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ġ", "images/enemy/human/�ΰ�(��ġ).bmp", 1400, 1600, 7, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������", "imgase/enemy/human/�ΰ�(�Ҹ�����).bmp", 1200, 800, 12, 8, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("�����Ӹ�", "images/NPC/�����Ӹ�.bmp", 5200 * 1.5f, 300 * 1.5f, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("�������", "images/NPC/�������.bmp", 2500 * 1.5f, 100 * 1.5f, 5, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("����", "images/item/���/����.bmp", 28 * 2, 23 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��", "images/�����.bmp", 22 * 2, 21 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ȱ", "images/����Ȱ.bmp", 22 * 2, 21 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Ȱ2", "images/����Ȱ2.bmp", 22 * 2, 21 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�޴�", "images/�޴�.bmp", 22 * 2, 21 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("������ư", "images/MapTool/��ư/������ư.bmp", 137, 73, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������Ʈ��ư", "images/MapTool/��ư/������Ʈ��ư.bmp", 258, 90, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("���ɳ�������", "images/enemy/�汸.bmp", 8750 * 1.5f, 250 * 1.5f, 35, 1, true, RGB(255, 0, 255));
}









