#include <PokemonEntry/PokemonEntry.h>
#include <stdlib.h>
#include <string>
#include <cassert>
#include <iostream>
#include <utility>

using namespace std;




void PokemonEntryUnitTest() {
	
	PokemonEntry pz("917",31);
	PokemonEntry bs("760",31);
//	assert(pe.getStat(0) == 373);
//	assert(pe.getStat(1) == 186);
//	assert(pe.getStat(2) == 238);

	pair<int,int> s = pz.getMoveDamageRange(bs,"Tri Attack");
	cout << s.first << ' ' << s.second << '\n';
	
//	cout << pe.getStat(3) << endl;
//	cout << pe.getStat(4) << endl;
//	cout << pe.getStat(5) << endl;
//	
//	assert(pe.getStat(3) == 259);
//	assert(pe.getStat(4) == 298);
//	assert(pe.getStat(5) == 86);

}

int main() {
	PokemonEntryUnitTest();
	return 0;
}
