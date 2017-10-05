// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Header for the game's saving system
#ifndef SAVE_H
#define SAVE_H
#define _CRT_SECURE_NO_WARNINGS //used to stop Visual Studio from throwing unnecessary errors

#include <vector>

class Save
{
public:
	static void createSave(std::vector<char>& square); //Generates a save file using current game data states
	static void loadSave(); //Reads save file and loads game data values
private:
};
#endif