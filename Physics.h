// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Header for the game's physics engine
#ifndef PHYSICS_H
#define PHYSICS_H

class Physics
{
public:
	float displacementFin[2], displacementIni[2] = { 0,0 }, velocityFin[3], velocityIni[3], velocityAvg[3], acceleration[3] = {1}, accelerationAvg[3], time, angle; //Displacement array - 0 = X, 1 = Y -- Velocity and Acceleration arrays - 0 = X, 1 = Y, 2 = Total
	void staffordEngine();
private:
};
#endif