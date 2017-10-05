// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's physics engine
#include "Physics.h"
#include <cmath>

#define PI 3.14159265

//Function to create Physics Engine
void Physics::staffordEngine()
{
	acceleration[1] = -9.8;
	velocityIni[0] = velocityIni[2] * cos((angle * PI) / 180); //Velocity in X direction
	velocityIni[1] = velocityIni[2] * sin((angle * PI) / 180); //Velocity in Y direction
	time = ((0 - velocityIni[1]) / acceleration[1]);
	displacementFin[1] = ((velocityIni[1] * time) + (.5 * acceleration[1] * (time * time))); //Displacement in Y direction
	displacementFin[0] = (displacementIni[0] + (velocityIni[0] * time) + (.5 * acceleration[0] * (time * time)));
	for (int x = 0; x < 2; x++)
	{
		velocityAvg[x] = ((displacementFin[x] - displacementIni[x]) / time);
		accelerationAvg[x] = ((velocityFin[x] - velocityIni[x]) / time);
	};
}