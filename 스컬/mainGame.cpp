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

	SCENEMANAGER->addScene("인트로", new introScene);
	SCENEMANAGER->addScene("맵툴", new mapTool);
	SCENEMANAGER->addScene("마을씬", new townScene);
	SCENEMANAGER->addScene("던전1", new dungeon1);
	SCENEMANAGER->addScene("상점", new storeScene);

	SCENEMANAGER->changeScene("던전1");

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
	//흰색 비트맵
	//PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(getMemDC(), CAMERAMANAGER->getCameraCenter().x - WINSIZEX / 2, CAMERAMANAGER->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY, WHITENESS);
	PatBlt(CAMERAMANAGER->getCameraDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=====================================================

	TIMEMANAGER->render(CAMERAMANAGER->getCameraDC());
	SCENEMANAGER->render();
	//PLAYER->render(getMemDC());
	MOUSE->render(getMemDC());

	//=====================================================
	//백버퍼의 내용을 HDC에 그린다.(지우지마!!)
	//this->getBackBuffer()->render(getHDC(), 0, 0);
	CAMERAMANAGER->render(this->getBackBuffer());
	this->getBackBuffer()->render(getHDC(), 0, 0, CAMERAMANAGER->getCameraCenter().x - WINSIZEX / 2, CAMERAMANAGER->getCameraCenter().y - WINSIZEY / 2, WINSIZEX, WINSIZEY);
}

