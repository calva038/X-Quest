// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's battle system
#include "Battle.h"
#include "Globals.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int Battle::battleEncounter;
int Battle::enemyLevel, Battle::enemyHealth, Battle::enemyAttack, Battle::enemyDefense, Battle::victoryGold, Battle::victoryXP, Battle::choiceFail;
string Battle::enemyName;
vector<int> Battle::specialMove = { 1,0,0,0,0,0,0,0,0,0 };
vector<int> Battle::magicMove = { 1,0,0,0,0,0,0,0,0,0 };
vector<int> Battle::partyHealth = { 80,150,125,90,95,100,50,200 };
vector<int> Battle::partyMagic = { 200,0,25,50,100,0,0,0 };
vector<int> Battle::partyStamina = { 0,50,25,0,25,40,0,75 };

//Function to create battle system
int Battle::battle()
{
	PlaySound("music\\Battle.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	enemyLevel = Battle::enemyLvl(enemyLevel, Globals::xCord, Globals::yCord); //decides enemy difficulty
	Battle::enemyStat(enemyName, enemyHealth, enemyAttack, enemyDefense, victoryGold, victoryXP); //decides enemy attributes
	enemyHealth = enemyHealth*enemyLevel;
	enemyAttack = enemyAttack*enemyLevel;
	enemyDefense = enemyDefense*enemyLevel;
	Sleep(1000);
	cin.clear();
	cout << "You have come across a Level " << enemyLevel << " " << enemyName << "." << endl;
	cout << "                                                                        Press enter to continue";
	cin.ignore();
	do
	{
		if (Globals::health <= 0) //if player dies
		{
			cout << "Game Over";
			return(0);
		}
		else
		{
			choiceAgain:
			Battle::choiceFail = 1;
			cout << "Health: " << Globals::health << " | Magic: " << Globals::magic << " | Stamina: " << Globals::stamina << endl; //displays player attributes
			//if companions are in party, displays their attributes
			if (Globals::partyCharacters[0] == 2)
				cout << "Ellen - Health: " << partyHealth[0] << " | Magic: " << partyMagic[0] << " | Stamina: " << partyStamina[0] << endl;
			if (Globals::partyCharacters[1] == 2)
				cout << "Kelson - Health: " << partyHealth[1] << " | Magic: " << partyMagic[1] << " | Stamina: " << partyStamina[1] << endl;
			if (Globals::partyCharacters[2] == 2)
				cout << "Alex - Health: " << partyHealth[2] << " | Magic: " << partyMagic[2] << " | Stamina: " << partyStamina[2] << endl;
			if (Globals::partyCharacters[3] == 2)
				cout << "Penelope - Health: " << partyHealth[3] << " | Magic: " << partyMagic[3] << " | Stamina: " << partyStamina[3] << endl;
			if (Globals::partyCharacters[4] == 2)
				cout << "Sanders - Health: " << partyHealth[4] << " | Magic: " << partyMagic[4] << " | Stamina: " << partyStamina[4] << endl;
			if (Globals::partyCharacters[5] == 2)
				cout << "Ted - Health: " << partyHealth[5] << " | Magic: " << partyMagic[5] << " | Stamina: " << partyStamina[5] << endl;
			if (Globals::partyCharacters[6] == 2)
				cout << "Amos - Health: " << partyHealth[6] << " | Magic: " << partyMagic[6] << " | Stamina: " << partyStamina[6] << endl;
			cout << "Enemy Health: " << enemyHealth << endl;
			cout << "What would you like to do?" << endl;
			cout << "Up: Attack" << endl << "Left: Item" << endl << "Down: Special" << endl << "Right: Magic" << endl;
			//Player input for battle turn
			int ch = _getch();
			cout << endl;
			switch (ch)
			{
			case Globals::ARROW_UP:
			{
				system("CLS");
				if ((Globals::attackFull - (.5 * enemyDefense)) < 0)
					enemyHealth = enemyHealth - (enemyHealth * .01);
				else
					enemyHealth = enemyHealth - (Globals::attackFull - (.5 * enemyDefense));
			}
			break;
			case Globals::ARROW_DOWN:
			{
				system("CLS");
				Battle::specialMenu(specialMove);
				if (Battle::choiceFail == 0)
					goto choiceAgain;

			}
			continue;
			case Globals::ARROW_LEFT:
			{
				system("CLS");
				Battle::itemMenu(Globals::health, Globals::healthMax, Globals::item);
				if (Battle::choiceFail == 0)
					goto choiceAgain;
			}
			continue;
			case Globals::ARROW_RIGHT:
			{
				system("CLS");
				Battle::magicMenu(magicMove);
				if (Battle::choiceFail == 0)
					goto choiceAgain;
			}
			continue;
			}
			if (Globals::partyCharacters[0] == 2) //If party member is in current party, calculate party member's attack
			{
				enemyHealth = enemyHealth - (6 - (.5 * enemyDefense));
				cout << "Ellen attacked." << endl;
			}
			if (Globals::partyCharacters[1] == 2)
			{
				enemyHealth = enemyHealth - (6 - (.5 * enemyDefense));
				cout << "Kelson attacked." << endl;
			}
			if (Globals::partyCharacters[2] == 2)
			{
				enemyHealth = enemyHealth - (6 - (.5 * enemyDefense));
				cout << "Alex attacked." << endl;
			}
			if (Globals::partyCharacters[3] == 2)
			{
				enemyHealth = enemyHealth - (6 - (.5 * enemyDefense));
				cout << "Penelope attacked." << endl;
			}
			if (Globals::partyCharacters[4] == 2)
			{
				enemyHealth = enemyHealth - (6 - (.5 * enemyDefense));
				cout << "Sanders attacked." << endl;
			}
			if (Globals::partyCharacters[5] == 2)
			{
				enemyHealth = enemyHealth - (6 - (.5 * enemyDefense));
				cout << "Ted attacked." << endl;
			}
			if (Globals::partyCharacters[6] == 2)
			{
				enemyHealth = enemyHealth - (6 - (.5 * enemyDefense));
				cout << "Amos attacked." << endl;
			}
			if (enemyHealth < 0)
				goto battleWin;
			if ((enemyAttack - (.5 * Globals::defenseFull)) < 0)
				Globals::health = Globals::health - (Globals::health * .01);
			else
				Globals::health = Globals::health - (enemyAttack - (.5 * Globals::defenseFull));
		}
	} while (enemyHealth > 0);
battleWin:
	cout << "You received " << (enemyLevel*victoryXP) << " XP and " << (enemyLevel*victoryGold) << " Bytes." << endl << endl;
	Globals::xP = Globals::xP + (enemyLevel*victoryXP); //Increase player experience
	Globals::gold = Globals::gold + (enemyLevel*victoryGold); //Increase player currency
	return(Globals::health, Globals::gold, Globals::xP);
}

//Function to set enemy level
int Battle::enemyLvl(int enemyLevel, int xCord, int yCord)
{
	if ((xCord <= 5) && (xCord >= -5) && (yCord <= 5) && (yCord >= -5)) //Sets enemy level based on distance from map origin
		Battle::enemyLevel = 1;
	else if ((xCord <= 15) && (xCord >= -15) && (yCord <= 15) && (yCord >= -15))
		Battle::enemyLevel = 2;
	else if ((xCord <= 30) && (xCord >= -30) && (yCord <= 30) && (yCord >= -30))
		Battle::enemyLevel = 3;
	else if ((xCord <= 50) && (xCord >= -50) && (yCord <= 50) && (yCord >= -50))
		Battle::enemyLevel = 4;
	else if ((xCord <= 70) && (xCord >= -70) && (yCord <= 70) && (yCord >= -70))
		Battle::enemyLevel = 5;
	else
		Battle::enemyLevel = 6;
	return(Battle::enemyLevel);
}

//Function to set enemy stats
int Battle::enemyStat(string enemyName, int enemyHealth, int enemyAttack, int enemyDefense, int victoryGold, int victoryXP)
{
	int enemyNameGen = rand() % 3; //Calculate what enemy has been encountered
	if (enemyNameGen == 0)
	{
		Battle::enemyName = "Rat-icand";
		Battle::enemyHealth = 5;
		Battle::enemyAttack = 1;
		Battle::enemyDefense = 0;
		Battle::victoryGold = 2;
		Battle::victoryXP = 1;
	}
	else if (enemyNameGen == 1)
	{
		Battle::enemyName = "Nominator";
		Battle::enemyHealth = 20;
		Battle::enemyAttack = 2;
		Battle::enemyDefense = 0;
		Battle::victoryGold = 10;
		Battle::victoryXP = 10;
	}
	else if (enemyNameGen == 2)
	{
		Battle::enemyName = "Denominator";
		Battle::enemyHealth = 25;
		Battle::enemyAttack = 3;
		Battle::enemyDefense = 1;
		Battle::victoryGold = 15;
		Battle::victoryXP = 20;
	}
	return(Battle::enemyName, Battle::enemyHealth, Battle::enemyAttack, Battle::enemyDefense, Battle::victoryGold, Battle::victoryXP);
}

//Function to display special attack menu
int Battle::specialMenu(vector<int>& specialMove)
{
	if (specialMove[0] == 1)
	{
		system("CLS");
		cout << "You do not have any special attacks." << endl;
		choiceFail = 0;
		return(Battle::choiceFail);
	}
}

//Function to display item menu
int Battle::itemMenu(int health, int healthMax, int item[])
{
	if (item[0] > 1)
	{
		cout << "What item would you like to use?" << endl << "1)Health Bit | 2)Nothing" << endl;
		int ch = _getch();
		switch (ch)
		{
		case Globals::KEY_1:
			health = healthMax;
			item[0] = item[0] - 1;
			return(1);
			break;
		case Globals::KEY_2:
			return(0);
			break;
		}
	}
	else
	{
		system("CLS");
		cout << "You do not have any special attacks." << endl;
		choiceFail = 0;
		return(Battle::choiceFail);
	}
}

//Function to display magic menu
int Battle::magicMenu(vector<int>&  magicMove)
{
	if (magicMove[0] == 1)
	{
		system("CLS");
		cout << "You do not have any spells." << endl;
		choiceFail = 0;
		return(Battle::choiceFail);
	}
}