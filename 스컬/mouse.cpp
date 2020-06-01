#include "stdafx.h"
#include "mouse.h"

mouse::mouse(){}

mouse::~mouse(){}

HRESULT mouse::init()
{
	_mouse = IMAGEMANAGER->addImage("마우스", "images/마우스커서.bmp", 30, 30, true, RGB(255, 0, 255));

	mousePoint.x = CAMERAMANAGER->getCameraXY().x + m_ptMouse.x;
	mousePoint.y = CAMERAMANAGER->getCameraXY().y + m_ptMouse.y;

	rc = RectMake(mousePoint.x, mousePoint.y, _mouse->getWidth(), _mouse->getHeight());

	return S_OK;
}

void mouse::release()
{
}

void mouse::update()
{
	mousePoint.x = CAMERAMANAGER->getCameraXY().x + m_ptMouse.x;
	mousePoint.y = CAMERAMANAGER->getCameraXY().y + m_ptMouse.y;

	rc = RectMake(mousePoint.x, mousePoint.y, _mouse->getWidth(), _mouse->getHeight());
}

void mouse::render(HDC hdc)
{
	_mouse->render(hdc, rc.left, rc.top);
}
