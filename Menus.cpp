// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's menus
#include "Menus.h"
#include "Globals.h"
#include "Save.h"
#include "Title.h"
#include <iostream>
#include <conio.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

//Function to ititialize pause menu
vector<char> Menus::pauseMenu(std::vector<char>& square)
{
	cout << endl << endl << endl << endl
		<< "PAUSED - Hit Escape to return to the game" << endl << endl << endl
		<< "1)Options" << endl
		<< "2)Save" << endl
		<< "3)Quit";
	int ch = _getch();
	switch (ch)
	{
	case Globals::KEY_1:
		Title::options();
		break;
	case Globals::KEY_2:
		Save::createSave(square);
		break;
	case Globals::KEY_3:
		exit(EXIT_FAILURE);
		break;
	case Globals::KEY_4:

		break;
	case Globals::KEY_ESC:
		return (square);
		break;
	}
}

//Function to display in-game menu
void Menus::gameMenu()
{
	int ch = _getch();
	cout << endl << endl << endl << endl;
	cout << "STATS - Hit Tab to return to game" << endl << endl << endl;
	switch (ch)
	{
	case Globals::KEY_1:

		break;
	case Globals::KEY_2:

		break;
	case Globals::KEY_3:

		break;
	case Globals::KEY_4:

		break;
	case Globals::KEY_TAB:
		return;
		break;
	}
}

//Function to display console command menu
int Menus::consoleMenu(int gold, int attack, int item[])
{
	string consoleCommand;
	cout << endl << endl << endl << endl;
	cout << "Console" << endl << endl << endl;
	do
	{
		cout << "Input a console command and hit enter. Input '`' to return to the game." << endl << endl;
		cin.clear();
		cin >> consoleCommand;
		if (consoleCommand == "0000000f")
		{
			gold = gold + 100;
			cout << "100 Bytes added." << endl;
		}
		else if (consoleCommand == "0000000a")
		{
			item[0] = item[0] + 1;
			cout << "1 Health Bit added." << endl;
		}
		else if (consoleCommand == "player.attack=100")
		{
			attack = 100;
		}
	} while (consoleCommand != "`");
	return(gold, attack);
}