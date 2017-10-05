// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's pre-game start menu
#include "StartMenu.h"
#include "Globals.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int StartMenu::initialize()
{
	int lagCounter = 0;
	int recommendedSettings = 0;
	int startMenuExit = 0;
	vector<int> detail = { 1,1,1,1,1,1,1,1,1,1};
	vector<int> advanceddetail = { 1,1,1,1,1,1,1,1,1,1,1};
	do
	{
		char logo = 92;
		cout << "Uncertain Games" << endl << "X-Quest" << endl << endl << endl;
		cout << "1) Play" << endl << endl << "2) Options" << endl << endl << "3) Exit" << endl << endl
			<< "                     _     _      _____  _     _ _______ _______ _______" << endl
			<< "                      " << logo << "___/  ___ |   __| |     | |______ |______    |   " << endl
			<< "                     _/   " << logo << "_     |____" << logo << "| |_____| |______ ______|    |   " << endl;
		if (recommendedSettings == 0)
		{
			cout << endl << endl << "X-Quest will now detect your video hardware and set video options accordingly." << endl;
			Sleep(2000);
			cout << "                                              Press enter to continue";
			cin.ignore();
			Sleep(6000);
			system("CLS");
			cout << "Uncertain Games" << endl << "X-Quest" << endl << endl << endl;
			cout << "1) Play" << endl << endl << "2) Options" << endl << endl << "3) Exit" << endl << endl
				<< "                     _     _      _____  _     _ _______ _______ _______" << endl
				<< "                      " << logo << "___/  ___ |   __| |     | |______ |______    |   " << endl
				<< "                     _/   " << logo << "_     |____" << logo << "| |_____| |______ ______|    |   " << endl;
			cout << endl << endl << "Video settings have been set to Ultra Low Quality." << endl;
			Sleep(2000);
			cout << "                                              Press enter to continue";
			cin.ignore();
			system("CLS");
			cout << "Uncertain Games" << endl << "X-Quest" << endl << endl << endl;
			cout << "1) Play" << endl << endl << "2) Options" << endl << endl << "3) Exit" << endl << endl
				<< "                     _     _      _____  _     _ _______ _______ _______" << endl
				<< "                      " << logo << "___/  ___ |   __| |     | |______ |______    |   " << endl
				<< "                     _/   " << logo << "_     |____" << logo << "| |_____| |______ ______|    |   " << endl;
			recommendedSettings = 1;
		}
		int ch = _getch();
		switch (ch)
		{
		case Globals::KEY_1:
			Globals::lagCounter = (calculateLag(detail, advanceddetail));
			if (detail[9] == 1)
			{
				return(1);
			}
			else
			{
				keybd_event(VK_MENU, 0x38, 0, 0);
				keybd_event(VK_RETURN, 0x1c, 0, 0);
				keybd_event(VK_RETURN, 0X1c, KEYEVENTF_KEYUP, 0);
				keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
				return(1);
			}
			break;
		case Globals::KEY_2:
			system("CLS");
			startOptions(detail, advanceddetail);
			break;
		case Globals::KEY_3:
			startMenuExit = 1;
			break;
		}
	} while (startMenuExit == 0);
	if (startMenuExit == 0)
		return(1);
	else
		return(0);
}

