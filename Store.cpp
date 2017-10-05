// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's store system
#include "Store.h"
#include "Globals.h"
#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;

int Store::storeLevel;

//Function to manage store
int Store::storeMain(int xCord, int yCord, int gold, int storeLevel, int item[])
{
	storeLvl(storeLevel, xCord, yCord);
	if (storeLevel = 1)
	{
	storeBegin1:
		cout << "What would you like to purchase?" << endl << "1)Health Bit - 100 Bytes | 2)Nothing" << endl;
		int ch = _getch();
		switch (ch)
		{
		case Globals::KEY_1:
			if (gold > 100)
			{
				item[0] = item[0] + 1;
				gold = gold - 100;
			}
			else
				cout << "You do not have enough Bytes to purchase that." << endl;
			break;
		case Globals::KEY_2:
			return(gold);
			break;
		}
		goto storeBegin1;
	}
	else if (storeLevel = 2)
	{
	storeBegin2:
		cout << "What would you like to purchase?" << endl << "1)Health Bit - 100 Bytes | 2)Nothing" << endl;
		int ch = _getch();
		switch (ch)
		{
		case Globals::KEY_1:
			if (gold > 100)
			{
				item[0] = item[0] + 1;
				gold = gold - 100;
			}
			else
				cout << "You do not have enough Bytes to purchase that." << endl;
			break;
		case Globals::KEY_2:
			return(gold);
			break;
		}
		goto storeBegin2;
	}
	else if (storeLevel = 3)
	{
	storeBegin3:
		cout << "What would you like to purchase?" << endl << "1)Health Bit - 100 Bytes | 2)Nothing" << endl;
		int ch = _getch();
		switch (ch)
		{
		case Globals::KEY_1:
			if (gold > 100)
			{
				item[0] = item[0] + 1;
				gold = gold - 100;
			}
			else
				cout << "You do not have enough Bytes to purchase that." << endl;
			break;
		case Globals::KEY_2:
			return(gold);
			break;
		}
		goto storeBegin3;
	}
	else if (storeLevel = 4)
	{
	storeBegin4:
		cout << "What would you like to purchase?" << endl << "1)Health Bit - 100 Bytes | 2)Nothing" << endl;
		int ch = _getch();
		switch (ch)
		{
		case Globals::KEY_1:
			if (gold > 100)
			{
				item[0] = item[0] + 1;
				gold = gold - 100;
			}
			else
				cout << "You do not have enough Bytes to purchase that." << endl;
			break;
		case Globals::KEY_2:
			return(gold);
			break;
		}
		goto storeBegin4;
	}
	else if (storeLevel = 5)
	{
	storeBegin5:
		cout << "What would you like to purchase?" << endl << "1)Health Bit - 100 Bytes | 2)Nothing" << endl;
		int ch = _getch();
		switch (ch)
		{
		case Globals::KEY_1:
			if (gold > 100)
			{
				item[0] = item[0] + 1;
				gold = gold - 100;
			}
			else
				cout << "You do not have enough Bytes to purchase that." << endl;
			break;
		case Globals::KEY_2:
			return(gold);
			break;
		}
		goto storeBegin5;
	}
	else if (storeLevel = 6)
	{
	storeBegin6:
		cout << "What would you like to purchase?" << endl << "1)Health Bit - 100 Bytes | 2)Nothing" << endl;
		int ch = _getch();
		switch (ch)
		{
		case Globals::KEY_1:
			if (gold > 100)
			{
				item[0] = item[0] + 1;
				gold = gold - 100;
			}
			else
				cout << "You do not have enough Bytes to purchase that." << endl;
			break;
		case Globals::KEY_2:
			return(gold);
			break;
		}
		goto storeBegin6;
	}
}

//Function to set store level
int Store::storeLvl(int storeLevel, int xCord, int yCord)
{
	if ((xCord <= 5) && (xCord >= -5) && (yCord <= 5) && (yCord >= -5))
		storeLevel = 1;
	else if ((xCord <= 15) && (xCord >= -15) && (yCord <= 15) && (yCord >= -15))
		storeLevel = 2;
	else if ((xCord <= 30) && (xCord >= -30) && (yCord <= 30) && (yCord >= -30))
		storeLevel = 3;
	else if ((xCord <= 50) && (xCord >= -50) && (yCord <= 50) && (yCord >= -50))
		storeLevel = 4;
	else if ((xCord <= 70) && (xCord >= -70) && (yCord <= 70) && (yCord >= -70))
		storeLevel = 5;
	else
		storeLevel = 6;
	return(storeLevel);
}