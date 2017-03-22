
/*
	Backbone of this webapp

	loadData.js: Our model is to have the list of EntryData loaded, and create an inverted index of the list of EntryData.
	Let's say an entry is
	Charizard
	Fire/Flying
	Flamethrower
	Smokescreen
	More data etc.

	We keep an mapping of type to list of entries, name to list of entries, move to list of entries.
	So, the entry above would be in both the fire and flying keys of the type entries, and the charizard key of name entries, 
	and the smokescreen and flamethrower key of the move entries.

	As of right now, I am going to use XMLHttpRequest to get my data from my repo, but in the future, if I need to reduce bandwidth,
	then I will hardcode the data into a javascript file. It probably won't reduce it by much, but hopefully enough.
	Only things I can see is from headers from the requests. I seriously doubt I'll go over 100GB a month.
*/
//TODO: Move all functions inside namespace and change syntax accordingly. Get rid of front-end link and parameterize EntryFilter
//TODO: Precede mapSpace fields with mapSpace inside function scopes due to
//it checking global scope instead of enclosing scope.
var mapSpace = {
	
	mapData:{},
	InitMapNames:function() {
		mapSpace.NameToDexIDMap = {};
		mapSpace.DexIDToBaseStatsMap = {};
		mapSpace.DexIDToNameMap = {};
		mapSpace.MoveIDToMoveNameMap = {};
		mapSpace.MoveNameToMoveIDMap = {};
		mapSpace.DexIDToTypeMap = {};
		mapSpace.TypeToEntryIDMap = {};
		mapSpace.DexIDToEntryIDMap = {};
		mapSpace.MoveIDToEntryIDMap = {};
		mapSpace.EntryIDToEntryDataMap = {};
		mapSpace.NameDataLoaded = false;
		mapSpace.TypeDataLoaded = false;
		mapSpace.EntryDataLoaded = false;
		mapSpace.MoveDataLoaded = false;
		mapSpace.StatDataLoaded = false;	
		mapSpace.entryDataItems = [];
	} ,
	LoadDexIDToBaseStatsMap:function(xhttp) {
		var newText = xhttp.responseText.split("\n");
		var DexIDToBaseStatsMap = mapSpace.DexIDToBaseStatsMap;
		for(var i = 0; i < newText.length; i++) {
			if(newText[i+6] != undefined) {
				var dexID = newText[i].trim();
				DexIDToBaseStatsMap[dexID] = [];
				i++;
				for(var j = 0; j < 6; j++,i++) {
					DexIDToBaseStatsMap[dexID].push(newText[i].trim());
				}
			}
		}
		mapSpace.StatDataLoaded = true;
	} ,
	LoadMoveIDToEntryIDMap:function() {
		var EntryIDToEntryDataMap = mapSpace.EntryIDToEntryDataMap;
		var MoveIDToEntryIDMap = mapSpace.MoveIDToEntryIDMap;
		for(var entryID in EntryIDToEntryDataMap) {
			var moveList = EntryIDToEntryDataMap[entryID].moves;
			if(moveList != undefined) {
				for(var i = 0; i < moveList.length; i++) {
					if(!MoveIDToEntryIDMap.hasOwnProperty(moveList[i])) {
						MoveIDToEntryIDMap[moveList[i]] = [];
					}
					MoveIDToEntryIDMap[moveList[i]].push(entryID);
				}
			}
		}
	} ,
	LoadDexIDToNameMap:function() {
		var NameToDexIDMap = mapSpace.NameToDexIDMap;
		var DexIDToNameMap = mapSpace.DexIDToNameMap;
		for(var name in NameToDexIDMap) {
			var dexID = NameToDexIDMap[name];
			DexIDToNameMap[dexID] = name;
		}
	} ,
	LoadMoveNameToMoveIDMap:function() {
		var MoveIDToMoveNameMap = mapSpace.MoveIDToMoveNameMap;
		var MoveNameToMoveIDMap = mapSpace.MoveNameToMoveIDMap;
		for(var moveID in MoveIDToMoveNameMap) {
			var moveName = MoveIDToMoveNameMap[moveID];
			MoveNameToMoveIDMap[moveName] = moveID;
		}
	} ,
	LoadTypeToEntryIDMap:function() {
		var EntryIDToEntryDataMap = mapSpace.EntryIDToEntryDataMap;
		var DexIDToTypeMap = mapSpace.DexIDToTypeMap;
		var TypeToEntryIDMap = mapSpace.TypeToEntryIDMap;	
		for(var entryID in EntryIDToEntryDataMap) {
			var typeList = DexIDToTypeMap[EntryIDToEntryDataMap[entryID].dexID];
			if(typeList != undefined) {
				for(var i = 0; i < typeList.length; i++) {
					if(!TypeToEntryIDMap.hasOwnProperty(typeList[i]) ) {
						TypeToEntryIDMap[typeList[i]] = [];
					}
					TypeToEntryIDMap[typeList[i]].push(entryID);
				}			
			}

		}
	} ,
	loadDoc:function(url,doFunc) {
		var xhttp = new XMLHttpRequest();
		xhttp.responseType = 'text';
		xhttp.onreadystatechange = function() {
			if(this.readyState == 4 && this.status == 200) {
				doFunc(xhttp);
				console.log("AFTER LOAD DOC");
				if(mapSpace.AllLoadedQuery()) {
					mapSpace.LoadRestData();
				}
			} else {
				console.log(this.status);
			}
		}
		xhttp.open("GET",url,true);
		xhttp.send();

	} ,
	LoadRestData:function() {
		mapSpace.LoadDexIDToEntryIDMap();
		mapSpace.LoadDexIDToNameMap();
		mapSpace.LoadMoveNameToMoveIDMap();
		mapSpace.LoadTypeToEntryIDMap();	
		mapSpace.LoadMoveIDToEntryIDMap();
	} ,
	LoadNameToDexIDMap:function(xhttp) {
		
		var newText = xhttp.responseText.split("\n");
		//console.log("I have started logging Func");
		for(var i = 0; i < newText.length; i++) {
			if(newText[i] != undefined && newText[i+1] != undefined) {
				var value = newText[i].trim();
				i++;
				var key = newText[i].trim();
				mapSpace.NameToDexIDMap[key] = value;
				//console.log(key + ' ' + value + ' ' + typeof key + ' ' + typeof value);			
				i++;			
			}

		}
		//console.log("I have finished initializing map");
		
		//TODO: Rid console log
		//console.log("I have finished printing map");
		mapSpace.NameDataLoaded = true;
		return false;
	} ,
	LoadMoveIDToMoveNameMap:function(xhttp) {
		var newText = xhttp.responseText.split('\n');
		for(var i = 0; i < newText.length; i += 6) {
			if(newText[i+1] != undefined) {
				var moveID = newText[i].trim();
				var moveName = newText[i+1].trim();
				mapSpace.MoveIDToMoveNameMap[moveID] = moveName;			
			}

			
		}
		mapSpace.MoveDataLoaded = true;
	} ,
	CreateEntryData:function(unfilteredDataArray){ 
		var i = 0;
		var entryData = {};
		var dataArray = [];
		for(var k = 0; k < unfilteredDataArray.length; k++) {
			dataArray.push(unfilteredDataArray[k].trim());
		}
		entryData.entryID = dataArray[i];
		i++;
		entryData.dexID = dataArray[i];
		i++;
		entryData.moves = [];
		for(var j = 0; j < 4; j++,i++) {
			entryData.moves.push(dataArray[i]);
		}
		entryData.ability = dataArray[i];
		i++;
		entryData.item = dataArray[i];
		i++;
		entryData.nature = dataArray[i];
		i++;
		entryData.EVs = [];
		for(var k = 0; k < 6; k++,i++) {
			entryData.EVs.push(dataArray[i]);
		}
		return entryData;
	} ,
	LoadDexIDToEntryIDMap:function() {
		var EntryIDToEntryDataMap = mapSpace.EntryIDToEntryDataMap;
		var DexIDToEntryIDMap = mapSpace.DexIDToEntryIDMap;
		
		for(var eID in EntryIDToEntryDataMap) {
			var entryData = EntryIDToEntryDataMap[eID];
			if(!DexIDToEntryIDMap.hasOwnProperty(entryData.dexID)) {
				DexIDToEntryIDMap[entryData.dexID] = [];
			}
			DexIDToEntryIDMap[entryData.dexID].push(entryData.entryID);
		}
		console.log("DIDENTRYIDFIN");
	} ,
	LoadEntryIDToEntryDataMap:function(xhttp) {
		var EntryIDToEntryDataMap = mapSpace.EntryIDToEntryDataMap;
		var newText = xhttp.responseText.split('\n');
		for(var i = 0; i < newText.length; i += 16) {
			var entryData = mapSpace.CreateEntryData(newText.slice(i,i+15));
			//console.log(newText[i]);
			EntryIDToEntryDataMap[entryData.entryID] = entryData;
		}
		
		mapSpace.EntryDataLoaded = true;
		console.log("Finised This one");
		return false;
	} ,
	LoadDexIDToTypeMap:function(xhttp) {
		var DexIDToTypeMap = mapSpace.DexIDToTypeMap;
		
		var newText = xhttp.responseText.split('\n');
		for(var i = 0; i < newText.length; i++) {
			if(newText[i] != undefined) {
				var dataPieces = newText[i].trim().split(' ');
				var dexID = dataPieces[0];
				var numTypes = Number(dataPieces[1]);
				var typeList = [];
				for(var j = 0; j < numTypes; j++) {
					typeList.push(dataPieces[j+2]);
				}
				DexIDToTypeMap[dexID] = typeList;
			}

		}
		mapSpace.TypeDataLoaded = true;
		console.log(DexIDToTypeMap.length);
	}	,
	AllLoadedQuery:function() {
		return mapSpace.NameDataLoaded 
		&& mapSpace.EntryDataLoaded 
		&& mapSpace.TypeDataLoaded 
		&& mapSpace.MoveDataLoaded 
		&& mapSpace.StatDataLoaded;
	} ,
	LoadAllData:function() {
		mapSpace.loadDoc("BASE/NAME/Names.txt",mapSpace.LoadNameToDexIDMap);
		mapSpace.loadDoc("BASE/ENTRY/WebEntryData.txt",mapSpace.LoadEntryIDToEntryDataMap);
		mapSpace.loadDoc("BASE/TYPE/Types.txt",mapSpace.LoadDexIDToTypeMap);
		mapSpace.loadDoc("BASE/MOVE/MoveData.txt",mapSpace.LoadMoveIDToMoveNameMap);
		mapSpace.loadDoc("BASE/STATS/BaseStats.txt",mapSpace.LoadDexIDToBaseStatsMap);
	} ,
	StringListIntersection:function(list1,list2) {
		var res = [];
		var seen = {};
		for(var i = 0; i < list1.length; i++) {
			seen[list1[i]] = true;
		}
		for(var j = 0; j < list2.length; j++) {
			if(seen.hasOwnProperty(list2[j]) ) {
				res.push(list2[j]);
			}
		}
		return res;
	} ,

	CalculateNameQuery:function(name) {
		var nameVal = name.trim();
		var NameToDexIDMap = mapSpace.NameToDexIDMap;
		var DexIDToEntryIDMap = mapSpace.DexIDToEntryIDMap;
		/*

		console.log(nameVal);
		console.log("Function Called");
		*/
		if(NameToDexIDMap.hasOwnProperty(nameVal)) {
			var dID = NameToDexIDMap[nameVal];
			if(DexIDToEntryIDMap.hasOwnProperty(dID)) {
				return DexIDToEntryIDMap[dID];
			}
		}
		
		return [];
	} ,

	CalculateTypeQuery:function(type) {
		var TypeToEntryIDMap = mapSpace.TypeToEntryIDMap;
		var typeVal = type.trim();
		if(TypeToEntryIDMap.hasOwnProperty(typeVal)) {
			return TypeToEntryIDMap[typeVal];
		}
		return [];
	} ,

	CalculateSingleMoveQuery:function(move) {
		var moveID = MoveNameToMoveIDMap[move];
		var MoveNameToMoveIDMap = mapSpace.MoveNameToMoveIDMap;
		var MoveIDToEntryIDMap = mapSpace.MoveIDToEntryIDMap;
		
		if(MoveNameToMoveIDMap.hasOwnProperty(move)) {
			var moveID = MoveNameToMoveIDMap[move];
			if(MoveIDToEntryIDMap.hasOwnProperty(moveID) ) {
				return MoveIDToEntryIDMap[moveID];
			}
		}

		return [];
	} ,

	CalculateMovesQuery:function(moveList) {
		var resList = [];
		var StringListIntersection = mapSpace.StringListIntersection;
		var CalculateSingleMoveQuery = mapSpace.CalculateSingleMoveQuery;
		
		for(var i = 0; i < 4; i++) {
			var moveName = moveList[i].trim();
			if(moveName.length > 0) {
				resList.push(CalculateSingleMoveQuery(moveName));
			}
		}
		var res = [];
		if(resList.length >= 2) {
			res = StringListIntersection(resList[0],resList[1]);
			for(var i = 2; i < resList.length; i++) {
				res = StringListIntersection(res,resList[i]);
			}
		} else if(resList.length == 1){
			res = resList[0];
		} else {
			res = resList;
		}
		return res;
	} ,

	CalculateEntryQuery:function(entryQuery) {
		var resList = [];
		
		var CalculateNameQuery = mapSpace.CalculateNameQuery;
		var CalculateTypeQuery = mapSpace.CalculateTypeQuery;
		var CalculateMovesQuery = mapSpace.CalculateMovesQuery;
		var StringListIntersection = mapSpace.StringListIntersection;

		var NameQueryResIDs = CalculateNameQuery(entryQuery.name);
		if(NameQueryResIDs.length > 0) {
			resList.push(NameQueryResIDs);
		} else {
			console.log("GG Failed");
		}
		var TypeQueryResIDs = CalculateTypeQuery(entryQuery.type);
		if(TypeQueryResIDs.length > 0) {
			resList.push(TypeQueryResIDs);
		} else {
			console.log("Type Fail");
		}
		var MoveQueryResIDs = CalculateMovesQuery(entryQuery.moveList);
		if(MoveQueryResIDs.length > 0) {
			resList.push(MoveQueryResIDs);
		} else {
			console.log("Move Fail");
		}
		var res = [];
		if(resList.length >= 2) {
			res = StringListIntersection(resList[0],resList[1]);
			for(var i = 2; i < resList.length; i++) {
				res = StringListIntersection(res,resList[i]);
			}
		} else {
			res = resList[0];
		}
		return res;
	}

};
/* PREVIOUS VARS
var entryDataItems = [
	
];

var NameToDexIDMap = {};
var DexIDToBaseStatsMap = {};
var DexIDToNameMap = {};
var MoveIDToMoveNameMap = {};
var MoveNameToMoveIDMap = {};
var DexIDToTypeMap = {};
var TypeToEntryIDMap = {};
var DexIDToEntryIDMap = {};
var MoveIDToEntryIDMap = {};
var EntryIDToEntryDataMap = {};
var selectedEntry = 0;

var NameDataLoaded = false;
var TypeDataLoaded = false;
var EntryDataLoaded = false;
var MoveDataLoaded = false;
var StatDataLoaded = false;
*/
/* PREVIOUS INIT FUNCTIONS
function LoadDexIDToBaseStatsMap(xhttp) {
	var newText = xhttp.responseText.split("\n");
	for(var i = 0; i < newText.length; i++) {
		if(newText[i+6] != undefined) {
			var dexID = newText[i].trim();
			DexIDToBaseStatsMap[dexID] = [];
			i++;
			for(var j = 0; j < 6; j++,i++) {
				DexIDToBaseStatsMap[dexID].push(newText[i].trim());
			}
		}
	}
	StatDataLoaded = true;
}


function LoadMoveIDToEntryIDMap() {
	for(var entryID in EntryIDToEntryDataMap) {
		var moveList = EntryIDToEntryDataMap[entryID].moves;
		if(moveList != undefined) {
			for(var i = 0; i < moveList.length; i++) {
				if(!MoveIDToEntryIDMap.hasOwnProperty(moveList[i])) {
					MoveIDToEntryIDMap[moveList[i]] = [];
				}
				MoveIDToEntryIDMap[moveList[i]].push(entryID);
			}
		}
	}
}

function LoadDexIDToNameMap() {
	for(var name in NameToDexIDMap) {
		var dexID = NameToDexIDMap[name];
		DexIDToNameMap[dexID] = name;
	}
}

function LoadMoveNameToMoveIDMap() {
	for(var moveID in MoveIDToMoveNameMap) {
		var moveName = MoveIDToMoveNameMap[moveID];
		MoveNameToMoveIDMap[moveName] = moveID;
	}
}

function LoadTypeToEntryIDMap() {
	for(var entryID in EntryIDToEntryDataMap) {
		var typeList = DexIDToTypeMap[EntryIDToEntryDataMap[entryID].dexID];
		if(typeList != undefined) {
			for(var i = 0; i < typeList.length; i++) {
				if(!TypeToEntryIDMap.hasOwnProperty(typeList[i]) ) {
					TypeToEntryIDMap[typeList[i]] = [];
				}
				TypeToEntryIDMap[typeList[i]].push(entryID);
			}			
		}

	}
}




function loadDoc(url,doFunc) {
	var xhttp = new XMLHttpRequest();
	xhttp.responseType = 'text';
	xhttp.onreadystatechange = function() {
		if(this.readyState == 4 && this.status == 200) {
			doFunc(xhttp);
			console.log("AFTER LOAD DOC");
			if(AllLoadedQuery()) {
				LoadRestData();
			}
		} else {
			console.log(this.status);
		}
	}
	xhttp.open("GET",url,true);
	xhttp.send();

}

function LoadRestData() {
	LoadDexIDToEntryIDMap();
	LoadDexIDToNameMap();
	LoadMoveNameToMoveIDMap();
	LoadTypeToEntryIDMap();	
	LoadMoveIDToEntryIDMap();
}


function LoadNameToDexIDMap(xhttp) {
	
	var newText = xhttp.responseText.split("\n");
	//console.log("I have started logging Func");
	for(var i = 0; i < newText.length; i++) {
		if(newText[i] != undefined && newText[i+1] != undefined) {
			var value = newText[i].trim();
			i++;
			var key = newText[i].trim();
			NameToDexIDMap[key] = value;
			//console.log(key + ' ' + value + ' ' + typeof key + ' ' + typeof value);			
			i++;			
		}

	}
	//console.log("I have finished initializing map");
	
	//TODO: Rid console log
	//console.log("I have finished printing map");
	NameDataLoaded = true;
	return false;
}

function LoadMoveIDToMoveNameMap(xhttp) {
	var newText = xhttp.responseText.split('\n');
	for(var i = 0; i < newText.length; i += 6) {
		if(newText[i+1] != undefined) {
			var moveID = newText[i].trim();
			var moveName = newText[i+1].trim();
			MoveIDToMoveNameMap[moveID] = moveName;			
		}

		
	}
	MoveDataLoaded = true;
}


function CreateEntryData(unfilteredDataArray){ 
	var i = 0;
	var entryData = {};
	var dataArray = [];
	for(var k = 0; k < unfilteredDataArray.length; k++) {
		dataArray.push(unfilteredDataArray[k].trim());
	}
	entryData.entryID = dataArray[i];
	i++;
	entryData.dexID = dataArray[i];
	i++;
	entryData.moves = [];
	for(var j = 0; j < 4; j++,i++) {
		entryData.moves.push(dataArray[i]);
	}
	entryData.ability = dataArray[i];
	i++;
	entryData.item = dataArray[i];
	i++;
	entryData.nature = dataArray[i];
	i++;
	entryData.EVs = [];
	for(var k = 0; k < 6; k++,i++) {
		entryData.EVs.push(dataArray[i]);
	}
	return entryData;
}

function LoadDexIDToEntryIDMap() {
	for(var eID in EntryIDToEntryDataMap) {
		var entryData = EntryIDToEntryDataMap[eID];
		if(!DexIDToEntryIDMap.hasOwnProperty(entryData.dexID)) {
			DexIDToEntryIDMap[entryData.dexID] = [];
		}
		DexIDToEntryIDMap[entryData.dexID].push(entryData.entryID);
	}
	console.log("DIDENTRYIDFIN");
}

function LoadEntryIDToEntryDataMap(xhttp) {
	var newText = xhttp.responseText.split('\n');
	for(var i = 0; i < newText.length; i += 16) {
		var entryData = CreateEntryData(newText.slice(i,i+15));
		//console.log(newText[i]);
		EntryIDToEntryDataMap[entryData.entryID] = entryData;
	}
	
	EntryDataLoaded = true;
	console.log("Finised This one");
	return false;
}



function LoadDexIDToTypeMap(xhttp) {
	var newText = xhttp.responseText.split('\n');
	for(var i = 0; i < newText.length; i++) {
		if(newText[i] != undefined) {
			var dataPieces = newText[i].trim().split(' ');
			var dexID = dataPieces[0];
			var numTypes = Number(dataPieces[1]);
			var typeList = [];
			for(var j = 0; j < numTypes; j++) {
				typeList.push(dataPieces[j+2]);
			}
			DexIDToTypeMap[dexID] = typeList;
		}

	}
	TypeDataLoaded = true;
	console.log(DexIDToTypeMap.length);
}
*/
//TODO: Be careful starting here. This is the query portion and we need to decouple front-end back-end here.cccccc


