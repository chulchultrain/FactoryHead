#ifndef __MAPGENERATOR_H_INCLUDED__
#define __MAPGENERATOR_H_INCLUDED__

#include <stdlib.h>
#include <map>
#include <string>

using namespace std;
/*
	Our Token Evaluator implementation rely on mappings between
	DexID, Name, Types, and Entry ID.
	
	Given an empty map and a desired mapping,
	The map generator will fill the map data structures with the appropriate
	mappings.

	The mappings that I wish for the MG to support are
	DexID to EntryID
	
	Name to DexID
	Type to DexID Vector
	DexID to Name
	DexID to Type Vector
	DexID to EntryID Vector
	
	
	
	
	 

*/


class MapGenerator {
	public:

		/*
			@param m - the map to fill
			m will be a map whose keys are the names of all the 
			Pokemon, and the values are the DexIDs of the Pokemon.
		*/
		void NameToDexIDMap(map<string,string> &m);

	private:



};





#endif
