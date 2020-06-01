#pragma once
#include"item.h"
class head :public item
{
private:
	const char* _imgName;
public:
	head();
	~head();

	HRESULT init();
	void release();
	void update();
	void render();

	void create(const char* imgName, int x, int y);

	void change();

	void remove();

	bool getCreate() { return _isCreate; }
};

