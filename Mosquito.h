#pragma once
#include "Animal.h"

class Mosquito :public Animal
{
	int buff_strenght;
	int buff_initiative;

public:

	friend class World;

	Mosquito(World &world, int x = 3, int y = 3, int strenght = 1, int initiative = 1, char type = 'm') :Animal(world, x, y, strenght, initiative, type)
	{
		buff_strenght = strenght;
		buff_initiative = initiative;
	}

	int check_neighbors();
	void add_new(int buff_x, int buff_y);
	bool death(int &buff_x, int &buff_y);
};