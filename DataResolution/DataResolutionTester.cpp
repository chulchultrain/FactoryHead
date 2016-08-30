#include <DataResolution/DataResolution.h>


#include <iostream>
using namespace std;

void PrintDRCriteria(string name, vector<string> &moves, vector<int> &stats) {
	cout << name << '\n';
	cout << "Moves:\n";
	for(unsigned i = 0; i < moves.size(); i++) {
		cout << moves[i] << '\n';
	}
	cout << "Stats:\n";
	for(unsigned i = 0; i < stats.size(); i++) {
		cout << stats[i] << '\n';
	}
	cout << '\n';	
}

void DRMenu() {
	DataResolution dr;
	vector<string> moves(4);
	vector<int> stats(6);
	string name;
	bool sentValue = true;
	int choice;
	int which;
	while(sentValue) {
		cout << "Enter Choice\n1 - name.\n2 - moves.\n3 - stats\n";
		cout << "4 - Print\n5 - Evaluate\n 6 - Cancel\n";
		cin >> choice;
		switch(choice) {
			case 1: cout << "Enter the name\n";
				cin >> name; break;
			case 2: cout << "Enter which move to change 0-3\n";
				cin >> which;
				if(which >= 0 && which < 4) {
					cout << "Enter move name\n";
					getline(cin,moves[which]);
					getline(cin,moves[which]);
				} else {
					cout << "Invalid move number. Need 0-3\n";
				}
				break;
			case 3: cout << "Enter which stat to change 0-5(HP,A,D,SA,SD,S)\n";
				cin >> which;
				if(which >= 0 && which < 6) {
					cout << "Enter stat amount\n";
					cin >> stats[which];
				} else {
					cout << "Invalid stat number. Need 0=5\n";
				}
				break;
			case 4: PrintDRCriteria(name,moves,stats);
				break;
			case 5: dr.Input(name,moves,stats);
				break;
			case 6: sentValue = false;
				break;
			default: cout << "INVALID CHOICE\n";
		}
	
	}


}




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
	DRMenu();
	




	return 0;
}
