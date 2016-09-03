#include <MapGenerator/MapGenerator.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
#include <vector>

using namespace std;

/*
	MapGenerator Unit Test:
		Consists of Smaller Unit Tests which mean testing each of the maps
		that the MapGenerator supports.

		Test NameToDexIDMap(map<string,string> &m)
		Test TypeToDexIDListMap(map<string,vector<string> &m)
		Test DexIDToNameMap(map<string,string> &m);
		Test DexIDToTypeListMap(map<string,vector<string> &m)
		Test DexIDToEntryID
*/

void MapGeneratorUnitTest() {

}
/*
	This is dependent on the data in our files, which should have all the Pokemon
	from Gen 1 through Gen 5, whose IDs are the IDs taken from the List of Pokemon
	by Base Stats page on Bulbapedia.

	Will choose some random Pokemon. 
	Pokemon who have no spaces in their names, those who do.
	Pokemon whose IDs only contain numerical digits and those that also contain letters.

	
*/
void NameToDexIDMapUnitTest() {
	MapGenerator mg;
	map<string,string> m;
	mg.NameToDexIDMap(m);
	
	assert(m["Bulbasaur"] == "001" && "1");

	assert(m["Ivysaur"] == "002" && "2");
		
	assert(m["Venusaur"] == "003" && "3");

	assert(m["Meloetta (Pirouette Forme)"] == "648P" && "4");

	assert(m["Meloetta (Aria Forme)"] == "648" && "5");

	assert(m["Rotom (Mow Rotom)"] == "479L" && "6");

	
}



bool TestStringVectorPresence(vector<string> &a, string s) {
	int len = a.size();
	for(int i = 0; i < len; i++) {
		if(s == a[i])
			return true;
	}
	return false;
}

/*
	This is dependent on the data in our files, which should have all the Pokemon
	from Gen 1 through Gen 5, whose IDs are the IDs taken from the List of Pokemon
	by Base Stats page on Bulbapedia(we call these DexIDs). For every type, the DexIDs all the Pokemon with that type should appear int he vector.

	Partition:	
		Check one Pokemon from each type that exists in it.
		Check one Pokemon that doesnt exist in each type.
		Check one Pokemon that exists in 2 types.
	Grass
		
*/


void TypeToDexIDListMapUnitTest() {
	MapGenerator mg;
	map<string,vector<string> > m;
	mg.TypeToDexIDVectorMap(m);

	//dual pokemon
	assert(TestStringVectorPresence(m["Grass"],"001")); //bulbasaur
	assert(TestStringVectorPresence(m["Poison"],"001")); //ivysaur

	//shoudl be in 
	assert(TestStringVectorPresence(m["Grass"],"253")); //grovyle
	assert(TestStringVectorPresence(m["Normal"],"035")); //clefairy
	assert(TestStringVectorPresence(m["Fire"],"392")); //infernape
	assert(TestStringVectorPresence(m["Fighting"],"448")); //lucario
	assert(TestStringVectorPresence(m["Poison"],"024")); //arbok
	assert(TestStringVectorPresence(m["Water"],"062")); //poliwrath
 	assert(TestStringVectorPresence(m["Flying"],"018")); //pidgeot
	assert(TestStringVectorPresence(m["Electric"],"466")); //electivire
	assert(TestStringVectorPresence(m["Ground"],"450")); //hippowdon
	assert(TestStringVectorPresence(m["Psychic"],"065")); //alakazam
	assert(TestStringVectorPresence(m["Rock"],"112")); //Rhydon
	assert(TestStringVectorPresence(m["Ice"],"144")); //articuno
	assert(TestStringVectorPresence(m["Bug"],"214")); //heracross
	assert(TestStringVectorPresence(m["Dragon"],"445")); //garchomp
	assert(TestStringVectorPresence(m["Ghost"],"479")); //rotom (Normal Rotom)
	assert(TestStringVectorPresence(m["Dark"],"229")); //houndoom
	assert(TestStringVectorPresence(m["Steel"],"208")); //steelix

	assert(TestStringVectorPresence(m["Grass"],"035") == false); //clefairy
	assert(TestStringVectorPresence(m["Normal"],"253") == false); //groyvle
	assert(TestStringVectorPresence(m["Fighting"],"065") == false); //alakazam
	assert(TestStringVectorPresence(m["Poison"],"466") == false); //electivire
	assert(TestStringVectorPresence(m["Water"],"479O") == false); //rotom (heat rotom)
 	assert(TestStringVectorPresence(m["Flying"],"208") == false); //steelix
	assert(TestStringVectorPresence(m["Electric"],"229") == false); //houndoom
	assert(TestStringVectorPresence(m["Ground"],"214") == false); //heracross
	assert(TestStringVectorPresence(m["Psychic"],"466") == false); //electivire
	assert(TestStringVectorPresence(m["Rock"],"electivire") == false); //electivire
	assert(TestStringVectorPresence(m["Ice"],"214") == false); //heracross
	assert(TestStringVectorPresence(m["Bug"],"144") == false); //articuno
	assert(TestStringVectorPresence(m["Dragon"],"479O") == false); //heat rotom
	assert(TestStringVectorPresence(m["Ghost"],"208") == false); //steelix
	assert(TestStringVectorPresence(m["Dark"],"445") == false); //garchomp
	assert(TestStringVectorPresence(m["Steel"],"144") == false); //articuno	
}



