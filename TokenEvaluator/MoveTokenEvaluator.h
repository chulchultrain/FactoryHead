#ifndef __MOVETOKENEVALUATOR_H_INCLUDED__
#define __MOVETOKENEVALUATOR_H_INCLUDED__

#include <TokenEvaluator/TokenEvaluator.h>
#include <map>

/*
	This is the class that evaluates Move Tokens and returns all the EntryIDs
	of all the Factory Entries that contain that move

	Moves here refer to the names of moves, rather than their moveID.
*/

class MoveTokenEvaluator : public TokenEvaluator {
	public:
		MoveTokenEvaluator();

		/*
			given a move token, this function fills up the res vector
			with the entry IDs of all the factory entries taht have that move
		*/
		virtual void EvalToken(string moveToken, vector<string> &res);		

	private:
		map<string, vector<string> > moveToEntry;
};
















#endif
