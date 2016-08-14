#include <TokenEvaluator/NameTokenEvaluator.h>
#include <MapGenerator/MapGenerator.h>


NameTokenEvaluator::NameTokenEvaluator() {
	MapGenerator mg;
	mg.NameToEntryIDVectorMap(nameToEntry);
}


 void NameTokenEvaluator::EvalToken(string nameToken, vector<string> &res) {
	res = nameToEntry[nameToken];
}