/*
	For every DexID, the corresponding Pokemon Name should be the value of the map.
	Partition:
		DexIDs with just numbers, or also letters.
		Names that are single word, or multiple words.
		a DexID from each generation.
*/


void DexIDToNameMapUnitTest() {
	MapGenerator mg;
	map<string,string> m;
	mg.DexIDToNameMap(m);

	assert(m["001"] == "Bulbasaur" && "1");

	assert(m["002"] == "Ivysaur" && "2");
		
	assert(m["003"] == "Venusaur" && "3");

	assert(m["648P"] == "Meloetta (Pirouette Forme)" && "4");

	assert(m["648"] == "Meloetta (Aria Forme)" && "5");

	assert(m["479L"] == "Rotom (Mow Rotom)" && "6");
	
}

/*
	For every DexID, the appropriate types should be inside the vector that is the value of the map.
	Also, each of these types should appear once and only once.
	
*/


void DexIDToTypeVectorMapUnitTest() {
	MapGenerator mg;
	map<string,vector<string> > m;
	mg.DexIDToTypeVectorMap(m);
	
	assert(TestStringVectorPresence(m["001"],"Grass"));
	assert(TestStringVectorPresence(m["001"],"Poison"));
	assert(TestStringVectorPresence(m["001"],"Dark") == false);
	
	assert(TestStringVectorPresence(m["479L"],"Grass"));
	assert(TestStringVectorPresence(m["479L"],"Electric"));
	assert(TestStringVectorPresence(m["479L"],"Water") == false);

	
}

/*
	For every DexID, the map should be loaded with all the Entry IDs of the Factory Entries
	that have that DexID
*/

void DexIDToEntryIDVectorMapUnitTest() {
	MapGenerator mg;
	map<string,vector<string> > m;	
	mg.DexIDToEntryIDVectorMap(m);

	assert(TestStringVectorPresence(m["001"],"001"));
	assert(TestStringVectorPresence(m["002"],"003"));
	assert(TestStringVectorPresence(m["002"],"002"));
	assert(TestStringVectorPresence(m["002"],"100") == false);
	assert(TestStringVectorPresence(m["229"],"429"));
	assert(TestStringVectorPresence(m["229"],"430"));
	assert(TestStringVectorPresence(m["229"],"431"));
	assert(TestStringVectorPresence(m["229"],"432"));	
	assert(TestStringVectorPresence(m["229"],"434") == false);	
}

/*
	For every Type, the map should be loaded with all Entry IDs of the Factory Entries
	that have that Type.

	One for each type. An entry that should be presence in 2 types.

*/

void TypeToEntryIDVectorMapUnitTest()  {
	MapGenerator mg;
	map<string, vector<string> > m;
	mg.TypeToEntryIDVectorMap(m);

	assert(TestStringVectorPresence(m["Grass"],"001"));
	assert(TestStringVectorPresence(m["Normal"],"541"));
	assert(TestStringVectorPresence(m["Fire"],"011"));
	assert(TestStringVectorPresence(m["Flying"],"011"));
	assert(TestStringVectorPresence(m["Water"],"011") == false);
	assert(TestStringVectorPresence(m["Ground"],"840"));
	assert(TestStringVectorPresence(m["Poison"],"813"));
	assert(TestStringVectorPresence(m["Dark"],"813"));
	assert(TestStringVectorPresence(m["Psychic"],"813") == false);
	assert(TestStringVectorPresence(m["Electric"],"170"));
	assert(TestStringVectorPresence(m["Dragon"],"290"));
	assert(TestStringVectorPresence(m["Ice"],"933"));
	assert(TestStringVectorPresence(m["Ghost"],"933"));
	assert(TestStringVectorPresence(m["Bug"],"230"));
	assert(TestStringVectorPresence(m["Rock"],"194"));
	assert(TestStringVectorPresence(m["Steel"],"394"));	
	assert(TestStringVectorPresence(m["Fighting"],"394") == false);	
}

