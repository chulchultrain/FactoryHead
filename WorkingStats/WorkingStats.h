#ifndef __WORKINGSTATS_H_INCLUDED__
#define __WORKINGSTATS_H_INCLUDED__

#include <MapGenerator/MapGenerator.h>
#include <stdlib.h>
#include <map>
#include <vector>
       
using namespace std;

class WorkingStats {
	public:	
		WorkingStats() { stats.resize(6,0); }
		WorkingStats(const vector<int> &bs, vector<int> EV,int IV, string nature);
		WorkingStats(const vector<int> &a);
		int  CalculateIVs(const vector<int> &bs,string nature);
		vector<int> CalculateEVs(const vector<int> &bs, string nature);

		int getStat(string s);

		vector<int> stats;
	
	private:
		static map<string, map<int,int> > natureMul;
		static bool mapsInitialized;
		vector<int> CalculateEVs(const vector<int> &bs, int IV,string nature);


		void initializeMaps();

		int CalcHP(int base, int EV, int IV,int level);
		int CalcNonHP(int which, int base, int EV, int IV, int level,string nature);
		double CalcNatureMultiplier(int which, string nature) ;
};






























#endif
