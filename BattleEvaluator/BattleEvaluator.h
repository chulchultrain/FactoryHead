#ifndef __BATTLEEVALUATOR_H_INCLUDED__
#define __BATTLEEVALUATOR_H_INCLUDED__


#include <PokemonEntry/PokemonEntry.h>
#include <EntryFilter/EntryFilter.h>

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
			Criteria() { name = ""; moves.resize(4);}
		};	

		BattleEvaluator();
		BattleEvaluator(int numWayBattle);
		~BattleEvaluator();
		void SetParticipant(int whichCriteria, int whichEntry);
		void Evaluate();
		void RetrieveResults(vector< vector<MoveResult> > &res);
		
		void SetName(int whichCriteria,string nameToBe);
		void SetType(int whichCriteria, string type);
		void SetMove(int whichCriteria, int whichMove, string moveName);
		void EvaluateCriteria(int whichCriteria);
		bool inBoundCriteria(int whichCriteria);

	private:
		EntryFilter ef;
		vector< vector<PokemonEntry> > fitsCriteria;
		vector<Criteria> crit;
		vector<PokemonEntry> battleEntries;
		vector< vector<MoveResult> > res;
		int numCriteria;


		
};









#endif
