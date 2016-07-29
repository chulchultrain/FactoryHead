#ifndef __MAPGENERATOR_H_INCLUDED__
#define __MAPGENERATOR_H_INCLUDED__

#include <stdlib.h>
#include <map>
#include <string>
#include <vector>

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

	TODO:
	DexID to EntryID Vector
	Type to EntryID Vector
	MoveID to EntryID Vector
	Move Name to MoveID
	MoveID to MoveData Vector
	DexID to BaseStats
	
	 

*/


class MapGenerator {
	public:

		/*
			@param m - the map to fill
			m will be a map whose keys are the names of all the 
			Pokemon, and the values are the DexIDs of the Pokemon.
		*/
		void NameToDexIDMap(map<string,string> &m);


		/*
			@param m - the map to fill.
			m will be a map whose keys are the Types in the Pokemon game.
			The Values will be all vectors containing the DexIDs of all the Pokemon
			who have that type.
		*/

		void TypeToDexIDVectorMap(map<string,vector<string> > &m);

		/*
			@param m - the map to fill.
			m will be a map whose keys are the DexIDs of the Pokemon.
			the values will be the names of those pokemon.
		*/

		void DexIDToNameMap(map<string,string> &m);

		/*
			@param m - the map to fill.
			m will be a map whose keys are the DexIDs of the Pokemon.
			The Values will be a vector containing the types of that Pokemon.
		*/

		void DexIDToTypeVectorMap(map<string,vector<string> > &m);

		/*
			@param m - the map to fill.
			m will be a map whose keys are the DexIDs of the Pokemon.
			The values will be the Factory Entry IDs of the Factory Entries that
			have that DexID.
		*/

		void DexIDToEntryIDVectorMap(map<string,vector<string> > &m);
	private:



};





#endif
