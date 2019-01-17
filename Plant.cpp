#include "Plant.h"

bool Plant::action()
{
	int buff_x = this->x;
	int buff_y = this->y;
	int r = rand() % 33; 

	return seed(r, buff_x, buff_y);
}

bool Plant::seed(int &r, int buff_x, int buff_y) 
{
	if (r == 1) {
		this->draw();

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
				} while (world->organisms[buff_x][buff_y] != NULL);
			}
		}
	end:
		add_new(buff_x, buff_y);

	}
		
	return false;
}

bool Plant::death(int &buff_x, int &buff_y, bool &belladonna)
{
	world->buff_x = buff_x;
	world->buff_y = buff_y;
	world->org_numb--;
	return true;
}

void Plant::draw()
{
	gotoxy(this->x, this->y);
	std::cout << this->type;
}

void Plant::erase()
{
	gotoxy(this->x, this->y);
	std::cout << '.';
}

char Plant::GetType()
{
	return this->type;
}

int Plant::GetX()
{
	return this->x;
}

int Plant::GetY()
{
	return this->y;
}

int Plant::GetInitiative()
{
	return this->initiative;
}

int Plant::GetStrenght()
{
	return this->strenght;
}

void Plant::ChangeType(char type)
{
	this->type = type;
}

void Plant::ChangeX(int x)
{
	this->x = x;
}

void Plant::ChangeY(int y)
{
	this->y = y;
}

void Plant::ChangeInitiative(int initiative)
{
	this->initiative = initiative;
}

void Plant::ChangeStrenght(int strenght)
{
	this->strenght = strenght;
}