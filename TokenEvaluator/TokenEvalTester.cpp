#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <TokenEvaluator/TypeTokenEvaluator.h>
#include <MapGenerator/MapGenerator.h>

using namespace std;


void PrintVector(vector<string> &a) {
	for(unsigned int i = 0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

/*
	022 023 069 070 071 072 220 221 230 231 232 233 318 319 353 376 377 378 379 394 395 396 397 398 399 400 401 402 403 404 405 505 506 525 526 537 538 539 570 571 630 631 632 633 634 738 739 762 763 764 765 766 767 768 769 770 771 844 897 898 899 900 

*/

void TypeTokenEvaluatorUnitTest() {
	MapGenerator mg;
	mg.equals
	TypeTokenEvaluator tte;
	vector<string> poison;
	tte.EvalToken("Bug",poison);
	PrintVector(poison);
	

}


int main() {

	TypeTokenEvaluatorUnitTest();

	return 0;
}
