#pragma once
#include "Animal.h"

class GoldenEagle :public Animal
{
public:

	friend class World;

	GoldenEagle(World &world, int x = 3, int y = 3, int strenght = 6, int initiative = 11, char type = 'E') :Animal(world, x, y, strenght, initiative, type)
	{
	}

	bool action();
	void add_new(int buff_x, int buff_y);
	
	int check_neighbors() {
		return 0;
	}
};