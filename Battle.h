// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Header for the game's battle system
#ifndef BATTLE_H
#define BATTLE_H

#include <string>
#include <vector>

class Battle
{
public:
	static int battleEncounter; //Used to check whether an enemy is encountered
	static int enemyLevel, enemyHealth, enemyAttack, enemyDefense, victoryGold, victoryXP; //enemy attributes and battle victory rewards
	static std::string enemyName;
	static std::vector<int>  specialMove; //Tracks what special moves the player has unlocked
	static std::vector<int>  magicMove; //Tracks what magical moves the player has unlocked
	static std::vector<int>  partyHealth; //Tracks the health of each party member
	static std::vector<int>  partyMagic; //Tracks the magic of each party member
	static std::vector<int>  partyStamina; //Tracks the stamina of each party member
	static int battle(); //1.17
	static int enemyLvl(int enemyLevel, int xCord, int yCord); //1.17.1
	static int enemyStat(std::string enemyName, int enemyHealth, int enemyAttack, int enemyDefense, int victoryGold, int victoryXP); //1.17.2
	static int specialMenu(std::vector<int>& specialMove); //1.17.3
	static int itemMenu(int health, int healthMax, int item[]); //1.17.4
	static int magicMenu(std::vector<int>& magicMove); //1.17.5
	static int choiceFail;
private:
};
#endif