// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's calendar system

#include "Calendar.h"
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::vector;
using std::setfill;
using std::setw;

vector<int> Calendar::minute(2), Calendar::hour(2), Calendar::day(2), Calendar::month(2), Calendar::year(2);

vector<int> Calendar::calendarIni()
{
	Calendar::minute[0] = 0, Calendar::hour[0] = 0, Calendar::day[0] = 1, Calendar::month[0] = 1, Calendar::year[0] = 2016;
	return (Calendar::minute, Calendar::hour, Calendar::day, Calendar::month, Calendar::year);
}

//Function for day/night cycle and calendar
vector<int> Calendar::calendarMain()
{
	Calendar::minute[0] = (Calendar::minute[0] + 3);
	if (Calendar::minute[0] == 60)
	{
		Calendar::minute[0] = 0;
		Calendar::hour[0]++;
	}
	if ((Calendar::hour[0] == 6) && (Calendar::minute[0] == 0))
		cout << "Sunrise" << endl;
	else if ((Calendar::hour[0] == 12) && (Calendar::minute[0] == 0))
		cout << "It is noon." << endl;
	else if ((Calendar::hour[0] == 18) && (Calendar::minute[0] == 0))
		cout << "Sunset" << endl;
	else if ((Calendar::hour[0] == 24) && (Calendar::minute[0] == 0))
	{
		cout << "It is midnight." << endl;
		Calendar::hour[0] = 0;
		Calendar::day[0]++;
	}
	if (Calendar::day[0] > 30)
	{
		Calendar::day[0] = 1;
		Calendar::month[0]++;
	}
	if (Calendar::month[0] > 12)
	{
		Calendar::month[0] = 1;
		Calendar::year[0]++;
	}
	cout << setfill('0') << setw(2) << Calendar::hour[0] << ":" << setfill('0') << setw(2) << Calendar::minute[0] << " " << setfill('0') << setw(2) << Calendar::month[0] << "/" << setfill('0') << setw(2) << Calendar::day[0] << "/" << Calendar::year[0] << endl;
	return (Calendar::minute, Calendar::hour, Calendar::day, Calendar::month, Calendar::year);
}