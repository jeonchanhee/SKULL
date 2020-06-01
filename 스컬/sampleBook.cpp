#include "stdafx.h"
#include "sampleBook.h"

sampleBook::sampleBook(){}

sampleBook::~sampleBook(){}

HRESULT sampleBook::init()
{
	// ¼ÀÇÃºÏ ¼³Á¤
	_sampleBook.img = IMAGEMANAGER->findImage("¼ÀÇÃºÏ");
	_sampleBook.x = WINSIZEX - 50;
	_sampleBook.y = WINSIZEY / 2;

	_sampleBook.imgRc = RectMakeCenter(_sampleBook.x, _sampleBook.y, _sampleBook.img->getFrameWidth(), _sampleBook.img->getFrameHeight());

	//_sampleBook.checkRc = new RECT;
	//*_sampleBook.checkRc = RectMakeCenter(_sampleBook.x, _sampleBook.y, 100, _sampleBook.img->getFrameHeight());

	page = 0;

	_open = false;

	_page2 = new page2;
	_page2->init(_sampleBook.imgRc.left, _sampleBook.imgRc.top);

	_page3 = new page3;
	_page3->init(_sampleBook.imgRc.left, _sampleBook.imgRc.top);

	_page4 = new page4;
	_page4->init(_sampleBook.imgRc.left, _sampleBook.imgRc.top);

	_page5 = new page5;
	_page5->init();

	_page6 = new page6;
	_page6->init();

	_page7 = new page7;
	_page7->init();

	_page8 = new page8;
	_page8->init();

	return S_OK;
}

void sampleBook::relaese(){}

void sampleBook::update()
{
	bookControl();
	setButton();

	switch (page)
	{
	case 2:
		_page2->update(_sampleBook.imgRc.left, _sampleBook.imgRc.top);
		break;
	case 3:
		_page3->update(_sampleBook.imgRc.left, _sampleBook.imgRc.top);
		break;
	case 4:
		_page4->update(_sampleBook.imgRc.left, _sampleBook.imgRc.top);
		break;
	case 5:
		_page5->update(_sampleBook.imgRc.left, _sampleBook.imgRc.top);
		break;
	case 6:
		_page6->update(_sampleBook.imgRc.left, _sampleBook.imgRc.top);
		break;
	case 7:
		_page7->update(_sampleBook.imgRc.left, _sampleBook.imgRc.top);
		break;
	case 8:
		_page8->update(_sampleBook.imgRc.left, _sampleBook.imgRc.top);
		break;
	}
}

void sampleBook::render()
{
	if (page == 0) _sampleBook.img->frameRender(getMemDC(), _sampleBook.imgRc.left, _sampleBook.imgRc.top);
	else if (page == 1) _sampleBook.img->frameRender(getMemDC(), _sampleBook.imgRc.left, _sampleBook.imgRc.top, _sampleBook.img->getFrameX(), _sampleBook.img->getFrameY(), 1200, 600);
	else _sampleBook.img->frameRender(getMemDC(), _sampleBook.imgRc.left, _sampleBook.imgRc.top, _sampleBook.img->getFrameX(), _sampleBook.img->getFrameY(), _sampleBook.img->getFrameWidth(), 600);

	switch (page)
	{
	case 2:
		_page2->render();
		break;
	case 3:
		_page3->render();
		break;
	case 4:
		_page4->render();
		break;
	case 5:
		_page5->render();
		break;
	case 6:
		_page6->render();
		break;
	case 7:
		_page7->render();
		break;
	case 8:
		_page8->render();
		break;
	}

}



void sampleBook::setButton()
{
	if (page == 0) return;

	for (int i = 0; i < 3; i++)
	{
		_button[i].rc = new RECT;

		if (page == 1)
		{
			*_button[i].rc = RectMakeCenter(_sampleBook.imgRc.right - 300, (_sampleBook.imgRc.top + 140) + i * 129, 150, 40);
		}

		if (page > 1 && page < 7)
		{
			*_button[i].rc = RectMakeCenter((_sampleBook.imgRc.left + 220) + i * 230, (_sampleBook.imgRc.bottom - 75), 145, 60);
		}
	}
}



