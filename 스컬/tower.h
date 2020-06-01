#pragma once
#include "object.h"
class tower : public object
{
public:
	tower();
	~tower();

	HRESULT init();
	void release();
	void update();
	void render();
};

