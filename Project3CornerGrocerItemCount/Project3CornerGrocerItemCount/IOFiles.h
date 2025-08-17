#ifndef IOFiles_H
#define IOFiles_H

#include <map>
#include <string>
using namespace std;

class IOFiles {
	public:
		int MapToOutputFile();
		void PrintItemCountAlone(string& itemName);
		map<string, int> GetMap() { return this->itemCountPairs; }
		IOFiles();

	private:
		map<string, int> itemCountPairs;
		int InputFileToMap();

};

#endif

