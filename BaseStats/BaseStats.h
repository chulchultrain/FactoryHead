#ifndef __BASESTATS_H_INCLUDED__
#define __BASESTATS_H_INCLUDED__



struct BaseStats {
	int HP;
	int A;
	int D;
	int SA;
	int SD;
	int S;
	BaseStats();
	BaseStats(int x1,int x2, int x3, int x4, int x5, int x6);
};

bool operator == (const BaseStats &lhs, const BaseStats &rhs);

#endif
