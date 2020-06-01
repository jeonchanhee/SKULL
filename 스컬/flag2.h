#pragma once
#include "object.h"
class flag2 : public object
{
private:
public:
	flag2();
	~flag2();

	HRESULT init();
	void release();
	void update();
	void render();
};

