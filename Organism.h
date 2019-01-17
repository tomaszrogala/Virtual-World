#pragma once
#include "Interface.h"
#include "World.h"

class Organism
{

public:

	virtual char GetType() = 0;
	virtual int GetX() = 0;
	virtual int GetY() = 0;
	virtual int GetInitiative() = 0;
	virtual int GetStrenght() = 0;

	virtual void ChangeType(char type) = 0;
	virtual void ChangeX(int x) = 0;
	virtual void ChangeY(int y) = 0;
	virtual void ChangeInitiative(int initiative) = 0;
	virtual void ChangeStrenght(int strenght) = 0;

	friend class Animal;
	friend class Plant;

	virtual bool death(int &buff_x, int &buff_y, bool &belladonna) = 0;
	virtual bool action() = 0;
	virtual bool fight(int buff_x, int buff_y) = 0;
	virtual bool collision(Organism* &org, int &buff_x, int &buff_y) = 0;
	virtual void draw() = 0;
	virtual void erase() = 0;
	
};