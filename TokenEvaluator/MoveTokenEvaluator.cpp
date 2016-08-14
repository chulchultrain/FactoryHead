#include <MapGenerator/MapGenerator.h>
#include <TokenEvaluator/MoveTokenEvaluator.h>

MoveTokenEvaluator::MoveTokenEvaluator() {
	MapGenerator mg;
	mg.MoveNameToEntryIDVectorMap(moveToEntry);

}

/*
	given a move token, this function fills up the res vector
	with the entry IDs of all the factory entries taht have that move

	The real work of this function was done inside the MapGenerator which 
	initialized the moveToEntry vector. All that's left is to actually access
	the map by index.
*/

void MoveTokenEvaluator::EvalToken(string moveToken, vector<string> &res) {
	res = moveToEntry[moveToken];
}
