#include <BattleEvaluator/BattleEvaluator.h>


#include<iostream>

//CONSTRUCTOR
BattleEvaluator::BattleEvaluator() {
	resize(2);
}

void BattleEvaluator::resize(int n) {
	crit.resize(n);
	candidates.resize(n);
	participants.resize(n);
	res.resize(n);
	for(int i = 0; i < n; i++) {
		res[i].resize(n);
		for(int j = 0; j < n; j++)
			res[i][j].resize(4);
	}
	numCriteria = n;
}

BattleEvaluator::BattleEvaluator(int numPokemon) {
	
	resize(numPokemon);
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
		candidates[whichCriteria].resize(resIDs.size());
		int IV = crit[whichCriteria].IV;
		for(unsigned x = 0; x < resIDs.size(); x++) {
			candidates[whichCriteria][x] = PokemonEntry(resIDs[x],IV); //TODO: ADD IVs to criteria AND CHANGE MAGIC NUMBER
		}		
	}	
}

void BattleEvaluator::SetParticipant(int whichCriteria, int whichEntry) {
	if(inBoundCriteria(whichCriteria))
		if(whichEntry >= 0 && whichEntry < (int)candidates[whichCriteria].size() )
			participants[whichCriteria] = candidates[whichCriteria][whichEntry];
}

/*
	i = attacker
	j = defender
*/
void BattleEvaluator::Evaluate(int i, int j) {

		
	for(int x = 0; x < 4; x++) {
		res[i][j][x].damage = participants[i].getMoveDamageRange(participants[j],x);
		res[i][j][x].participants = make_pair(participants[i].getName(),participants[j].getName() );
		res[i][j][x].moveName = participants[i].getMove(x).name;
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




int BattleEvaluator::CandidateListSize(int whichCriteria) {
	if(inBoundCriteria(whichCriteria) ) {
		return candidates.size();
	}	
	return -1;
}

//RESULT ACCESSOR:

void BattleEvaluator::RetrieveResults(vector<BattleEvaluator::MoveResult> &results, int i, int j) {
	results = res[i][j];
}


//DESCRIPTION ACCESSORS:


void BattleEvaluator::CriteriaDescription(int whichCriteria, string &res) {
	if(inBoundCriteria(whichCriteria) ) {
		res = crit[whichCriteria].toString();
	}
}

		

void BattleEvaluator::CandidateDescription(int whichCriteria, int whichEntry, string &res) {
	if(inBoundCriteria(whichCriteria) ) {
		if(whichEntry < (int)(candidates[whichCriteria].size() ) ) {
			res = candidates[whichCriteria][whichEntry].toString();
		}
	}
}

void BattleEvaluator::ParticipantDescription(int whichCriteria, string &res) {
	if(inBoundCriteria(whichCriteria) ) {
		res = participants[whichCriteria].toString();
	}		
}


//HELPERS:

bool BattleEvaluator::inBoundCriteria(int whichCriteria) {
	return whichCriteria >= 0 && whichCriteria < numCriteria;
	
}

string BattleEvaluator::Criteria::toString() {
	string res = "Name: ";
	res += (name + string("\n") );
	res += (string("Type: ") + type + string("\n")  );
	for(unsigned i = 0; i < moves.size(); i++) {
		res += (string("Move: ") + moves[i] + string("\n") );
	}
	return res;
}

