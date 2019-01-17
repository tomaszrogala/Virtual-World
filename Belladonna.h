#pragma once
#include "Plant.h"

class Belladonna :public Plant
{

public:
	friend class World;

	Belladonna(World &world, int x = 3, int y = 3, int strenght = 0, int initiative = 0, char type = 'o') : Plant(world, x, y, strenght, initiative, type)
	{
	}

	void add_new(int buff_x, int buff_y);
	bool death(int &buff_x, int &buff_y, bool &belladonna);
};