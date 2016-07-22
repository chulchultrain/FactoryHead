#include <MapGenerator/MapGenerator.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

/*
	MapGenerator Unit Test:
		Consists of Smaller Unit Tests which mean testing each of the maps
		that the MapGenerator supports.

		Test NameToDexIDMap(map<string,string> &m)
		Test TypeToDexIDListMap(map<string,vector<string> &m)
		Test DexIDToNameMap(map<string,string> &m);
		Test DexIDToTypeListMap(map<string,vector<string> &m)
		Test DexIDToEntryID
*/

void MapGeneratorUnitTest() {

}
/*
	This is dependent on the data in our files, which should have all the Pokemon
	from Gen 1 through Gen 5, whose IDs are the IDs taken from the List of Pokemon
	by Base Stats page on Bulbapedia.

	Will choose some random Pokemon. 
	Pokemon who have no spaces in their names, those who do.
	Pokemon whose IDs only contain numerical digits and those that also contain letters.

	
*/
void NameToDexIDMapUnitTest() {
	MapGenerator mg;
	map<string,string> m;
	mg.NameToDexIDMap(m);
	
	assert(m["Bulbasaur"] == "001" && "1");

	assert(m["Ivysaur"] == "002" && "2");
		
	assert(m["Venasaur"] == "003" && "3");

	assert(m["Meloetta (Pirouette Forme)"] == "648P" && "4");

	assert(m["Meloetta (Aria Forme)"] == "648" && "5");

	assert(m["Rotom (Mow Rotom)"] == "479L" & "6");

	
}


int main() {
	
	


	NameToDexIDMapUnitTest();





	return 0;
}
