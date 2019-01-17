#include "Sheep.h"

void Sheep::add_new(int buff_x, int buff_y)
{
	world->organisms[buff_x][buff_y] = new Sheep(*world, buff_x, buff_y);

	world->queue.push_back(world->organisms[buff_x][buff_y]);

	world->organisms[buff_x][buff_y]->draw();

	world->org_numb++; 

	std::string sentence("Przychodzi na swiat nowa " + type_name(this->type) + " na polu: X " + to_string(buff_x) + " Y " + to_string(buff_y));
	world->add_message(sentence);
}
