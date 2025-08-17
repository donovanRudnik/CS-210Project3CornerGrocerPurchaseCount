#include <iostream>
#include <iomanip>
using namespace std;

#include "UserMenu.h"

UserMenu::UserMenu() {
	this->menuSelection = "0";
	this->menuNumSelection = 0;
}


//Display menu that provides options for user and prompt for input.
void UserMenu::PrintMenu() {
	cout << setw(50) << setfill('-') << "" << endl;
	cout << setw(38) << " Corner Grocer Item Frequency " << setw(10) << "" << setfill(' ') << endl;
	cout << setw(40) << setfill('-') << "" << setfill(' ') << endl << endl;

	cout << "| 1: Search for item and display amount ordered.             |" << endl;
	cout << "| 2: Display list of items and order frequency.              |" << endl;
	cout << "| 3: Display list of items and order frequency as histogram. |" << endl;
	cout << "| 4: Exit program.                                           |\n" << endl;

	cout << "Select an option (1-4)" << endl;

	// Accept user input as string for easier input validation.
	getline(cin, this->menuSelection);
	InputValidation(this->menuSelection);
	return;
}

// Check that user input a valid value. If input is an alphabet character or outside of the range of options,
// run the print menu function again. Input saved as object member for easier access.
void UserMenu::InputValidation(string& userInput) {
	if (isalpha(userInput.at(0))) {
		cout << "Enter an option from the menu." << endl;
		PrintMenu();
	}
	else if (isdigit(userInput.at(0))) {
		userInput = userInput.at(0);
		this->menuNumSelection = stoi(userInput);

		if (this->menuNumSelection < 1 || this->menuNumSelection > 4) {
			cout << "Enter an option from the menu." << endl;
			PrintMenu();
		}
	}
	return;
}

// Prompt user to enter name of an item. Call IOFiles method to print frequency if name is in the itemCountPairs map.
void UserMenu::UserInputItemFreq() {
	string userInput;

	cout << "Enter the name of an item: " << endl;
	getline(cin, userInput);

	IOMapAccess.PrintItemCountAlone(userInput);
}

// Display a list of each item name followed by how many times it appears in the original input file
void UserMenu::PrintItemCountList() {
	cout << setw(50) << setfill('=') << "" << setfill(' ') << endl;
	cout << setw(40) << setfill('-') << " List of Items and Number Sold " << setw(10) << "" << setfill(' ') << endl;
	cout << setw(50) << setfill('=') << "" << setfill(' ') << endl;
	cout << setw(25) << left << "ITEM NAME" << setw(25) << left << "NUMBER SOLD" << endl;

	// Iterate through each item in the map to display the item name and its frequency.
	for (auto item : itemMap) {
		cout << setw(25) << left << item.first << setw(25) << left << item.second << endl;
	}

	cout << setw(50) << setfill('=') << "" << setfill(' ') << endl << endl;
}

// Display a list of every item present in the original input file.
// Each name has a histogram bar representing how often that item appeared.
void UserMenu::PrintItemCountHist() {
	cout << setw(50) << setfill('=') << "" << setfill(' ') << endl;
	cout << setw(43) << setfill('-') << " Histogram of Items and Number Sold " << setw(7) << "" << setfill(' ') << endl;
	cout << setw(50) << setfill('=') << "" << setfill(' ') << endl << endl;
	
	// For every item in the itemMap, display the item name and bar representing its frequency.
	for (auto item : itemMap) {
		int itemCount = item.second;

		cout << setw(25) << left << item.first << setw(itemCount) << setfill('*') << left << "" << setfill(' ') << endl;
	}
}

// Switch with each case representing a menu option. Runs the function that matches each menu option.
void UserMenu::MenuFunctions() {
	switch (this->menuNumSelection) {
	case 1:
		UserInputItemFreq();
		break;
	case 2:
		PrintItemCountList();
		break;
	case 3:
		PrintItemCountHist();
		break;
	}
}


