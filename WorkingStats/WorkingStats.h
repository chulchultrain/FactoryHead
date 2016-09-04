#ifndef __WORKINGSTATS_H_INCLUDED__
#define __WORKINGSTATS_H_INCLUDED__

#include <MapGenerator/MapGenerator.h>
#include <stdlib.h>
#include <map>
#include <vector>
       
using namespace std;



		vector<int> CalcWorkingStats(const vector<int> &bs, vector<int> EV,int IV, string nature);
		int  CalculateIVs(const vector<int> &ws, const vector<int> &bs,string nature);
		vector<int> CalculateEVs(const vector<int> &ws, const vector<int> &bs, string nature);

		vector<int> CalculateEVs(const vector<int> &ws, const vector<int> &bs, int IV,string nature);
		int CalcHP(int base, int EV, int IV,int level);
		int CalcNonHP(int which, int base, int EV, int IV, int level,string nature);
		double CalcNatureMultiplier(int which, string nature) ;

		void initializeWorkingStatsMaps();


















#endif
