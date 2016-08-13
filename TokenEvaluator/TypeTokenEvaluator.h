#ifndef __TYPETOKENEVALUATOR_H_INCLUDED__
#define __TYPETOKENEVALUATOR_H_INCLUDED__

#include <TokenEvaluator/TokenEvaluator.h>
#include <map>

/*
	This is the class that evaluates Type Tokens and 

*/

class TypeTokenEvaluator : public TokenEvaluator {
	public:
		TypeTokenEvaluator();
		virtual void EvalToken(string token, vector<string> &res);



	private:
		map<string,vector<string> > typeToEntry;
};




#endif
