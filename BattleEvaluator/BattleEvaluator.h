#ifndef __BATTLEEVALUATOR_H_INCLUDED__
#define __BATTLEEVALUATOR_H_INCLUDED__


#include <PokemonEntry/PokemonEntry.h>
#include <EntryFilter/EntryFilter.h>

/*
	TODO:SET TYPE FILTER
	     MAGIC NUMBERS
	     GET FITCRITERIA
	     SET IVS

	     RESET CRITERIA
*/

/*
	This is the main high-level construct that will be used.
	BattleEvaluator is a class that can calculate PokemonEntries inside the 
	Pokemon Platinum Battle Factory.
	It can also calculate the results of a battle between 2 PokemonEntries.

	The purpose of this class is to streamline the process between these two steps.

	The class stores a list of criteria, a list of list of candidates and a list of actual participants.

	For each criteria, we can evaluate it to find the list of candidate Pokemon Entries that match the criteria.
	For each list of candidate entries, we can select one candidate entry to be a battle participant.
	And we can evaluate the damage of a move done by one battle participant to another battle participant.
	
	The list of criteria is of size N
	The list of list of candidates is size N (while each list of candidates may or may not be of size N).
	The list of actual participants is size N.
	N is the parameter we give to our class.
*/

using namespace std;

class BattleEvaluator {
	public:

		/*
			Data containing the damage range from an attacker to a defender using a certain move.
		*/	

		struct MoveResult{
			pair<string,string> participants; //first = attacker, second = defender
			string moveName; //name of Move
			pair<int,int> damage; //first = minDamage,second = maxDamage
		};

		/*
			Criteria - inputs used to calculate the PokemonEntry
		*/
		struct Criteria {
			string name;
			string type;
			vector<string> moves;
			int IV;
			Criteria() { name = ""; moves.resize(4); IV = 0;}
			string toString();
					    
		};	

		//Default Constructor. Will save information on 2 criterias
		BattleEvaluator(); 
		//Will save information on N criterias.
		BattleEvaluator(int N);
		~BattleEvaluator();



		//CRITERIA QUERIES

		//SET
		void SetName(int whichCriteria,string nameToBe);
		void SetType(int whichCriteria, string type);
		void SetMove(int whichCriteria, int whichMove, string moveName);
		void SetIVs(int whichCriteria,int IV);

		//RETRIEVE
		void CriteriaDescription(int whichCriteria, string &res);

		//EVALUATE
		void EvaluateCriteria(int whichCriteria);
	
		//CANDIDATE QUERIES

		//RETRIEVE
		void CandidateDescription(int whichCriteria, int whichEntry, string &res);
		int CandidateListSize(int whichCriteria);

		//PARTICIPANT QUERIES

		//SET
		void SetParticipant(int whichCriteria, int whichEntry);

		//RETRIEVE
		void ParticipantDescription(int whichCriteria, string &res);
		
		//EVALUATE
		void Evaluate(int i,int j);
		void RetrieveResults( vector<MoveResult> &results,int i,int j);


		//GENERAL QUERIES


		//CAN RESIZE AFTER CREATION
		void resize(int n);

		int size();
		//HELPER - use can be duplicated through use of size()
		bool inBoundCriteria(int whichCriteria);

	private:



		EntryFilter ef;
		vector< vector<PokemonEntry> > candidates;
		vector<Criteria> crit;
		vector<PokemonEntry> participants;
		vector<vector< vector<MoveResult> > >res;
		int numCriteria;


		
};









#endif
