#include "stdafx.h"
#include "savePage.h"

savePage::savePage()
{
}

savePage::~savePage()
{
}

HRESULT savePage::init(int left, int top)
{
	for (int i = 0; i < 5; i++)
	{
		_button[i].rc = new RECT;
		
		if (i < 2)
		{
			_button[i].x = (left + 50) + i * 100;
			_button[i].y = (top + 100);
		}
		else if (i > 1 && i < 4)
		{
			_button[i].x = (left + 50) + i * 100;
			_button[i].y = (top + 200);
		}
		else
		{
			_button[i].x = (left + 50) + i * 100;
			_button[i].y = (top + 300);
		}

		*_button[i].rc = RectMakeCenter(_button[i].x, _button[i].y, 150, 100);
	}

	_button[0].img = IMAGEMANAGER->findImage("����1��ư");
	_button[1].img = IMAGEMANAGER->findImage("����2��ư");
	_button[2].img = IMAGEMANAGER->findImage("����3��ư");
	_button[3].img = IMAGEMANAGER->findImage("����4��ư");
	_button[4].img = IMAGEMANAGER->findImage("����5��ư");

	return S_OK;
}

void savePage::release()
{
}

void savePage::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < 5; i++)
		{
			if (PtInRect(_button[i].rc, MOUSE->getPoint()))
			{
				if (i == 0)
				{
					fileName = "����1";
				}
				else if (i == 1)
				{
					fileName = "����2";
				}
				else if (i == 2)
				{
					fileName = "����3";
				}
				else if (i == 3)
				{
					fileName = "����4";
				}
				else if (i == 4)
				{
					fileName = "����5";
				}
				break;
			}
		}
	}
}

void savePage::render()
{
	for (int i = 0; i < 5; i++)
	{
		_button[i].img->render(getMemDC(), _button[i].rc->left, _button[i].rc->top);
	}
}
