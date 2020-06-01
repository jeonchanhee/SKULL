#include "stdafx.h"
#include "UI.h"

UI::UI()
{
}

UI::~UI()
{
}

HRESULT UI::init()
{
	_img = IMAGEMANAGER->findImage("UI");

	_x = _img->getWidth() / 2;
	_y = WINSIZEY - _img->getHeight() / 2;

	_rc = RectMakeCenter(_x, _y, _img->getWidth(), _img->getHeight());

	_headX = _img->getWidth() / 2 - 108;
	_headY = WINSIZEY - _img->getHeight() / 2 - 19;

	_headImg = IMAGEMANAGER->findImage("기본머리UI2");

	_headRc = RectMakeCenter(_headX, _headY, _headImg->getWidth(), _headImg->getHeight());

	return S_OK;
}

void UI::release()
{
}

void UI::update()
{

	switch (PLAYER->getSkull())
	{
	case BASICS:
		_headImg = IMAGEMANAGER->findImage("기본머리UI2");
		break;
	case WARRIOR:
		_headImg = IMAGEMANAGER->findImage("워리어머리UI2");
		break;
	case WARRIOR2:
		_headImg = IMAGEMANAGER->findImage("워리어머리2UI2");
		break;
	case SWORD:
		break;
	case ARCHER:
		_headImg = IMAGEMANAGER->findImage("궁수UI2");
		break;
	case SPEAR:
		_headImg = IMAGEMANAGER->findImage("창병UI2");
		break;
	}

	_headRc = RectMakeCenter(CAMERAX +  _headX, CAMERAY + _headY, _headImg->getWidth(), _headImg->getHeight());
	_rc = RectMakeCenter(CAMERAX + _x, CAMERAY + _y, _img->getWidth(), _img->getHeight());
}

void UI::render()
{
	_img->render(getMemDC(), _rc.left, _rc.top);
	_headImg->render(getMemDC(), _headRc.left, _headRc.top);
}

void UI::headUIrender()
{

}
