// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's save system
#include "Save.h"
#include "Map.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ofstream;

//Function to create save file
void Save::createSave(vector<char>& square)
{
	FILE* saveFile;
	saveFile = fopen("Saves\\Save.txt", "w+");
	
	fclose(saveFile);
	fflush(stdin), getchar();
	return;
}

void Save::loadSave()
{

}