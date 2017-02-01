
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

var NameToDexIDMap = {};
var DexIDToNameMap = {};
var MoveIDToMoveNameMap = {};
var MoveNameToMoveIDMap = {};
var DexIDToTypeMap = {};
var TypeToEntryIDMap = {};
var DexIDToEntryIDMap = {};
var MoveIDToEntryIDMap = {};
var EntryIDToEntryDataMap = {};

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

var NameDataLoaded = false;
var TypeDataLoaded = false;
var EntryDataLoaded = false;
var MoveDataLoaded = false;



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
	for(var i = 0; i < newText.length; i += 15) {
		var entryData = CreateEntryData(newText.slice(i,i+14));
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
}

function StringListIntersection(list1,list2) {
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
}

function CalculateNameQuery() {
	var nameVal = document.getElementById("nameInput").value.trim();
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
}

function CalculateTypeQuery() {
	var typeVal = document.getElementById("typeInput").value.trim();
	if(TypeToEntryIDMap.hasOwnProperty(typeVal)) {
		return TypeToEntryIDMap[typeVal];
	}
	return [];
}

function CalculateSingleMoveQuery(move) {
	var moveID = MoveNameToMoveIDMap[move];
	if(MoveNameToMoveIDMap.hasOwnProperty(move)) {
		var moveID = MoveNameToMoveIDMap[move];
		if(MoveIDToEntryIDMap.hasOwnProperty(moveID) ) {
			return MoveIDToEntryIDMap[moveID];
		}
	}

	return [];
}

function CalculateMovesQuery() {
	var resList = [];
	for(var i = 0; i < 4; i++) {
		var moveName = document.getElementById("moveInput" + String(i)).value.trim();
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
	} else {
		res = resList[0];
	}
	return res;
}

function CalculateEntryQuery() {
	var resList = [];

	var NameQueryResIDs = CalculateNameQuery();
	if(NameQueryResIDs.length > 0) {
		resList.push(NameQueryResIDs);
	} else {
		console.log("GG Failed");
	}
	var TypeQueryResIDs = CalculateTypeQuery();
	if(TypeQueryResIDs.length > 0) {
		resList.push(TypeQueryResIDs);
	} else {
		console.log("Type Fail");
	}
	var MoveQueryResIDs = CalculateMovesQuery();
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
	var whichEntry = Number(document.getElementById("whichEntryInput").value);
	var chosenOne = res[whichEntry % (res.length)];
	OutputEntryData(chosenOne);
	return false;
}

function OutputEntryData(x) {
	//TODO: Type
	var entryData = EntryIDToEntryDataMap[x];
	if(entryData == undefined) {
		console.log("und");
		return false;
	}
	document.getElementById("typeOutput").value = DexIDToTypeMap[entryData.dexID].join(' ');
	for(var i = 0; i < 4; i++) {
		document.getElementById("moveOutput" + String(i)).value = MoveIDToMoveNameMap[entryData.moves[i]];
	}
	for(var j = 0; j < 6; j++) {
		document.getElementById("EVOutput" + String(j)).value = entryData.EVs[j];
	}
	document.getElementById("itemOutput").value = entryData.item;
	document.getElementById("natureOutput").value = entryData.nature;
	return false;
}

function AllLoadedQuery() {
	return NameDataLoaded && EntryDataLoaded && TypeDataLoaded && MoveDataLoaded;
}

function LoadAllData() {
	loadDoc("BASE/NAME/Names.txt",LoadNameToDexIDMap);
	loadDoc("BASE/ENTRY/OutputEntryData.txt",LoadEntryIDToEntryDataMap);
	loadDoc("BASE/TYPE/Types.txt",LoadDexIDToTypeMap);
	loadDoc("BASE/MOVE/MoveData.txt",LoadMoveIDToMoveNameMap);

}

LoadAllData();