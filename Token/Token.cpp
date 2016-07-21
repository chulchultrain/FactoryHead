#include <Token/Token.h>

Token::Token() { tt = NONE; val = "";}

/*
	Don't waste time optimizing this. Other important parts.
	
*/
Token::Token(string t, string s) {
	if(t == "MOVE")
		tt = MOVE;
	else if(t == "NAME")
		tt = NAME;
	else if(t == "TYPE")
		tt = TYPE;
	else if(t == "ROUND")
		tt = ROUND;
	else
		tt = NONE;
	val = s;
} 

string Token::getVal() { return val;}

Token::TokenType Token::getTokenType() { return tt; }
