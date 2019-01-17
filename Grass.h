#pragma once
#include "Plant.h"

class Grass :public Plant 
{

public:
	friend class World;

	Grass(World &world, int x = 3, int y = 3, int strenght = 0, int initiative = 0, char type = 'l') : Plant(world, x, y, strenght, initiative, type)
	{
	}

	void add_new(int buff_x, int buff_y);
};