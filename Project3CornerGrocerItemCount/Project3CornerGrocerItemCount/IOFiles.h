#ifndef IOFiles_H
#define IOFiles_H

#include <map>
#include <string>
using namespace std;

class IOFiles {
	public:
		void PrintItemCountAlone(string& itemName);
		map<string, int> GetMap() { return this->itemCountPairs; }
		int InputFileToMap(string fileName);
		IOFiles();

	private:
		map<string, int> itemCountPairs;
		int FrequencyFileToMap();
		int MapToOutputFile();
};

#endif

