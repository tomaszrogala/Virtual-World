#include "Wolf.h"

void Wolf::add_new(int buff_x, int buff_y)
{
	world->organisms[buff_x][buff_y] = new Wolf(*world, buff_x, buff_y);

	world->queue.push_back(world->organisms[buff_x][buff_y]);

	world->organisms[buff_x][buff_y]->draw();

	world->org_numb++; 

	std::string sentence("Przychodzi na swiat nowy " + type_name(this->type) + " na polu: X " + to_string(buff_x) + " Y " + to_string(buff_y));
	world->add_message(sentence);
	return;
}
