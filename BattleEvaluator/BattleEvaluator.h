#ifndef __BATTLEEVALUATOR_H_INCLUDED__
#define __BATTLEEVALUATOR_H_INCLUDED__


#include <PokemonEntry/PokemonEntry.h>
#include <EntryFilter/EntryFilter.h>

/*
	TODO:SET TYPE FILTER
	     MAGIC NUMBERS
	     GET FITCRITERIA
	     SET IVs
*/

using namespace std;

class BattleEvaluator {
	public:
	
		struct MoveResult{
			pair<string,string> participants; //first = attacker, second = defender
			string moveName; //name of Move
			pair<int,int> damage; //first = minDamage,second = maxDamage
		};

		struct Criteria {
			string name;
			string type;
			vector<string> moves;
			int IV;
			Criteria() { name = ""; moves.resize(4); IV = 0;}
		};	

		BattleEvaluator(); 
		BattleEvaluator(int numWayBattle);
		~BattleEvaluator();

		//SETTING CRITERIA
		void SetName(int whichCriteria,string nameToBe);
		void SetType(int whichCriteria, string type);
		void SetMove(int whichCriteria, int whichMove, string moveName);
		void SetIVs(int whichCriteria,int IV);

		//EVALUTE CRITERIA AND RETRIEVE RESULTS
		void EvaluateCriteria(int whichCriteria);
		void SetParticipant(int whichCriteria, int whichEntry);
		void Evaluate(int i,int j);
		void RetrieveResults( vector<MoveResult> &results,int i,int j);

		//HELPER
		bool inBoundCriteria(int whichCriteria);

	private:
		EntryFilter ef;
		vector< vector<PokemonEntry> > fitsCriteria;
		vector<Criteria> crit;
		vector<PokemonEntry> battleEntries;
		vector<vector< vector<MoveResult> > >res;
		int numCriteria;


		
};









#endif
