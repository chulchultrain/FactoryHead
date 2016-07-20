#include <Token/TypeToken.h>

TypeToken::TypeToken(string s) { 
	val = s; 
}

string TypeToken::getVal() {
	return val;
}


TokenType TypeToken::getTokenType() {
	return TYPE;
}
