#ifndef __ENTRYFILTER_H_INCLUDED__
#define __ENTRYFILTER_H_INCLUDED__


#include <TokenEvaluator/TypeTokenEvaluator.h>
#include <TokenEvaluator/NameTokenEvaluator.h>
#include <TokenEvaluator/MoveTokenEvaluator.h>
#include <string>
#include <stdlib.h>

using namespace std;

/*
	Entry Filter will be the class that takes tokens (from a filter set). that denote what moves, name, and
	Types the Factory Entry has, and will return a list(vector) 


	Layout 4 move tokens, 1 name token, 2 type tokens. This is due to this being the limit
	of an actual Pokemon.

	

	Functions are split into 3 categories.
	ResetFilter, SetFilter, Evaluate

	ResetFilter - clears out a certain filter.
	
	SetFilter - sets a certain filter to contain a certain value.

	Evaluate - evaluates all the filters that are currently set.
*/


class EntryFilter {
	public:
		EntryFilter();
		void Evaluate(vector<string> &res);

		void ResetAllFilters();

		void ResetAllMoveFilters();

		void ResetMoveFilter(int which);

		void ResetNameFilter();

		void ResetAllTypeFilters();

		void ResetTypeFilter(int which);

		void SetMoveFilter(int which,string move);

		void SetNameFilter(string name);

		void SetTypeFilter(int which, string type);
	private:
		string moves[4];
		string name;
		string types[2];		

		TypeTokenEvaluator tte;
		NameTokenEvaluator nte;
		MoveTokenEvaluator mte;
};





#endif
