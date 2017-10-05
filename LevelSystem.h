// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Header for the game's player leveling system
#ifndef LEVELSYSTEM_H
#define LEVELSYSTEM_H

#include <vector>

class LevelSystem
{
public:
	static std::vector<int> attribute;
	static std::vector<int> skill;
	static std::vector<std::string> attributeName; //{Vitality,Occult,Charisma,Alertness,Brawn,Understanding,Longevity,Agility,Resolve,Yield}
	static std::vector<std::string> skillName;
	static int levelDifference, levelXp, level;
	static int levelSystemMain(); //1.8
	static int levelUp(int level, int health, int healthMax, int levelDifference, int levelXp); //1.8.1
	static void levelUpPerk(); //1.8.2
	static std::vector<int> characterCreateAttribute(std::vector<int> attribute); //1.8.3
	static std::vector<int> characterCreateSkill(std::vector<int> skill); //1.8.3
private:
};
#endif