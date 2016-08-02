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



#include <fstream>
#include <iostream>

/*
	Will fill the map with Name To DexID.
	Open Name and DexID file.
	Retrieve all Name-DexID pairs and insert into map as go through the file.

*/


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