void MoveNameToMoveIDMapUnitTest() {
	MapGenerator mg;
	map<string,string> m;
	mg.MoveNameToMoveIDMap(m);

	assert(m["Pound"] == "001");
	assert(m["Karate Chop"] == "002");
	assert(m["Double-Edge"] == "038");
	assert(m["Protect"] == "182");
	assert(m["Sweet Kiss"] == "186");
}

void DexIDToBaseStatsUnitTest() {
	MapGenerator mg;
	map<string,vector<int> > m;
	mg.DexIDToBaseStatsMap(m);

	vector<int> bul(6);
	bul[0] = 45;
	bul[1] = 49;
	bul[2] = 49;
	bul[3] = 65;
	bul[4] = 65;
	bul[5] = 45;
	vector<int> bulbaTest = m["001"];
	assert(bulbaTest == bul);

	vector<int> ivy(6);
	ivy[0] = 60;
	ivy[1] = 62;
	ivy[2] = 63;
	ivy[3] = 80;
	ivy[4] = 80;
	ivy[5] = 60;
	assert(m["002"] == ivy);
		
	vector<int> ven(6);
	ven[0] = 80;
	ven[1] = 82;
	ven[2] = 83;
	ven[3] = 100;
	ven[4] = 100;
	ven[5] = 80;
	assert(m["003"] == ven);

	vector<int> mpf(6);
	mpf[0] = 100;
	mpf[1] = 128;
	mpf[2] = 90;
	mpf[3] = 77;
	mpf[4] = 77;
	mpf[5] = 128;
	assert(m["648P"] == mpf);

	vector<int> maf(6);
	maf[0] = 100;
	maf[1] = 77;
	maf[2] = 77;
	maf[3] = 128;
	maf[4] = 128;
	maf[5] = 90;
	assert(m["648"] == maf);
	vector<int> rmr(6);
	rmr[0] = 50;
	rmr[1] = 65;
	rmr[2] = 107;
	rmr[3] = 105;
	rmr[4] = 107;
	rmr[5] = 86;

	
	assert(m["479L"] == rmr);

}

void MoveIDToMoveDataMapUnitTest() {
/*
	assert(m["Pound"] == "001");
	assert(m["Karate Chop"] == "002");
	assert(m["Double-Edge"] == "038");
	assert(m["Protect"] == "182");
	assert(m["Sweet Kiss"] == "186");
	assert(m["Hyperspace Fury"] == "621");

	Pound, Karate Chpo, Double-Edge, Protect, Sweet Kiss, Hyperspace Fury
*/
	MapGenerator mg;
	map<string,MoveData> m;
	mg.MoveIDToMoveDataMap(m);	

	MoveData pound("001","Pound","Normal","Physical",40);
	assert(m["001"] == pound);

	MoveData karateChop("002","Karate Chop","Fighting","Physical",50);
	assert(m["002"] == karateChop);

	MoveData doubleEdge("038","Double-Edge","Normal","Physical",120);
	assert(m["038"] == doubleEdge);
	
	MoveData protect("182","Protect","Normal","Status",0);
	assert(m["182"] == protect);

	MoveData sweetKiss("186","Sweet Kiss","Normal","Status",0);
	assert(m["186"] == sweetKiss);


}

void EntryIDToEntryDataMapUnitTest() {
	MapGenerator mg;
	map <string, EntryData> m;
	mg.EntryIDToEntryDataMap(m);
/*
0  1  2 3 4  5
hp,a,d,sa,sd,s
*/
	vector<string> e001M(4);
	e001M[0] = "073";
	e001M[1] = "092";
	e001M[2] = "230";
	e001M[3] = "345";
	vector<int> e001E(6,0);
	e001E[4] = 255;
	e001E[5] = 255;
	EntryData e001("001","001",e001M,"BrightPowder","Modest",e001E);
	assert(m["001"] == e001);

	vector<string> e950M(4);
	e950M[0] = "058";
	e950M[1] = "094";
	e950M[2] = "236";
	e950M[3] = "324";
	vector<int> e950E(6,0);
	e950E[0] = 170;
	e950E[2] = 170;
	e950E[5] = 170;
	EntryData e950("950","488",e950M,"Leftovers","Modest",e950E);
	assert(m["950"] == e950);
	
	vector<string> e648M(4);
	e648M[0] = "073";
	e648M[1] = "075";
	e648M[2] = "332";
	e648M[3] = "445";
	vector<int> e648E(6,0);
	e648E[0] = 255;
	e648E[1] = 255;
	EntryData e648("648","357",e648M,"Lansat Berry","Adamant",e648E);
	assert(m["648"] == e648);
}

