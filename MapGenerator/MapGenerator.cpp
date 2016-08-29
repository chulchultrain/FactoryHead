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

#ifndef NATUREFILE
#define NATUREFILE "BASE/NATURE/NatureData.txt"
#endif

#ifndef TYPECHARTFILE
#define TYPECHARTFILE "BASE/TYPE/TypeChart.txt"
#endif

#ifndef OUTPUTENTRYFILE
#define OUTPUTENTRYFILE "BASE/ENTRY/OutputEntryData.txt"
#endif

#include <fstream>
#include <iostream>
#include <sstream>

/*
	Will fill the map with Name To DexID.
	Open Name and DexID file.
	Retrieve all Name-DexID pairs and insert into map as go through the file.

*/


map<string,string> MapGenerator::NameToDexID;
map<string,vector<string> > MapGenerator::TypeToDexIDVector;
map<string,string> MapGenerator::DexIDToName;
map<string, vector<string> > MapGenerator::DexIDToTypeVector;
map<string, vector<string> > MapGenerator::DexIDToEntryIDVector;
map<string, vector<string> > MapGenerator::TypeToEntryIDVector;
map<string, vector<string> > MapGenerator::MoveIDtoEntryIDVector;
map<string, vector<string> > MapGenerator::NameToEntryIDVector;
map<string, vector<string> > MapGenerator::MoveNameToEntryIDVector;
map<string, string> MapGenerator::MoveNameToMoveID;
map<string, BaseStats> MapGenerator::DexIDToBaseStats;
map<string, MoveData> MapGenerator::MoveIDToMoveData;
map<string, EntryData> MapGenerator::EntryIDToEntryData;
map <string, map<int, int> > MapGenerator::NatureToStatMultiplier;
map<string, map<string, int> > MapGenerator::TypeMultiplier;
bool MapGenerator::mapsInitialized;

void MapGenerator::NameToDexIDMap(map<string,string> &m) {
	m = NameToDexID;
}

void MapGenerator::NameToDexIDMapHelper(map<string,string> &m) {
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
	m = TypeToDexIDVector;
}

