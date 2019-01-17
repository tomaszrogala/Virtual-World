#pragma once
#include "Animal.h"

class Antelope :public Animal
{
public:

	friend class World;

	Antelope(World &world, int x = 3, int y = 3, int strenght = 4, int initiative = 4, char type = 'A') :Animal(world, x, y, strenght, initiative, type)
	{
	}

	void add_new(int buff_x, int buff_y);
	bool fight(int buff_x, int buff_y);
	bool action();
	
	int check_neighbors(){
		return 0;
	}
};
