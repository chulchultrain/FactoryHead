#include <MapGenerator/MapGenerator.h>


#ifndef NAMESFILE
#define NAMESFILE "/BASE/NAME/Names.txt"
#endif

#include <fstream>


/*
	Will fill the map with Name To DexID.
	Open Name and DexID file.
	Retrieve all Name-DexID pairs and insert into map as go through the file.

*/


void MapGenerator::NameToDexIDMap(map<string,string> &m) {
	m.clear();
	ifstream fin(NAMESFILE);
	string name;
	string DexID;
	while(getline(fin,DexID) ) {
		getline(fin,name);
		m[name] = DexID;
	}

	

}


