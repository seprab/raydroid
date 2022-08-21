#pragma once
#include "entity.h"
class item :
    public entity
{
	public:
	item(int x, int y, int w, int h, int id, int type, int value);
	~item();
	void update();
	void draw();

	
};

