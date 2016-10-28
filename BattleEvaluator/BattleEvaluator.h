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
			string toString();
					    
		};	

		BattleEvaluator(); 
		BattleEvaluator(int numWayBattle);
		~BattleEvaluator();

		void resize(int n);

		//SETTING CRITERIA
		void SetName(int whichCriteria,string nameToBe);
		void SetType(int whichCriteria, string type);
		void SetMove(int whichCriteria, int whichMove, string moveName);
		void SetIVs(int whichCriteria,int IV);

		void CriteriaDescription(int whichCriteria, string &res);

		//EVALUTE CRITERIA AND RETRIEVE RESULTS
		void EvaluateCriteria(int whichCriteria);
	
		//TODO: IMPLEMENT
		void CandidateDescription(int whichCriteria, int whichEntry, string &res);
		int CandidateListSize(int whichCriteria);

		void SetParticipant(int whichCriteria, int whichEntry);

		void ParticipantDescription(int whichCriteria, string &res);
		

		void Evaluate(int i,int j);
		void RetrieveResults( vector<MoveResult> &results,int i,int j);

		int size();

		//HELPER
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
