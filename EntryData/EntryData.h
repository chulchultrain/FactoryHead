#ifndef __ENTRYDATA_H_INCLUDED__
#define __ENTRYDATA_H_INCLUDED__

#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

struct EntryData {
	string ID;
	string DexID;
	vector<string> moveID;
	string nature;
	vector<int> EV;
	EntryData(string x1, string x2, vector<string> &x3, string x4, vector<int> &x5);
	EntryData();
};

bool operator == (const EntryData &lhs, const EntryData &rhs);


#endif
