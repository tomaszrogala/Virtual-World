#include "Grass.h"

void Grass::add_new(int buff_x, int buff_y)
{
 world->organisms[buff_x][buff_y] = new Grass(*world, buff_x, buff_y);

 world->queue.push_back(world->organisms[buff_x][buff_y]);

 world->organisms[buff_x][buff_y]->draw();

 world->org_numb++;

 std::string sentence("Na polu: X " + to_string(buff_x) + " Y " + to_string(buff_y) + " wyrasta " + type_name(this->type));
 world->add_message(sentence);
}
