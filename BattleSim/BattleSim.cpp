#include <BattleSim/BattleSim.h>

#include <PokemonEntry/PokemonEntry.h>
#include <EntryFilter/EntryFilter.h>




BattleSim::BattleSim() {
	promptSetOn = true; // TODO:Do something about PromptSetOn
}


//TOP LEVEL QUERY

void BattleSim::Menu(ostream &pout, istream &fin, ostream &fout) {
	string option;
	str_code sc = INITCODE;
	while(sc != EXIT) {	
		pout << "Enter Choice: SETCRITERIA,EVALUATECRITERIA,SETPARTICIPANTS\n";
		pout << "PRINTCRITERIA, PRINTCANDIDATES, PRINTPARTICIPANTS, SIMULATE\n";
		pout << "RETRIEVERESULTS\n";
		getline(fin,option);
	
		sc = HashString(option);
		//TODO: EVALUATE CRITERIA OPTION, print results option
		switch(sc) {
			case SETCRITERIA:
				SetCriteria(pout,fin); break;
			case EVALUATECRITERIA:
				EvaluateCriteria(pout,fin); break;
			case SETPARTICIPANTS:
				SetParticipants(pout,fin); break;
			case PRINTCRITERIA:
				PrintCriteria(pout,fin); break;
			case PRINTCANDIDATES:
				PrintCandidates(pout,fin); break;
			case PRINTPARTICIPANTS:
				PrintParticipants(pout); break;
			case SIMULATE:
				Simulate(pout,fin,fout); break;
			case RETRIEVERESULTS:
				RetrieveResults(pout,fin,fout); break; 
			case EXIT: break;
			default:
				pout << "Invalid Choice\n";

		}
	}
}


//CRITERIA QUERIES

//SET

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
	be.SetMove(whichCriteria,whichMove,move);
}	

void BattleSim::SetType(ostream &pout, istream &fin, int whichCriteria) {
	string type;
	pout << "Enter Type\n";
	getline(fin,type);
	be.SetType(whichCriteria,type);
}

void BattleSim::SetIV(ostream &pout, istream &fin, int whichCriteria) {
	string iv;
	getline(fin,iv);
	int ivInt = StringToIntHelper(iv);
	if(ivInt != -1) {
		be.SetIVs(whichCriteria,ivInt);
	} else {
		pout << "Enter valid value for IV(positive integer 0 - 31)\n";
	}
}

void BattleSim::SetCriterion(ostream &pout, istream &fin, int whichCriteria) {

	string option;
	str_code sc = INITCODE;
	while(sc != EXIT) {
		pout << "Enter what to change.(SETNAME,SETMOVE,SETTYPE,SETIV)\n";
		getline(fin,option);
		sc = HashString(option);
		switch(sc) {
			case SETNAME:
				SetName(pout,fin,whichCriteria); break;
			case SETMOVE: 
				SetMoves(pout,fin,whichCriteria); break;
			case SETTYPE:
				SetType(pout,fin,whichCriteria); break;
			case SETIV:
				SetIV(pout,fin,whichCriteria); break;
			case EXIT:
				pout << "Exit Criteria Menu\n"; break;
			default:
				pout << "Invalid Choice\n"; break;
		}
	}
}

void BattleSim::SetCriteria(ostream &pout, istream &fin) {
	//TODO: FIX MAGIC NUMBER of 2
	string whichEntry;
	int whichEntryInt;

	pout << "Enter Which Entry To Modify\n";
	getline(fin,whichEntry);
	whichEntryInt = StringToIntHelper(whichEntry);
	if(whichEntryInt >= 0 && whichEntryInt < be.size() ) {
		SetCriterion(pout,fin,whichEntryInt);
	} else {
		pout << "Invalid Choice\n"; //TODO: TELL SIZE?
	}

}

//RETRIEVE

void BattleSim::PrintCriterion(ostream &pout, int wcInt) {
	string r;
        be.CriteriaDescription(wcInt,r);
	pout << r << endl;
}

void BattleSim::PrintCriteria(ostream &pout, istream &fin) {
	/*
		Prompt:
		Get Input Number:
		Call PrintCriterion Function with param
	*/
	pout << "Enter which criterion to print.\n";
	string whichCriterion;
	getline(fin,whichCriterion);	
	int wcInt = StringToIntHelper(whichCriterion);
	if(wcInt == 0 || wcInt == 1) {
		PrintCriterion(pout, wcInt);
	} else {
		pout << "Invalid Choice.(0 or 1)\n";
	}
}

//EVALUATE
//TODO:PROMPT STATEMENT
void BattleSim::EvaluateCriteria(ostream &pout, istream &fin) {
	string whichCriteria;
	pout << "Enter which criterion to evaluate.\n";
	getline(fin,whichCriteria);
	
	int wcInt = StringToIntHelper(whichCriteria);
	if(wcInt == 0 || wcInt == 1) {
		EvaluateCriterion(pout,wcInt);
	} else {
		pout << "Invalid choice\n";
	}
}


void BattleSim::EvaluateCriterion(ostream &pout, int whichCriteria) {
	be.EvaluateCriteria(whichCriteria);
}


//CANDIDATE QUERIES

void BattleSim::PrintCandidates(ostream &pout, istream &fin) {
	string whichEntry;
	int whichEntryInt;

	pout << "Enter Which Candidate List to Print from\n";
	getline(fin,whichEntry);
	whichEntryInt = StringToIntHelper(whichEntry);
	if(whichEntryInt == 0 || whichEntryInt == 1) {
		PrintAllCandidates(pout, whichEntryInt);
	} else {
		pout << "Invalid Choice.(0 or 1)\n";
	}
		
}
		
