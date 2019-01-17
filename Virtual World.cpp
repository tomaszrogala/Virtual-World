#include "Interface.h"
#include "Organism.h"
#include "World.h"
#include "Animal.h"
#include "Plant.h"

int main()
{
	srand(time(NULL));

	World world; char button;
	int sheep = 5; int wolf = 3; int antelope = 4; int mosquito = 10; int golden_eagle = 3; 
	int grass = 15; int belladonna = 4; int thorn = 1;

	world.Load(sheep, wolf, antelope, mosquito, golden_eagle, grass, belladonna, thorn);
	world.Draw();
	HideCursor();

	button = _getch();

	while (button != 'k') { 
		world.Start();
		world.Draw();
		ShowCursor();
		button = _getch();

		while (_kbhit()) {
			button = _getch();
		}

		if (button == 's') {
			world.Save();
			system("pasue");
		}
			
		if (button == 'l') {
			world.LoadFromSave();
			system("pause");
		}
		HideCursor();
	}	

	return 0;
}
