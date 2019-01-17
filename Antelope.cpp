#include "Antelope.h"

void Antelope::add_new(int buff_x, int buff_y)
{
	world->organisms[buff_x][buff_y] = new Antelope(*world, buff_x, buff_y);

	world->queue.push_back(world->organisms[buff_x][buff_y]);

	world->organisms[buff_x][buff_y]->draw();

	world->org_numb++;

	std::string sentence("Przychodzi na swiat nowy " + type_name(this->type) + " na polu: X " + to_string(buff_x) + " Y " + to_string(buff_y));
	world->add_message(sentence);
}

bool Antelope::action()
{
	erase();

	int buff_x = this->x;
	int buff_y = this->y;
	int r = rand() % 4;

	switch (r) {
		case 1: {
			if (this->x > 0 + 2) //x--
				this->x = this->x - 2;
			else
				this->x = this->x + 2;
			break; 
		}
		case 2: {
			if (this->x < 19 - 2) //x++
				this->x = this->x + 2;
			else
				this->x = this->x - 2;
			break;
		}
		case 3: {
			if (this->y > 0 + 2) //y--
				this->y = this->y - 2;
			else
				this->y = this->y + 2;
			break;
		}
		case 0: {
			if (this->y < 19 - 2) //y++
				this->y = this->y + 2;
			else
				this->y = this->y - 2;
			break; 
		}
	}

	int buffor = check_neighbors();
	this->initiative = this->initiative + buffor;
	this->strenght = this->strenght + buffor;

	if (world->organisms[this->x][this->y] != NULL) {
		return collision(world->organisms[this->x][this->y], buff_x, buff_y);
	}

	world->organisms[this->x][this->y] = this;

	world->organisms[buff_x][buff_y] = NULL;

	this->draw();

	return false;
}

bool Antelope::fight(int buff_x, int buff_y)
{
	if (rand() % 2 == 1) {
		std::string sentence(type_name(this->type) + " ucieka przed walka na polu: X " + to_string(buff_x) + " Y " + to_string(buff_y));
		world->add_message(sentence);
		return false;
	}
	else
		return true;
}
