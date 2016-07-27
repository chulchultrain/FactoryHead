#include <MapGenerator/MapGenerator.h>


#ifndef NAMESFILE
#define NAMESFILE "base/name/Names.txt"
#endif

#ifndef TYPESFILE
#define TYPESFILE "/base/type/Types.txt"
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

}

		/*
			@param m - the map to fill.
			m will be a map whose keys are the DexIDs of the Pokemon.
			the values will be the names of those pokemon.
		*/

void MapGenerator::DexIDToNameMap(map<string,string> &m) {

}

		/*
			@param m - the map to fill.
			m will be a map whose keys are the DexIDs of the Pokemon.
			The Values will be a vector containing the types of that Pokemon.
		*/

void MapGenerator::DexIDToTypeVectorMap(map<string,vector<string> > &m) {

}

		/*
			@param m - the map to fill.
			m will be a map whose keys are the DexIDs of the Pokemon.
			The values will be the Factory Entry IDs of the Factory Entries that
			have that DexID.
		*/

void MapGenerator::DexIDToEntryIDVectorMap(map<string,vector<string> > &m) {


}





