#include <iostream>
#include <iomanip>
using namespace std;

#include "UserMenu.h"

UserMenu::UserMenu() {
	this->menuSelection = "0";
}

void UserMenu::PrintMenu() {
	cout << setw(50) << setfill('-') << "" << endl;
	cout << setw(38) << " Corner Grocer Item Frequency " << setw(10) << "" << setfill(' ') << endl;
	cout << setw(40) << setfill('-') << "" << setfill(' ') << endl << endl;

	cout << "| 1: Search for item and display amount ordered.             |" << endl;
	cout << "| 2: Display list of items and order frequency.              |" << endl;
	cout << "| 3: Display list of items and order frequency as histogram. |" << endl;
	cout << "| 4: Exit program.                                           |\n" << endl;

	getline(cin, this->menuSelection);
	InputValidation(this->menuSelection);
	return;
}

void UserMenu::InputValidation(string& userInput) {
	if (isalpha(userInput.at(0))) {
		cout << "Enter an option from the menu." << endl;
		PrintMenu();
	}
	return;
}

void UserMenu::UserInputItemFreq() {
	string userInput;

	cout << "Enter the name of an item: " << endl;
	getline(cin, userInput);

	
}

void UserMenu::PrintItemCountList(map<string, int>& itemCounts) {

}

void UserMenu::PrintItemCountHist(map<string, int>& itemCounts) {

}

void UserMenu::MenuFunctions() {
	
}


