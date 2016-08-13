#ifndef __MOVEDATA_H_INCLUDED__
#define __MOVEDATA_H_INCLUDED__

#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

struct MoveData {
	string ID;
	string name;
	string type;
	string category;
	int damage;
	MoveData(string x1, string x2, string x3, string x4, int x5);
	MoveData();
};

bool operator == (const MoveData &lhs, const MoveData &rhs);

#endif