var queryRes = [];
var selectedEntry = 0;

//NEW TOP LEVEL
function BuildEntryQuery() {
	var entryQuery = {};
	entryQuery.name = $('#' + 'nameInput').val();
	console.log(entryQuery.name + " " + typeof(entryQuery.name));
	entryQuery.type = $('#' + 'typeInput').val();
	entryQuery.moveList = [];
	for(var i = 0; i < 4; i++) {
		entryQuery.moveList[i] = $('#' + 'moveInput' + String(i)).val();
	}
	return entryQuery;
}

function EntryFormSubmit() {
	var entryQuery = BuildEntryQuery();
	var res = mapSpace.CalculateEntryQuery(entryQuery);
	selectedEntry = 0;
	queryRes = res;
	
	OutputEntryData(queryRes[selectedEntry]);
	document.getElementById('querySize').value = queryRes.length;
	return false;
}


function GetPrevEntry() {
	selectedEntry--;
	if(selectedEntry < 0) {
		selectedEntry += queryRes.length;
	}
	OutputEntryData(queryRes[selectedEntry]);	
	return false;
}

function GetNextEntry() {
	selectedEntry++;
	selectedEntry %= queryRes.length;
	OutputEntryData(queryRes[selectedEntry]);
	return false;
}

function GetSelectedEntry() {
	var whichEntry = Number(document.getElementById("whichEntryInput").value);
	var chosenOne = queryRes[whichEntry % (queryRes.length)];
	OutputEntryData(chosenOne);
	return false;
}

