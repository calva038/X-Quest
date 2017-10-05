// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Header for the game's game clock and calendar
#ifndef CALENDAR_H
#define CALENDAR_H

#include <vector>

class Calendar
{
public:
	static std::vector<int>  minute, hour, day, month, year; //Various time intervals
	static std::vector<int> calendarIni();
	static std::vector<int> calendarMain(); //1.18
private:
};
#endif