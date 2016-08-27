#include <EntryFilter/EntryFilter.h>

#include <iostream>
#include <cassert>
using namespace std;


/*
	Only setting a few and setting all.
	1 Move
	4 Move

	1 Type
	2 Type

	Name

	
*/

void EntryFilterUnitTest() {
	EntryFilter ef;
	
	//Entry 195
	ef.SetNameFilter("Rhydon");
	vector<string> res;
	ef.Evaluate(res);
	ef.SetMoveFilter(0,"Thunder Punch");
	ef.Evaluate(res);
	assert(res.size() == 1 && res[0] == "195");

	ef.ResetAllFilters();

	//All Magnezone Entries
	ef.SetNameFilter("Magnezone");
	vector <string> magnezone;
	magnezone.push_back("869");
	magnezone.push_back("870");
	magnezone.push_back("871");
	magnezone.push_back("872");
	ef.Evaluate(res);
	assert(res == magnezone);

	ef.ResetAllFilters();
	ef.SetNameFilter("Swampert");
	ef.SetTypeFilter(0,"Water");
	ef.SetTypeFilter(1,"Ground");
	ef.SetMoveFilter(0,"Earthquake");
	ef.SetMoveFilter(1,"Curse");
	ef.SetMoveFilter(2,"Hammer Arm");
	ef.SetMoveFilter(3,"Aqua Tail");
	ef.Evaluate(res);
	assert(res.size() == 1 && res[0] == "498");

	ef.ResetAllFilters();
	
	ef.SetTypeFilter(0,"Fire");
	ef.SetTypeFilter(1,"Flying");
	ef.Evaluate(res);
	//cout << res.size() << endl;
	assert(res.size() == 8);

	ef.ResetAllFilters();
	ef.SetMoveFilter(0,"Energy Ball");
	ef.SetMoveFilter(1,"Focus Blast");
	ef.Evaluate(res);
	//cout << res.size() << endl;
	assert(res.size() == 5);
}

int main () {

	EntryFilterUnitTest();

	cout << "Entry Filter Tests Finished Without a Hitch\n";
	return 0;
}
