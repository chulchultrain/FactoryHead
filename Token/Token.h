#ifndef __TOKEN_H_INCLUDED__
#define __TOKEN_H_INCLUDED__

#include <stdlib.h>
#include <string>
using namespace std;

/*
	These Tokens will be used for holding info about the Battle Factory
	pokemon.
*/

class Token {
	public:
		enum TokenType { NONE,TYPE, NAME, MOVE, ROUND };
		Token();
		Token(TokenType t, string s);
		string getVal();
		TokenType getTokenType();
	private:
		TokenType tt;
		string val;
};


#endif