void MapGenerator::TypeToDexIDVectorMapHelper(map<string,vector<string> > &m) {
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


void MapGenerator::DexIDToNameMap(map<string,string> &m) {
	m = DexIDToName;
}

		/*
			@param m - the map to fill.
			m will be a map whose keys are the DexIDs of the Pokemon.
			the values will be the names of those pokemon.
		*/

void MapGenerator::DexIDToNameMapHelper(map<string,string> &m) {
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

void MapGenerator::DexIDToTypeVectorMap(map<string,vector<string> > &m) {
	m = DexIDToTypeVector;
}

		/*
			@param m - the map to fill.
			m will be a map whose keys are the DexIDs of the Pokemon.
			The Values will be a vector containing the types of that Pokemon.
		*/

void MapGenerator::DexIDToTypeVectorMapHelper(map<string,vector<string> > &m) {
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
	m = DexIDToEntryIDVector;
}

void MapGenerator::DexIDToEntryIDVectorMapHelper(map<string,vector<string> > &m) {
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

void MapGenerator::TypeToEntryIDVectorMap(map<string, vector<string> > &m) {
	m = TypeToEntryIDVector;
}

		/*
			@param m - the map to be filled
			m will be a map whose keys are the Names of moves in Pokemon.
			the values will be the IDs of those moves.
		*/

void MapGenerator::TypeToEntryIDVectorMapHelper(map<string, vector<string> > &m) {
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
	m = MoveIDtoEntryIDVector;
}

void MapGenerator::MoveIDtoEntryIDVectorMapHelper(map<string, vector<string> > &m) {
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
		getline(fin,discard);
		while(discard != "") {
			getline(fin,discard);
		}
	}	
	fin.close();
}


void MapGenerator::NameToEntryIDVectorMap(map<string, vector<string> > &m) {
	m = NameToEntryIDVector;
}

		/*
			@param m - the map to fill
			m will be a map whose keys are the names of the Pokemon.
			The values will be the Factory Entry IDs of the Factory Entries that have that name.
		*/

void MapGenerator::NameToEntryIDVectorMapHelper(map<string, vector<string> > &m) {
	m.clear();
	//ifstream fin(ENTRYFILE);
	map<string, string> dtn;
	DexIDToNameMap(dtn);
	map<string, vector<string> > dte;
	DexIDToEntryIDVectorMap(dte);
	for( 	map<string, vector<string> >::iterator it = dte.begin(); it != dte.end(); it++) {
		m[dtn[it->first]] = it->second;
	}
	//fin.close();
}


void MapGenerator::MoveNameToEntryIDVectorMap(map<string, vector<string> > &m) {
	m = MoveNameToEntryIDVector;
}

	/*
		@param m - the map to fill
		m wlil be a map whose keys are the names of Pokemon moves.
		The values will be the Factory Entry IDs of the Factory Entries that have that move in their move set.
	*/

void MapGenerator::MoveNameToEntryIDVectorMapHelper(map<string, vector<string> > &m) {
	m.clear();
	map<string, MoveData> midtmd; 
	MoveIDToMoveDataMap(midtmd);
	map<string, vector<string> > midteid;
	MoveIDtoEntryIDVectorMap(midteid);
	for( 	map<string, vector<string> >::iterator it = midteid.begin(); it != midteid.end(); it++) {
		m[midtmd[it->first].name] = it->second;
	}	
}


		/*
			@param m - the map to be filled
			m will be a map whose keys are the Names of moves in Pokemon.
			the values will be the IDs of those moves.
		*/

void MapGenerator::MoveNameToMoveIDMap(map <string, string> &m) {
	m = MoveNameToMoveID;
}
	
void MapGenerator::MoveNameToMoveIDMapHelper(map <string, string> &m) {
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
	m = DexIDToBaseStats;
}

void MapGenerator::DexIDToBaseStatsMapHelper(map <string, BaseStats> &m) {
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
	m = MoveIDToMoveData;
}

void MapGenerator::MoveIDToMoveDataMapHelper(map <string, MoveData> &m) {
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
	m = EntryIDToEntryData;
}

void MapGenerator::EntryIDToEntryDataMapHelper(map <string, EntryData> &m) {
	m.clear();
	map<string,int> stat;
	ifstream fin(OUTPUTENTRYFILE);
	stat["HP"] = 0;
	stat["A"] = 1;
	stat["D"] = 2;
	stat["SA"] = 3;
	stat["SD"] = 4;
	stat["S"] = 5;
	string entryID;
	string DexID;
	string discard;
	string item;
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
		getline(fin,item);
		getline(fin,nature);
		for(int i = 0; i < 6; i++)
			fin >> EV[i];
		EntryData e(entryID,DexID,moveID,item,nature,EV);
		m[entryID] = e;
		for(int i = 0; i < 6; i++) {
			EV[i] = 0;
		}
	}
	fin.close();
}

		/*
			@param m - the map to be filled
			m will be a map whose keys are the natures of Pokemon.
			the values will be maps of that nature. These maps will have
			int keys that correspond to each of the stats. 
			0 for HP
			1 for A
			2 for D
			3 for SA
			4 for SD
			5 for S
		*/

void MapGenerator::NatureToStatMultiplierMap(map <string, map<int, int> > &m) {
	m = NatureToStatMultiplier;
}

void MapGenerator::NatureToStatMultiplierMapHelper(map <string, map<int, int> > &m) {
	m.clear();
	ifstream fin(NATUREFILE);
	string nature;
	int incStat,decStat;
	while(fin >> nature) {
		fin >> incStat >> decStat;
	//	cout << nature << " " << incStat << " " << decStat << '\n';
		m[nature][incStat] = 1;
		m[nature][decStat] = -1;
	}
	fin.close();
}

//TODO:check for everything but EVs
void MapGenerator::ProposeData(string entryID, EntryData ed) {
	EntryIDToEntryData[entryID] = ed;
}

void MapGenerator::SaveChangesToFile() {
	ofstream fout(OUTPUTENTRYFILE);
	for(map<string, EntryData>::iterator it = EntryIDToEntryData.begin(); it != EntryIDToEntryData.end(); it++) {
		PrintEntryData(fout,it->second);
	}

	fout.close();
}

void MapGenerator::TypeMultiplierMap(map<string, map<string,int> > &m) {
	m = TypeMultiplier;
}

void MapGenerator::TypeMultiplierMapHelper(map<string, map<string,int> > &m) {
	m.clear();
	ifstream fin(TYPECHARTFILE);
	string atype,dtype;
	int code;
	while(fin >> atype) {
		fin >> dtype;
		fin >> code;
		m[atype][dtype] = code;
	}
	fin.close();
}

void MapGenerator::PrintEntryData(ofstream &fout, const EntryData &ed) {
	fout << ed.ID << '\n';
	fout << ed.DexID << '\n';
	for(unsigned i = 0; i < 4; i++) {
		fout << ed.moveID[i] << '\n';
	}
	fout << ed.item << '\n';
	fout << ed.nature << '\n';
	for(unsigned i = 0; i < 6; i++) {
		fout << ed.EV[i] << '\n';
	}
	fout << '\n';
}







