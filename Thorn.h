#pragma once
#include "Plant.h"

class Thorn :public Plant
{
public:
	friend class World;

	Thorn(World &world, int x = 3, int y = 3, int strenght = 2, int initiative = 0, char type = '^') : Plant(world, x, y, strenght, initiative, type)
	{
	}

	void add_new(int buff_x, int buff_y);
	bool action();
};