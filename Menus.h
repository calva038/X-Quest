// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Header for the game's menus
#ifndef MENUS_H
#define MENUS_H

#include <vector>

class Menus
{
public:
	static std::vector<char> pauseMenu(std::vector<char>& square); //1.12.1
	static void gameMenu(); //1.12.2
	static int consoleMenu(int gold, int attack, int item[]); //1.12.3
private:
};
#endif