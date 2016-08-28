#include <DataResolution/DataResolution.h>

#include <iostream>
#include <MapGenerator/MapGenerator.h>
#include <WorkingStats/WorkingStats.h>


map<string, EntryData> DataResolution::edata;
map<string, BaseStats> DataResolution::bsdata;
bool DataResolution::mapsInitialized;




DataResolution::DataResolution() {
	if(!mapsInitialized) {
		MapGenerator mg;
		mg.EntryIDToEntryDataMap(edata);
		mg.DexIDToBaseStatsMap(bsdata);
		mapsInitialized = true;
	}
	ef.ResetAllFilters();
}

void DataResolution::Input(string name, const vector<string> &moveList, const vector<int> &givenStats) {
	ef.ResetAllFilters();
	ef.SetNameFilter(name);
	for(unsigned i = 0; i < moveList.size() && i < 4; i++)
		ef.SetMoveFilter(i,moveList[i]);
	vector<string> eid;
	ef.Evaluate(eid);
	if(eid.size() != 1) {
		cout << "DATARESOLUTION.CPP/INPUT Problem. Not Enough Information to reduce to 1 EntryID.\n";
		cout << eid.size() << endl;
		return;
	}
	EntryData ed = edata[eid[0]];
	BaseStats bs = bsdata[ed.DexID];
	WorkingStats ws(givenStats);
	//cout << ed.nature << endl;
	vector<int> TrueEV = ws.CalculateEVs(bs,ed.nature);
	if(TrueEV != ed.EV) {
		cout << "Changed for EID: " << ed.ID << '\n';
		for(unsigned i = 0; i < TrueEV.size(); i++) {
			cout << TrueEV[i] << endl;
		}
	}
	
}
