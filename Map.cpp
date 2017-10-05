// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's map
#include "Map.h"
#include "Globals.h"
#include "Quests.h"
#include "Dialogue.h"
#include "Menus.h"
#include "Store.h"
#include <iomanip>
#include <windows.h>
#include <iostream>
#include <conio.h>

using std::cout;
using std::wcout;
using std::endl;
using std::string;
using std::vector;
using std::setfill;
using std::setw;

vector<char> Map::square(40000);
vector<int> Map::location(40000);
vector<int> Map::discovery = { 1,1,1,1,1,1,1,1,1,1 };

//Function to generate map locations
void Map::generateMap()
{
	int startCity, genTest;
	srand(time(NULL) + GetTickCount());
	startCity = rand() % 3;
	if (startCity == 0)
		location[0] = 20312;
	else if (startCity == 1)
		location[0] = 19503;
	else if (startCity == 2)
		location[0] = 20706;
	else if (startCity == 3)
		location[0] = 19111;
	for (int x = 1; x < 2000; x++)
	{
		location[x] = ((rand() % 199 + 4) + ((rand() % 199) * 200) + 5);
		if ((location[x]) == (location[x - 1]))
			location[x] = location[x] + 1;
		//cout << "value of location[" << x << "]: " << location[x] << endl; //Debug
		Sleep(10);
	}
	for (int x = 1; x < 2000; x++)
	{
		if (((x > 75) && (x < 500)) || (x > 550))
		{
			genTest = rand() % 10;
			if (genTest > 6)
				location[x + 2000] = (location[x] + 1);
			if (genTest > 7)
				location[x + 2000] = (location[x] - 1);
			if (genTest > 8)
				location[x + 2000] = (location[x] + 200);
			if (genTest > 9)
				location[x + 2000] = (location[x] -200);
		}
	}
	return;
}

//Function to reset map markers
void Map::boardReset() //1.9
{
	square[19506] = 32;
	square[19507] = 32;
	square[19508] = 32;
	square[19509] = 32;
	square[19510] = 32;
	square[19706] = 32;
	square[19707] = 32;
	square[19708] = 32;
	square[19709] = 32;
	square[19710] = 32;
	square[19906] = 32;
	square[19907] = 32;
	square[19908] = 32;
	square[19909] = 32;
	square[19910] = 32;
	square[20106] = 32;
	square[20107] = 32;
	square[20108] = 32;
	square[20109] = 32;
	square[20110] = 32;
	square[20306] = 32;
	square[20307] = 32;
	square[20308] = 32;
	square[20309] = 32;
	square[20310] = 32;
}

//Function to draw map markers
int Map::locations() //1.10
{
	int n = Globals::xCord, m = Globals::yCord, a, locationNumber;
	string village[50] = { "Adynaton","Bathos","Consonance" };
	/*
	ASCII Codes
	Landmark - Letter - ASCII Code
	Cave     - C      -
	Desert   - D      -
	Forest   - ¶      - 182
	Island   - I      -
	Jungle   - J      -
	Lake     - L      -
	Mountain - ^      - 94
	Ocean    -        -
	Ruins    - R      - 166
	School   - S      -
	Temple   - T      - 165
	Village  - V      - 164
	Wall     - W      - 87
	Water    - ~      - 126
	*/
	for (int x = 0; x < 3000; x++)
	{
		if (x == 0)
		{
			a = (location[0] - (n - (200 * m)));
			if (a == 19908)
			{
				if (discovery[0] == 1)
				{
					cout << "You have discovered " << village[0] << "." << endl;
					Quests::firstVillage();
					Quests::questStages[0] = 2;
					discovery[0] = 2;
				}
				else if (discovery[0] == 2)
				{
					cout << "The village of " << village[0] << "." << endl;
					cout << "Would you like to visit the town? 1) Yes" << endl;
					board();
					int ch = _getch();
					switch (ch)
					{
					case Globals::KEY_1:
						town();
						break;
					case Globals::KEY_2:
						continue;
						break;
					}
				}
			}
			else if ((a <= 20310) && (a >= 19506))
				square[a] = 164;
			else if ((a < 0) || (a > 39807))
				a = 0;
		}
		if ((x >= 1) && (x < 50))
		{
			a = (location[x] - (n - (200 * m)));
			if (a == 19908)
			{
				cout << "A village" << endl;
			}
			else if ((a <= 20310) && (a >= 19506))
				square[a] = 86;
			else if ((a < 0) || (a > 39807))
				a = 0;
		}
		if ((x >= 50) && (x < 75))
		{
			a = (location[x] - (n - (200 * m)));
			if (a == 19908)
				cout << "A temple to the Goddess" << endl;
			else if ((a <= 20310) && (a >= 19506))
				square[a] = 165;
			else if ((a < 0) || (a > 39807))
				a = 0;
		}
		if (((x >= 75) && (x < 500)) || ((x >= 2075) && (x < 2500)))
		{
			a = (location[x] - (n - (200 * m)));
			if (a == 19908)
				cout << "A mountain" << endl;
			else if ((a <= 20310) && (a >= 19506))
				square[a] = 94;
			else if ((a < 0) || (a > 39807))
				a = 0;
		}
		if ((x >= 500) && (x < 550))
		{
			a = (location[x] - (n - (200 * m)));
			if (a == 19908)
				cout << "Some ruins" << endl;
			else if ((a <= 20310) && (a >= 19506))
				square[a] = 166;
			else if ((a < 0) || (a > 39807))
				a = 0;
		}
		if (((x >= 550) && (x < 1000)) || ((x >= 2550) && (x < 3000)))
		{
			a = (location[x] - (n - (200 * m)));
			if (a == 19908)
				cout << "A wooded thicket. Nothing but trees here." << endl;
			else if ((a <= 20310) && (a >= 19506))
				square[a] = 182;
			else if ((a < 0) || (a > 39807))
				a = 0;
		}
		if ((x >= 1000) && (x < 1100))
		{
			a = (location[x] - (n - (200 * m)));
			if (a == 19908)
				cout << "Flowing water" << endl;
			else if ((a <= 20310) && (a >= 19506))
				square[a] = 126;
			else if ((a < 0) || (a > 39807))
				a = 0;
		}
	}
	return(0);
}

