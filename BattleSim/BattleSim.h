#ifndef __BATTLESIM_H_INCLUDED__
#define __BATTLESIM_H_INCLUDED__

#include <stdlib.h>
#include <vector>
#include <BattleEvaluator/BattleEvaluator.h>
#include <iostream>

using namespace std;

/*
	Purpose of this class is to simulate a battle between 2 Pokemon Entries from the
	Pokemon Platinum Battle Factory, given only their names and move knowledge.

	TODO:SET IVs 
*/

class BattleSim {
	public:
	
		/*
			Constructs a BattleSim Object.
		*/

		BattleSim();

		/*
			This menu is how we are going to access the BattleSim. The Menu will
			take input from a certain stream and print output to a certain stream
			in text format.

			TODO:For use on properly accessing/manipulating the menu, check the README in the BattleSim subdir.
		*/

		void Menu(ostream &pout, istream &fin, ostream &fout);
	private:
		BattleEvaluator be;	

		enum str_code{
			INITCODE,
			PRINTCRITERIA,
			EVALUATECRITERIA,
			SETPARTICIPANTS,
			PRINTCANDIDATES,
			PRINTPARTICIPANTS,
			SIMULATE,
			RETRIEVERESULTS,
			SETCRITERIA,
			SETNAME,
			SETMOVE,
			SETTYPE,
			SETIV,
			EXIT,
			INVALID
		};

		str_code HashString(string s);

		void SetCriterion(ostream &pout, istream &fin, int whichCriteria);
		void SetCriteria(ostream &pout, istream &fin);
		void SetName(ostream &pout, istream &fin, int whichCriteria);
		void SetMoves(ostream &pout, istream &fin, int whichCriteria);
		void SetMove(ostream &pout, istream &fin, int whichCriteria,int whichMove);
		void SetType(ostream &pout, istream &fin, int whichCriteria);
		void SetIV(ostream &pout, istream &fin, int whichCriteria);

		void EvaluateCriteria(ostream &pout, istream &fin);
		void EvaluateCriterion(ostream &pout, int whichCriteria);

		void PrintCriteria(ostream &pout, istream &fin);
		void PrintCriterion(ostream &pout, int wcInt);

		void PrintCandidates(ostream &pout, istream &fin);
		void PrintCandidate(ostream &pout, istream &fin, int whichCriteria);
		void PrintAllCandidates(ostream &pout, int whichCriteria);

		void SetParticipants(ostream &pout,istream &fin);
		void SetParticipant(ostream &pout, istream &fin, int whichEntryInt);
		void PrintParticipants(ostream &pout);
		void Simulate(ostream &pout,istream &fin, ostream &fout);


		void RetrieveResults(ostream &pout,istream &fin, ostream &fout);
		void RetrieveResult(ostream &pout, ostream &fout, int wcInt1, int wcInt2);
		bool promptSetOn;

		
		void PrintBattle(ostream &fout);
		string Prompt(ostream &pout, istream &pin);
	//Helpers
		int StringToIntHelper(const string &a); 
	//TODO: a helper function that will retrieve an int from an input stream and ret a bool value that says whether or not
	//the int value was successfully retrieved or if there were problems.


	//Message Printers
	//Error Message
	void PrintOutOfBoundError(ostream &pout);
	
};


#endif
