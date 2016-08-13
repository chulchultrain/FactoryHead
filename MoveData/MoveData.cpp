#include <MoveData/MoveData.h>

MoveData::MoveData(string x1, string x2, string x3, string x4, int x5) {
	ID = x1;
	name = x2;
	type = x3;
	category = x4;
	damage = x5;
}

MoveData::MoveData() {
	ID = "";
	name = "";
	type = "";
	category = "";
	damage = 0;
}

bool operator == (const MoveData &lhs, const MoveData &rhs) {
	if(lhs.ID != rhs.ID) {
		//cout << "FAIL HERE\n";
		return false;

	}
	if(lhs.name != rhs.name) {
		//cout << "FAIL HERE 2\n";
		return false;
	}
	if(lhs.type != rhs.type){
		//cout << "FAIL HERE 3\n";
		return false;
	}
	if(lhs.category != rhs.category){
		//cout << "FAIL HERE 4\n";
		return false;
	}
	if(lhs.damage != rhs.damage){
		//cout << "FAIL HERE 5\n";
		return false;
	}
	return true;
//	return lhs.ID == rhs.ID && lhs.name == rhs.name && lhs.type == rhs.type && lhs.category == rhs.category && lhs.damage == rhs.damage;
}
