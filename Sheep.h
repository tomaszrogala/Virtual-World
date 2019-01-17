#pragma once
#include "Animal.h"

class Sheep :public Animal
{
public:
	friend class World;

	Sheep(World &world, int x = 3, int y = 3, int strenght = 4, int initiative = 4, char type = 'S') : Animal(world, x, y, strenght, initiative, type)
	{
	}

	void add_new(int buff_x, int buff_y);
	int check_neighbors() {
		return 0;
	}
};