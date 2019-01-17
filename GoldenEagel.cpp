#include "GoldenEagle.h"

void GoldenEagle::add_new(int buff_x, int buff_y)
{
	world->organisms[buff_x][buff_y] = new GoldenEagle(*world, buff_x, buff_y);

	world->queue.push_back(world->organisms[buff_x][buff_y]);

	world->organisms[buff_x][buff_y]->draw();

	world->org_numb++;

	std::string sentence("Przychodzi na swiat nowy " + type_name(this->type) + " na polu: X " + to_string(buff_x) + " Y " + to_string(buff_y));
	world->add_message(sentence);
	return;
}

bool GoldenEagle::action()
{
	erase();

	int buff_x = this->x;
	int buff_y = this->y;
	int r = rand() % 4;

	switch (r) {
	case 1: {if (this->x > 0) //x--
				this->x--;
			else
				this->x++;
		break; }
	case 2: {if (this->x < 19) //x++
				this->x++;
			else
				this->x--;
		break; }
	case 3: {if (this->y > 0) //y--
				this->y--;
			else
				this->y++;
		break; }
	case 0: {if (this->y < 19) //y++
				this->y++;
			else
				this->y--;
		break; }
	}
	
	int buffor = check_neighbors();
	this->initiative = this->initiative + buffor;
	this->strenght = this->strenght + buffor;

	if (world->organisms[this->x][this->y] != NULL) {
		if (world->organisms[this->x][this->y]->GetStrenght() > this->strenght) {
			switch (r) {
				case 1: {//x--
					while (world->organisms[this->x][this->y] != NULL) {
						if (x == 0)
							break;
						this->x--;
					}
				}
				case 2: {//x++
					while (world->organisms[this->x][this->y] != NULL) {
						if (x == 19)
							break;
						this->x++;
					}
				}
				case 3: {//y--
					while (world->organisms[this->x][this->y] != NULL) {
						if (y == 0)
							break;
						this->y--;
					}
				}
				case 0: {//y++
					while (world->organisms[this->x][this->y] != NULL) {
						if (y == 19)
							break;
						this->y++;
					}
				}
			}
			int loop = 0;
			while (world->organisms[this->x][this->y] != NULL) {
				this->x = rand() % 20;
				this->y = rand() % 20;
				loop++;
				if (loop > 99999)
					break;
			}

			std::string sentence(type_name(this->type) + " startuje z pola X " + to_string(buff_x) + " Y " + to_string(buff_y) +"przelatuje nad wrogiem i laduje na polu: X " + to_string(this->x) + " Y " + to_string(this->y));
			world->add_message(sentence);
		}
		else
			return collision(world->organisms[this->x][this->y], buff_x, buff_y);
	}

	world->organisms[this->x][this->y] = this;

	world->organisms[buff_x][buff_y] = NULL;

	this->draw();

	return false;
}