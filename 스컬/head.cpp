#include "stdafx.h"
#include "head.h"

head::head()
{
}

head::~head()
{
}

HRESULT head::init()
{
	return S_OK;
}

void head::release()
{
	delete _imgRc;
	SAFE_DELETE(_img);
}

void head::update()
{
	RECT temp;
	if(IntersectRect(&temp, _imgRc, &PLAYER->getRc()))
	{
		if (KEYMANAGER->isOnceKeyDown('E'))
		{
			PLAYER->setChange(true);

			if (_imgName == "��ġ�⺻�Ӹ�")
			{
				change();
				if (PLAYER->getSecondSkull() == EMPTY)
				{
					PLAYER->setSecondSkull(PLAYER->getSkull());
					remove();
				}
				PLAYER->setSkull(BASICS);
				return;
			}

			if (_imgName == "��ġ������Ӹ�")
			{
				change();
				if (PLAYER->getSecondSkull() == EMPTY)
				{
					PLAYER->setSecondSkull(PLAYER->getSkull());
					remove();
				}
				PLAYER->setSkull(WARRIOR);
				return;
			}

			if (_imgName == "��ġ������2�Ӹ�")
			{
				change();
				if (PLAYER->getSecondSkull() == EMPTY)
				{
					PLAYER->setSecondSkull(PLAYER->getSkull());
					remove();
				}
				PLAYER->setSkull(WARRIOR2);
				return;
			}

			if (_imgName == "��ġ�˺��Ӹ�")
			{
				change();
				if (PLAYER->getSecondSkull() == EMPTY)
				{
					PLAYER->setSecondSkull(PLAYER->getSkull());
					remove();
				}
				PLAYER->setSkull(SWORD);
				return;
			}

			if (_imgName == "��ġ�ü��Ӹ�")
			{
				change();
				if (PLAYER->getSecondSkull() == EMPTY)
				{
					PLAYER->setSecondSkull(PLAYER->getSkull());
					remove();
				}
				PLAYER->setSkull(ARCHER);
				return;
			}

			if (_imgName == "��ġâ���Ӹ�")
			{
				change();
				if (PLAYER->getSecondSkull() == EMPTY)
				{
					PLAYER->setSecondSkull(PLAYER->getSkull());
					remove();
				}
				PLAYER->setSkull(SPEAR);
				return;
			}
		}
	}
}

void head::render()
{
	if(_isCreate) _img->render(getMemDC(), _imgRc->left, _imgRc->top);
}

void head::create(const char* imgName, int x, int y)
{
	_imgName = imgName;
	_img = IMAGEMANAGER->findImage(_imgName);

	_x = x;
	_y = y;

	_imgRc = new RECT;
	*_imgRc = RectMakeCenter(_x, _y, _img->getWidth(), _img->getHeight());

	_isCreate = true;
}

void head::change()
{
	switch (PLAYER->getSkull())
	{
	case BASICS:
		_imgName = "��ġ�⺻�Ӹ�";
		break;
	case WARRIOR:
		_imgName = "��ġ������Ӹ�";
		break;
	case WARRIOR2:
		_imgName = "��ġ������Ӹ�2";
		break;
	case SWORD:
		_imgName = "��ġ�˺��Ӹ�";
		break;
	case ARCHER:
		_imgName = "��ġ�ü��Ӹ�";
		break;
	case SPEAR:
		_imgName = "��ġâ���Ӹ�";
		break;
	}

	_img = IMAGEMANAGER->findImage(_imgName);
}

void head::remove()
{
	_isCreate = false;
	
}