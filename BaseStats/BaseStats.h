#ifndef __BASESTATS_H_INCLUDED__
#define __BASESTATS_H_INCLUDED__

#include <vector>
using namespace std;

struct BaseStats {
	vector<int> stats;
	BaseStats();
	BaseStats(int x1,int x2, int x3, int x4, int x5, int x6);
};

bool operator == (const BaseStats &lhs, const BaseStats &rhs);

#endif
