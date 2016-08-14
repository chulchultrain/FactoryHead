#ifndef __NAMETOKENEVALUATOR_H_INCLUDED__
#define __NAMETOKENEVALUATOR_H_INCLUDED__

#include <TokenEvaluator/TokenEvaluator.h>
#include <map>


/*
	This is the class that evaluates name Tokens and returns all the EntryIDs
	of all the Factory Entries that are the pokemon with that name	

*/

class NameTokenEvaluator : public TokenEvaluator {
	public:
	NameTokenEvaluator();
	/*
		Given a name token, this function fills up the res vector with the EntryIDs
		of all the Factory Entries with that name.
	*/
	virtual void EvalToken(string nameToken, vector<string> &res);


	private:
	map<string, vector<string> > nameToEntry;



};




















#endif
