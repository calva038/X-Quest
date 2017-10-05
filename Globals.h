// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Header for the game's globally required variables
#ifndef GLOBALS_H
#define GLOBALS_H

#include <string>

class Globals
{
public:
	// 1: False, 2: True
	static int item[]; //{Health}
	static int partyCharacters[]; //{Ellen,Kelson,Alex,Penelope,Sanders,Ted,Amos,Root}
	static int health, magic, stamina, attack, defense, weaponAttack, armorDefense, xCord, yCord, gold, xP, attackFull, defenseFull, questMark, healthMax,lagCounter;
	static std::string weaponType[][15];
	static std::string weaponMaterial[];
	static std::string weaponLevel[];
	static std::string gems[];
	static std::string gemLevels[];
	static std::string weaponMod[][1];
	static std::string weaponEnchantment[][1];
	static std::string utilityItems[];
	static std::string weaponCurrent;
	static std::string armorCurrent;
	static std::string armor[];
	static std::string characterName;
	/* System dependent key codes */
	enum MYKEYS
	{
		KEY_TAB = 9,
		KEY_ESC = 27,
		KEY_TILDE = 96,
		KEY_1 = 49,
		KEY_2 = 50,
		KEY_3 = 51,
		KEY_4 = 52,
		KEY_5 = 53,
		KEY_6 = 54,
		KEY_7 = 55,
		KEY_8 = 56,
		KEY_9 = 57,
		KEY_0 = 48,
		KEY_HYPHEN = 45,
		KEY_EQUALS = 61,
		ARROW_UP = 72,
		ARROW_DOWN = 80,
		ARROW_LEFT = 75,
		ARROW_RIGHT = 77
	}; //Used for user controls
	static int stats(int level); //1.7
	static std::string currentWeapon(std::string weaponLevel, std::string weaponMod, std::string weaponMaterial, std::string weaponType, std::string weaponEnchantment);
private:
};
#endif