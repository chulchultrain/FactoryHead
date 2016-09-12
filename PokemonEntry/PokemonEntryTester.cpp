#include <PokemonEntry/PokemonEntry.h>
#include <EntryFilter/EntryFilter.h>
#include <stdlib.h>
#include <string>
#include <cassert>
#include <iostream>
#include <utility>

using namespace std;


int stringToInt(string s) {
	int res = 0;
	for(unsigned i = 0; i < s.size(); i++) {
		res *= 10;
		if(s[i] >= '0' && s[i] <= '9') {
			res += (int)(s[i] - '0');
		}
		else {
			res = -1;
			break;
		}
		if(res < 0) {
			res = -1;
			break;
		}
	}	
	return res;
}

void PokemonEntryUnitTest() {
	
	PokemonEntry pz("917",31);
	PokemonEntry bs("760",31);
//	assert(pe.getStat(0) == 373);
//	assert(pe.getStat(1) == 186);
//	assert(pe.getStat(2) == 238);

	pair<int,int> s = pz.getMoveDamageRange(bs,"Tri Attack");
	cout << s.first << ' ' << s.second << '\n';
	
//	cout << pe.getStat(3) << endl;
//	cout << pe.getStat(4) << endl;
//	cout << pe.getStat(5) << endl;
//	
//	assert(pe.getStat(3) == 259);
//	assert(pe.getStat(4) == 298);
//	assert(pe.getStat(5) == 86);

}

void Input(int x, string &name, vector<string> &moves) {
	bool sentValue = true;
	int choice,which;
	while(sentValue) {
		cout << "Input for Entry " << x << '\n';
		cout << "0 - Name\n1 - Moves\n2 - Stop editing this Entry\n";
		cin >> choice;
		switch(choice) {
			case 0: cout << "Enter Name\n";
				getline(cin,name);
				getline(cin,name);
				break;
			case 1: cout << "Enter which move(0-3)\n";
				cin >> which;
				if(which >= 0 && which < 4) {
					cout << "Enter move name\n";
					getline(cin,moves[which]);
					getline(cin,moves[which]);
				} else {
					cout << "Invalid move Choice(0-3)\n";
				}
				break;
			case 2: sentValue = false;
				break;
			default: cout << "Invalid choice\n";
		}

	}

}

void PrintCriteriaForPE(int x, string &name, vector<string> &moves) {
	cout << "Entry " << x << '\n';
	cout << "Name: " << name << '\n';
	cout << "Moves:\n";
	for(unsigned i = 0; i < moves.size(); i++) {
		cout << moves[i] << '\n';
	}
	cout << '\n';
}

void BattleSim(vector<string> &names, vector<vector<string> > &moves) {
	vector<vector<string> > res(2);
	vector<EntryFilter> ef(2);
	for(unsigned i = 0; i < 2; i++) {
		ef[i].SetNameFilter(names[i]);
		for(unsigned j = 0; j < moves[i].size(); j++) {
			ef[i].SetMoveFilter(j,moves[i][j]);
		}
		ef[i].Evaluate(res[i]);
	}
	if(res[0].size() != 1 || res[1].size() != 1) {
		cout << "Cannot Simulate Battle due to not enough information\n";
		return;
	}
	vector<PokemonEntry> entries;
	entries.push_back(PokemonEntry(res[0][0],31));
	entries.push_back(PokemonEntry(res[1][0],31));
	for(int i = 0; i < 2; i++) {
		cout << entries[i].getName() << '\n';
		for(int j = 0; j < 4; j++) {
			pair<int,int> damage = entries[i].getMoveDamageRange(entries[1-i],j);
			cout << entries[i].getMove(j).name << " does " << damage.first << " to " << damage.second << '\n';
		}
		cout << '\n';
	}
}

void BattleMenu() {
	vector<string> names(2);
	vector<vector<string> > moves(2);
	for(unsigned i = 0 ; i < moves.size(); i++)
		moves[i].resize(4);
	vector<vector<int> > stats(2);
	for(unsigned i = 0; i < stats.size(); i++)
		stats[i].resize(6);
	vector<EntryFilter> ef(2);
	bool sentValue = true;
	int pokeChoice;
	//int choice;
	//int which;
	while(sentValue) {
		cout << "0 - First Pokemon\n1 - Second Pokemon\n2 - PrintBoth\n3 - See Battle\n4 - Cancel\n";
		cin >> pokeChoice;
		if(pokeChoice == 0 || pokeChoice == 1) {
			Input(pokeChoice,names[pokeChoice],moves[pokeChoice]);
		} 
		if(pokeChoice == 2) {
			for(int i = 0; i < 2; i++)
				PrintCriteriaForPE(i,names[i],moves[i]);
		} else if(pokeChoice == 3) {
			BattleSim(names,moves);
		} else if(pokeChoice == 4){
			sentValue = false;
		} else {
			cout << "Invalid Choice\n";
		}
	}
}


int main() {
	PokemonEntryUnitTest();
	BattleMenu();
	return 0;
}
