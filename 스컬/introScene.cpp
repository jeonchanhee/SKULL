#include "stdafx.h"
#include "introScene.h"

introScene::introScene()
{
}

introScene::~introScene()
{
}

HRESULT introScene::init()
{
	CAMERAMANAGER->setCameraCenter(PointMake(WINSIZEX / 2, WINSIZEY / 2));

	_img = IMAGEMANAGER->addImage("배경화면", "images/배경화면.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));

	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			_button[i].img = IMAGEMANAGER->addImage("시작버튼", "images/인트로버튼/시작버튼.bmp", 150, 50, true, RGB(255, 0, 255));
			break;
		case 1:
			_button[i].img = IMAGEMANAGER->addImage("맵툴버튼", "images/인트로버튼/맵툴버튼.bmp", 150, 50, true, RGB(255, 0, 255));
			break;
		case 2:
			_button[i].img = IMAGEMANAGER->addImage("옵션버튼", "images/인트로버튼/옵션버튼.bmp", 150, 50, true, RGB(255, 0, 255));
			break;
		case 3:
			_button[i].img = IMAGEMANAGER->addImage("나가기버튼", "images/인트로버튼/나가기버튼.bmp", 150, 50, true, RGB(255, 0, 255));
			break;
		}


		_button[i].x = WINSIZEX / 2;
		_button[i].y = WINSIZEY / 2 + i * 100;

		_button[i].rc = RectMakeCenter(_button[i].x, _button[i].y, _button[i].img->getWidth(), _button[i].img->getHeight());
		_button[i].isOnMouse = false;
	}


	

	return S_OK;
}

void introScene::release(){}

void introScene::update()
{
	for (int i = 0; i < 4; i++)
	{
		if (PtInRect(&_button[i].rc, MOUSE->getPoint()))
		{
			_button[i].isOnMouse = true;
		}
		else
		{
			_button[i].isOnMouse = false;
		}

	}


	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < 4; i++)
		{
			if (PtInRect(&_button[i].rc, MOUSE->getPoint()))
			{
				switch (i)
				{
				case 0:
					SCENEMANAGER->changeScene("마을씬");
					break;
				case 1:
					SCENEMANAGER->changeScene("맵툴");
					break;
				case 2:
					SCENEMANAGER->changeScene("옵션");
					break;
				case 3:
					PostQuitMessage(0);
					break;
				}


			}
		}
	}
}

void introScene::render()
{
	_img->render(getMemDC());
	
	for (int i = 0; i < 4; i++)
	{
		if(!_button[i].isOnMouse) _button[i].img->render(getMemDC(), _button[i].rc.left, _button[i].rc.top);
		else _button[i].img->render(getMemDC(), _button[i].rc.left - 5 , _button[i].rc.top - 5, 160, 60);
	}
}
