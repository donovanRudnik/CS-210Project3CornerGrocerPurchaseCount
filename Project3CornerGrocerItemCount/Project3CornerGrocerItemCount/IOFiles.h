#ifndef IOFiles_H
#define IOFiles_H

#include <map>
#include <string>
using namespace std;

class IOFiles {
	public:
		int MapToOutputFile();
		void PrintItemCountPair(string& itemName);
		IOFiles();

	private:
		map<string, int> itemCountPairs;
		int InputFileToMap();

};

#endif