vector<int> StartMenu::startOptions(vector<int>& detail, vector<int>& advanceddetail)
{
	int tempWindowMode;
	startMenuOptions:
	cout << "1) Aspect Ratio: 16:9 Widescreen[X] " << endl
		<< "2) Resolutions: 1920x1080[X]" << endl
		<< "3) 2880p Downampling: Off[";
	if (detail[3] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  On[";
	if (detail[3] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "4) Vertical Sync: Off[";
	if (detail[4] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  On[";
	if (detail[4] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "5) Antialiasing: Off[";
	if (detail[5] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  MSAA[";
	if (detail[5] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]  FXAA[";
	if (detail[5] == 3)
		cout << "X";
	else
		cout << " ";
	cout << "]  SMAA[";
	if (detail[5] == 4)
		cout << "X";
	else
		cout << " ";
	cout << "]  TAA[";
	if (detail[5] == 5)
		cout << "X";
	else
		cout << " ";
	cout << "]  MFAA[";
	if (detail[5] == 6)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "6) Antialiasing Level: Off[";
	if (detail[6] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  2x[";
	if (detail[6] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]  4x[";
	if (detail[6] == 3)
		cout << "X";
	else
		cout << " ";
	cout << "]  8x[";
	if (detail[6] == 4)
		cout << "X";
	else
		cout << " ";
	cout << "]  12x[";
	if (detail[6] == 5)
		cout << "X";
	else
		cout << " ";
	cout << "]  16x[";
	if (detail[6] == 6)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "7) Anisotropic Filtering: Off[";
	if (detail[7] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  2x[";
	if (detail[7] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]  4x[";
	if (detail[7] == 3)
		cout << "X";
	else
		cout << " ";
	cout << "]  8x[";
	if (detail[7] == 4)
		cout << "X";
	else
		cout << " ";
	cout << "]  12x[";
	if (detail[7] == 5)
		cout << "X";
	else
		cout << " ";
	cout << "]  16x[";
	if (detail[7] == 6)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "8) Detail: Low[";
	if (detail[8] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  Medium[";
	if (detail[8] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]  High[";
	if (detail[8] == 3)
		cout << "X";
	else
		cout << " ";
	cout << "]  Ultra[";
	if (detail[8] == 4)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "9) Windowed Mode[";
	if (detail[9] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  Borderless[";
	if (detail[9] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "0) Frame Per Second: 30 [";
	if (detail[0] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  60[";
	if (detail[0] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]  120[";
		if (detail[0] == 3)
			cout << "X";
		else
			cout << " ";
	cout << "]  Unlimited[";
	if (detail[0] == 4)
		cout << "X";
	else
		cout << " ";
	cout << "]"
		<< endl << "-) Advanced Options"
		<< endl << "=) Return";
	int ch = _getch();
	switch (ch)
	{
	case Globals::KEY_1:
		system("CLS");
		goto startMenuOptions;
		break;
	case Globals::KEY_2:
		system("CLS");
		goto startMenuOptions;
		break;
	case Globals::KEY_3:
		if (detail[3] == 1)
			detail[3] = 2;
		else
			detail[3] = 1;
		system("CLS");
		goto startMenuOptions;
		break;
	case Globals::KEY_4:
		if (detail[4] == 1)
			detail[4] = 2;
		else
			detail[4] = 1;
		system("CLS");
		goto startMenuOptions;
		break;
	case Globals::KEY_5:
		if (detail[5] >= 1 && detail[5] < 6)
			detail[5] = (detail[5] + 1);
		else
			detail[5] = 1;
		system("CLS");
		goto startMenuOptions;
		break;
	case Globals::KEY_6:
		if (detail[6] >= 1 && detail[6] < 6)
			detail[6] = (detail[6] + 1);
		else
			detail[6] = 1;
		system("CLS");
		goto startMenuOptions;
		break;
	case Globals::KEY_7:
		if (detail[7] >= 1 && detail[7] < 6)
			detail[7] = (detail[7] + 1);
		else
			detail[7] = 1;
		system("CLS");
		goto startMenuOptions;
		break;
	case Globals::KEY_8:
		if (detail[8] >= 1 && detail[8] < 4)
			detail[8] = (detail[8] + 1);
		else
			detail[8] = 1;
		system("CLS");
		goto startMenuOptions;
		break;
	case Globals::KEY_9:
		if (detail[9] == 1)
			detail[9] = 2;
		else
			detail[9] = 1;
		system("CLS");
		goto startMenuOptions;
		break;
	case Globals::KEY_0:
		if (detail[0] >= 1 && detail[0] < 4)
			detail[0] = (detail[0] + 1);
		else
			detail[0] = 1;
		system("CLS");
		goto startMenuOptions;
		break;
	case Globals::KEY_HYPHEN:
		system("CLS");
		advancedOptions(advanceddetail);
		system("CLS");
		goto startMenuOptions;
		break;
	case Globals::KEY_EQUALS:
		system("CLS");
		return (detail, advanceddetail);
		break;
	}
}

vector<int> StartMenu::advancedOptions(vector<int>& advanceddetail)
{
advancedMenuOptions:
	cout << "1) Texture Quality: Low[";
	if (advanceddetail[1] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  Medium[";
	if (advanceddetail[1] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]  High[";
	if (advanceddetail[1] == 3)
		cout << "X";
	else
		cout << " ";
	cout << "]  Ultra[";
	if (advanceddetail[1] == 4)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "2) Shadow Quality: Low[";
	if (advanceddetail[2] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  Medium[";
	if (advanceddetail[2] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]  High[";
	if (advanceddetail[2] == 3)
		cout << "X";
	else
		cout << " ";
	cout << "]  Ultra[";
	if (advanceddetail[2] == 4)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "3) Shadow Distance: None[";
	if (advanceddetail[3] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  Low[";
	if (advanceddetail[3] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]  Medium[";
	if (advanceddetail[3] == 3)
		cout << "X";
	else
		cout << " ";
	cout << "]  High[";
	if (advanceddetail[3] == 4)
		cout << "X";
	else
		cout << " ";
	cout << "]  Ultra[";
	if (advanceddetail[3] == 5)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "4) Decal Quality: Low[";
	if (advanceddetail[4] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  Medium[";
	if (advanceddetail[4] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]  High[";
	if (advanceddetail[4] == 3)
		cout << "X";
	else
		cout << " ";
	cout << "]  Ultra[";
	if (advanceddetail[4] == 4)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "5) Lighting Quality: None[";
	if (advanceddetail[5] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  Low[";
	if (advanceddetail[5] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]  Medium[";
	if (advanceddetail[5] == 3)
		cout << "X";
	else
		cout << " ";
	cout << "]  High[";
	if (advanceddetail[5] == 4)
		cout << "X";
	else
		cout << " ";
	cout << "]  Ultra[";
	if (advanceddetail[5] == 5)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "6) Godrays Quality: None[";
	if (advanceddetail[6] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  Low[";
	if (advanceddetail[6] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]  Medium[";
	if (advanceddetail[6] == 3)
		cout << "X";
	else
		cout << " ";
	cout << "]  High[";
	if (advanceddetail[6] == 4)
		cout << "X";
	else
		cout << " ";
	cout << "]  Ultra[";
	if (advanceddetail[6] == 5)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "7) Depth of Field: None[";
	if (advanceddetail[7] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  SSAO[";
	if (advanceddetail[7] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]  H*AO[";
	if (advanceddetail[7] == 3)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "8) Ambient Occlusion: None[";
	if (advanceddetail[8] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  On[";
	if (advanceddetail[8] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "9) Lens Flare: None[";
	if (advanceddetail[9] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  On[";
	if (advanceddetail[9] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]" << endl
		<< "0) Bloom: None[";
	if (advanceddetail[0] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  On[";
	if (advanceddetail[0] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]"
		<< endl << "-) High Dynamic Range Rendering: None[";
	if (advanceddetail[10] == 1)
		cout << "X";
	else
		cout << " ";
	cout << "]  On[";
	if (advanceddetail[10] == 2)
		cout << "X";
	else
		cout << " ";
	cout << "]"
		<< endl << "=) Return";
	int chx = _getch();
	switch (chx)
	{
	case Globals::KEY_1:
		if (advanceddetail[1] >= 1 && advanceddetail[1] < 4)
			advanceddetail[1] = (advanceddetail[1] + 1);
		else
			advanceddetail[1] = 1;
		system("CLS");
		goto advancedMenuOptions;
		break;
	case Globals::KEY_2:
		if (advanceddetail[2] >= 1 && advanceddetail[2] < 4)
			advanceddetail[2] = (advanceddetail[2] + 1);
		else
			advanceddetail[2] = 1;
		system("CLS");
		goto advancedMenuOptions;
		break;
	case Globals::KEY_3:
		if (advanceddetail[3] >= 1 && advanceddetail[3] < 5)
			advanceddetail[3] = (advanceddetail[3] + 1);
		else
			advanceddetail[3] = 1;
		system("CLS");
		goto advancedMenuOptions;
		break;
	case Globals::KEY_4:
		if (advanceddetail[4] >= 1 && advanceddetail[4] < 4)
			advanceddetail[4] = (advanceddetail[4] + 1);
		else
			advanceddetail[4] = 1;
		system("CLS");
		goto advancedMenuOptions;
		break;
	case Globals::KEY_5:
		if (advanceddetail[5] >= 1 && advanceddetail[5] < 5)
			advanceddetail[5] = (advanceddetail[5] + 1);
		else
			advanceddetail[5] = 1;
		system("CLS");
		goto advancedMenuOptions;
		break;
	case Globals::KEY_6:
		if (advanceddetail[6] >= 1 && advanceddetail[6] < 5)
			advanceddetail[6] = (advanceddetail[6] + 1);
		else
			advanceddetail[6] = 1;
		system("CLS");
		goto advancedMenuOptions;
		break;
	case Globals::KEY_7:
		if (advanceddetail[7] >= 1 && advanceddetail[7] < 3)
			advanceddetail[7] = (advanceddetail[7] + 1);
		else
			advanceddetail[7] = 1;
		system("CLS");
		goto advancedMenuOptions;
		break;
	case Globals::KEY_8:
		if (advanceddetail[8] == 1)
			advanceddetail[8] = 2;
		else
			advanceddetail[8] = 1;
		system("CLS");
		goto advancedMenuOptions;
		break;
	case Globals::KEY_9:
		if (advanceddetail[9] == 1)
			advanceddetail[9] = 2;
		else
			advanceddetail[9] = 1;
		system("CLS");
		goto advancedMenuOptions;
		break;
	case Globals::KEY_0:
		if (advanceddetail[0] == 1)
			advanceddetail[0] = 2;
		else
			advanceddetail[0] = 1;
		system("CLS");
		goto advancedMenuOptions;
		break;
	case Globals::KEY_HYPHEN:
		if (advanceddetail[10] == 1)
			advanceddetail[10] = 2;
		else
			advanceddetail[10] = 1;
		system("CLS");
		goto advancedMenuOptions;
		break;
	case Globals::KEY_EQUALS:
		system("CLS");
		return (advanceddetail);
		break;
	}
}

int StartMenu::calculateLag(vector<int>& detail, vector<int>& advanceddetail)
{
	srand(time(NULL) + GetTickCount());
	int lagMeasure = 0;
	for (int i = 3; i < 9; i++)
	{
		lagMeasure = lagMeasure + ((detail[i] - 1)*(rand() % 50 + 1));
	}
	for (int i = 0; i < 11; i++)
	{
		lagMeasure = lagMeasure + ((advanceddetail[i] - 1)*(rand() % 50 + 50));
	}
	return (lagMeasure);
}