#pragma once
#include "object.h"
class tent : public object
{
public:
	tent();
	~tent();

	HRESULT init();
	void release();
	void update();
	void render();
};

