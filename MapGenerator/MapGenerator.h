#ifndef __MAPGENERATOR_H_INCLUDED__
#define __MAPGENERATOR_H_INCLUDED__

#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

struct BaseStats {
	int HP;
	int A;
	int D;
	int SA;
	int SD;
	int S;
	BaseStats() {
		HP = A = D = SA = SD = S = 0;
	}
	BaseStats(int x1,int x2, int x3, int x4, int x5, int x6) {
		HP = x1;
		A = x2;
		D = x3;
		SA = x4; 
		SD = x5;
		S = x6;
	}

};

bool operator == (const BaseStats &lhs, const BaseStats &rhs);

struct MoveData {
	string ID;
	string name;
	string type;
	string category;
	int damage;
	MoveData(string x1, string x2, string x3, string x4, int x5) {
		ID = x1;
		name = x2;
		type = x3;
		category = x4;
		damage = x5;
	}
	MoveData() {
		ID = "";
		name = "";
		type = "";
		category = "";
		damage = 0;
	}
};

bool operator == (const MoveData &lhs, const MoveData &rhs);

struct EntryData {
	string ID;
	string DexID;
	vector<string> moveID;
	string nature;
	vector<int> EV;
	EntryData(string x1, string x2, vector<string> &x3, string x4, vector<int> &x5) {
		ID = x1;
		DexID = x2;
		moveID = x3;
		nature = x4;
		EV = x5;
	}
	EntryData() {
		ID = "";
		DexID = "";
		moveID.resize(4,"");
		nature = "";
		EV.resize(6,0);
	}
};


bool operator == (const EntryData &lhs, const EntryData &rhs);


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
	Type to EntryID Vector
	MoveID to EntryID Vector
	Move Name to MoveID

	TODO:


	DexID to BaseStats
	MoveID to MoveData Vector
	EntryID to EntryData Vector	 

*/

/*
	Space for writing methods before adding them to MG.

		

		

	
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

		/*
			@param m - the map to fill.
			m will be a map whose keys are the Types of Pokemon, 
			and the values are the EntryIDs of Factory Entries who have
			that type as denoted by the key.
		*/

		void TypeToEntryIDVectorMap(map<string, vector<string> > &m);

		/*
			@param m - the map to be filled.
			m will be a map whose keys are the MoveIDs of moves.
			the values will be the EntryIDs of Factory entries who
			have the move indicated by the MoveID key.	
		*/
		void MoveIDtoEntryIDVectorMap(map<string, vector<string> > &m);

		/*
			@param m - the map to be filled
			m will be a map whose keys are the Names of moves in Pokemon.
			the values will be the IDs of those moves.
		*/
	
		void MoveNameToMoveIDMap(map <string, string> &m);

		/*
			@param m - the map to be filled
			m will be a map whose keys are the DexIDs of Pokemon.
			The values will be BaseStats structures
		*/
		
		void DexIDToBaseStatsMap(map <string, BaseStats> &m);


		/*
			@param m - the map to be filled.
			m will be a map whose keys are the MoveIDs of moves.
			The values will be MoveData structures
		*/
		void MoveIDToMoveDataMap(map <string, MoveData> &m);
	//MoveID to MoveData Vector

		/*
			@param m - the map to be filled
			m will be a map whose keys are the EntryIDs of Factory Entries
			The values will be EntryData Structures
		*/

		void EntryIDToEntryDataMap(map <string, EntryData> &m);
	//EntryID to EntryData Vector
	private:



};





#endif
