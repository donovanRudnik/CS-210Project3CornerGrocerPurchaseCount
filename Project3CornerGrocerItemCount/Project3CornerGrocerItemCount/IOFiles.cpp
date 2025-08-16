#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

#include "IOFiles.h"


int IOFiles::InputFileToMap() {
	ifstream inFS;
	string itemName;
	int itemFrequency;
	
	cout << "Opening CornerGrocerItemRecord.txt" << endl;

	inFS.open("CornerGrocerItemRecord.txt");

	// TODO: WHEN USED, ADD CHECK FOR RETURN VALUE TO HANDLE ERROR
	if (!inFS.is_open()) {
		cout << "Could not open CornerGrocerItemRecord.txt" << endl;
		return 1;
	}

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

int IOFiles::MapToOutputFile() {
	string key;
	ofstream outFS;

	outFS.open("frequency.dat");

	if (!outFS.is_open()) {
		cout << "frequency.dat could not be opened" << endl;
		return 1;
	}

	for (auto itemCount : this->itemCountPairs) {
		outFS << itemCount.first << " " << itemCount.second << endl;
	}

	return 0;
}

IOFiles::IOFiles() {
	this->itemCountPairs = {};
	InputFileToMap();
	MapToOutputFile();
}

void IOFiles::PrintItemCountPair(string& itemName) {
	if (this->itemCountPairs.count(itemName) == 0) {
		cout << "Item not present. Enter a different item name:" << endl;
		getline(cin, itemName);
		PrintItemCountPair(itemName);
	}
	else {
		cout << itemName << " " << this->itemCountPairs.at(itemName) << endl << endl;
	}

}
