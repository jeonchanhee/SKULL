#include "stdafx.h"
#include "inven.h"

inven::inven()
{
}

inven::~inven()
{
}

HRESULT inven::init()
{
	_invenImg = IMAGEMANAGER->findImage("인벤토리");
	_selectImg = IMAGEMANAGER->findImage("선택");

	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2 - 50;

	_rc = new RECT;
	*_rc = RectMakeCenter(_x, _y, _invenImg->getWidth(), _invenImg->getHeight());

	for (int i = 0; i < 9; i++)
	{
		_invenRc[i] = new RECT;

		if(i < 2)*_invenRc[i] = RectMakeCenter(_rc->left + 183 + i * 67, _rc->top + 180, 40, 40);
		else if(i == 2) *_invenRc[i] = RectMakeCenter(_rc->left + 216, _rc->top + 297, 40, 40);
		else if(i > 2 && i < 6)* _invenRc[i] = RectMakeCenter((_rc->left + 148) + (i - 3) * 68, _rc->top + 413, 40, 40);
		else *_invenRc[i] = RectMakeCenter((_rc->left + 148) + (i - 6) * 68, _rc->top + 475, 40, 40);

	}
	
	num = 0;

	_selectX = (_invenRc[num]->left + (_invenRc[num]->right - _invenRc[num]->left) / 2);
	_selectY = (_invenRc[num]->top + (_invenRc[num]->bottom - _invenRc[num]->top) / 2) - 3;

	_selectRc = new RECT;
	*_selectRc = RectMakeCenter(_selectX, _selectY, _selectImg->getWidth(), _selectImg->getHeight());

	_head = new head;
	_head->init();

	_secondHead = new head;
	_secondHead->init();

	_imgX = _x;
	_imgY = _y;

	PLAYER->setPoint(PointMake(200, 650));

	return S_OK;
}

void inven::release()
{
}

void inven::update()
{
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		if (num > 0) num--;
	}

	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		if (num < 9) num++;
	}

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		if (num > 5) num -= 3;
		else if (num > 2 && num < 6) num = 2;
		else if (num == 2) num = 0;

	}

	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		if (num == 0 || num == 1) num = 2;
		else if (num == 2) num = 4;
		else if (num > 2 && num < 6) num += 3;
	}

	_selectX = _invenRc[num]->left + (_invenRc[num]->right - _invenRc[num]->left) / 2;
	_selectY = _invenRc[num]->top + (_invenRc[num]->bottom - _invenRc[num]->top) / 2;

	*_selectRc = RectMakeCenter(_selectX, _selectY, _selectImg->getWidth(), _selectImg->getHeight());

	if (num == 0)
	{
		switch (PLAYER->getSkull())
		{
		case BASICS:
			_img = IMAGEMANAGER->findImage("기본머리UI");
			break;
		case WARRIOR:
			_img = IMAGEMANAGER->findImage("워리어머리UI");
			break;
		case WARRIOR2:
			_img = IMAGEMANAGER->findImage("워리어머리2UI");
			break;
		case SWORD:
			_img = IMAGEMANAGER->findImage("검병UI");
			break;
		case ARCHER:
			_img = IMAGEMANAGER->findImage("궁수UI");
			break;
		case SPEAR:
			_img = IMAGEMANAGER->findImage("창병UI");
			break;
		}
	}
	else if (num == 1)
	{
		switch (PLAYER->getSecondSkull())
		{
		case BASICS:
			_img = IMAGEMANAGER->findImage("기본머리UI");
			break;
		case WARRIOR:
			_img = IMAGEMANAGER->findImage("워리어머리UI");
			break;
		case WARRIOR2:
			_img = IMAGEMANAGER->findImage("워리어머리2UI");
			break;
		case SWORD:
			_img = IMAGEMANAGER->findImage("검병UI");
			break;
		case ARCHER:
			_img = IMAGEMANAGER->findImage("궁수UI");
			break;
		case SPEAR:
			_img = IMAGEMANAGER->findImage("창병UI");
			break;
		}
	}

	_imgX = CAMERAX + _x;
	_imgY =  _y + 45;

	_imgRc = new RECT;
	*_imgRc = RectMakeCenter(_imgX + 130, _imgY + 20, _img->getWidth(), _img->getHeight());
}

void inven::render()
{
	if (_isOpen)
	{
		_invenImg->render(getMemDC(), _rc->left, _rc->top);
		_selectImg->render(getMemDC(), _selectRc->left, _selectRc->top);

		_head->render();
		_img->render(getMemDC(), _imgRc->left, _imgRc->top);

		if (PLAYER->getSecondSkull() != EMPTY) _secondHead->render();

		if (!_vItem.empty())
		{
			for (int i = 0; i < _vItem.size(); i++)
			{
				_vItem[i]->render(_invenRc[i + 3]->left, _invenRc[i + 3]->top);
			}
		}
	}
}

void inven::open()
{
	_rc = new RECT;
	*_rc = RectMakeCenter(CAMERAX + _x,CAMERAY + _y, _invenImg->getWidth(), _invenImg->getHeight());

	for (int i = 0; i < 9; i++)
	{
		if (i < 2)* _invenRc[i] = RectMakeCenter((_rc->left + 183 + i * 67), (_rc->top + 180), 40, 40);
		else if (i == 2)* _invenRc[i] = RectMakeCenter(_rc->left + 216, _rc->top + 297, 40, 40);
		else if (i > 2 && i < 6)* _invenRc[i] = RectMakeCenter((_rc->left + 148) + (i - 3) * 68, _rc->top + 413, 40, 40);
		else *_invenRc[i] = RectMakeCenter((_rc->left + 148) + (i - 6) * 68, _rc->top + 475, 40, 40);
	}

	sethead();
}

void inven::close()
{
}

void inven::sethead()
{
	int x, y;

	x = _invenRc[0]->left + (_invenRc[0]->right - _invenRc[0]->left) / 2;
	y = _invenRc[0]->top + (_invenRc[0]->bottom - _invenRc[0]->top) / 2;

	switch (PLAYER->getSkull())
	{
	case BASICS:
		_head->create("기본머리", x, y);
		break;
	case WARRIOR:
		_head->create("워리어머리", x, y);
		break;
	case WARRIOR2:
		_head->create("워리어2머리", x, y);
		break;
	case SWORD:
		_head->create("검병머리", x, y);
		break;
	case ARCHER:
		_head->create("궁수머리", x, y);
		break;
	case SPEAR:
		_head->create("창병머리", x, y);
		break;
	}

	int x2, y2;

	x2 = _invenRc[1]->left + (_invenRc[1]->right - _invenRc[1]->left) / 2;
	y2 = _invenRc[1]->top + (_invenRc[1]->bottom - _invenRc[1]->top) / 2;

	switch (PLAYER->getSecondSkull())
	{
	case BASICS:
		_secondHead->create("기본머리", x2, y2);
		break;
	case WARRIOR:
		_secondHead->create("워리어머리", x2, y2);
		break;
	case WARRIOR2:
		_secondHead->create("워리어2머리", x2, y2);
		break;
	case SWORD:
		_secondHead->create("검병머리", x2, y2);
		break;
	case ARCHER:
		_secondHead->create("궁수머리", x2, y2);
		break;
	case SPEAR:
		_secondHead->create("창병머리", x2, y2);
		break;
	}
}

void inven::itemPush(item* items)
{
	_vItem.push_back(items);
}
