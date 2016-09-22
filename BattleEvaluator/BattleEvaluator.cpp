#include <BattleEvaluator/BattleEvaluator.h>


#include<iostream>

//CONSTRUCTOR
BattleEvaluator::BattleEvaluator() {
	numCriteria = 2;
	crit.resize(2);
	fitsCriteria.resize(2);
	battleEntries.resize(2);
	res.resize(2);
	for(int i = 0 ; i < 2; i++) {
		res[i].resize(4);
	}
}

BattleEvaluator::BattleEvaluator(int numWayBattle) {
	
	crit.resize(numWayBattle);
	fitsCriteria.resize(numWayBattle);
	battleEntries.resize(numWayBattle);
	res.resize(numWayBattle); //TODO: NOT RIGHT
	numCriteria = numWayBattle;
	for(int i = 0 ; i < numWayBattle; i++) { //ALSO THIS
		res[i].resize(4);
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

void BattleEvaluator::EvaluateCriteria(int whichCriteria) {
	if(inBoundCriteria(whichCriteria) ) {
		ef.ResetAllFilters();
		ef.SetNameFilter(crit[whichCriteria].name);
		for(unsigned j = 0; j < crit[whichCriteria].moves.size(); j++) {
			ef.SetMoveFilter(j,crit[whichCriteria].moves[j]);
		}
		vector<string> resIDs;
		ef.Evaluate(resIDs);
		fitsCriteria[whichCriteria].resize(resIDs.size());
		for(unsigned x = 0; x < resIDs.size(); x++) {
			fitsCriteria[whichCriteria][x] = PokemonEntry(resIDs[x],31); //TODO: ADD IVs to criteria AND CHANGE MAGIC NUMBER
		}		
	}	
}

void BattleEvaluator::SetParticipant(int whichCriteria, int whichEntry) {
	if(inBoundCriteria(whichCriteria))
		if(whichEntry >= 0 && whichEntry < (int)fitsCriteria[whichCriteria].size() )
			battleEntries[whichCriteria] = fitsCriteria[whichCriteria][whichEntry];
}


void BattleEvaluator::Evaluate() {
		for(int i = 0; i < 2; i++) {
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
}

bool BattleEvaluator::inBoundCriteria(int whichCriteria) {
	return whichCriteria >= 0 && whichCriteria < numCriteria;
	
}

void BattleEvaluator::RetrieveResults(vector< vector<BattleEvaluator::MoveResult> > &res) {

}
		




