#include <TokenEvaluator/TypeTokenEvaluator.h>
#include <MapGenerator/MapGenerator.h>

/*
	In the constructor, the map from type to Entry ID vector is initialized
	through use of MapGenerator's function TypeToEntryIDVectorMap. All the real work
	of this class is done here by another class. All that's left is vector
	copy constructor.
*/	

TypeTokenEvaluator::TypeTokenEvaluator() {
	MapGenerator mg;
	mg.TypeToEntryIDVectorMap(typeToEntry);
}

/*
	given a type token, this function fills up the res vector
	with the entry IDs of all the factory entries taht have that type
	
	The real work of this function was done inside the MapGenerator which 
	initialized the typeToEntry vector. All that's left is to actually access
	the map by index.
*/
void TypeTokenEvaluator::EvalToken(string typeToken, vector<string> &res) {
	res = typeToEntry[typeToken];
}
