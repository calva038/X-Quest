// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Header for the game's pre-game start menu
#ifndef STARTMENU_H
#define STARTMENU_H

#include <vector>

class StartMenu
{
public:
	static int initialize();
	static std::vector<int> startOptions(std::vector<int>& detail, std::vector<int>& advanceddetail);
	static std::vector<int> advancedOptions(std::vector<int>& advanceddetail);
	static int calculateLag(std::vector<int>& detail, std::vector<int>& advanceddetail);
private:
	std::vector<int> detail; //stores what graphics options the player has chosen
	int startMenuExit;
	int lagCounter;
	int recommendedSettings;
	int tempWindowMode;
};
#endif