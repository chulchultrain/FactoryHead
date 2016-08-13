#include <EntryData/EntryData.h>

EntryData::EntryData(string x1, string x2, vector<string> &x3, string x4, vector<int> &x5) {
	ID = x1;
	DexID = x2;
	moveID = x3;
	nature = x4;
	EV = x5;
}

EntryData::EntryData() {
	ID = "";
	DexID = "";
	moveID.resize(4,"");
	nature = "";
	EV.resize(6,0);
}

bool operator == (const EntryData &lhs, const EntryData &rhs) {
	if(lhs.ID != rhs.ID) {
	//	cout << "FAIL HERE\n";
		return false;

	}
	if(lhs.DexID != rhs.DexID) {
	//	cout << "FAIL HERE2\n";
		return false;
	}	
	if(lhs.moveID != rhs.moveID) {
	///	cout << "FAIL HERE3\n";
		return false;
	}
	if(lhs.nature != rhs.nature) {
	//	cout << "FAIL HERE4\n";
		return false;
	}
	if(lhs.EV != rhs.EV) {
	//	cout << "FAIL HERE5\n";
		return false;
	}
	return true;
}