void mainGame::imageInit()
{
	IMAGEMANAGER->addImage("UI", "images/UI/UI.bmp", 167 * 2, 68 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("기본머리UI", "images/UI/기본머리UI.bmp", 64 * 1.7f, 64 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("워리어머리UI", "images/UI/워리어UI.bmp", 64 * 1.7f, 64 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("워리어머리2UI", "images/UI/워리어2UI.bmp", 64 * 2, 74 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("검병UI", "images/UI/검병UI.bmp", 64 * 1.7f, 64 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("궁수UI", "images/UI/궁수UI.bmp", 64 * 1.7f, 64 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("창병UI", "images/UI/창병UI.bmp", 95 * 2, 64 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("기본머리UI2", "images/UI/기본머리UI2.bmp", 46 * 2, 45 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("워리어머리UI2", "images/UI/워리어UI2.bmp", 46 * 2, 43 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("워리어머리2UI2", "images/UI/워리어2UI2.bmp", 50 * 2, 51 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("궁수UI2", "images/UI/궁수UI2.bmp", 43 * 2, 43 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("창병UI2", "images/UI/창병UI2.bmp", 43 * 2, 43 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("인벤토리", "images/UI/인벤토리.bmp", 599 * 1.6f, 276 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("선택", "images/인벤렉트선택.bmp", 40, 55, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("기본머리", "images/item/머리/기본머리.bmp", 15 * 2, 13 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("워리어머리", "images/item/머리/워리어머리.bmp", 15 * 2, 13 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("워리어2머리", "images/item/머리/워리어2머리.bmp", 15 * 2, 13 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("창병머리", "images/item/머리/창병머리.bmp", 15 * 2, 13 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("궁수머리", "images/item/머리/궁수머리.bmp", 15 * 2, 13 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("검병머리", "images/item/머리/검병머리.bmp", 15 * 2, 13 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("배치기본머리", "images/item/머리/기본머리.bmp", 15 * 2.5f, 13 * 2.5f, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배치워리어머리", "images/item/머리/워리어머리.bmp", 15 * 2.5f, 13 * 2.5f, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배치워리어2머리", "images/item/머리/워리어2머리.bmp", 15 * 2.5f, 13 * 2.5f, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배치창병머리", "images/item/머리/창병머리.bmp", 15 * 2.5f, 13 * 2.5f, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배치궁수머리", "images/item/머리/궁수머리.bmp", 15 * 2.5f, 13 * 2.5f, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("배치검병머리", "images/item/머리/검병머리.bmp", 15 * 2.5f, 13 * 2.5f, true, RGB(255, 0, 255));

	
	IMAGEMANAGER->addFrameImage("지형", "images/MapTool/Terrain/맵툴지형.bmp", 300, 250, 6, 5, true, RGB(255, 0, 255));

	// 오브젝트
	IMAGEMANAGER->addFrameImage("깃발", "images/MapTool/Obj/오브젝트(깃발).bmp", 250 * 1.5f, 150 * 1.5f, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("깃발2", "images/MapTool/Obj/오브젝트(깃발2).bmp", 350 * 1.7f, 100 * 1.7f, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("나무", "images/MapTool/Obj/오브젝트(나무).bmp", 1000 * 1.5f, 250 * 1.5f, 5, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("돌탑", "images/MapTool/Obj/오브젝트(돌탑).bmp", 300, 170, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("화로", "images/MapTool/Obj/오브젝트(불).bmp", 350 * 1.5f, 100 * 1.5f, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("큰나무", "images/MapTool/Obj/오브젝트(큰나무).bmp", 800, 400, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("타워", "images/MapTool/Obj/오브젝트(타워).bmp", 840 * 1.3f, 214 * 1.3f, 7, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("텐트", "images/MapTool/Obj/오브젝트(텐트).bmp", 600, 100, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("던전문", "images/MapTool/obj/다음던전문.bmp", 1548 * 1.8f, 124 * 1.8f, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("상점문", "images/MapTool/obj/상점문.bmp", 1620 * 1.8f, 133 * 1.8f, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("중간보스문", "images/MapTool/obj/중간보스문.bmp", 2034, 171, 9, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("보스문", "images/MapTool/obj/보스문.bmp", 2790, 178, 9, 1, true, RGB(255, 0, 255));


	//셈플북
	IMAGEMANAGER->addFrameImage("셈플북", "images/MapTool/셈플북.bmp", 1800 * 1.5f, 300 * 1.5f, 3, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("셈플북렉트", "images/MapTool/셈플북렉트.bmp", 60, 60, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("머리주는여우", "images/NPC/머리주는애.bmp", 2400 * 2, 200 * 2, 8, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("기본나무", "images/enemy/Tree/나무(기본).bmp", 500 * 1.9f, 800 * 1.9f, 5, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("박혀있는나무", "images/enemy/Tree/박혀있는나무.bmp", 1200 * 2, 800 * 2, 6, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("벚꽃나무", "images/enemy/Tree/나무(방귀).bmp", 1000 * 1.9f, 800 * 1.9f, 10, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("가시나무", "images/enemy/Tree/나무(가시).bmp", 800 * 1.9f, 800 * 1.9f, 8, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("인간검", "images/enemy/human/인간(검병).bmp", 700 * 2, 800 * 2, 7, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("인간궁수", "images/enemy/human/인간(궁수).bmp", 600, 800, 6, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("망치", "images/enemy/human/인간(망치).bmp", 1400, 1600, 7, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("마법사", "imgase/enemy/human/인간(불마법사).bmp", 1200, 800, 12, 8, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("상점머리", "images/NPC/상점머리.bmp", 5200 * 1.5f, 300 * 1.5f, 13, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("무기상인", "images/NPC/무기상인.bmp", 2500 * 1.5f, 100 * 1.5f, 5, 1, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("갑옷", "images/item/장비/갑옷.bmp", 28 * 2, 23 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("검", "images/무기검.bmp", 22 * 2, 21 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("활", "images/무기활.bmp", 22 * 2, 21 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("활2", "images/무기활2.bmp", 22 * 2, 21 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("메달", "images/메달.bmp", 22 * 2, 21 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("지형버튼", "images/MapTool/버튼/지형버튼.bmp", 137, 73, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("오브젝트버튼", "images/MapTool/버튼/오브젝트버튼.bmp", 258, 90, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage("벚꽃나무공격", "images/enemy/방구.bmp", 8750 * 1.5f, 250 * 1.5f, 35, 1, true, RGB(255, 0, 255));
}









