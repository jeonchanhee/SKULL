#pragma once
#include "object.h"
class tree : public object
{
private:
public:
	tree();
	~tree();

	HRESULT init();
	HRESULT init(int frameX);
	void release();
	void update();
	void render();
};