//Function to manage towns
int Map::town()
{
	Store::storeMain(Globals::xCord, Globals::yCord, Globals::gold, Store::storeLevel, Globals::item);
	return(Globals::gold);
}

// Function to draw map
void Map::board()
{
	string space1;
	string space2;
	if ((Globals::xCord < -9) && (Globals::yCord < -9))
	{
		space1 = " ";
		space2 = " ";
	}
	else if ((Globals::xCord < -9) && (Globals::yCord >= -9))
	{
		space1 = " ";
		space2 = "| ";
	}
	else if ((Globals::xCord >= -9) && (Globals::yCord < -9))
	{
		space1 = " |";
		space2 = " ";
	}
	else
	{
		space1 = " |";
		space2 = "| ";
	}
	cout << "     |     |     |     |     " << endl;
	wcout << "  " << square[19506] << "  |  " << square[19507] << "  |  " << square[19508] << "  |  " << square[19509] << "  |  " << square[19510] << "  " << endl;
	cout << "_____|_____|_____|_____|_____" << endl;
	cout << "     |     |     |     |     " << endl;
	wcout << "  " << square[19706] << "  |  " << square[19707] << "  |  " << square[19708] << "  |  " << square[19709] << "  |  " << square[19710] << "  " << endl;
	cout << "_____|_____|_____|_____|_____" << endl;
	cout << "     |    " << space1 << setfill('0') << setw(2) << Globals::xCord << "," << setfill('0') << setw(2) << Globals::yCord << space2 << "    |     " << endl;
	wcout << "  " << square[19906] << "  |  " << square[19907] << "  |  x  |  " << square[19909] << "  |  " << square[19910] << "  " << endl;
	cout << "_____|_____|_____|_____|_____" << endl;
	cout << "     |     |     |     |     " << endl;
	wcout << "  " << square[20106] << "  |  " << square[20107] << "  |  " << square[20108] << "  |  " << square[20109] << "  |  " << square[20110] << "  " << endl;
	cout << "_____|_____|_____|_____|_____" << endl;
	cout << "     |     |     |     |     " << endl;
	wcout << "  " << square[20306] << "  |  " << square[20307] << "  |  " << square[20308] << "  |  " << square[20309] << "  |  " << square[20310] << "  " << endl;
	cout << "     |     |     |     |     " << endl << endl;
}

// Function to record user input
int Map::move()
{
	int menuReturn = 0;
afterMenus:
	if (menuReturn = 1)
		int board(int xCord, int yCord);
	menuReturn = 0;
	cout << "Your move:" << endl << endl;
	int ch = _getch();
	cout << string(10, '\n');
	switch (ch)
	{
	case Globals::ARROW_UP:
		if (Globals::yCord != 99)
		{
			return(Globals::xCord, Globals::yCord++);
		}
		else
		{
			cout << "An invisible wall blocks your path. What did you expect? This is a video game." << endl;
			goto afterMenus;
		}
		break;
	case Globals::ARROW_DOWN:
		if (Globals::yCord != -99)
		{
			return(Globals::xCord, Globals::yCord--);
		}
		else
		{
			cout << "An invisible wall blocks your path. What did you expect? This is a video game." << endl;
			goto afterMenus;
		}
		break;
	case Globals::ARROW_LEFT:
		if (Globals::xCord != -99)
		{
			return(Globals::xCord--, Globals::yCord);
		}
		else
		{
			cout << "An invisible wall blocks your path. What did you expect? This is a video game." << endl;
			goto afterMenus;
		}
		break;
	case Globals::ARROW_RIGHT:
		if (Globals::xCord != 99)
		{
			return(Globals::xCord++, Globals::yCord);
		}
		else
		{
			cout << "An invisible wall blocks your path. What did you expect? This is a video game." << endl;
			goto afterMenus;
		}
		break;
	case Globals::KEY_TAB:
		Menus::gameMenu();
		goto afterMenus;
		break;
	case Globals::KEY_ESC:
		Menus::pauseMenu(Map::square);
		goto afterMenus;
		break;
	case Globals::KEY_TILDE:
		Menus::consoleMenu(Globals::gold, Globals::attack, Globals::item);
		goto afterMenus;
		break;
	}
}