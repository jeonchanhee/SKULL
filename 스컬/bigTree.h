#pragma once
#include "object.h"
class bigTree : public object
{
public:
	bigTree();
	~bigTree();

	HRESULT init();
	void release();
	void update();
	void render();
};

