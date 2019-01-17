#pragma once
#include "Animal.h"

class Wolf :public Animal
{
public:
	friend class World;

	Wolf(World &world, int x = 3, int y = 3, int strenght = 9, int initiative = 5, char type = 'W') :Animal(world,x,y,strenght,initiative,type)
	{
	}

	void add_new(int buff_x, int buff_y);
	int check_neighbors(){
		return 0;
	}
};