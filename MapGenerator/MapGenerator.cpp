#include <MapGenerator/MapGenerator.h>


#ifndef NAMESFILE
#define NAMESFILE "BASE/NAME/Names.txt"
#endif

#ifndef TYPESFILE
#define TYPESFILE "BASE/TYPE/Types.txt"
#endif

#ifndef ENTRYFILE
#define ENTRYFILE "BASE/ENTRY/EntryData.txt"
#endif

#ifndef MOVESFILE
#define MOVESFILE "BASE/MOVE/MoveData.txt"
#endif

#ifndef STATSFILE
#define STATSFILE "BASE/STATS/BaseStats.txt"
#endif


#include <fstream>
#include <iostream>
#include <sstream>

/*
	Will fill the map with Name To DexID.
	Open Name and DexID file.
	Retrieve all Name-DexID pairs and insert into map as go through the file.

*/

bool operator == (const BaseStats &lhs, const BaseStats &rhs) {
	int n = memcmp(&lhs,&rhs,sizeof(BaseStats));
	return n == 0;
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

	string ID;
	string DexID;
	vector<string> moveID;
	string nature;
	vector<int> EV;
bool operator == (const EntryData &lhs, const EntryData &rhs) {
	if(lhs.ID != rhs.ID) {
		cout << "FAIL HERE\n";
		return false;

	}
	if(lhs.DexID != rhs.DexID) {
		cout << "FAIL HERE2\n";
		return false;
	}	
	if(lhs.moveID != rhs.moveID) {
		cout << "FAIL HERE3\n";
		return false;
	}
	if(lhs.nature != rhs.nature) {
		cout << "FAIL HERE4\n";
		return false;
	}
	if(lhs.EV != rhs.EV) {
		cout << "FAIL HERE5\n";
		return false;
	}
	return true;
}


void MapGenerator::NameToDexIDMap(map<string,string> &m) {
	m.clear();
	ifstream fin(NAMESFILE);
	string name;
	string DexID,discard;
	//int i = 0;
	while(getline(fin,DexID) ) {
		getline(fin,name);
		m[name] = DexID;
		//cout << name << ' ' << DexID << '\n';
		//i++;
		getline(fin,discard);
	}
	//cout << i << endl;
	fin.close();
	//cout << "Finished NDIDM\n";
	

}


void MapGenerator::TypeToDexIDVectorMap(map<string,vector<string> > &m) {
	m.clear();
	ifstream fin(TYPESFILE);
	string type;
	string DexID;
	int numTypes;
	while(fin >> DexID) {
		fin >> numTypes;
		for(int i = 0; i < numTypes; i++) {
			fin >> type;
			m[type].push_back(DexID);
		}		
	}
	fin.close();
}
		/*
			@param m - the map to fill.
			m will be a map whose keys are the DexIDs of the Pokemon.
			the values will be the names of those pokemon.
		*/

void MapGenerator::DexIDToNameMap(map<string,string> &m) {
	m.clear();
	ifstream fin(NAMESFILE);
	string name;
	string DexID,discard;
	while(getline(fin,DexID) ) {
		getline(fin,name);
		m[DexID] = name;
		getline(fin,discard);
	}
	fin.close();
	
}

		/*
			@param m - the map to fill.
			m will be a map whose keys are the DexIDs of the Pokemon.
			The Values will be a vector containing the types of that Pokemon.
		*/

void MapGenerator::DexIDToTypeVectorMap(map<string,vector<string> > &m) {
	m.clear();
	ifstream fin(TYPESFILE);
	string type;
	string DexID;
	int numTypes;
	while(fin >> DexID) {
		fin >> numTypes;
		for(int i = 0; i < numTypes; i++) {
			fin >> type;
			m[DexID].push_back(type);
		}		
	}
	fin.close();	
}

		/*
			@param m - the map to fill.
			m will be a map whose keys are the DexIDs of the Pokemon.
			The values will be the Factory Entry IDs of the Factory Entries that
			have that DexID.
		*/

void MapGenerator::DexIDToEntryIDVectorMap(map<string,vector<string> > &m) {
	m.clear();
	ifstream fin(ENTRYFILE);
	string DexID;
	string EntryID;
	string discard;
	//int i = 0;
	while(getline(fin,EntryID) ) {
		getline(fin,DexID);
		getline(fin,discard);
		//cout << i++ << endl;
		while(discard != "")
			getline(fin,discard);
		m[DexID].push_back(EntryID);
	}
	fin.close();
}

		/*
			@param m - the map to be filled
			m will be a map whose keys are the Names of moves in Pokemon.
			the values will be the IDs of those moves.
		*/

void MapGenerator::TypeToEntryIDVectorMap(map<string, vector<string> > &m) {
	map <string,vector<string> > dtt;
	//map <string, vector<string> > dte;

	DexIDToTypeVectorMap(dtt);


	m.clear();
	ifstream fin(ENTRYFILE);
	string DexID;
	string EntryID;
	string discard;	
	while(getline(fin,EntryID) ) {
		getline(fin,DexID);
		getline(fin,discard);
		while(discard != "")
			getline(fin,discard);
		vector<string> &types = dtt[DexID];
		for(unsigned int i = 0; i < types.size(); i++) {
			m[types[i]].push_back(EntryID);
		}
		m[DexID].push_back(EntryID);
	}
	fin.close();
}



		/*
			@param m - the map to be filled.
			m will be a map whose keys are the MoveIDs of moves.
			the values will be the EntryIDs of Factory entries who
			have the move indicated by the MoveID key.	
		*/
void MapGenerator::MoveIDtoEntryIDVectorMap(map<string, vector<string> > &m) {
	m.clear();
	ifstream fin(ENTRYFILE);
	string DexID;
	string EntryID;
	string discard;	
	string move;
	while(getline(fin,EntryID) ) {
		getline(fin,DexID);
		for(unsigned int i = 0; i < 4; i++) {
			getline(fin,move);
			m[move].push_back(EntryID);
		}
	}	
	fin.close();
}


		/*
			@param m - the map to be filled
			m will be a map whose keys are the Names of moves in Pokemon.
			the values will be the IDs of those moves.
		*/
	
void MapGenerator::MoveNameToMoveIDMap(map <string, string> &m) {
	m.clear();
	ifstream fin(MOVESFILE);
	string MoveID;
	string moveName;
	string discard;
	while(getline(fin,MoveID) ) {
		getline(fin,moveName);
		getline(fin,discard);
		while(discard != "") {
			getline(fin,discard);
		}
		m[moveName] = MoveID;
	}
	fin.close();
}

		/*
			@param m - the map to be filled
			m will be a map whose keys are the DexIDs of Pokemon.
			The values will be BaseStats structures
		*/

void MapGenerator::DexIDToBaseStatsMap(map <string, BaseStats> &m) {
	m.clear();
	ifstream fin(STATSFILE);
	string DexID;
	int s[6];
	while(fin >> DexID) {
		for(int i = 0; i < 6; i++)
			fin >> s[i];
		BaseStats b(s[0],s[1],s[2],s[3],s[4],s[5]);
		m[DexID] = b;
	}
	fin.close();
	
}



		/*
			@param m - the map to be filled.
			m will be a map whose keys are the MoveIDs of moves.
			The values will be MoveData structures
		*/



void MapGenerator::MoveIDToMoveDataMap(map <string, MoveData> &m) {
	m.clear();
	ifstream fin(MOVESFILE);
	string moveID;
	string moveName;
	string moveType;
	string moveCat;
	string damageStr;
	string discard;
	int damage;
	while(getline(fin,moveID)) {
		getline(fin,moveName);
		getline(fin,moveType);
		getline(fin,moveCat);
		fin >> damage;
		getline(fin,discard);
		getline(fin,discard);
		MoveData md(moveID,moveName,moveType,moveCat,damage);
		m[moveID] = md; 
		//if(moveID < "100")
		//cout << moveID << ' ' << moveName << ' ' << moveType << ' ' << moveCat << ' ' << damage << endl;
	}
	fin.close();
}

		/*
			@param m - the map to be filled
			m will be a map whose keys are the EntryIDs of Factory Entries
			The values will be EntryData Structures
		*/

void MapGenerator::EntryIDToEntryDataMap(map <string, EntryData> &m) {
	m.clear();
	map<string,int> stat;
	ifstream fin(ENTRYFILE);
	stat["HP"] = 0;
	stat["A"] = 1;
	stat["D"] = 2;
	stat["SA"] = 3;
	stat["SD"] = 4;
	stat["S"] = 5;
	string entryID;
	string DexID;
	string discard;
	string nature;
	string whichEV;
	int amtEV;
	int numEV;
	vector<string> moveID(4);
	vector<int> EV(6,0);
	while(fin >> entryID) {
		fin >> DexID;
		for(int i = 0; i < 4; i++) {
			fin >> moveID[i];
		}
		getline(fin,discard);
		getline(fin,discard);
		getline(fin,nature);
		fin >> numEV;
		for(int i = 0; i < numEV; i++) {
			fin >> amtEV >> whichEV;
			EV[stat[whichEV]] = amtEV;
		}
		EntryData e(entryID,DexID,moveID,nature,EV);
		m[entryID] = e;
		for(int i = 0; i < 6; i++) {
			EV[i] = 0;
		}
	}
	fin.close();
}


