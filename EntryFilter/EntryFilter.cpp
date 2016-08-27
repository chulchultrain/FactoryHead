
#include <EntryFilter/EntryFilter.h>
#include <iostream>


EntryFilter::EntryFilter() {
	tte = TypeTokenEvaluator();
	nte = NameTokenEvaluator();
	mte = MoveTokenEvaluator();
	
		string moves[4];
		string name;
		string types[2];
	for(int i = 0; i < 4; i++)
		moves[i] = "";
	for(int i = 0; i < 2; i++)
		types[i] = "";
	name = "";
}

void EntryFilter::ResetAllFilters() {
	ResetAllMoveFilters();
	ResetAllTypeFilters();
	ResetNameFilter();
}

void EntryFilter::ResetAllMoveFilters() {
	for(int i = 0; i < 4; i++)
		ResetMoveFilter(i);
}

void EntryFilter::ResetMoveFilter(int which) {
	moves[which] = "";
}

void EntryFilter::ResetNameFilter() {
	name = "";
}

void EntryFilter::ResetAllTypeFilters() {
	for(int i = 0; i < 2; i++)
		ResetTypeFilter(i);
}

void EntryFilter::ResetTypeFilter(int which) {
	types[which] = "";
}


void EntryFilter::SetMoveFilter(int which,string move) {
	moves[which] = move; 
}

void EntryFilter::SetNameFilter(string s) {
	name = s;
}

void EntryFilter::SetTypeFilter(int which, string type) {
	types[which] = type;
}

void MergeVectors(vector<string> &res, vector<vector<string> > &temp) {
	map<string, unsigned int> rMap;
	for(unsigned int i = 0; i < temp.size(); i++)
		for(unsigned int j = 0; j < temp[i].size(); j++)
			rMap[temp[i][j]]++;
	res.clear();
	for( map<string,unsigned int>::iterator it = rMap.begin(); it != rMap.end(); it++)
		if( it->second == temp.size())
			res.push_back(it->first);

	
}

/*
	make a list of all the set filters.
	From those set filters, find their intersection.
*/



void EntryFilter::Evaluate(vector<string> &res) {
	res.clear();
	vector< vector<string> > totalTemp;
	vector<string> temp;
	if(name != "") {
		nte.EvalToken(name,temp);
		totalTemp.push_back(temp);
	}
	for(unsigned int i = 0; i < 4; i++) {
		if(moves[i] != "") {
			mte.EvalToken(moves[i],temp);
			totalTemp.push_back(temp);
		}
	}
	for(unsigned int i = 0; i < 2; i++) {
		if(types[i] != "") {
			tte.EvalToken(types[i],temp);
			totalTemp.push_back(temp);
		}
	}
	MergeVectors(res,totalTemp);
}






