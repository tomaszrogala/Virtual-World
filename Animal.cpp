#include "Animal.h"

bool Animal::action()
{
	erase();

	int buff_x = this->x;
	int buff_y = this->y;
	int r = rand() % 4;

	switch (r) {
		case 1: {
			if (this->x > 0) //x--
					this->x--;
				else
					this->x++;
				break; 
		}
		case 2: {
			if (this->x < 19) //x++
					this->x++;
				else
					this->x--;
				break; 
		}
		case 3: {
			if (this->y > 0) //y--
					this->y--;
				else
					this->y++;
				break; 
		}
		case 0: {
			if (this->y < 19) //y++
					this->y++;
				else
					this->y--;
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

bool Animal::fight(int buff_x, int buff_y) {
	return true;
}

bool Animal::death(int &buff_x, int &buff_y, bool &belladonna) 
{
	world->buff_x = buff_x;
	world->buff_y = buff_y;
	world->org_numb--;
	return true;
}

bool Animal::collision(Organism* &attacked_org, int &buff_x,int &buff_y)
{
	bool belladonna = false;
	bool score = false;
	char type_buffor = attacked_org->GetType();
	std::string activity;
	
	if (attacked_org->GetType() != this->type) { //fighting
		if (this->fight(buff_x, buff_y) && attacked_org->fight(buff_x,buff_y)) {
			if (this->strenght >= attacked_org->GetStrenght()) {
				if (attacked_org->death(buff_x, buff_y, belladonna)) {

					world->queue.remove(world->organisms[this->x][this->y]);
					if (belladonna) {
						activity = " ginie od trujacej ";
						world->organisms[this->x][this->y] = NULL;
						world->org_numb--;
						score = true;
					}
					else {
						activity = " zjada ";
						world->organisms[this->x][this->y] = this;
					}
					world->organisms[buff_x][buff_y] = NULL;
				}
				else {
					activity = " nie trafia ";
					world->organisms[this->x][this->y] = this;
					attacked_org->ChangeX(buff_x);
					attacked_org->ChangeY(buff_y);
					world->organisms[buff_x][buff_y] = attacked_org;
					attacked_org->draw();
				}
				this->draw();
			}
			else {
				attacked_org->draw();
				if (death(buff_x, buff_y, belladonna)) {
					if (attacked_org->GetType() == '^')
						activity = "zostaje zabity/a";
					else
						activity = " zostaje zjedzony/a przez ";
					score = true;
				}
				else {
					activity = " uchodzi z zyciem z walki z ";
					this->x = buff_x;
					this->y = buff_y;
					this->draw();
				}
			}
		}
		else {
			this->x = buff_x;
			this->y = buff_y;
			return score;
		}
			
	}
	else { //multiplication	

		activity = " kopuluje z ";
		this->x = buff_x;
		this->y = buff_y;
		world->organisms[this->x][this->y] = this;

		if (world->org_numb >= 400)
			return false;

		int add = 1;
		if ((this->x - add) >= 0 && (this->y - add) >= 0 && (this->x + add) < 20 && (this->y + add) < 20) {
			buff_x = this->x - add;
			buff_y = this->y - add;
		}
		else
			goto next;

		while (add < 20) {
			for (int i = -add; i <= add; i++) {
				for (int j = -add; j <= add; j++) {
					if (i <= (add - 1) && i >= (-add + 1) && j <= (add - 1) && j >= (-add + 1)) {
						buff_x++;
						continue;
					}
					if (world->organisms[buff_x][buff_y] == NULL)
						goto end;
					buff_x++;
				}
				buff_x = buff_x - (2 * add + 1);
				buff_y++;
			}
			add++;
			if ((this->x - add) >= 0 && (this->y - add) >= 0 && (this->x + add) < 20 && (this->y + add) < 20) {
				buff_x = this->x - add;
				buff_y = this->y - add;
			}
			else {
			next:
				bool flag;

				if ((this->x - add) < 0 || (this->y - add) < 0)
					flag = true;
				else
					flag = false;
				int loop_circuits = 0;
				int range = 2 * add;
				do {
					if (flag) {
						buff_x = rand() % range;
						buff_y = rand() % range;
					}
					if (!flag) {
						buff_x = -(rand() % range) + 19;
						buff_y = -(rand() % range) + 19;
					}
					if (range < 20)
						range++;
					loop_circuits++;
					if (loop_circuits > 9999)
						goto end;
				} while (world->organisms[buff_x][buff_y] != NULL);
			}
		}
		end:

		std::string sentence(type_name(this->type) + activity + type_name(type_buffor) + " na polu: X " + to_string(this->x) + " Y " + to_string(this->y));
		world->add_message(sentence);
		add_new(buff_x, buff_y);
		return score;
	}

	std::string sentence(type_name(this->type) + activity + type_name(type_buffor) + " na polu: X " + to_string(this->x) + " Y " + to_string(this->y));
	world->add_message(sentence);

	return score;
} 

void Animal::draw()
{
	gotoxy(this->x, this->y);
	std::cout << this->type;
}

void Animal::erase()
{
	gotoxy(this->x, this->y);
	std::cout << '.';
}

char Animal::GetType()
{
	return this->type;
}

int Animal::GetX()
{
	return this->x;
}

int Animal::GetY()
{
	return this->y;
}

int Animal::GetInitiative()
{
	return this->initiative;
}

int Animal::GetStrenght()
{
	return this->strenght;
}

void Animal::ChangeType(char type)
{
	this->type = type;
}

void Animal::ChangeX(int x)
{
	this->x = x;
}

void Animal::ChangeY(int y)
{
	this->y = y;
}

void Animal::ChangeInitiative(int initiative)
{
	this->initiative = initiative;
}

void Animal::ChangeStrenght(int strenght)
{
	this->strenght = strenght;
}
