#ifndef UserMenu_H
#define UserMenu_H

#include <map>
#include <fstream>
#include <string>
using namespace std;

#include "IOFiles.h"

class UserMenu {
	public:
		void PrintMenu();
		void MenuFunctions();
		UserMenu();

	private:
		string menuSelection;
		IOFiles itemMap;
		void InputValidation(string& userInput);
		void UserInputItemFreq();
		void PrintItemCountList(map<string, int>& itemCounts);
		void PrintItemCountHist(map<string, int>& itemCounts);

};

#endif

