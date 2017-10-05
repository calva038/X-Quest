// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's leveling system
#include "LevelSystem.h"
#include "Globals.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

vector<int> LevelSystem::attribute = { 1,1,1,1,1,1,1,1,1,1 }; //{Vitality,Occult,Charisma,Alertness,Brawn,Understanding,Longevity,Agility,Resolve,Yield} (1 = 0, max: 16)
vector<int> LevelSystem::skill = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }; // (1 = 0, max: 128)
vector<string> LevelSystem::attributeName = { "Vitality","Occult","Charisma","Alertness","Brawn","Understanding","Longevity","Agility","Resolve","Yield" };
vector<string> LevelSystem::skillName = { "Light Armor","Medium Armor","Heavy Armor","Archery","Hand-to-Hand","Thrown","Magic Weapons","Energy Weapons","Bladed Weapons","Firearms",
"Melee","Spear","Explosives","Destruction","Block","Survival","Alchemy","Medicine","Smithing","Pickpocketing",
"Sneak","Lockpicking","Restoration","Conjuration","Alteration","Illusion","Enchanting","Mysticism","Science","Speech"};
int LevelSystem::levelDifference = 100, LevelSystem::levelXp = 0, LevelSystem::level = 1;

//Function to create leveling system
int LevelSystem::levelSystemMain()
{
	if (Globals::xP >= (levelXp + levelDifference))
	{
		levelUp(level, Globals::health, Globals::healthMax, levelDifference, levelXp);
	}
	return(level, Globals::health, levelDifference, levelXp);
}

//Function to process level up
int LevelSystem::levelUp(int level, int health, int healthMax, int levelDifference, int levelXp)
{
	LevelSystem::level = (LevelSystem::level + 1);
	LevelSystem::levelDifference = (100 * (LevelSystem::level - 1));
	LevelSystem::levelXp = (LevelSystem::levelXp + LevelSystem::levelDifference);
	cout << "Level Up!" << endl;
	Globals::health = Globals::healthMax;
	levelUpPerk();
	cout << LevelSystem::level << endl << LevelSystem::levelXp << endl << LevelSystem::levelDifference;
	return(LevelSystem::level, Globals::health, LevelSystem::levelDifference, LevelSystem::levelXp);
}

//Function to display perk select
void LevelSystem::levelUpPerk()
{
	//Added in future update
	return;
}

//Function to display attributes select
vector<int> LevelSystem::characterCreateAttribute(vector<int> attribute)
{
	int answer, ch = _getch();
	//Displays description of attributes
	cout << "It is now time to expand your VOCABULARY. This is the set of attributes that dictate your" << endl
		<< "play style, so choose wisely. You have 30 points to put into 10 different attributes." << endl
		<< "You can place up to 9 points in a single stat, for a total of 10." << endl << endl;
	cout << "Vitality increases maximum health and resistances to elemental attacks, and provides a chance to attack multiple times during a turn." << endl <<
		"Occult dictates maximum magic and the rate it recovers while improving the chance that a spell cast will be successful." << endl <<
		"Charisma improves interactions with Asciina's inhabitants, dictating store prices and speech checks." << endl <<
		"Alertness advances ranged combat effectiveness, influences the sequence of attacks during combat, and grants the player a chance to surprise attak an enemy." << endl <<
		"Brawn manages attack power, carry weight, and whether a weapon is usable by the player." << endl <<
		"Understanding boosts all skills, the experience gained during combat, and the skill points earned each level." << endl <<
		"Longevity enhances the effects of items, helps avoid combat, and reduces the rate of equipment degradation." << endl <<
		"Agility helps avoid being staggered during a fight while improving both dodge and hit chance." << endl <<
		"Resolve increases maximum stamina and dictates the rate that it recovers and overall defense." << endl <<
		"Yield governs loot drops and critical hit chances, while also improving the overall effects of your actions. 'A higher Yield yields a higher yield!'" << endl << endl;
attributeSelect:
	int attributePoints = 50;
	for (int x = 0; x < 10; x++)
	{
		cout << attributeName[x] << ":" << endl;
		cout << "Please input a number between 0 and 16. Attribute points available: " << attributePoints << endl;
		cin >> attribute[x];
		if ((attribute[x] < 1) || (attribute[x] > 9))
		{
			do
			{
				cin.clear();
				cin.ignore();
				cout << "Please input a number between 0 and 16." << endl;
				cin >> attribute[x];
			} while ((attribute[x] < 0) && (attribute[x] > 16));
		}
		if (attribute[x] > attributePoints)
		{
			do
			{
				cin.clear();
				cin.ignore();
				cout << "You do not have enough points for that." << endl;
				cin >> attribute[x];
			} while (attribute[x] > attributePoints);
		}
		attributePoints = attributePoints - attribute[x];
	}
	if (attributePoints > 0) //Tests if attribute points remain
	{
		cout << "You have VOCABULARY points left over. Would you like to reselect your attributes?";
		int ch = _getch();
		string key;
		cout << endl;
		switch (ch)
		{
		case Globals::ARROW_UP:
		{
			answer = 1;
		}
		break;
		case Globals::ARROW_DOWN:
		{
			answer = 2;
		}
		break;
		}
		if (answer == 2)
			goto attributeSelect;
	}
	cout << "Your attributes are: " << endl
		<< "Vitality: " << attribute[0] << "| Occult: " << attribute[1] << "| Charisma: " << attribute[2] << "| Alertness: " << attribute[3] << "| Brawn: " << attribute[4] << endl
		<< "Understanding: " << attribute[5] << "| Longevity: " << attribute[6] << "| Agility: " << attribute[7] << "| Resolve: " << attribute[8] << "| Yield: " << attribute[9] << endl << endl;
	cout << "Are these the stats you want? 1) Yes, 2) No" << endl;
	ch = _getch();
	cout << endl;
	switch (ch)
	{
	case Globals::KEY_1:
	{
		cout << endl << "Continue to expand your VOCABULARY!" << endl << endl;
		Sleep(100);
	}
	break;
	case Globals::KEY_2:
	{
		goto attributeSelect;
	}
	break;
	}
	return(LevelSystem::attribute);
}

vector<int> LevelSystem::characterCreateSkill(vector<int> skill)
{
	return(LevelSystem::skill);
}