function OutputEntryData(x) {
	//TODO: Type
	var EntryIDToEntryDataMap = mapSpace.EntryIDToEntryDataMap;
	var DexIDToBaseStatsMap = mapSpace.DexIDToBaseStatsMap;
	var DexIDToNameMap = mapSpace.DexIDToNameMap;
	var DexIDToTypeMap = mapSpace.DexIDToTypeMap;
	var MoveIDToMoveNameMap = mapSpace.MoveIDToMoveNameMap;
	
	var entryData = EntryIDToEntryDataMap[x];
	if(entryData == undefined) {
		console.log("und");
		return false;
	}
	for(var i = 0;i < 6; i++) {
		document.getElementById('baseStatOutput' + String(i)).value = DexIDToBaseStatsMap[entryData.dexID][i];
	}
	document.getElementById("nameOutput").value = DexIDToNameMap[entryData.dexID];
	document.getElementById("typeOutput").value = DexIDToTypeMap[entryData.dexID].join(' ');
	document.getElementById("abilityOutput").value = entryData.ability;
	for(var i = 0; i < 4; i++) {
		document.getElementById("moveOutput" + String(i)).value = MoveIDToMoveNameMap[entryData.moves[i]];
	}
	for(var j = 0; j < 6; j++) {
		document.getElementById("EVOutput" + String(j)).value = entryData.EVs[j];
	}
	document.getElementById("itemOutput").value = entryData.item;
	document.getElementById("natureOutput").value = entryData.nature;
	// $('#nonono').append("nerpus");
	// $('#outputTag').val(entryData.item); jquery example of setting HTML element value

	return false;
}


mapSpace.InitMapNames();
mapSpace.LoadAllData();
