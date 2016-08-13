#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <TokenEvaluator/TypeTokenEvaluator.h>

using namespace std;


void PrintVector(vector<string> &a) {
	for(unsigned int i = 0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}
	cout << endl;
}

void TypeTokenEvaluatorUnitTest() {
	TypeTokenEvaluator tte;
	vector<string> poison;
	tte.EvalToken("Bug",poison);
	PrintVector(poison);


}


int main() {

	TypeTokenEvaluatorUnitTest();

	return 0;
}
