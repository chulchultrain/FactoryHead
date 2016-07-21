#include <Token/Token.h>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <cassert>
#include <vector>

using namespace std;

/*
	Token Test Function. Will test the constructor and whether the proper values
	can be retrieved from the class instance. 

	Types(as specified by the enum in the header file):
	NONE,TYPE, NAME, MOVE, ROUND

	Can have values of empty and non-empty strings.
	Non-empty have a space
*/
void TokenUnitTest() {

	Token a("TYPE","FIRE");
	
	assert(a.getTokenType() == Token::TYPE && a.getVal() == "FIRE" && "1");

	Token b("NONE","WATER");

	assert(b.getTokenType() == Token::NONE && b.getVal() == "WATER" && "2");
	
	Token c("NAME","MOVE");

	assert(c.getTokenType() == Token::NAME && c.getVal() == "MOVE" && "3");

	Token d("MOVE","Flamethrower");

	assert(d.getTokenType() == Token::MOVE && d.getVal() == "Flamethrower" && "4");

	Token e("ROUND","Solar Beam");

	assert(e.getTokenType() == Token::ROUND && e.getVal() == "Solar Beam" && "5");



}


int main() {
	TokenUnitTest();
	return 0;


}
