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

	_button[0].img = IMAGEMANAGER->findImage("던전1버튼");
	_button[1].img = IMAGEMANAGER->findImage("던전2버튼");
	_button[2].img = IMAGEMANAGER->findImage("던전3버튼");
	_button[3].img = IMAGEMANAGER->findImage("던전4버튼");
	_button[4].img = IMAGEMANAGER->findImage("던전5버튼");

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
					fileName = "던전1";
				}
				else if (i == 1)
				{
					fileName = "던전2";
				}
				else if (i == 2)
				{
					fileName = "던전3";
				}
				else if (i == 3)
				{
					fileName = "던전4";
				}
				else if (i == 4)
				{
					fileName = "던전5";
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
