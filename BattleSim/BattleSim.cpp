#include <BattleSim/BattleSim.h>

#include <PokemonEntry/PokemonEntry.h>
#include <EntryFilter/EntryFilter.h>




BattleSim::BattleSim() {
	promptSetOn = true; // TODO:Do something about PromptSetOn
}



void BattleSim::SetName(ostream &pout, istream &fin, int whichCriteria) {
	string name;
	pout << "Enter Name\n";
	getline(fin,name);
	be.SetName(whichCriteria,name);
}

void BattleSim::SetMoves(ostream &pout, istream &fin, int whichCriteria) {
	pout << "Enter the number of the move to change.(0-4)\n";
	string whichMove;
	getline(fin,whichMove);
	int whichMoveInt = StringToIntHelper(whichMove);
	if(whichMoveInt >= 0 && whichMoveInt < 4) {
		SetMove(pout,fin,whichCriteria,whichMoveInt);
		
	} else {
		pout << "Incorrect Move Choice. You have to choose between " << 0 << " and " << 4 << '\n';
	}
}

void BattleSim::SetMove(ostream &pout, istream &fin, int whichCriteria, int whichMove) {
	string move;
	pout <<"Enter Move\n";
	getline(fin,move);
	be.SetMove(whichCriteria,move);
}	

void BattleSim::SetType(ostream &pout, istream &fin, int whichCriteria) {
	string type;
	pout << "Enter Type\n";
	getline(fin,type);
	be.SetType(whichCriteria,type);
}

void BattleSim::SetCriterion(ostream &pout, istream &fin, int whichCriteria) {

	string option;
	str_code sc = INITCODE;
	while(sc != EXIT) {
		pout << "Enter what to change.(SETNAME,SETMOVE)\n";
		getline(fin,option);
		sc = HashString(option);
		switch(sc) {
			case SETNAME:
				SetName(pout,fin,whichCriteria); break;
			case SETMOVE: 
				SetMoves(pout,fin,whichCriteria); break;
			case SETTYPE:
				SetType(pout,fin,whichCriteria);
			case EXIT:
				pout << "Exit Criteria Menu\n"; break;
			default:
				pout << "Invalid Choice\n"; break;
		}
	}
}

void BattleSim::SetCriteria(ostream &pout, istream &fin) {
	//TODO: FIX
	string whichEntry;
	int whichEntryInt;

	pout << "Enter Which Entry To Modify\n";
	getline(fin,whichEntry);
	whichEntryInt = StringToIntHelper(whichEntry);
	if(whichEntryInt == 0 || whichEntryInt == 1) {
		SetCriterion(pout,fin,whichEntryInt);
	} else {
		pout << "Invalid Choice.(0 or 1)\n";
	}

}

void BattleSim::Menu(ostream &pout, istream &fin, ostream &fout) {
	string option;
	str_code sc = INITCODE;
	while(sc != EXIT) {	
		pout << "Enter Choice(SETENTRY,PRINTSELECTIONS,SIMULATE,EXIT)\n";
	
		getline(fin,option);
	
		sc = HashString(option);
		switch(sc) {
			case SETENTRY:
				SetCriteria(pout,fin); break;
			case PRINTSELECTIONS:
				PrintSelections(pout); break;
			case SIMULATE:
				Simulate(pout,fout); break;
			case EXIT: break;
			default:
				pout << "Invalid Choice\n";

		}
	}
}

void BattleSim::PrintSelections(ostream &pout) {
	for(unsigned i = 0; i < 2; i++) {
		pout << crit[i].name << ":\n";
		for(unsigned j = 0; j < 4; j++)
			pout << crit[i].moves[j] << '\n';
		pout << '\n';
	}
	pout << '\n';
}


int BattleSim::StringToIntHelper(const string &a) {
	unsigned i = 0;
	unsigned len = a.size();
	int res = 0;
	for(i = 0; i < len; i++) {
		res *= 10;
		res += (int)(a.at(i) - '0');
		if(res < 0)
			return -1;
	}
	return res;
	
}

void BattleSim::Simulate(ostream &pout,ostream &fout) {
	
}


BattleSim::str_code BattleSim::HashString(string s) {
	if(s == "INITCODE")
		return INITCODE;
	else if(s == "SETENTRY")
		return SETENTRY;
	else if(s == "SETNAME")
		return SETNAME;
	else if(s == "SETMOVE")
		return SETMOVE;
	else if(s == "SETTYPE")
		return SETTYPE;
	else if(s == "SETIV")
		return SETIV;
	else if(s == "EXIT")
		return EXIT;
	else if(s == "PRINTSELECTIONS")
		return PRINTSELECTIONS;
	else if(s == "SIMULATE")
		return SIMULATE;
	else 
		return INVALID;
}



