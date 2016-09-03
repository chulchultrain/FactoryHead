#include <WorkingStats/WorkingStats.h>



#include <string>
#include <iostream>
map<string, map<int,int> > WorkingStats::natureMul;
bool WorkingStats::mapsInitialized = false;

WorkingStats::WorkingStats(const vector<int> &bs, vector<int> EV, int IV, string nature) {
	if(!mapsInitialized) {
		initializeMaps();
		mapsInitialized = true;
	}
	stats.resize(6);
	stats[0] = CalcHP(bs[0],EV[0],IV,100);
	for(unsigned i = 1; i < 6; i++) {
		stats[i] = CalcNonHP(i,bs[i],EV[i],IV,100,nature);
	}	
}


WorkingStats::WorkingStats(const vector<int> &a) {
	if(!mapsInitialized) {
		initializeMaps();
		mapsInitialized = true;
	}
	stats = a;
	if(stats.size() != 6)
		stats.resize(6);
}
vector<int> WorkingStats::CalculateEVs(const vector<int> &bs, string nature) {
//	cout << natureMul[nature][5] << endl;


	int iv = CalculateIVs(bs,nature);
	//cout << iv << endl;
	if(iv == -1)
		return vector<int>(6,-1);
	return CalculateEVs(bs,iv,nature);
}

int  WorkingStats::CalculateIVs(const vector<int> &bs,string nature) {
	for(int i = 0; i <= 31; i++) {
		if( CalcHP(bs[0],0,i,100) == stats[0]) {
		//	cout << "HP FAIL\n";
			return i;
		}
		for(int j = 1; j < 6; j++) {
			if(CalcNonHP(j,bs[j],0,i,100,nature) == stats[j]) {
			//	cout << j << " FAIL\n";
				return i;
			}
		} 

	}
	return -1;
}
	


vector<int> WorkingStats::CalculateEVs(const vector<int> &bs, int IV,string nature) {
	vector<int> res(6,-1);
	int splitAcross = 0;
	if( CalcHP(bs[0],0,IV,100) == stats[0])
		res[0] = 0;
	for(int i = 1; i < 6; i++)
		if( CalcNonHP(i,bs[i],0,IV,100,nature) == stats[i])
			res[i] = 0;
	for(int j = 0; j < 6; j++)
		if( res[j] == -1)
			splitAcross++;
	if(splitAcross > 0 && splitAcross < 6) {
		for(int j = 0; j < 6; j++)
			if( res[j] == -1)
				res[j] = 510 / splitAcross;

		if( CalcHP(bs[0],res[0],IV,100) != stats[0]) {
				cout << "ERROR:WORKINGSTATS.CPP/CALCULATEEVS EV CANNOT MATCH STATS\n";
				cout << 0 << " " << res[0] << endl;			
		}
		for(int i = 1; i < 6; i++)
			if(CalcNonHP(i,bs[i],res[i],IV,100,nature) != stats[i]) {
				cout << "ERROR:WORKINGSTATS.CPP/CALCULATEEVS EV CANNOT MATCH STATS\n";
				cout << i << " " << res[i] << endl;
				return res;
			}			
	}
	return res;
}
		
void WorkingStats::initializeMaps() {
	MapGenerator mg;
	mg.NatureToStatMultiplierMap(natureMul);
/*
	if(natureMul.size() != 0) {
		cout << "MAPINIT SUCCESS\n";
		cout << natureMul.size() << endl;
	} else {
		cout << "MAPINIT FAIL\n";
	}
*/
}




int WorkingStats::CalcHP(int base, int EV, int IV,int level) {
	int res = 2 * base + IV + EV / 4;
	res *= level;
	res /= 100;
	res += (level + 10);
	return res;
}



int WorkingStats::CalcNonHP(int which, int base, int EV, int IV, int level,string nature) {
	int res = 2 * base + IV + EV / 4;
	res *= level;
	res /= 100;
	res += 5;
	double natureMultiplier = CalcNatureMultiplier(which,nature);
	res = int( double(res) * natureMultiplier);
	return res;
}


double WorkingStats::CalcNatureMultiplier(int which, string nature) {
	int code = natureMul[nature][which];
	switch(code) {
		case -1: return .9;
		case 1: return 1.1;
		default: return 1;
	}
	
}





