// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's globally required variables
#include "Globals.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int Globals::item[50] = { 1 }; //{Health}
string Globals::weaponCurrent;
string Globals::armorCurrent;
int Globals::partyCharacters[9] = { 1 }; //{Ellen,Kelson,Alex,Penelope,Sanders,Ted,Amos,Root}
int Globals::health = 100, Globals::magic = 0, Globals::stamina = 0, Globals::attack, Globals::defense, Globals::weaponAttack, Globals::armorDefense = 0, Globals::xCord = 0, Globals::yCord = 0, Globals::gold = 0, Globals::xP = 0, Globals::attackFull, Globals::defenseFull, Globals::questMark, Globals::healthMax = 100;
int Globals::lagCounter = 0;
string Globals::weaponType[7][15] = {
	{"Rock","Club","Hatchet","Mace","Maul","War Axe","Battleaxe","Warhammer","Crowbar","Sledgehammer"}
	,{ "Knife","Dagger","Shortsword","Longsword","Greatsword","Claymore","Katana","Dai-Katana","Machete","Spade","Chainsaw"}
	,{ "Bow","Hunting Bow","Long Bow","Recurve Bow","Crossbow","Compound Bow","Pistol","Rifle","Shotgun","Submachine Gun","Sniper","Machine Gun","Anti-Material Rifle","Minigun	Railgun","Gauss Rifle"}
	,{ "Pike","Javelin","Halberd","Harpoon","Trident"}
	,{ "Wand","Rod","Cane","Scepter","Staff","Cards","Tome"}
	,{ "Dart","Throwing Knife","Throwing Star","Greek Fire","Flame Thrower","Grenade","Mine","Grenade Launcher","Missile Launcher","Heavy Explosive"}
	,{ "Brass Knuckles","Claws","Bladed Guantlets","Power Fist","Power Glove"}
	};
string Globals::weaponMaterial[18] = { "","Wood","Stone","Copper","Bronze","","Irony","Dramatic Irony","Steel","Electrum","Numeric Steel","Ebony","Alphastone","Silicon","","Laser","Heavy","Plasma" };
string Globals::weaponLevel[9] = { "Junk","Inferior","","Fine","Superior","Exquisite","Flawless","Epic","Legendary"};
string Globals::gems[12] = { "Garnet","Amethyst","Aquamarine","Diamond","Emerald","Pearl","Ruby","Peridot","Sapphire","Opal","Topaz","Turquoise"};
string Globals::gemLevels[20] = { "Bit","Byte","Kilobyte","Megabyte","Gigabyte","Terabyte","DDR","Megabyte DDR","Gigabyte DDR","Terabyte DDR","DDR2",
"Megabyte DDR2","Gigabyte DDR2","Terabyte DDR2","DDR3","Terabyte DDR3","DDR4","Terabyte DDR4","DDR5","DDR5X"};
string Globals::weaponMod[1][1] = { {""} };
string Globals::weaponEnchantment[1][1] = { { " " } };
string Globals::utilityItems[1];
string Globals::armor[10] = { "None" , "Iron" , "Steel" };
string Globals::characterName;

//Function to display stats
int Globals::stats(int level)
{
	attackFull = attack + weaponAttack;
	defenseFull = defense + armorDefense;
	cout << "Health: " << health << " | Magic: " << magic << " | Stamina: " << stamina << endl
	<< "Attack: " << attackFull << " | Defense: " << defenseFull << endl
	<< "Weapon: " << weaponCurrent << endl//" Armor: " << armorCurrent << endl
	<< "Bytes: " << gold << " | XP: " << xP << " | Level: " << level << endl
	<< endl;
	return(attackFull, defenseFull);
}

//Function to calculate current weapon
string Globals::currentWeapon(string weaponLevel, string weaponMod, string weaponMaterial, string weaponType, string weaponEnchantment)
{
	weaponCurrent = (weaponLevel + " " + weaponMod + " " + weaponMaterial + " " + weaponType + " " + weaponEnchantment);
	//				(weaponLevel[2],weaponMod[0][0], weaponMaterial[0], weaponType[0][0],weaponEnchantment[0])="Rock
	return (weaponCurrent);
}

//Function to calculate current armor