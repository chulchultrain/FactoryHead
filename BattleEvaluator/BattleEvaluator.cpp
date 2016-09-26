#include <BattleEvaluator/BattleEvaluator.h>


#include<iostream>

//CONSTRUCTOR
BattleEvaluator::BattleEvaluator() {
	numCriteria = 2;
	crit.resize(numCriteria);
	fitsCriteria.resize(numCriteria);
	battleEntries.resize(numCriteria);
	res.resize(numCriteria);
	for(int i = 0 ; i < numCriteria; i++) {
		res[i].resize(numCriteria);
		for(int j = 0; j < numCriteria; j++)
			res[i][j].resize(4);
	}
}

BattleEvaluator::BattleEvaluator(int numPokemon) {
	
	crit.resize(numPokemon);
	fitsCriteria.resize(numPokemon);
	battleEntries.resize(numPokemon);
	res.resize(numPokemon); //TODO: NOT RIGHT
	numCriteria = numPokemon;
	for(int i = 0 ; i < numPokemon; i++) { //ALSO THIS
		res[i].resize(numPokemon);
		for(int j = 0; j < numPokemon; j++)
			res[i][j].resize(4);
	}
}

//DESTRUCTOR
BattleEvaluator::~BattleEvaluator() {

}

//SETTING CRITERIA METHODS
void BattleEvaluator::SetName(int whichCriteria, string name) {
	if(inBoundCriteria(whichCriteria))
		crit[whichCriteria].name = name;
}

void BattleEvaluator::SetType(int whichCriteria, string type) {
	if(inBoundCriteria(whichCriteria))
		crit[whichCriteria].type = type;
}


void BattleEvaluator::SetMove(int whichCriteria, int whichMove, string moveName) {
	if(inBoundCriteria(whichCriteria))
		if(whichMove >= 0 && whichMove < 4)
			crit[whichCriteria].moves[whichMove] = moveName;
}

void BattleEvaluator::SetIVs(int whichCriteria,int IV) {
	if(inBoundCriteria(whichCriteria))
		if(IV >= 0 && IV <= 31)
			crit[whichCriteria].IV = IV;
}

void BattleEvaluator::EvaluateCriteria(int whichCriteria) {
	if(inBoundCriteria(whichCriteria) ) {
		ef.ResetAllFilters();
		ef.SetNameFilter(crit[whichCriteria].name);
		for(unsigned j = 0; j < crit[whichCriteria].moves.size(); j++) {
			ef.SetMoveFilter(j,crit[whichCriteria].moves[j]);
		}	
		ef.SetTypeFilter(0,crit[whichCriteria].type); //Take note will only set first type.
		vector<string> resIDs;
		ef.Evaluate(resIDs);
		fitsCriteria[whichCriteria].resize(resIDs.size());
		int IV = crit[whichCriteria].IV;
		for(unsigned x = 0; x < resIDs.size(); x++) {
			fitsCriteria[whichCriteria][x] = PokemonEntry(resIDs[x],IV); //TODO: ADD IVs to criteria AND CHANGE MAGIC NUMBER
		}		
	}	
}

void BattleEvaluator::SetParticipant(int whichCriteria, int whichEntry) {
	if(inBoundCriteria(whichCriteria))
		if(whichEntry >= 0 && whichEntry < (int)fitsCriteria[whichCriteria].size() )
			battleEntries[whichCriteria] = fitsCriteria[whichCriteria][whichEntry];
}


void BattleEvaluator::Evaluate(int i, int j) {

		
	for(int x = 0; x < 4; x++) {
		res[i][j][x].damage = battleEntries[i].getMoveDamageRange(battleEntries[j],x);
		res[i][j][x].participants = make_pair(battleEntries[i].getName(),battleEntries[j].getName() );
		res[i][j][x].moveName = battleEntries[i].getMove(x).name;
	}
/**
		for(int i = 0; i < numCriteria; i++) {
		cout << battleEntries[i].getName() << '\n';
		for(int j = 0; j < 4; j++) {
			pair<int,int> damage = battleEntries[i].getMoveDamageRange(battleEntries[1-i],j);
			res[i][j].participants = make_pair(battleEntries[i].getName(),battleEntries[1-i].getName() );
			res[i][j].moveName = battleEntries[i].getMove(j).name;
			res[i][j].damage = damage;
			cout << battleEntries[i].getMove(j).name << " does " << damage.first << " to " << damage.second << '\n';
		}
		cout << '\n';
	}
**/
}

bool BattleEvaluator::inBoundCriteria(int whichCriteria) {
	return whichCriteria >= 0 && whichCriteria < numCriteria;
	
}

void BattleEvaluator::RetrieveResults(vector<BattleEvaluator::MoveResult> &results, int i, int j) {
	results = res[i][j];
}
		




