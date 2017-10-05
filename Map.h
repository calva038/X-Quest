// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Header for the game's map
#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>

class Map
{
public:
	static std::vector<char> square; //stores each map cell's data
	static std::vector<int> location; //stores each map cell's location type
	static std::vector<int> discovery; //stores whether the player has discovered a location
	static void generateMap(); //1.6.1
	static void boardReset(); //1.9
	static int locations(); //1.10
	static int town(); //1.10.1
	static void board(); //1.11
	static int move(); //1.12
private:
};
#endif