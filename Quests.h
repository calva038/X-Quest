// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Header for the game's questlines
#ifndef QUESTS_H
#define QUESTS_H

#include <string>

class Quests
{
public:
	static int questStages[]; //Stores what quest stages the player has completed
	static int startX, startY; //Stores first quest city coordinates
	static int introduction(); //1.6
	static std::string characterNameInput();
	static void quest(); //1.13
	static int firstVillage(); //1.10.2
	static std::string nameHolder;
	int ending(const char* enemyName, std::string enemyType[10], int enemyHealth, int enemyAttack, int enemyDefense, int victoryGold, int victoryXP, int& health, int magic, int stamina, int& xP, int& gold, int xCord, int yCord, const char* dialogue1, const char* dialogue2, const char* dialogue3, const char* dialogue4, std::string dialogue1a, std::string dialogue2a, std::string dialogue3a, std::string dialogue4a, int attackFull, int defenseFull, int healthMax, int enemyLevel, int choice1, int choice2, int *partyHealth, int *partyMagic, int *partyStamina, int specialMove[], int magicMove[], int partyCharacters[], int item[]);
private:
};
//WIP, available in a future update
#endif