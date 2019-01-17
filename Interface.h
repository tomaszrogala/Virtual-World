#pragma once
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <fstream>

class Organism;
class Plant;
class Animal;
class World;

class Antelope;
class Wolf;
class Sheep;
class Mosquito;
class GoldenEagle;

class Grass;
class Thorn;
class Belladonna;

void HideCursor();
void gotoxy(int x, int y);
void ShowCursor();

std::string to_string(int value);
bool compare(Organism* l, Organism* r);
std::string type_name(char &switch_type);


