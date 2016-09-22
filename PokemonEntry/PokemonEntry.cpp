#include <PokemonEntry/PokemonEntry.h>

#include <MapGenerator/MapGenerator.h>

		map<string,string> PokemonEntry::NameToDexID;
		map<string, MoveData> PokemonEntry::MoveIDToMoveData;
		map<string,string> PokemonEntry::MoveNameToMoveID;
		map<string, vector<int> > PokemonEntry::DexIDToBaseStats;
		map<string, vector<string> > PokemonEntry::DexIDToTypes;
		map<string, EntryData> PokemonEntry::EntryIDToEntryData;
		map<string, string> PokemonEntry::DexIDToName;
		bool PokemonEntry::initialized;
		map<string, map<int, int> > PokemonEntry::natureStatMod;
		map<string, map<string,int> > PokemonEntry::typeMul;
/*
bool initialized = false;
map<string, MoveData> MoveIDToMoveData;
map<string, BaseStats> DexIDToBaseStats;
map<string, vector<string> > DexIDToTypes;
map<string, EntryData> EntryIDToEntryData;
map<string, string> DexIDToName;
*/

#include <iostream>

PokemonEntry::PokemonEntry() {
	if(!initialized) {
		InitializeMaps();
		initialized = true;
	}
	EntryData ed;
	Construct(ed,0);
}
PokemonEntry::PokemonEntry(string id,int IV) {
	if(!initialized) {
		InitializeMaps();
		initialized = true;
	}
	
	EntryData ed = EntryIDToEntryData[id];
	Construct(ed,IV);

}

PokemonEntry::PokemonEntry(EntryData &edata,int IV) {
	if(!initialized) {
		InitializeMaps();
		initialized = true;
	}
	Construct(edata,IV);	
}

PokemonEntry::PokemonEntry(string knownName, vector<int> &stats, vector<string> &knownMoves)  {
	if(!initialized) {
		InitializeMaps();
		initialized = true;
	}
	name = knownName;
	ws = stats;
	moves.clear();
	for(unsigned i = 0; i < knownMoves.size(); i++) {
		moves.push_back( MoveIDToMoveData[MoveNameToMoveID[knownMoves[i]]]);
	}	
	
	types = DexIDToTypes[NameToDexID[name]];

}


void PokemonEntry::InitializeMaps() {
	MapGenerator mg;
	mg.NameToDexIDMap(NameToDexID);
	mg.DexIDToBaseStatsMap(DexIDToBaseStats);
	mg.EntryIDToEntryDataMap(EntryIDToEntryData);
	mg.DexIDToTypeVectorMap(DexIDToTypes);
	mg.DexIDToNameMap(DexIDToName);
	mg.MoveIDToMoveDataMap(MoveIDToMoveData);
	mg.TypeMultiplierMap(typeMul);
	mg.MoveNameToMoveIDMap(MoveNameToMoveID);
}

string PokemonEntry::getName() {
	return name;
}

MoveData PokemonEntry::getMove(int which) {
	MoveData mm;
	if(which >= 0 && which < (int)moves.size())
		return moves[which];
	else 
		return mm;
}

void PokemonEntry::Construct(EntryData &ed,int IV) {
	vector<int> bs = DexIDToBaseStats[ed.DexID];
	types = DexIDToTypes[ed.DexID];
	ws = CalcWorkingStats(bs,ed.EV,IV,ed.nature);
	moves.resize(4);
	name = DexIDToName[ed.DexID];
	for(unsigned i = 0; i < 4; i++) {
		moves[i] = MoveIDToMoveData[ed.moveID[i]];
	}
}

int PokemonEntry::getStat(int which) {
	if(ws.size() == 6 && which >= 0 && which < 6)
		return ws[which];
	else
		return -1;
}

pair<int,int> PokemonEntry::getMoveDamageRange(PokemonEntry &defender, string moveName) {
	int chosen;
	for(unsigned i = 0; i < moves.size(); i++) {
		if(moves[i].name == moveName) {
			chosen = i;
			break;
		}
	}
	return getMoveDamageRange(defender,chosen);
}

pair<int,int> PokemonEntry::getMoveDamageRange(PokemonEntry &defender,int which) {
	const MoveData &md = moves[which];
	double dStat = 0,aStat = 0;
	if(md.category == "Physical") {
		aStat = this->getStat(1);
		dStat = defender.getStat(2);
	}
	else if(md.category == "Special") {
		aStat = this->getStat(3);
		dStat = defender.getStat(4);
	}
	else {
//		cout << "HIT STATUS\n";
		return pair<int,int>(0,0);
	}
	double damage = double((2 * 100 + 10)) / double(250);
//	cout << aStat << ' ' << dStat << '\n';
	damage *= (double(aStat) / double(dStat));
	damage *= md.damage;
	damage += 2;
//	cout << damage << endl;
	for(unsigned i = 0; i < types.size(); i++)
		if(md.type == types[i]) {
			damage *= 1.5;
			break;
		}
	vector<string> defTypes = defender.getTypes();
	for(unsigned i = 0; i < defTypes.size(); i++) {
//		cout << defTypes[i] << " " << dmgMultiplier(md.type,defTypes[i]);
		damage *= dmgMultiplier(md.type,defTypes[i]);
//		cout << damage << '\n';
	}
	return pair<int,int>(int(.85 * damage),int(damage));
}


double PokemonEntry::dmgMultiplier(string att, string def) {
	int code = typeMul[att][def];
	switch(code) {
		case 0: return 1;
		case 1: return .5;
		case 2: return 2;
		case 3: return 0;
	}
	return 0;
}






