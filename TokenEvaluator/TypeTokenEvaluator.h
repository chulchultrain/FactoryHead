#ifndef __TYPETOKENEVALUATOR_H_INCLUDED__
#define __TYPETOKENEVALUATOR_H_INCLUDED__

#include <TokenEvaluator/TokenEvaluator.h>
#include <map>

/*
	This is the class that evaluates Type Tokens and returns all the EntryIDs
	of all the Factory Entries that contain that type

*/

class TypeTokenEvaluator : public TokenEvaluator {
	public:
		TypeTokenEvaluator();
		/*
			given a type token, this function fills up the res vector
			with the entry IDs of all the factory entries taht have that type
		*/
		virtual void EvalToken(string typeToken, vector<string> &res);



	private:
		map<string,vector<string> > typeToEntry;
};




#endif
