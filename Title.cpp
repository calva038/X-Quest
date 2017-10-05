// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Source code for the game's title screen and main menu
#include "Title.h"
#include "Globals.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//Function that sets up the command line
void Title::setUp()
{
	HWND consoleWindow = GetConsoleWindow();
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	SMALL_RECT WinRect;
	int x = GetSystemMetrics(SM_CXSCREEN);
	int y = GetSystemMetrics(SM_CYSCREEN);
	if ((x == 1920) && (y == 1080))
	{
		system("MODE 173,42");
		WinRect = { 0, 0, 173, 42 };
		cfi.nFont = 0;
		cfi.dwFontSize.X = 11;
		cfi.dwFontSize.Y = 24;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, L"Consolas");
	}
	else
	{
		system("MODE 173,42");
		WinRect = { 0, 0, 173, 42 };
		cfi.nFont = 0;
		cfi.dwFontSize.X = 6;
		cfi.dwFontSize.Y = 12;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, L"Consolas");
	}
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	SMALL_RECT* WinSize = &WinRect;
	SetWindowPos(consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}

//Function to create logo and start screen
void Title::logoMenu()
{
	//PlaySound("music/Title.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	Sleep(1000);
	char logo = 92;
	cout << endl << endl << endl << endl;
	cout << "                 _____                     _____                     _____                     _____                     _____                     _____          " << endl;
	Sleep(100);
	cout << "                /" << logo << "    " << logo << "                   /" << logo << "    " << logo << "                   /" << logo << "    " << logo << "                   /" << logo << "    " << logo << "                   /" << logo << "    " << logo << "                   /" << logo << "    " << logo << "         " << endl;
	Sleep(100);
	cout << "               /::" << logo << "____" << logo << "                 /::" << logo << "____" << logo << "                 /::" << logo << "    " << logo << "                 /::" << logo << "    " << logo << "                 /::" << logo << "    " << logo << "                 /::" << logo << "    " << logo << "        " << endl;
	Sleep(100);
	cout << "              /:::/    /                /::::|   |                /::::" << logo << "    " << logo << "               /::::" << logo << "    " << logo << "               /::::" << logo << "    " << logo << "               /::::" << logo << "    " << logo << "       " << endl;
	Sleep(100);
	cout << "             /:::/    /                /:::::|   |               /::::::" << logo << "    " << logo << "             /::::::" << logo << "    " << logo << "             /::::::" << logo << "    " << logo << "             /::::::" << logo << "    " << logo << "      " << endl;
	Sleep(100);
	cout << "            /:::/    /                /::::::|   |              /:::/" << logo << ":::" << logo << "    " << logo << "           /:::/" << logo << ":::" << logo << "    " << logo << "           /:::/" << logo << ":::" << logo << "    " << logo << "           /:::/" << logo << ":::" << logo << "    " << logo << "     " << endl;
	Sleep(100);
	cout << "           /:::/    /                /:::/|::|   |             /:::/  " << logo << ":::" << logo << "    " << logo << "         /:::/__" << logo << ":::" << logo << "    " << logo << "         /:::/  " << logo << ":::" << logo << "    " << logo << "         /:::/__" << logo << ":::" << logo << "    " << logo << "    " << endl;
	Sleep(100);
	cout << "          /:::/    /                /:::/ |::|   |            /:::/    " << logo << ":::" << logo << "    " << logo << "       /::::" << logo << "   " << logo << ":::" << logo << "    " << logo << "       /:::/    " << logo << ":::" << logo << "    " << logo << "       /::::" << logo << "   " << logo << ":::" << logo << "    " << logo << "   " << endl;
	Sleep(100);
	cout << "         /:::/    /      _____     /:::/  |::|   | _____     /:::/    / " << logo << ":::" << logo << "    " << logo << "     /::::::" << logo << "   " << logo << ":::" << logo << "    " << logo << "     /:::/    / " << logo << ":::" << logo << "    " << logo << "     /::::::" << logo << "   " << logo << ":::" << logo << "    " << logo << "  " << endl;
	Sleep(100);
	cout << "        /:::/____/      /" << logo << "    " << logo << "   /:::/   |::|   |/" << logo << "    " << logo << "   /:::/    /   " << logo << ":::" << logo << "    " << logo << "   /:::/" << logo << ":::" << logo << "   " << logo << ":::" << logo << "    " << logo << "   /:::/    /   " << logo << ":::" << logo << " ___" << logo << "   /:::/" << logo << ":::" << logo << "   " << logo << ":::" << logo << "    " << logo << " " << endl;
	Sleep(100);
	cout << "       |:::|    /      /::" << logo << "____" << logo << " /:: /    |::|   /::" << logo << "____" << logo << " /:::/____/     " << logo << ":::" << logo << "____" << logo << " /:::/__" << logo << ":::" << logo << "   " << logo << ":::" << logo << "____" << logo << " /:::/____/  ___" << logo << ":::|    | /:::/  " << logo << ":::" << logo << "   " << logo << ":::" << logo << "____" << logo << "" << endl;
	Sleep(100);
	cout << "       |:::|____" << logo << "     /:::/    / " << logo << "::/    /|::|  /:::/    / " << logo << ":::" << logo << "    " << logo << "      " << logo << "::/    / " << logo << ":::" << logo << "   " << logo << ":::" << logo << "   " << logo << "::/    / " << logo << ":::" << logo << "    " << logo << " /" << logo << "  /:::|____| " << logo << "::/    " << logo << ":::" << logo << "  /:::/    /" << endl;
	Sleep(100);
	cout << "        " << logo << ":::" << logo << "    " << logo << "   /:::/    /   " << logo << "/____/ |::| /:::/    /   " << logo << ":::" << logo << "    " << logo << "      " << logo << "/____/   " << logo << ":::" << logo << "   " << logo << ":::" << logo << "   " << logo << "/____/   " << logo << ":::" << logo << "    /::" << logo << " " << logo << "::/    /   " << logo << "/____/ " << logo << ":::" << logo << "/:::/    / " << endl;
	Sleep(100);
	Sleep(100);
	cout << "         " << logo << ":::" << logo << "    " << logo << " /:::/    /            |::|/:::/    /     " << logo << ":::" << logo << "    " << logo << "                " << logo << ":::" << logo << "   " << logo << ":::" << logo << "    " << logo << "        " << logo << ":::" << logo << "   " << logo << ":::" << logo << " " << logo << "/____/             " << logo << "::::::/    /  " << endl;
	Sleep(100);
	cout << "          " << logo << ":::" << logo << "    /:::/    /             |::::::/    /       " << logo << ":::" << logo << "    " << logo << "                " << logo << ":::" << logo << "   " << logo << ":::" << logo << "____" << logo << "        " << logo << ":::" << logo << "   " << logo << ":::" << logo << "____" << logo << "                " << logo << "::::/    /   " << endl;
	Sleep(100);
	cout << "           " << logo << ":::" << logo << "__/:::/    /              |:::::/    /         " << logo << ":::" << logo << "    " << logo << "                " << logo << ":::" << logo << "   " << logo << "::/    /         " << logo << ":::" << logo << "  /:::/    /                /:::/    /    " << endl;
	Sleep(100);
	cout << "            " << logo << "::::::::/    /               |::::/    /           " << logo << ":::" << logo << "    " << logo << "                " << logo << ":::" << logo << "   " << logo << "/____/           " << logo << ":::" << logo << "/:::/    /                /:::/    /     " << endl;
	Sleep(100);
	cout << "             " << logo << "::::::/    /                /:::/    /             " << logo << ":::" << logo << "    " << logo << "                " << logo << ":::" << logo << "    " << logo << "                " << logo << "::::::/    /                /:::/    /      " << endl;
	Sleep(100);
	cout << "              " << logo << "::::/    /                /:::/    /               " << logo << ":::" << logo << "____" << logo << "                " << logo << ":::" << logo << "____" << logo << "                " << logo << "::::/    /                /:::/    /       " << endl;
	Sleep(100);
	cout << "               " << logo << "::/____/                 " << logo << "::/    /                 " << logo << "::/    /                 " << logo << "::/    /                 " << logo << "::/____/                 " << logo << "::/    /        " << endl;
	Sleep(100);
	cout << "                                          " << logo << "/____/                   " << logo << "/____/                   " << logo << "/____/                                             " << logo << "/____/         " << endl << endl << endl;
	Sleep(1000);
	string intro = "                                                                             Uncertain Games";
	int x = 0;
	while (intro[x] != '\0')
	{
		if (intro[x] != ' ' && intro[x] != '\n')
		{
			cout << intro[x];
			Sleep(100);
		}
		else
			cout << intro[x];
		x++;
	};
	PlaySound("Sound/Production Logo.wav", NULL, SND_FILENAME);
	Sleep(500);
	system("CLS");
	Sleep(500);
	PlaySound("music/Title.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	cout << endl << endl << endl << endl;
	cout << "                	______________???    	LLLLLLLLLLL					" << endl;
	cout << "                	_____________?????   	L:::::::::L					" << endl;
	cout << "                	____________??___??  	L:::::::::L					" << endl;
	cout << "                	____________??___??  	LL:::::::LL					" << endl;
	cout << "                	____________??___??  	  L:::::L					" << endl;
	cout << "                	____________??___??  	  L:::::L					" << endl;
	cout << "                	____________??___??  	  L:::::L					" << endl;
	cout << "                	____________??__??   	  L:::::L					" << endl;
	cout << "                	____________??_??    	  L:::::L					" << endl;
	cout << "                	____________????     	  L:::::L					" << endl;
	cout << "                	____________???      	  L:::::L					" << endl;
	cout << "                	___________???       	  L:::::L         LLLLLL	" << endl;
	cout << "                	_________??_??       	LL:::::::LLLLLLLLL:::::L	" << endl;
	cout << "                	________??__??       	L::::::::::::::::::::::L	" << endl;
	cout << "                	_______??___??       	L::::::::::::::::::::::L	" << endl;
	cout << "                	______??____??       	LLLLLLLLLLLLLLLLLLLLLLLL	" << endl;
	cout << "                	_____??____????      							    Lubinsky Lentsch Productions" << endl;
	cout << "                	____??__?????????    	LLLLLLLLLLL					" << endl;
	cout << "                	___??__??___??___??  	L:::::::::L					" << endl;
	cout << "                	___??__??___??____?? 	L:::::::::L					" << endl;
	cout << "                	___??___??__??____?? 	LL:::::::LL					" << endl;
	cout << "                	___??_______??____?? 	  L:::::L					" << endl;
	cout << "                	____??______??___??  	  L:::::L					" << endl;
	cout << "                	______??____??__??   	  L:::::L					" << endl;
	cout << "                	________????????     	  L:::::L					" << endl;
	cout << "                	___________.????     	  L:::::L					" << endl;
	cout << "                	____________.??      	  L:::::L					" << endl;
	cout << "                	_____???___..??      	  L:::::L					" << endl;
	cout << "                	____?????__.??       	  L:::::L         LLLLLL	" << endl;
	cout << "                	____????___.??       	LL:::::::LLLLLLLLL:::::L	" << endl;
	cout << "                	____??_____..??      	L::::::::::::::::::::::L	" << endl;
	cout << "                	_____??____..??      	L::::::::::::::::::::::L	" << endl;
	cout << "                	_______?????         	LLLLLLLLLLLLLLLLLLLLLLLL	" << endl;
	Sleep(4000);
	system("CLS");
	cout << endl << endl << endl << endl;
	cout << "                XXXXXXX       XXXXXXX                      QQQQQQQQQ                                                                      tttt             " << endl;
	cout << "                X:::::X       X:::::X                    QQ:::::::::QQ                                                                 ttt:::t             " << endl;
	cout << "                X:::::X       X:::::X                  QQ:::::::::::::QQ                                                               t:::::t             " << endl;
	cout << "                X::::::X     X::::::X                 Q:::::::QQQ:::::::Q                                                              t:::::t             " << endl;
	cout << "                XXX:::::X   X:::::XXX                 Q::::::O   Q::::::Q uuuuuu    uuuuuu       eeeeeeeeeeee         ssssssssss    ttttttt:::::ttttttt    " << endl;
	cout << "                   X:::::X X:::::X                    Q:::::O     Q:::::Q u::::u    u::::u     ee::::::::::::ee     ss::::::::::s   t:::::::::::::::::t    " << endl;
	cout << "                    X:::::X:::::X                     Q:::::O     Q:::::Q u::::u    u::::u    e::::::eeeee:::::ee ss:::::::::::::s  t:::::::::::::::::t    " << endl;
	cout << "                     X:::::::::X      --------------- Q:::::O     Q:::::Q u::::u    u::::u   e::::::e     e:::::e s::::::ssss:::::s tttttt:::::::tttttt    " << endl;
	cout << "                     X:::::::::X      -:::::::::::::- Q:::::O     Q:::::Q u::::u    u::::u   e:::::::eeeee::::::e  s:::::s  ssssss        t:::::t          " << endl;
	cout << "                    X:::::X:::::X     --------------- Q:::::O     Q:::::Q u::::u    u::::u   e:::::::::::::::::e     s::::::s             t:::::t          " << endl;
	cout << "                   X:::::X X:::::X                    Q:::::O  QQQQ:::::Q u::::u    u::::u   e::::::eeeeeeeeeee         s::::::s          t:::::t          " << endl;
	cout << "                XXX:::::X   X:::::XXX                 Q::::::O Q::::::::Q u:::::uuuu:::::u   e:::::::e            ssssss   s:::::s        t:::::t    tttttt" << endl;
	cout << "                X::::::X     X::::::X                 Q:::::::QQ::::::::Q u:::::::::::::::uu e::::::::e           s:::::ssss::::::s       t::::::tttt:::::t" << endl;
	cout << "                X:::::X       X:::::X                  QQ::::::::::::::Q   u:::::::::::::::u  e::::::::eeeeeeee   s::::::::::::::s        tt::::::::::::::t" << endl;
	cout << "                X:::::X       X:::::X                    QQ:::::::::::Q     uu::::::::uu:::u   ee:::::::::::::e    s:::::::::::ss           tt:::::::::::tt" << endl;
	cout << "                XXXXXXX       XXXXXXX                      QQQQQQQQ::::QQ     uuuuuuuu  uuuu     eeeeeeeeeeeeee     sssssssssss               ttttttttttt  " << endl;
	cout << "                                                                   Q:::::Q                                                                                 " << endl;
	cout << "                                                                    QQQQQQ                                                                                 " << endl << endl << endl << endl << endl;
	Sleep(4000);
	cout << "                                                                        Press enter to start";
	cin.ignore();
	system("CLS");
}

//Function to create main menu
bool Title::startMenu()
{
	startMenuDraw:
	cout << endl << endl << endl << endl;
	cout << "                XXXXXXX       XXXXXXX                      QQQQQQQQQ                                                                      tttt             " << endl;
	cout << "                X:::::X       X:::::X                    QQ:::::::::QQ                                                                 ttt:::t             " << endl;
	cout << "                X:::::X       X:::::X                  QQ:::::::::::::QQ                                                               t:::::t             " << endl;
	cout << "                X::::::X     X::::::X                 Q:::::::QQQ:::::::Q                                                              t:::::t             " << endl;
	cout << "                XXX:::::X   X:::::XXX                 Q::::::O   Q::::::Q uuuuuu    uuuuuu       eeeeeeeeeeee         ssssssssss    ttttttt:::::ttttttt    " << endl;
	cout << "                   X:::::X X:::::X                    Q:::::O     Q:::::Q u::::u    u::::u     ee::::::::::::ee     ss::::::::::s   t:::::::::::::::::t    " << endl;
	cout << "                    X:::::X:::::X                     Q:::::O     Q:::::Q u::::u    u::::u    e::::::eeeee:::::ee ss:::::::::::::s  t:::::::::::::::::t    " << endl;
	cout << "                     X:::::::::X      --------------- Q:::::O     Q:::::Q u::::u    u::::u   e::::::e     e:::::e s::::::ssss:::::s tttttt:::::::tttttt    " << endl;
	cout << "                     X:::::::::X      -:::::::::::::- Q:::::O     Q:::::Q u::::u    u::::u   e:::::::eeeee::::::e  s:::::s  ssssss        t:::::t          " << endl;
	cout << "                    X:::::X:::::X     --------------- Q:::::O     Q:::::Q u::::u    u::::u   e:::::::::::::::::e     s::::::s             t:::::t          " << endl;
	cout << "                   X:::::X X:::::X                    Q:::::O  QQQQ:::::Q u::::u    u::::u   e::::::eeeeeeeeeee         s::::::s          t:::::t          " << endl;
	cout << "                XXX:::::X   X:::::XXX                 Q::::::O Q::::::::Q u:::::uuuu:::::u   e:::::::e            ssssss   s:::::s        t:::::t    tttttt" << endl;
	cout << "                X::::::X     X::::::X                 Q:::::::QQ::::::::Q u:::::::::::::::uu e::::::::e           s:::::ssss::::::s       t::::::tttt:::::t" << endl;
	cout << "                X:::::X       X:::::X                  QQ::::::::::::::Q   u:::::::::::::::u  e::::::::eeeeeeee   s::::::::::::::s        tt::::::::::::::t" << endl;
	cout << "                X:::::X       X:::::X                    QQ:::::::::::Q     uu::::::::uu:::u   ee:::::::::::::e    s:::::::::::ss           tt:::::::::::tt" << endl;
	cout << "                XXXXXXX       XXXXXXX                      QQQQQQQQ::::QQ     uuuuuuuu  uuuu     eeeeeeeeeeeeee     sssssssssss               ttttttttttt  " << endl;
	cout << "                                                                   Q:::::Q                                                                                 " << endl;
	cout << "                                                                    QQQQQQ                                                                                 " << endl << endl << endl << endl << endl;
	Sleep(500);
	cout << "                                                                           1) -New Game" << endl << endl << endl;
	cout << "                                                                           2) -Options" << endl << endl << endl;
	cout << "                                                                           3) -Exit" << endl << endl;
	int newGame = 0;
	do
	{
		int ch = _getch();
		switch (ch)
		{
		case Globals::KEY_1:
			newGame = 1;
			break;
		case Globals::KEY_2:
			system("CLS");
			options();
			system("CLS");
			goto startMenuDraw;
			break;
		case Globals::KEY_3:
			newGame = 0;
			return (0);
			break;
		}

	} while (newGame != 1);
	system("CLS");
	return (1);
}

//Function to create options menu
void Title::options()
{
	cout << endl << endl << endl << "                                                                           Options" << endl << endl << endl;
	cout << "Here you can set the game resolution:" << endl << endl;
	cout << "1) 1024x768" << endl << "2) 1280x720" << endl << "3) 1600x900" << endl << "4) 1920x1080" << endl;
	HWND consoleWindow = GetConsoleWindow();
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof cfi;
	SMALL_RECT WinRect;
	int ch = _getch();
	switch (ch)
	{
	case Globals::KEY_1:
		system("MODE 168, 58");
		WinRect = { 0, 0, 168, 58 };
		cfi.dwFontSize.X = 6;
		cfi.dwFontSize.Y = 12;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, L"Consolas");
		break;
	case Globals::KEY_2:
		system("MODE 180,46");
		WinRect = { 0, 0, 180, 46 };
		cfi.dwFontSize.X = 7;
		cfi.dwFontSize.Y = 14;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, L"Consolas");
		break;
	case Globals::KEY_3:
		system("MODE 176,41");
		WinRect = { 0, 0, 176, 41 };
		cfi.dwFontSize.X = 9;
		cfi.dwFontSize.Y = 20;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, L"Consolas");
		break;
	case Globals::KEY_4:
		system("MODE 173,42");
		WinRect = { 0, 0, 173, 42 };
		cfi.dwFontSize.X = 11;
		cfi.dwFontSize.Y = 24;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		wcscpy_s(cfi.FaceName, L"Consolas");
		break;
	}
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	SMALL_RECT* WinSize = &WinRect;
	SetWindowPos(consoleWindow, 0, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}