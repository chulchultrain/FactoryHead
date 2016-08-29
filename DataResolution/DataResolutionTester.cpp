#include <DataResolution/DataResolution.h>









int main() {
	DataResolution dr;
	vector<string> moves;
	moves.push_back("Psychic");
	moves.push_back("Brine");
	moves.push_back("Trick Room");
	moves.push_back("Yawn");
	vector<int> ws(6);
	ws[0] = 373;
	ws[1] = 186;
	ws[2] = 238;
	ws[3] = 259;
	ws[4] = 298;
	ws[5] = 86;
	dr.Input("Slowking",moves,ws);

	




	return 0;
}
