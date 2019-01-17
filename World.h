#pragma once
#include "Interface.h"
#include "Organism.h"

class World
{
protected:
	Organism* *organisms[21];
	int buff_x; int buff_y;
	std::vector <std::string> log_array;
	std::list<Organism*> queue;
	int org_numb;
	
public:

	friend class Organism;
	
	friend class Animal;
	friend class Wolf;
	friend class Sheep;
	friend class Antelope;
	friend class Mosquito;
	friend class GoldenEagle;

	friend class Plant;
	friend class Grass;
	friend class Thorn;
	friend class Belladonna;
	
	World(int org_numb = 0) {
		this->org_numb = org_numb;

		for (int i = 0; i < 21; i++) {
			organisms[i] = new Organism*[21];
		}

		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				organisms[i][j] = NULL;
			}
		}
	}

	~World() {
		for (int i = 0; i < 21; i++) {
			delete[] organisms[i];
		}
	}
	void Save();
	void LoadFromSave();
	void Load(int sheep, int wolf, int antelope, int mosquito, int golden_eagle, int grass, int belladonna, int thorn);
	void Start();
	void Draw();
	

	void add_message(std::string word);
};