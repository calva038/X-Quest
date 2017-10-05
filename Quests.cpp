// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's questing system
#include "Quests.h"
#include "Globals.h"
#include "Map.h"
#include "Dialogue.h"
#include "Battle.h"
#include <windows.h>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <conio.h>

using std::cin;
using std::cout;
using std::wcout;
using std::endl;
using std::string;

int Quests::questStages[10] = { 1,1,1,1,1,1,1,1,1,1 };
int Quests::startX, Quests::startY;
string Quests::nameHolder;

// Function to create introduction
int Quests::introduction()
{
	HWND consoleWindow = GetConsoleWindow();
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	SMALL_RECT WinRect;
	system("MODE 112,28");
	WinRect = { 0, 0, 112, 28 };
	cfi.nFont = 0;
	cfi.dwFontSize.X = 17;
	cfi.dwFontSize.Y = 36;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	SMALL_RECT* WinSize = &WinRect;
	SetWindowPos(consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl
		<< "                                               Ready Player One" << endl;
	PlaySound("narration\\Intro.wav", NULL, SND_FILENAME | SND_ASYNC);
	Map::generateMap();
	Sleep(105000); //Time needed for introduction
	system("CLS");
	PlaySound("music\\Wake_Up.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	cout << "?: Wake up." << endl;
	Sleep(1500);
	cout << "?: Wake up." << endl;
	Sleep(1500);
	cout << "?: Get out of bed you lazy bum!" << endl;
	cout << "You begrudgingly roll out of your bunk, ending up face to face with your university headmaster," << endl;
	Sleep(1000);
	cout << "Dr. cook. The crotchety 'c' steps away from your bunk and flings open the curtains, allowing" << endl;
	Sleep(1000);
	cout << "the piercing light to momentarily blind you. Dr. cook turns again to address you." << endl;
	Sleep(1500);
	cout << "cook: You slept through your final exams. Thankfully, everyone knows that it's just an" << endl;
	Sleep(1000);
	cout << "aptitude test that the government uses to assign positions. Just fill out these forms so" << endl;
	Sleep(1000);
	cout << "I don't have to do any extra paperwork. The first question is your name. Can you handle that?" << endl;
	Sleep(1500);
	cout << "Welcome to X Quest, the text-based RPG. You are x, a young letter wishing to one day be uppercase" << endl <<
		"like your father and his father before that. The journey will be long and filled with obstacles. Do" << endl <<
		"you have what it takes? There are a few things you must know before venturing forth. Be mindful of" << endl <<
		"your health. If it reaches '0,' you lose. Your Attack and Defense keep you alive; balance these and" << endl <<
		"that of your enemies. Magic and Stamina can provide useful advantages in your quest as well." << endl << endl;
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();
	cout << "It's time for you to pick your stats. You have 5 points to put into your Attack and Defense." << endl <<
		"How many points will you put in your Attack? (Input a number between 1 and 4):" << endl;
	cin >> Globals::attack;
	if ((Globals::attack < 1) || (Globals::attack > 4))
	{
		do
		{
			cin.clear();
			cin.ignore();
			cout << "Please input a number between 1 and 4." << endl;
			cin >> Globals::attack;
		} while ((Globals::attack < 1) || (Globals::attack > 4));
	}
	Globals::defense = 5 - Globals::attack;
	cout << endl << "Your Attack is " << Globals::attack << " and your Defense is " << Globals::defense << "." << endl;
	cin.ignore();
	cout << "You are all set to begin your adventure. Oh, and one more thing: It's dangerous to go alone." << endl <<
		"Take this sword." << endl << "You recieved " << Globals::weaponType[0][0] << " (Attack +1)." << endl << endl;
	Globals::weaponAttack = 1;
	cout << "Press enter to continue..." << endl << endl;
	cin.ignore();
	system("CLS");
	cout << "You begin your journey at your small cottage in a grassy field." << endl << "Use the arrow keys to explore the map." << endl << endl;
	if (Map::location[0] == 20312)
	{
		startX = 4;
		startY = -2;
	}
	else if (Map::location[0] == 19503)
	{
		startX = -5;
		startY = 2;
	}
	else if (Map::location[0] == 20706)
	{
		startX = -2;
		startY = -4;
	}
	else if (Map::location[0] == 19111)
	{
		startX = 3;
		startY = 4;
	}
	cout << "You know of a small town at (" << startX << "," << startY << ")." << endl << "That may be a good place to start your adventure." << endl;
	return(Globals::attack, Globals::defense, Globals::weaponAttack, startX, startY);
}

string Quests::characterNameInput()
{
	int answer = 0;
	nameInput:
	cout << "Name: x";
	cin >> Quests::nameHolder;
	Globals::characterName = "x" + Quests::nameHolder;
	cout << "Your name is " << Globals::characterName << endl;
	return (Globals::characterName, Quests::nameHolder);
}

//Function to track and display quests
void Quests::quest()
{
	if (questStages[0] == 1)
		cout << "Visit the town at (" << startX << "," << startY << ")." << endl;
	return;
}

//Function to manage first village scene
int Quests::firstVillage()
{
	cout << "You walk into the vilage and see a young 'e' picking flowers." << endl;
	cout << "Noticing your disoriented expression, the 'e' stands and approaches." << endl;
	cout << "The e: Hi there. You're not from around here are you?" << endl << endl;
	Dialogue::dialogue1a = "No. I just arrived.";
	Dialogue::dialogue2a = "I'm just passing through.";
	Dialogue::dialogue3a = "*LIE* - I've always lived here.";
	Dialogue::dialogue4a = "*DODGE* - Here can mean a lot of things...";
	int choice = Dialogue::dialogueInt(Dialogue::dialogue1, Dialogue::dialogue2, Dialogue::dialogue3, Dialogue::dialogue4, Dialogue::dialogue1a, Dialogue::dialogue2a, Dialogue::dialogue3a, Dialogue::dialogue4a, Dialogue::choice1, Dialogue::choice2);
	if ((choice == 1) || (choice == 2))
	{
		Sleep(1500);
		cout << "The e: I can show you around. My name is Ellen. Nice to meet you." << endl;
	}
	else if (choice == 3)
	{
		int speechCheck = rand() % 10;
		if (speechCheck > 6)
		{
			Sleep(1500);
			cout << "The e: Strange. I've never seen you around before. My name is Ellen. Nice to meet you." << endl;
			Globals::xP = Globals::xP + 5;
		}
		else
		{
			Sleep(1500);
			cout << "The e: Nice try. I know everyone in town. My name is Ellen. Nice to meet you." << endl;
		}
	}
	else if (choice == 4)
	{
		Sleep(1500);
		cout << "The e: Have some secrets to hide? Well maybe I do to. I can show you around. I'm Ellen. Nice to meet you." << endl << endl;
	}
	Globals::partyCharacters[0] = 2;
	cout << "Ellen has joined your party." << endl
		<< "You recieved an Axe." << endl;
	Globals::weaponCurrent[0] = 1;
	Globals::xP = Globals::xP + 100;
	return(Globals::xP, Globals::partyCharacters[0]);
}

//Function to manage ending scene
int Quests::ending(const char* enemyName, string enemyType[10], int enemyHealth, int enemyAttack, int enemyDefense, int victoryGold, int victoryXP, int& health, int magic, int stamina, int& xP, int& gold, int xCord, int yCord, const char* dialogue1, const char* dialogue2, const char* dialogue3, const char* dialogue4, string dialogue1a, string dialogue2a, string dialogue3a, string dialogue4a, int attackFull, int defenseFull, int healthMax, int enemyLevel, int choice1, int choice2, int *partyHealth, int *partyMagic, int *partyStamina, int specialMove[], int magicMove[], int partyCharacters[], int item[])
{
	UINT oldcp = GetConsoleOutputCP();
	char death1 = 92;
	dialogue1a = "I will never join you!";
	dialogue2a = "You can't be serious.";
	dialogue3a = "It doesn't have to be like this!";
	dialogue4a = "I've already come this far. I won't let you leave this place.";
	Dialogue::dialogueInt(dialogue1, dialogue2, dialogue3, dialogue4, dialogue1a, dialogue2a, dialogue3a, dialogue4a, choice1, choice2);
	Sleep(1500);
	cout << "Xanthippos: Very well then. You die here!" << endl;
	Sleep(1500);
	cout << "Ellen: No!" << endl;
	Sleep(1500);
	cout << "X/ x   e" << endl;
	Sleep(1000);
	cout << "X/ x  e" << endl;
	Sleep(1000);
	cout << "X/ x e" << endl;
	Sleep(1000);
	cout << "X/ xe" << endl;
	Sleep(1000);
	cout << "X/ex" << endl;
	Sleep(1000);
	cout << "X" << death1;
	_setmode(_fileno(stdout), _O_U8TEXT);
	SetConsoleOutputCP(CP_UTF8);
	wcout << L"\u0247";
	_setmode(_fileno(stdout), _O_TEXT);
	SetConsoleOutputCP(oldcp);
	cout << "x" << endl << endl;
	Sleep(1250);
	cout << "Xavier: Ellen!" << endl;
	Sleep(2000);
	cout << "Ellen: I know now...";
	Sleep(2000);
	cout << " I'm a letter." << endl << endl;
	Sleep(1500);
	cout << "X" << death1;
	_setmode(_fileno(stdout), _O_U8TEXT);
	SetConsoleOutputCP(CP_UTF8);
	wcout << L"\u0247";
	_setmode(_fileno(stdout), _O_TEXT);
	SetConsoleOutputCP(oldcp);
	cout << "x" << endl;
	Sleep(1250);
	cout << "X" << death1;
	_setmode(_fileno(stdout), _O_U8TEXT);
	SetConsoleOutputCP(CP_UTF8);
	wcout << L"\u0489";
	_setmode(_fileno(stdout), _O_TEXT);
	SetConsoleOutputCP(oldcp);
	cout << "x" << endl;
	Sleep(1250);
	cout << "X" << death1 << " x";
	Battle::battle();
	//PlaySound("narration\\Ending.wav", NULL,SND_FILENAME|SND_ASYNC);
	//Sleep(105000); //Time needed for ending
	return(0);
}

/* Dialogue option format
dialogue1 = "Test1";
dialogue2 = "Test2";
dialogue3 = "Test3";
dialogue4 = "Test4";
*/

/* Speech check format
int speechCheck = rand()%10;
if (speechCheck > (speech requirement))
{
Sleep(1500);
cout << "(Success dialogue)" << endl;
xP = xP + 5;
}
else
{
Sleep(1500);
cout << "(Failure dialogue)" << endl;
}
*/