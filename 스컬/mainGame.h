#pragma once
#include"gameNode.h"
#include"mapTool.h"
#include"testScene.h"
#include"introScene.h"
#include"townScene.h"
#include"dungeon1.h"
#include"storeScene.h"

class mainGame : public gameNode
{
private:

public:
	mainGame();
	~mainGame();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);

	void imageInit();

};

