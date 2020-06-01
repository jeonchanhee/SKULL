#pragma once
#include"gameNode.h"
#include"tileNode.h"

class savePage : public gameNode
{
private:
	BUTTON _button[5];

	const char* fileName;
public:
	savePage();
	~savePage();

	HRESULT init(int left, int top);
	void release();
	void update();
	void render();

	const char* getFileName() { return fileName; }
};

