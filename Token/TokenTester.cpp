#include <Token/TypeToken.h>
#include <iostream>
#include <stdlib.h>
#include <map>

using namespace std;


int main() {
	Token *t = new TypeToken("herpes");
	if(t->getTokenType() == Token::TYPE)
		cout << "SUCCESS\n";
	else
		cout << "FAILURE\n";
	return 0;


}
