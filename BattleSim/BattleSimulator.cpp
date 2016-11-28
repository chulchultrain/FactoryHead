#include <BattleSim/BattleSim.h>
#include <fstream>

using namespace std;

int main() {
	BattleSim bs;
	//bs.Menu(cout,cin,cout);
	ifstream fin("BSTestData.txt");
	bs.Menu(cout,fin,cout);
	return 0;
}
