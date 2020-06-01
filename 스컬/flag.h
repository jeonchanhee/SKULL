#pragma once
#include "object.h"
class flag : public object
{
private:
public:
	flag();
	~flag();

	HRESULT init();
	void release();
	void update();
	void render();

};