void sampleBook::bookControl()
{
	keyControl();
	pageControl();


	_sampleBook.imgRc = RectMakeCenter(CAMERAMANAGER->getCameraXY().x + _sampleBook.x, CAMERAMANAGER->getCameraXY().y + _sampleBook.y, _sampleBook.img->getFrameWidth(), _sampleBook.img->getFrameHeight());
}

void sampleBook::keyControl()
{
	/*if (!_open)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{

			if (PtInRect(_sampleBook.checkRc, MOUSE->getPoint()))
			{
				onSampleBook();
			}

		}
	}*/

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		if (!_open) onSampleBook();
		else offSampleBook();
	}

	if (KEYMANAGER->isStayKeyDown('A') && KEYMANAGER->isStayKeyDown(VK_SHIFT))
	{
		_sampleBook.x -= 5;
		
	}

	if (KEYMANAGER->isStayKeyDown('D') && KEYMANAGER->isStayKeyDown(VK_SHIFT))
	{
		_sampleBook.x += 5;
	}

	if (KEYMANAGER->isStayKeyDown('W') && KEYMANAGER->isStayKeyDown(VK_SHIFT))
	{
		_sampleBook.y -= 5;
	}

	if (KEYMANAGER->isStayKeyDown('S') && KEYMANAGER->isStayKeyDown(VK_SHIFT))
	{
		_sampleBook.y += 5;
	}

	if (_open)
	{
		if (KEYMANAGER->isOnceKeyDown('Q'))
		{
			page--;
			if (page == 0) page = 1;
		}

		if (KEYMANAGER->isOnceKeyDown('E'))
		{
			page++;

			if (page > 1)
			{
				_sampleBook.x =   WINSIZEX / 2;
				_sampleBook.y =  WINSIZEY / 2;
			}
		}
	}
}

void sampleBook::pageControl()
{
	if(page == 0 ) _sampleBook.img->setFrameX(0);
	else if(page == 1) _sampleBook.img->setFrameX(1);
	else _sampleBook.img->setFrameX(2);
}

void sampleBook::onSampleBook()
{
	_open = true;

	page = 1;

	_sampleBook.x =  WINSIZEX / 2 - 100;
	_sampleBook.y =  WINSIZEY / 2 - 100;

	setButton();


	delete _sampleBook.checkRc;
}

void sampleBook::offSampleBook()
{
	_open = false;

	page = 0;

	_sampleBook.x = WINSIZEX - 50;
	_sampleBook.y = WINSIZEY / 2;

	_sampleBook.checkRc = new RECT;
	*_sampleBook.checkRc = RectMakeCenter(CAMERAX + _sampleBook.x,CAMERAY + _sampleBook.y, 100, _sampleBook.img->getFrameHeight());

	//for (int i = 0; i < 3; i++)
	//{
	//	delete _button[i].rc;
	//}
}

void sampleBook::setCarrentTile()
{
	switch (page)
	{
	case 2:
		_carrentTile.x = _page2->getSample().img->getFrameX();
		_carrentTile.y = _page2->getSample().img->getFrameY();
		_carrentTile.check = _page2->getCheck();
		break;
	case 3:
		_carrentTile.x = _page3->getSample().img->getFrameX();
		_carrentTile.y = _page3->getSample().img->getFrameY();
		_carrentTile.check = _page3->getCheck();
		break;
	case 4:
		_carrentTile.x = _page4->getSample().img->getFrameX();
		_carrentTile.y = _page4->getSample().img->getFrameY();
		_carrentTile.check = _page4->getCheck();

		break;
	case 5:
		_carrentTile.x = _page5->getSample().img->getFrameX();
		_carrentTile.y = _page5->getSample().img->getFrameY();
		_carrentTile.check = _page5->getCheck();

		break;
	case 6:
		_carrentTile.x = _page6->getSample().img->getFrameX();
		_carrentTile.y = _page6->getSample().img->getFrameY();
		_carrentTile.check = _page6->getCheck();
		break;
	case 7:
		_carrentTile.x = _page7->getSample().img->getFrameX();
		_carrentTile.y = _page7->getSample().img->getFrameY();
		_carrentTile.check = _page7->getCheck();
		break;
	case 8:
		_carrentTile.x = _page8->getSample().img->getFrameX();
		_carrentTile.y = _page8->getSample().img->getFrameY();
		_carrentTile.check = _page8->getCheck();
		
		break;
	}
}