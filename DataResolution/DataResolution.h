#ifndef __DATARESOLUTION_H_INCLUDED__
#define __DATARESOLUTION_H_INCLUDED__


#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <EntryFilter/EntryFilter.h>
#include <EntryData/EntryData.h>
#include <MapGenerator/MapGenerator.h>

class DataResolution {
	public:
		DataResolution();
		void Input(string name, const vector<string> &moveList, const vector<int> &ws);
		
		struct Criteria {
			
		};


	private:
		EntryFilter ef;
		MapGenerator mg;
		static map<string, EntryData> edata;
		static map<string, vector<int> > bsdata;
		static bool mapsInitialized;

		
};
































#endif