//TODO: IMPLEMENT
void BattleSim::PrintCandidate(ostream &pout, istream &fin, int whichCriteria) {
	cout << "DERP\n";
}


		
void BattleSim::PrintAllCandidates(ostream &pout,int whichCriteria) {
	//get num criteria not can list siz
	int sz = be.CandidateListSize(whichCriteria);
	string res;
	//ADD COUNTERS / A HEADER TO PRINT???
	for(int i = 0; i < sz; i++) {
		be.CandidateDescription(whichCriteria,i,res);
		pout << res << '\n';
	}
}

//PARTICIPANT QUERIES


void BattleSim::SetParticipants(ostream &pout,istream &fin) {
	string whichEntry;
	int whichEntryInt;
	
	pout << "Enter which participant to set\n";
	getline(fin,whichEntry);
	whichEntryInt = StringToIntHelper(whichEntry);
	if(whichEntryInt == 0 || whichEntryInt == 1) {
		SetParticipant(pout, fin, whichEntryInt);
	} else {
		pout << "Invalid choice(0 or 1)\n";
	}	
}

void BattleSim::SetParticipant(ostream &pout, istream &fin, int whichEntryInt) {
	string whichChoice;
	int whichChoiceInt;
	pout << "Enter which Candidate to set\n";
	getline(fin,whichChoice);
	whichChoiceInt = StringToIntHelper(whichChoice);

	if(be.CandidateListSize(whichEntryInt) > whichChoiceInt && whichChoiceInt >= 0) {
		be.SetParticipant(whichEntryInt,whichChoiceInt);
	} else {
		pout << "Invalid Choice\n";
	}
}

void BattleSim::PrintParticipants(ostream &pout) {
	//static vector<PokemonEntry> entrySelections(2);
	string res;
	for(unsigned i = 0; i < 2; i++) {
		be.ParticipantDescription(i,res);
		pout << res << '\n';
	}
	pout << '\n';
}



void BattleSim::Simulate(ostream &pout,istream &fin, ostream &fout) {
	//TODO:
	string whichEntry;
	int whichEntryInt1,whichEntryInt2;
	
	pout << "Enter first participant to set\n";
	getline(fin,whichEntry);
	whichEntryInt1 = StringToIntHelper(whichEntry);	
	pout << "Enter second participant to set\n";
	getline(fin,whichEntry);
	whichEntryInt2 = StringToIntHelper(whichEntry);
	if(whichEntryInt1 >= 0 && whichEntryInt1 <= 1 && whichEntryInt2 >= 0 && whichEntryInt2 <= 1) {
		be.Evaluate(whichEntryInt1,whichEntryInt2);
		be.Evaluate(whichEntryInt2,whichEntryInt1);
	} else {
		pout << "Invalid Choices\n";
	}
}

void BattleSim::RetrieveResults(ostream &pout,istream &fin, ostream &fout) {
	string whichEntry;
	int whichEntryInt1,whichEntryInt2;
	
	pout << "Enter first participant to set\n";
	getline(fin,whichEntry);
	whichEntryInt1 = StringToIntHelper(whichEntry);	
	pout << "Enter second participant to set\n";
	getline(fin,whichEntry);
	whichEntryInt2 = StringToIntHelper(whichEntry);	
	if(whichEntryInt1 >= 0 && whichEntryInt1 <= 1 && whichEntryInt2 >= 0 && whichEntryInt2 <= 1) {
		RetrieveResult(pout,fout,whichEntryInt1,whichEntryInt2);
	} else {
		pout << "Invalid Choices\n";
	}
}



void PrintMoveRes(BattleEvaluator::MoveResult &r) {
	cout << r.participants.first << " to " << r.participants.second << " using: ";
	cout << r.moveName << " does " << r.damage.first << " to " << r.damage.second;
	cout << ".\n";
}

void PrintRes(vector<BattleEvaluator::MoveResult> &a) {
	int sz = a.size();
	for(int i = 0; i < sz; i++) {
		PrintMoveRes(a[i]);
	}
}

void BattleSim::RetrieveResult(ostream &pout, ostream &fout, int wcInt1, int wcInt2) {
	vector<BattleEvaluator::MoveResult> rr;
	be.RetrieveResults(rr,wcInt1,wcInt2);
	PrintRes(rr);
	be.RetrieveResults(rr,wcInt2,wcInt1);
	PrintRes(rr);	
}



//HELPERS:

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

//Message Printers
//Error Message
void BattleSim::PrintOutOfBoundError(ostream &pout) {
	pout << "Out of Criteria Bound. Enter valid Number. ";
	pout << 0 << " to " << be.size() - 1 << '\n';
}
	


BattleSim::str_code BattleSim::HashString(string s) {
	if(s == "INITCODE")
		return INITCODE;
	else if(s == "SETCRITERIA")
		return SETCRITERIA;
	else if(s == "SETNAME")
		return SETNAME;
	else if(s == "SETMOVE")
		return SETMOVE;
	else if(s == "SETTYPE")
		return SETTYPE;
	else if(s == "SETIV")
		return SETIV;
	else if(s == "EVALUATECRITERIA")
		return EVALUATECRITERIA;
	else if(s == "SETPARTICIPANTS")
		return SETPARTICIPANTS;
	else if(s == "EXIT")
		return EXIT;
	else if(s == "PRINTCANDIDATES")
		return PRINTCANDIDATES;
	else if(s == "PRINTPARTICIPANTS")
		return PRINTPARTICIPANTS;
	else if(s == "PRINTCRITERIA")
		return PRINTCRITERIA;
	else if(s == "SIMULATE")
		return SIMULATE;
	else if(s == "RETRIEVERESULTS")
		return RETRIEVERESULTS;
	else 
		return INVALID;
}



