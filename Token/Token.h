#ifndef __TOKEN_H_INCLUDED__
#define __TOKEN_H_INCLUDED__

#include <stdlib.h>
#include <string>
using namespace std;

/*
	These Tokens will be used for holding info about the Battle Factory
	pokemon. Main purpose is to be able to use the TokenType to call the
	correct Token Evaluator.
*/

class Token {
	public:
		/*
			the Type of Token.
		*/
		enum TokenType { NONE,TYPE, NAME, MOVE, ROUND };
		/*
			@return a Token that has a NONE Type and an empty string value.
		*/
		Token();
		/*
			@param t - the type of Token to make.
			Valid types t are string forms of the enum values to create
			their corresponding enum values.
			Precondition: Valid t

			@param s - the value of the Token to make. 
			@return - a token with a type t and a string val of s.

			string val of s
		*/
		Token(string t, string s);
		/*
			@return - the string value of the Token.
		*/
		string getVal();
		/*
			@return - the enum value of the Token representing the 
				type of Token it is.
		*/
		TokenType getTokenType();
	private:
		TokenType tt;
		string val;
};


#endif
