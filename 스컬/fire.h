#pragma once
#include "object.h"
class fire : public object
{
public:
	fire();
	~fire();

	HRESULT init();
	void release();
	void update();
	void render();
};

