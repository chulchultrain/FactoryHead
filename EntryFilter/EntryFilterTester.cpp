#include <EntryFilter/EntryFilter.h>
#include <MapGenerator/MapGenerator.h>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;


/*
	Only setting a few and setting all.
	1 Move
	4 Move

	1 Type
	2 Type

	Name

	
*/



void EntryFilterUnitTest() {
	EntryFilter ef;
	
	//Entry 195
	ef.SetNameFilter("Rhydon");
	vector<string> res;
	ef.Evaluate(res);
	ef.SetMoveFilter(0,"Thunder Punch");
	ef.Evaluate(res);
	assert(res.size() == 1 && res[0] == "195");

	ef.ResetAllFilters();

	//All Magnezone Entries
	ef.SetNameFilter("Magnezone");
	vector <string> magnezone;
	magnezone.push_back("869");
	magnezone.push_back("870");
	magnezone.push_back("871");
	magnezone.push_back("872");
	ef.Evaluate(res);
	assert(res == magnezone);

	ef.ResetAllFilters();
	ef.SetNameFilter("Swampert");
	ef.SetTypeFilter(0,"Water");
	ef.SetTypeFilter(1,"Ground");
	ef.SetMoveFilter(0,"Earthquake");
	ef.SetMoveFilter(1,"Curse");
	ef.SetMoveFilter(2,"Hammer Arm");
	ef.SetMoveFilter(3,"Aqua Tail");
	ef.Evaluate(res);
	assert(res.size() == 1 && res[0] == "498");

	ef.ResetAllFilters();
	
	ef.SetTypeFilter(0,"Fire");
	ef.SetTypeFilter(1,"Flying");
	ef.Evaluate(res);
	//cout << res.size() << endl;
	assert(res.size() == 8);

	ef.ResetAllFilters();
	ef.SetMoveFilter(0,"Energy Ball");
	ef.SetMoveFilter(1,"Focus Blast");
	ef.Evaluate(res);
	//cout << res.size() << endl;
	assert(res.size() == 5);
}




map<string,string> dexIdToName;
map<string,MoveData> moveIdToMoveData;
map<string, EntryData> eIDToED;

void InitMaps() {
	MapGenerator mg;
	mg.DexIDToNameMap(dexIdToName);
	mg.MoveIDToMoveDataMap(moveIdToMoveData);
	mg.EntryIDToEntryDataMap(eIDToED);
}

/*
	string ID;
	string DexID;
	vector<string> moveID;
	string item;
	string nature;
	vector<int> EV;
*/
/*
Name:

Type:


Moves:

*/
string PITS(int x) {
	if(x == 0)
		return "0";
	string res = "";
	while(x > 0) {
		int dig = x % 10;
		char c = '0' + dig;
		res = c + res;
		x /= 10;
	}
	return res;
}

string TranslateEntryData(EntryData &ed) {
	string res = "";
	res += (dexIdToName[ed.DexID] + "\n");
	for(int i = 0; i < 6; i++) 
		res += ("HP EV: " + PITS(ed.EV[i]) + "\n");
	res += (ed.item + "\n");
	res += (ed.nature + "\n");
	for(int i = 0; i < 4; i++) 
		res += (moveIdToMoveData[ed.moveID[i]].name + "\n");

	return res;	
}

void ProcessFile(ifstream &fin, vector<string> &res) {
	res.clear();
	EntryFilter ef;
	string temp;
	string lastTagSeen = "";
	int counter = 0;
	while(getline(fin,temp)) {
		if(lastTagSeen == "") {
			if(temp == "Name:" || temp == "Type:" || temp == "Moves:")
				lastTagSeen = temp;
		} else {
			if(temp == "Name:" || temp == "Type:" || temp == "Moves:") {
				lastTagSeen = temp;
				counter = 0;
			}
			else {
				if(lastTagSeen == "Name:") {
					ef.SetNameFilter(temp);
				} else if(lastTagSeen == "Type:") {
					ef.SetTypeFilter(counter,temp);
					counter++;
				} else {
					ef.SetMoveFilter(counter,temp);
					counter++;
				}
			}
		}
	}
	vector<string> efres;
	ef.Evaluate(efres);
	int rsz = efres.size();
	for(int i = 0; i < rsz; i++) {
		res.push_back(TranslateEntryData(eIDToED[efres[i]]));
	}
}

int main() {
	InitMaps();
	ifstream fin("inputfile.txt");
	vector<string> res;
	ProcessFile(fin,res);
	int rsz = res.size();
	for(int i = 0; i < rsz; i++) {
		cout << res[i] << '\n';
	}
	return 0;
}
