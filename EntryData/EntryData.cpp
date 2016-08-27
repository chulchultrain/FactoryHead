#include <EntryData/EntryData.h>

EntryData::EntryData(string x1, string x2, vector<string> &x3, string x4, string x5, vector<int> &x6) {
	ID = x1;
	DexID = x2;
	moveID = x3;
	item = x4;
	nature = x5;
	EV = x6;
}

EntryData::EntryData() {
	ID = "";
	DexID = "";
	moveID.resize(4,"");
	nature = "";
	item = "";
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

	if(lhs.item != rhs.item) {
		return false;
	}	

	if(lhs.EV != rhs.EV) {
	//	cout << "FAIL HERE5\n";
		return false;
	}
	return true;
}

