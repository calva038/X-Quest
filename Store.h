// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Header for the game's buying and selling system
#ifndef STORE_H
#define STORE_H

class Store
{
public:
	static int storeLevel; //Dictates the level of each store, high has better items
	static int storeMain(int xCord, int yCord, int gold, int storeLevel, int item[]); //1.15
	static int storeLvl(int storeLevel, int xCord, int yCord); //1.15.1
private:
};
#endif