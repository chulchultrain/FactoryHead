#include <TokenEvaluator/TypeTokenEvaluator.h>
#include <MapGenerator/MapGenerator.h>


TypeTokenEvaluator::TypeTokenEvaluator() {
	MapGenerator mg;
	mg.TypeToEntryIDVectorMap(typeToEntry);
}

void TypeTokenEvaluator::EvalToken(string token, vector<string> &res) {
	res = typeToEntry[token];
}
