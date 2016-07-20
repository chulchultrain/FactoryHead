#ifndef __TYPETOKEN_H_INCLUDED__
#define __TYPETOKEN_H_INCLUDED__

#include <Token/Token.h>
#include <stdlib.h>
#include <string>
using namespace std;

class TypeToken : public Token {
	public:
		TypeToken(string s) { val = s; }
		virtual string getVal();
		virtual TokenType getTokenType();
	private:
		string val;

};

#endif
