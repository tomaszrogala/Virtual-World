#include "Mosquito.h"

void Mosquito::add_new(int buff_x, int buff_y)
{
	world->organisms[buff_x][buff_y] = new Mosquito(*world, buff_x, buff_y);

	world->queue.push_back(world->organisms[buff_x][buff_y]);

	world->organisms[buff_x][buff_y]->draw();

	world->org_numb++;

	std::string sentence("Przychodzi na swiat nowy " + type_name(this->type)  + " na polu: X " + to_string(buff_x) + " Y " + to_string(buff_y));
	world->add_message(sentence);
}

int Mosquito::check_neighbors() {

	this->initiative = buff_initiative;
	this->strenght = buff_strenght;

	int loop_it = 0;
	int add = 0;
	int buff_x = this->x;
	int buff_y = this->y;
	int sub = 0;
	bool sign = true;

	if (this->x == 0 && y != 0) {
		buff_y = this->y - 1;
		sub = 1;
	}	
	if (this->x != 19 && this->y == 0) {
		buff_x = this->x + 1;
		sub = 3;
	}
	if (this->x == 19 && y != 19) {
		buff_y = this->y + 1;
		sub = 1;
		sign = false;
	}
	if (this->x != 0 && this->y == 19) {
		buff_x = this->x - 1;
		sub = 3;
		sign = false;
	}
		
	if (this->x > 0 && this->x < 19 && this->y > 0 && this->y < 19) {
		buff_x = this->x - 1;
		buff_y = this->y - 1;
		loop_it = 8;
	}
	else if (this->x == this->y || this->x - this->y == 19 || this->y - this->x == 19) {
		loop_it = 3;
	}
	else {
		loop_it = 5;
	}
	
	for (int i = 0; i < loop_it; i++) { 
		if (world->organisms[buff_x][buff_y] != NULL && world->organisms[buff_x][buff_y] != this)
			 if (world->organisms[buff_x][buff_y]->GetType() == 'm') 
				add++;

		if (i < 2 - sub) {
			if (sign)
				buff_x++;
			else
				buff_x--;
		}	
		else if (i < 4 - sub) {
			if (sign)
				buff_y++;
			else
				buff_y--;
		}
		else if (i < 6 - sub) {
			if (sign)
				buff_x--;
			else
				buff_x++;
		}
		else {
			if (sign)
				buff_y--;
			else
				buff_y++;
		}
	}
	return add;
}

bool Mosquito::death(int &buff_x, int &buff_y) 
{
	if (rand() % 2 == 1) {
		world->buff_x = buff_x;
		world->buff_y = buff_y;
		world->org_numb--;
		return true;
	}
	else
		return false;
}