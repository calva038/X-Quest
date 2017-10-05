// Final.txt
// Christian Alvarado
// CISP 400
// Spring 2016

//Header for the game's dialogue system
#ifndef DIALOGUE_H
#define DIALOGUE_H

#include <string>
class Dialogue
{
public:
	static std::string dialogue1a, dialogue2a, dialogue3a, dialogue4a; //Used to display each dialogue option
	static const char *dialogue1;
	static const char *dialogue2;
	static const char *dialogue3;
	static const char *dialogue4;
	static int choice1, choice2;
	static int dialogueInt(const char* dialogueOption1, const char* dialogueOption2, const char* dialogueOption3, const char* dialogueOption4, std::string dialogue1a, std::string dialogue2a, std::string dialogue3a, std::string dialogue4a, int choice1, int choice2); //1.14
	static int dialogueSys(int choice1, const char* dialogue1, const char* dialogue2, const char* dialogue3, const char* dialogue4); //1.14.1
private:
};
#endif