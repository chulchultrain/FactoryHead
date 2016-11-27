#include <BattleEvaluator/BattleEvaluator.h>

#include <iostream>

using namespace std;

		struct MoveResult{
			pair<string,string> participants; //first = attacker, second = defender
			string moveName; //name of Move
			pair<int,int> damage; //first = minDamage,second = maxDamage
		};

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

void BattleEvaluatorUnitTest() {
	BattleEvaluator be;
	vector<BattleEvaluator::MoveResult> rr;
	be.Evaluate(0,1);
	be.RetrieveResults(rr,0,1);
	PrintRes(rr);

	be.resize(100);

	be.SetName(96,"Bastiodon");
	be.SetMove(96,0,"Iron Head");
	be.SetMove(96,1,"Iron Defense");
	be.SetIVs(96,31);
	be.SetIVs(1,31);

	be.SetName(1,"Porygon-Z");
	be.SetMove(1,0,"Tri Attack");
	be.SetMove(1,1,"Conversion 2");

	be.EvaluateCriteria(96);
	be.EvaluateCriteria(1);

	string pe;
	be.CandidateDescription(1,0,pe);
	cout << pe << endl;

	string cs;
	be.CriteriaDescription(1,cs);
	cout << cs << endl;

	be.SetParticipant(96,0);
	be.SetParticipant(1,0);

	be.Evaluate(96,1);	
	be.RetrieveResults(rr,96,1);


	PrintRes(rr);
	be.Evaluate(1,96);	
	be.RetrieveResults(rr,1,96);


	PrintRes(rr);
}

int main() {
	BattleEvaluatorUnitTest();
	return 0;
}
