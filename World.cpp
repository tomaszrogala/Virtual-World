#include "World.h"

#include "Wolf.h"
#include "Sheep.h"
#include "GoldenEagle.h"
#include "Mosquito.h"
#include "Antelope.h"

#include "Belladonna.h"
#include "Thorn.h"
#include "Grass.h"

void World::Draw()
{
	system("cls");
	gotoxy(0, 0);
	for (unsigned int i = 0; i < 20; i++) {
		for (unsigned int j = 0; j < 20; j++) {
			if (organisms[j][i] == NULL) {
				std::cout << '.';
			}
			else
				organisms[j][i]->draw();
		}
		std::cout << " | ";
		if(log_array.size()>i)
			std::cout << log_array[i].c_str();
		std::cout << '\n';
	}
	for (int i = 0; i < 21; i++) {
		std::cout << "_";
	}
	std::cout << "| ";
}

void World::Save() {

	std::fstream file;
	file.open("WirtualWorld.save", std::fstream::trunc | std::fstream::out); 

	if (file.is_open()) {
		file << queue.size() << std::endl;
		for (Organism* org : queue) { // browses every element
			file << org->GetType() <<  " " << org->GetX() << " " << org->GetY() << " " << org->GetStrenght() << " " << org->GetInitiative() << std::endl;
		}

		file << log_array.size() << std::endl;
		for (std::string msg : log_array) {
			file << msg << std::endl;
		}
		file.close();
		std::cout << "Zapisano swiat\n poprawnie";
	}
	else
		std::cout << "Zapisanie pliku nie powiodlo sie";
}

void World::LoadFromSave() {
	std::fstream file;
	file.open("WirtualWorld.save", std::fstream::in);

	if (file.is_open()) {

		for (int i = 0; i < 21; i++) {
			for (int j = 0; j < 21; j++) {
				organisms[i][j] = NULL;
			}
		}

		for (Organism* org : queue)
			delete org;

		queue.clear();
		log_array.clear();
		org_numb = 0;

		file >> org_numb;
		for (int i = 0; i < org_numb; i++) {
			char type = '.';
			int x = 0;
			int y = 0;
			int initiative = 0;
			int strenght = 0;
			file >> type  >> x >> y >> strenght >> initiative;
			
			switch (type) {
			case 'm': { queue.push_back(new Mosquito(*this, x, y, strenght, initiative)); break; }
			case 'W': { queue.push_back(new Wolf(*this, x, y, strenght, initiative)); break; }
			case 'S': { queue.push_back(new Sheep(*this, x, y, strenght, initiative)); break; }
			case 'A': { queue.push_back(new Antelope(*this, x, y, strenght, initiative)); break; }
			case 'l': { queue.push_back(new Grass(*this, x, y, strenght, initiative)); break; }
			case '^': { queue.push_back(new Thorn(*this, x, y, strenght, initiative)); break; }
			case 'o': { queue.push_back(new Belladonna(*this, x, y, strenght, initiative)); break; }
			case 'E': { queue.push_back(new GoldenEagle(*this, x, y, strenght, initiative)); break; }
			}

			for (Organism* it: queue) 
				organisms[it->GetX()][it->GetY()] = it;

			queue.sort(compare);
		}

		int n = 0;
		file >> n;
		for (int i = 0; i < n; i++) {
			std::string s;
			std::getline(file, s);
			log_array.push_back(s);
		}
		file.close();
		std::cout << "Wczytano swiat\n poprawnie";
	}
	else
		std::cout << "Brak dostepu do pliku";
}

void World::Load(int sheep, int wolf, int antelope, int mosquito, int golden_eagle, int grass, int belladonna, int thorn)
{
	for (int i = 0; i < sheep; i++) {
		queue.push_back(new Sheep(*this));
		org_numb++;
	}

	for (int i = 0; i < wolf; i++) {
		queue.push_back(new Wolf(*this));
		org_numb++;
	}

	for (int i = 0; i < antelope; i++) {
		queue.push_back(new Antelope(*this));
		org_numb++;
	}

	for (int i = 0; i < mosquito; i++) {
		queue.push_back(new Mosquito(*this));
		org_numb++;
	}

	for (int i = 0; i < golden_eagle; i++) {
		queue.push_back(new GoldenEagle(*this));
		org_numb++;
	}

	for (int i = 0; i < grass; i++) {
		queue.push_back(new Grass(*this));
		org_numb++;
	}

	for (int i = 0; i < belladonna; i++) {
		queue.push_back(new Belladonna(*this));
		org_numb++;
	}

	for (int i = 0; i < thorn; i++) {
		queue.push_back(new Thorn(*this));
		org_numb++;
	}

	for (Organism* it : queue) {
		while (organisms[it->GetX()][it->GetY()] != NULL) {
			it->ChangeX(rand() % 20);
			it->ChangeY(rand() % 20);
		}
		organisms[it->GetX()][it->GetY()] = it;
	}

	queue.sort(compare);
}

void World::Start()
{
	int buff_org_numb = org_numb;
	std::list<Organism*>::iterator it;
	int i = 0;
	for (it = queue.begin(); it != queue.end(); it++) {
		if (buff_org_numb <= 0)
			return;

		while ((*it)->action()) {
			std::list<Organism*>::iterator buffor = it;
			it++;
			queue.erase(buffor);
			organisms[buff_x][buff_y] = NULL;
			if (it == queue.end())
				return;
		}
		buff_org_numb--;
	}

	queue.sort(compare);
}


void World::add_message(std::string sentence)
{
	log_array.insert(log_array.begin(), sentence);
	while (log_array.size() > 20)
		log_array.pop_back();
}
