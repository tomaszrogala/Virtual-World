#pragma once
#include "Organism.h"
#include "World.h"

class Plant :public Organism
{
protected:
	char type;
	int x;
	int y;
	int strenght;
	int initiative;
	World *world;

public:
	friend class World;
	
	Plant(World &world, int x, int y, int strenght, int initiative, char type = '.') {
		this->type = type;
		this->x = x;
		this->y = y;
		this->strenght = strenght;
		this->initiative = initiative;
		this->world = &world;

	}

	virtual void add_new(int buff_x, int buff_y) = 0;
	
	char GetType();
	int GetX();
	int GetY();
	int GetInitiative();
	int GetStrenght();

	void ChangeType(char type);
	void ChangeX(int x);
	void ChangeY(int y);
	void ChangeInitiative(int initiative);
	void ChangeStrenght(int strenght);

	bool action();
	bool seed(int &r, int buff_x, int buff_y);
	bool death(int &buff_x, int &buff_y, bool &belladonna);
	bool collision(Organism* &org, int &buff_x, int &buff_y) {
		return false;
	}
	bool fight(int buff_x, int buff_y) {
		return true;
	}
	
	void draw();
	void erase();

};