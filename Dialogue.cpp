// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's dialogue system
#include "Dialogue.h"
#include "Globals.h"
#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::string;

string Dialogue::dialogue1a, Dialogue::dialogue2a, Dialogue::dialogue3a, Dialogue::dialogue4a;
const char *Dialogue::dialogue1;
const char *Dialogue::dialogue2;
const char *Dialogue::dialogue3;
const char *Dialogue::dialogue4;
int Dialogue::choice1, Dialogue::choice2;

//Function to initialize dialogue system
int Dialogue::dialogueInt(const char* dialogue1, const char* dialogue2, const char* dialogue3, const char* dialogue4, string dialogue1a, string dialogue2a, string dialogue3a, string dialogue4a, int choice1, int choice2)
{
	//Accepts dialogue options from function
	dialogue1 = dialogue1a.c_str();
	dialogue2 = dialogue2a.c_str();
	dialogue3 = dialogue3a.c_str();
	dialogue4 = dialogue4a.c_str();
	choice1 = Dialogue::dialogueSys(choice2, dialogue1, dialogue2, dialogue3, dialogue4);
	if (choice1 == 1)
		return(1);
	else if (choice1 == 2)
		return(2);
	else if (choice1 == 3)
		return(3);
	else if (choice1 == 4)
		return(4);
}

//Function to manage dialogue
int Dialogue::dialogueSys(int choice1, const char* dialogue1, const char* dialogue2, const char* dialogue3, const char* dialogue4)
{
	//Displays dialogue options and accepts player input
	cout << "Up: " << dialogue1 << endl << "Left: " << dialogue3 << endl << "Down: " << dialogue2 << endl << "Right: " << dialogue4 << endl;
	int ch = _getch();
	string key;
	cout << endl;
	ch = _getch();
	switch (ch)
	{
	case Globals::ARROW_UP:
	{
		cout << "Xavier: " << dialogue1 << endl;
		return(1);
	}
	break;
	case Globals::ARROW_DOWN:
	{
		cout << "Xavier: " << dialogue2 << endl;
		return(2);
	}
	break;
	case Globals::ARROW_LEFT:
	{
		cout << "Xavier: " << dialogue3 << endl;
		return(3);
	}
	break;
	case Globals::ARROW_RIGHT:
	{
		cout << "Xavier: " << dialogue4 << endl;
		return(4);
	}
	break;
	}
}