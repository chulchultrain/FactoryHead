#ifndef __TOKEN_H_INCLUDED__
#define __TOKEN_H_INCLUDED__

#include <stdlib.h>
#include <string>
using namespace std;

class Token {
	public:
		virtual string getVal() = 0;
		enum TokenType { TYPE, NAME, MOVE, ROUND };
		virtual TokenType getTokenType() = 0;
	private:


};


#endif
