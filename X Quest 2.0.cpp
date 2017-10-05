// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

/*
X Quest text-based Role Playing Game.
-A 5x5 cell map display
-A randomly generating 39,601 cell map
-A party system with up to four companions at a time WIP
-Multi-choice dialogue trees with speech checks
-A turn based battle system with scaling difficulty
-A Linear growth level up system with stats
-A shop system with scaling item attributes
-An original soundtrack by my friend Alex Lubinsky WIP
-Opening and closing narrations by my friend Kelson Lentsch WIP
-A day/night cycle
-A full year calendar
-A dynamic weather system WIP
-Lore, religons and a quest line
-Console commands for cheaters
-The ability to change the command line window for different resolutions (Optimized for 1080p)
-Stafford Physics Engine
-Pre-Game start menu for changing various graphical options
*/

#include "Globals.h"
#include "Title.h"
#include "Quests.h"
#include "Dialogue.h"
#include "Store.h"
#include "Map.h"
#include "LevelSystem.h"
#include "Calendar.h"
#include "Battle.h"
#include "Save.h"
#include "StartMenu.h"
#include <windows.h>

#define SND_FILENAME 0x20000
#define SND_LOOP 8
#define SND_ASYNC 1
#define _WIN64_WINNT 0x0500

// main() 1.0

int main()
{
	if (StartMenu::initialize() == 0)
		return(0);
	Title::setUp();
	Title::logoMenu();
	if (Title::startMenu() == 0)
		return(0);
	Sleep((Globals::lagCounter));
	Quests::introduction();
	Quests::characterNameInput();
	LevelSystem::characterCreateAttribute(LevelSystem::attribute);
	LevelSystem::characterCreateSkill(LevelSystem::skill);
	Calendar::calendarIni();
	Globals::currentWeapon(Globals::weaponLevel[6], Globals::weaponMod[0][0], Globals::weaponMaterial[6], Globals::weaponType[2][15], Globals::weaponEnchantment[0][0]);
	do {
		Globals::stats(LevelSystem::level);
		Quests::quest();
		Map::boardReset();
		Map::locations();
		Map::board();
		Map::move();
		if ((Map::square[19908]) = 32)
		{
			Battle::battleEncounter = ((rand() % 25 + 1));
			if (Battle::battleEncounter == 8)
			{
				system("CLS");
				Battle::battle();
				PlaySound("music\\Overworld.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
				if ((Globals::health == 0) || (Globals::health < 0))
					return 0;
			}
		}
		system("CLS");
		Sleep((Globals::lagCounter));
		LevelSystem::levelSystemMain();
		Calendar::calendarMain();
	} while (Globals::attack != 100);
	Save::createSave(Map::square);
	return 0;
}