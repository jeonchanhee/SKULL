#pragma once
#include "object.h"
class stoneTower :	public object
{
public:
	stoneTower();
	~stoneTower();

	HRESULT init();
	void release();
	void update();
	void render();
};

