#ifndef __BATTLESIM_H_INCLUDED__
#define __BATTLESIM_H_INCLUDED__

#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

/*
	Purpose of this class is to simulate a battle between 2 Pokemon Entries from the
	Pokemon Platinum Battle Factory, given only their names and move knowledge. 
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
		struct Criteria {
			string name;
			string type;
			vector<string> moves;
			Criteria() { name = ""; moves.resize(4);}
		};	

		enum str_code{
			INITCODE,
			PRINTSELECTIONS,
			SIMULATE,
			SETENTRY,
			SETNAME,
			SETMOVE,
			EXIT,
			INVALID
		};

		str_code HashString(string s);

		void SetCriterion(ostream &pout, istream &fin, Criteria &c);
		void SetCriteria(ostream &pout, istream &fin);
		void SetName(ostream &pout, istream &fin, string &name);
		void SetMoves(ostream &pout, istream &fin, vector<string> &moves);
		void SetMove(ostream &pout, istream &fin, string &move);

		void Simulate(ostream &pout,ostream &fout);

		bool promptSetOn;

		void PrintSelections(ostream &pout);
		
		void PrintBattle(ostream &fout);
		vector<Criteria> crit;
		string Prompt(ostream &pout, istream &pin);
	//Helpers
		int StringToIntHelper(const string &a); 
};


#endif