void NameToEntryIDVectorMapUnitTest() {
	MapGenerator mg;
	map <string, vector<string> > m;
	mg.NameToEntryIDVectorMap(m);

	assert(TestStringVectorPresence(m["Bulbasaur"],"001") );
	assert(TestStringVectorPresence(m["Ivysaur"],"002") );
	assert(TestStringVectorPresence(m["Ivysaur"],"003") );
	assert(TestStringVectorPresence(m["Venusaur"],"004") );	

	assert(TestStringVectorPresence(m["Cresselia"],"950") );
	assert(TestStringVectorPresence(m["Cresselia"],"949") );
	assert(TestStringVectorPresence(m["Cresselia"],"800") == false);	
	
	assert(TestStringVectorPresence(m["Mr. Mime"],"216") );
	assert(TestStringVectorPresence(m["Mr. Mime"],"215") == false);

	assert(TestStringVectorPresence(m["Steelix"],"383") );
	assert(TestStringVectorPresence(m["Steelix"],"384") );
	assert(TestStringVectorPresence(m["Steelix"],"385") );
	assert(TestStringVectorPresence(m["Steelix"],"386") );
	assert(TestStringVectorPresence(m["Steelix"],"387") == false );	

	assert(TestStringVectorPresence(m["Rhydon"], "194") );
	assert(TestStringVectorPresence(m["Rhydon"], "193") == false );
}

void MoveIDtoEntryIDVectorMapUnitTest() {
	MapGenerator mg;
	map<string, vector<string> > m;
	mg.MoveIDtoEntryIDVectorMap(m);
	
	//Thunder Punch
	assert(TestStringVectorPresence(m["009"],"035") );
	assert(TestStringVectorPresence(m["009"],"043") );
	assert(TestStringVectorPresence(m["009"],"108") );
	assert(TestStringVectorPresence(m["009"],"149") );
	assert(TestStringVectorPresence(m["009"],"410") );
	assert(TestStringVectorPresence(m["009"],"476") == false);
	assert(TestStringVectorPresence(m["447"],"589") );

	//Grass Knot
	assert(TestStringVectorPresence(m["447"],"621") );
	assert(TestStringVectorPresence(m["447"],"625") );
	assert(TestStringVectorPresence(m["447"],"626") == false);

	//Double-Edge
	assert(TestStringVectorPresence(m["038"],"129") );
	assert(TestStringVectorPresence(m["038"],"202") );
	assert(TestStringVectorPresence(m["038"],"201") == false);		
}


void MoveNameToEntryIDVectorMapUnitTest() {
	MapGenerator mg;	
	map<string, vector<string> > m;
	mg.MoveNameToEntryIDVectorMap(m);
	
	assert(TestStringVectorPresence(m["Payback"],"385") );
	assert(TestStringVectorPresence(m["Payback"],"390") );
	assert(TestStringVectorPresence(m["Payback"],"409") );
	assert(TestStringVectorPresence(m["Payback"],"426") );
	assert(TestStringVectorPresence(m["Payback"],"545") == false );

	assert(TestStringVectorPresence(m["Acupressure"],"845") );	
	assert(TestStringVectorPresence(m["Acupressure"],"139") );		

	assert(TestStringVectorPresence(m["Hammer Arm"],"196") );
}

void NatureToStatMultiplierMapUnitTest() {
	MapGenerator mg;
	map<string, map<int, int> > m;
	mg.NatureToStatMultiplierMap(m);

	assert(m["Lonely"][1] == 1);
	assert(m["Lonely"][2] == -1);
	assert(m["Lonely"][3] == 0);
	assert(m["Lonely"][0] == 0);
	assert(m["Lonely"][4] == 0);
	assert(m["Lonely"][5] == 0);

	assert(m["Careful"][4] == 1);
	assert(m["Careful"][3] == -1);
	assert(m["Careful"][2] == 0);
	assert(m["Careful"][1] == 0);
	assert(m["Careful"][0] == 0);
	assert(m["Careful"][5] == 0);

	
}

int main() {
	
	


	NameToDexIDMapUnitTest();
	TypeToDexIDListMapUnitTest();
	DexIDToNameMapUnitTest();
	DexIDToTypeVectorMapUnitTest();
	DexIDToEntryIDVectorMapUnitTest();
	TypeToEntryIDVectorMapUnitTest();	
	MoveNameToMoveIDMapUnitTest();
	DexIDToBaseStatsUnitTest();
	MoveIDToMoveDataMapUnitTest();
	EntryIDToEntryDataMapUnitTest();
	NameToEntryIDVectorMapUnitTest();
	MoveIDtoEntryIDVectorMapUnitTest();
	MoveNameToEntryIDVectorMapUnitTest(); 
	NatureToStatMultiplierMapUnitTest();
	cout << "Tests Finished Without A Hitch\n";
	return 0;
}
