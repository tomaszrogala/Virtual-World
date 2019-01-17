#pragma once
#include "Organism.h"
#include "World.h"

class Animal :public Organism
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
	
	Animal(World &world, int x = 3, int y = 3, int strenght = 5, int initiative = 4, char type = '.') {
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
	bool fight(int buff_x, int buff_y);
	virtual int check_neighbors() = 0;
	bool collision(Organism* &org, int &buff_x, int &buff_y); 
	bool death(int &buff_x, int &buff_y, bool &belladonna);

	void draw();
	void erase();

};