#include <BaseStats/BaseStats.h>
#include <cstring>


BaseStats::BaseStats() {
	stats.resize(6,0);
}

BaseStats::BaseStats(int x1,int x2, int x3, int x4, int x5, int x6) {
	stats.resize(6,0);	
	stats[0] = x1;
	stats[1] = x2;
	stats[2] = x3;
	stats[3] = x4;
	stats[4] = x5;
	stats[5] = x6;
	
}

bool operator == (const BaseStats &lhs, const BaseStats &rhs) {
	return lhs.stats == rhs.stats;
}
