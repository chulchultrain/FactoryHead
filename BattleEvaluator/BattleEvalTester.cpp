#include <BattleEvaluator/BattleEvaluator.h>



using namespace std;

void BattleEvaluatorUnitTest() {
	BattleEvaluator be;
	be.Evaluate();

	be.SetName(0,"Bastiodon");
	be.SetMove(0,0,"Iron Head");
	be.SetMove(0,1,"Iron Defense");

	be.SetName(1,"Porygon-Z");
	be.SetMove(1,0,"Tri Attack");
	be.SetMove(1,1,"Conversion 2");

	be.EvaluateCriteria(0);
	be.EvaluateCriteria(1);

	be.SetParticipant(0,0);
	be.SetParticipant(1,0);

	be.Evaluate();	
}

int main() {
	BattleEvaluatorUnitTest();
	return 0;
}
