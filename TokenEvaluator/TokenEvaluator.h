#ifndef __TOKENEVALUATOR_H_INCLUDED__
#define __TOKENEVALUATOR_H_INCLUDED__

#include <string>
#include <vector>

using namespace std;

/*
	an abstract base class that serves as an interface for the Token
	Evaluators that I will create.

*/

class TokenEvaluator {
	public:
		
		virtual void EvalToken(string Token, vector<string> &res) = 0;
	private:




};


#endif
