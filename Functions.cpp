#include "Interface.h"
#include "Organism.h"
#include "Animal.h"
#include "Plant.h"

std::string type_name(char &switch_type)
{
	switch (switch_type) {
	case 'm': {return "Komar/a"; break; }
	case 'W': {return "Wilk/a"; break; }
	case 'S': {return "Owca/e"; break; }
	case 'A': {return "Antylopa/e"; break; }
	case 'l': {return "Trawa/e"; break; }
	case '^': {return "Ciern/a"; break; }
	case 'o': {return "Wilcza jagoda/e"; break; }
	case 'E': {return "Orzel przedni"; break; }
	}
}

std::string to_string(int value)
{
	if (value <= 9) {
		char word[2];
		word[0] = value + 48;
		word[1] = '\0';
		std::string str(word);
		return str;
	}
	else {
		int a; int b;
		a = value % 10;
		b = (value - a) / 10;

		char word[3];
		word[0] = (b + 48);
		word[1] = (a + 48);
		word[2] = '\0';

		std::string str(word);
		return str;
	}
}
bool compare(Organism* l, Organism* r)
{
	if (l->GetInitiative() > r->GetInitiative())
		return true;
	else
		return false;
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void HideCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = FALSE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}

void ShowCursor()
{
	::HANDLE hConsoleOut = ::GetStdHandle(STD_OUTPUT_HANDLE);
	::CONSOLE_CURSOR_INFO hCCI;
	::GetConsoleCursorInfo(hConsoleOut, &hCCI);
	hCCI.bVisible = TRUE;
	::SetConsoleCursorInfo(hConsoleOut, &hCCI);
}