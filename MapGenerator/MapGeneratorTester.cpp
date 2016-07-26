#include <MapGenerator/MapGenerator.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>

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

	assert(m["Rotom (Mow Rotom)"] == "479L" && "6");

	
}



bool TestStringVectorPresence(vector<string> &a, string s) {
	int len = a.size();
	for(int i = 0; i < len; i++) {
		if(s == a[i])
			return true;
	}
	return false;
}

/*
	This is dependent on the data in our files, which should have all the Pokemon
	from Gen 1 through Gen 5, whose IDs are the IDs taken from the List of Pokemon
	by Base Stats page on Bulbapedia(we call these DexIDs). For every type, the DexIDs all the Pokemon with that type should appear int he vector.

	Partition:	
		Check one Pokemon from each type that exists in it.
		Check one Pokemon that doesnt exist in each type.
		Check one Pokemon that exists in 2 types.
	Grass
		
*/


void TypeToDexIDListMapUnitTest() {
	MapGenerator mg;
	map<string,vector<string> > m;
	mg.TypeToDexIDVectorMap(m);

	//dual pokemon
	assert(TestStringVectorPresence(m["Grass"],"001")); //bulbasaur
	assert(TestStringVectorPresence(m["Poison"],"001")); //ivysaur

	//shoudl be in 
	assert(TestStringVectorPresence(m["Grass"],"253")); //grovyle
	assert(TestStringVectorPresence(m["Normal"],"035")); //clefairy
	assert(TestStringVectorPresence(m["Fire"],"392")); //infernape
	assert(TestStringVectorPresence(m["Fighting"],"448")); //lucario
	assert(TestStringVectorPresence(m["Poison"],"024")); //arbok
	assert(TestStringVectorPresence(m["Water"],"062")); //poliwrath
 	assert(TestStringVectorPresence(m["Flying"],"018")); //pidgeot
	assert(TestStringVectorPresence(m["Electric"],"466")); //electivire
	assert(TestStringVectorPresence(m["Ground"],"450")); //hippowdon
	assert(TestStringVectorPresence(m["Psychic"],"065")); //alakazam
	assert(TestStringVectorPresence(m["Rock"],"112")); //Rhydon
	assert(TestStringVectorPresence(m["Ice"],"144")); //articuno
	assert(TestStringVectorPresence(m["Bug"],"214")); //heracross
	assert(TestStringVectorPresence(m["Dragon"],"445")); //garchomp
	assert(TestStringVectorPresence(m["Ghost"],"479O")); //rotom (heat rotom)
	assert(TestStringVectorPresence(m["Dark"],"229")); //houndoom
	assert(TestStringVectorPresence(m["Steel"],"208")); //steelix

	assert(TestStringVectorPresence(m["Grass"],"035") == false); //clefairy
	assert(TestStringVectorPresence(m["Normal"],"253") == false); //groyvle
	assert(TestStringVectorPresence(m["Fighting"],"065") == false); //alakazam
	assert(TestStringVectorPresence(m["Poison"],"466") == false); //electivire
	assert(TestStringVectorPresence(m["Water"],"479O") == false); //rotom (heat rotom)
 	assert(TestStringVectorPresence(m["Flying"],"208") == false); //steelix
	assert(TestStringVectorPresence(m["Electric"],"229") == false); //houndoom
	assert(TestStringVectorPresence(m["Ground"],"214") == false); //heracross
	assert(TestStringVectorPresence(m["Psychic"],"466") == false); //electivire
	assert(TestStringVectorPresence(m["Rock"],"electivire") == false); //electivire
	assert(TestStringVectorPresence(m["Ice"],"214") == false); //heracross
	assert(TestStringVectorPresence(m["Bug"],"144") == false); //articuno
	assert(TestStringVectorPresence(m["Dragon"],"479O") == false); //heat rotom
	assert(TestStringVectorPresence(m["Ghost"],"208") == false); //steelix
	assert(TestStringVectorPresence(m["Dark"],"445") == false); //garchomp
	assert(TestStringVectorPresence(m["Steel"],"144") == false); //articuno	
}



/*
	For every DexID, the corresponding Pokemon Name should be the value of the map.
	Partition:
		DexIDs with just numbers, or also letters.
		Names that are single word, or multiple words.
		a DexID from each generation.
*/


void DexIDToNameMapUnitTest() {
	MapGenerator mg;
	map<string,string> m;
	mg.DexIDToNameMap(m);
}

/*
	For every DexID, the appropriate types should be inside the vector that is the value of the map.
	Also, each of these types should appear once and only once.
	
*/


void DexIDToTypeVectorMapUnitTest() {
	MapGenerator mg;
	map<string,vector<string> > m;
	mg.DexIDToTypeVectorMap(m);

}

/*
	For every DexID, the map should be loaded with all the Entry IDs of the Factory Entries
	that have that DexID
*/

void DexIDToEntryIDVectorMapUnitTest() {
	MapGenerator mg;
	map<string,vector<string> > m;	
	mg.DexIDToEntryIDVectorMap(m);
}


int main() {
	
	


	NameToDexIDMapUnitTest();





	return 0;
}
