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
		int GetMenuNumSelection() { return menuNumSelection; }
		UserMenu();

	private:
		string menuSelection;
		int menuNumSelection;
		IOFiles IOMapAccess;
		map<string, int> itemMap = IOMapAccess.GetMap();
		void InputValidation(string& userInput);
		void UserInputItemFreq();
		void PrintItemCountList();
		void PrintItemCountHist();

};

#endif

