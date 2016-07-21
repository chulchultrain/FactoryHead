#include <Token/Token.h>
#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;

/*
	
*/

int main() {
	Token *t = new Token(Token::TYPE,"herpes");
	if(t->getTokenType() == Token::TYPE)
		cout << "SUCCESS\n";
	else
		cout << "FAILURE\n";
	return 0;


}
