#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "IOFiles.h"

int IOFiles::FrequencyFileToMap(){
	ifstream inFS;
	string itemName;
	int itemFrequency;

	cout << "Opening frequency.dat" << endl;

	inFS.open("frequency.dat");

	if (!inFS.is_open()) {
		cout << "Could not open frequency.dat" << endl;
		return 1;
	}

	while (!inFS.fail()) {
		inFS >> itemName;
		inFS >> itemFrequency;
		if (this->itemCountPairs.count(itemName) == 0) {
			this->itemCountPairs.emplace(itemName, itemFrequency);
		}
		else {
			this->itemCountPairs.at(itemName) += itemFrequency;
		}
	}

	if (!inFS.eof()) {
		cout << "Failed to reach end of frequency.dat" << endl;
		return 1;
	}

	cout << "Closing frequency.dat" << endl;

	inFS.close();
	return 0;
}

// Opens a text file containing a list of produce items. Adds each item to a map
// with keys representing item names and values representing how often the item appears.
int IOFiles::InputFileToMap(string fileName) {
	ifstream inFS;
	string itemName;
	int itemFrequency;
	
	cout << "Opening CornerGrocerItemRecord.txt" << endl;

	inFS.open("CornerGrocerItemRecord.txt");

	
	if (!inFS.is_open()) {
		cout << "Could not open CornerGrocerItemRecord.txt" << endl;
		return 1;
	}

	// Loop until the end of file is reached or input fails.
	// If item name is already present, increment the value in the map, otherwise create a new key-value pair.
	while (!inFS.fail()) {
		inFS >> itemName;
		if (this->itemCountPairs.count(itemName) == 0) {
			this->itemCountPairs.emplace(itemName, 1);
		}
		else {
			this->itemCountPairs.at(itemName) += 1;
		}
	}

	if (!inFS.eof()) {
		cout << "Failed to reach end of CornerGrocerItemRecord.txt" << endl;
		return 1;
	}

	cout << "Closing CornerGrocerItemRecord.txt" << endl;

	inFS.close();
	return 0;
}

// Converts the contents of a map containing item names and their frequency to a frequency.dat file.
int IOFiles::MapToOutputFile() {
	string key;
	ofstream outFS;

	outFS.open("frequency.dat");
	cout << "Opening frequency.dat" << endl;
	if (!outFS.is_open()) {
		cout << "frequency.dat could not be opened" << endl;
		return 1;
	}

	// Loops through each item in the map. Outputs the key and value to the frequency.dat file.
	for (auto itemCount : this->itemCountPairs) {
		outFS << itemCount.first << " " << itemCount.second << endl;
	}

	outFS.close();
	cout << "Closing frequency.dat" << endl;
	return 0;
}

// Constructor for IOFiles object. When object is created creates the map, fills it with items from
// the .txt file, and then outputs the map information to the .dat file.
IOFiles::IOFiles() {
	this->itemCountPairs = {};
	FrequencyFileToMap();
}

// For the first menu option, easier to access the map from this class.
// Checks if the input begins with an alphabet character and loops until an item
// present in the map is input or terminates if q is input.
void IOFiles::PrintItemCountAlone(string& itemName) {
	if (isalpha(itemName.at(0))) {
		itemName[0] = toupper(itemName[0]);
	}
	
	while (itemName != "Q") {
		if (this->itemCountPairs.count(itemName) == 0) {
			cout << "Item not present. Enter a different item name or Q/q to return to menu:" << endl;
			getline(cin, itemName);
			PrintItemCountAlone(itemName);
		}
		else {
			cout << endl << this->itemCountPairs.at(itemName) << endl << endl;
			itemName = "Q";
		}
	}
}
