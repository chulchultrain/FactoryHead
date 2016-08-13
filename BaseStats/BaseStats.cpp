#include <BaseStats/BaseStats.h>
#include <cstring>

BaseStats::BaseStats() {
	HP = A = D = SA = SD = S = 0;
}

BaseStats::BaseStats(int x1,int x2, int x3, int x4, int x5, int x6) {
	HP = x1;
	A = x2;
	D = x3;
	SA = x4; 
	SD = x5;
	S = x6;
}

bool operator == (const BaseStats &lhs, const BaseStats &rhs) {
	int n = memcmp(&lhs,&rhs,sizeof(BaseStats));
	return n == 0;
}
