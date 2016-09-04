#ifndef __POKEMONENTRY_H_INCLUDED__
#define __POKEMONENTRY_H_INCLUDED__

#include <stdlib.h>
#include <string>
#include <vector>
#include <map>

#include <MoveData/MoveData.h>
#include <EntryData/EntryData.h>
#include <WorkingStats/WorkingStats.h>
#include <utility>


using namespace std;


class PokemonEntry {
	public:
		PokemonEntry(string entryID,int IV);
		int getStat(int which);
		string getName();
		pair<int,int> getMoveDamageRange(PokemonEntry &defender,int which);
		vector<string> getTypes() {return types;}
		pair<int,int> getMoveDamageRange(PokemonEntry &defender, string moveName);
		MoveData getMove(int which);
		//int getDamage(const PokemonEntry &defender, int whichMove);

	private:
		string name;
		WorkingStats ws;
		vector<MoveData> moves;
		vector<string> types;
/*
		static map<string, MoveData> PokemonEntry::MoveIDToMoveData;
		static map<string, BaseStats> PokemonEntry::DexIDToBaseStats;
		static map<string, vector<string> > PokemonEntry::exIDToTypes;
		static map<string, EntryData> PokemonEntry::EntryIDToEntryData;
		static map<string, string> PokemonEntry::DexIDToName;
		static bool PokemonEntry::initialized;
*/
		static bool initialized;
		static map<string, MoveData> MoveIDToMoveData;
		static map<string, vector<int> > DexIDToBaseStats;
		static map<string, vector<string> > DexIDToTypes;
		static map<string, EntryData> EntryIDToEntryData;
		static map<string, string> DexIDToName;
		static map<string, map<int, int> > natureStatMod;
		static map<string, map<string, int> > typeMul;
		//TODO: ADD AND INIT NATURE STAT MAP
		void InitializeMaps();
		void Construct(string eid,int IV);
		double dmgMultiplier(string att, string def);
};

#endif
