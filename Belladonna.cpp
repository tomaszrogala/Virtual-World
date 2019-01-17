#include "Belladonna.h"

void Belladonna::add_new(int buff_x, int buff_y)
{
	world->organisms[buff_x][buff_y] = new Belladonna(*world, buff_x, buff_y);

	world->queue.push_back(world->organisms[buff_x][buff_y]);

	world->organisms[buff_x][buff_y]->draw();

	world->org_numb++;

	std::string sentence("Na polu: X " + to_string(buff_x) + " Y " + to_string(buff_y) + " wyrasta " + type_name(this->type));
	world->add_message(sentence);
}

bool Belladonna::death(int &buff_x, int &buff_y, bool &belladonna)
{
	belladonna = true;
	world->buff_x = buff_x;
	world->buff_y = buff_y;
	world->org_numb--;
	return true;
}
