var queryResIDs = [];
var selectedEntry = 0;

/*
	TODO:Make sure all buttons prev,next,forms work
*/

function EntryQToString(entryQuery) {
	var res = "";
	res += entryQuery.name + '\n';
	res += entryQuery.type + '\n';
	for(var i = 0; i < entryQuery.moveList.length; i++) {
		res += entryQuery.moveList[i] + '\n';
	}
	return res;
}

//NEW TOP LEVEL
function RetrieveEntryQueryInput() {
	var entryQuery = {};
	entryQuery.name = $('#' + 'nameInput').val();
	console.log(entryQuery.name + " " + typeof(entryQuery.name));
	entryQuery.type = $('#' + 'typeInput').val();
	entryQuery.moveList = [];
	for(var i = 0; i < 4; i++) {
		entryQuery.moveList[i] = $('#' + 'moveInput' + String(i)).val();
	}
	console.log(EntryQToString(entryQuery));
	return entryQuery;
}

function EntryFormSubmit() {
	var entryQuery = RetrieveEntryQueryInput();
	var resIDs = mapSpace.CalculateEntryIDList(entryQuery);
	selectedEntry = 0;
	queryResIDs = resIDs;
	var entryData = mapSpace.CalculateFullEntryData(resIDs[0]);
	OutputEntryData(entryData);
	document.getElementById('querySize').value = queryResIDs.length;
	return false;
}


function GetPrevEntry() {
	selectedEntry--;
	if(selectedEntry < 0) {
		selectedEntry += queryResIDs.length;
	}
	OutputEntryData(mapSpace.CalculateFullEntryData(queryResIDs[selectedEntry]));	
	return false;
}

function GetNextEntry() {
	selectedEntry++;
	selectedEntry %= queryResIDs.length;
	OutputEntryData(mapSpace.CalculateFullEntryData(queryResIDs[selectedEntry]));
	return false;
}

function GetSelectedEntry() {
	var whichEntry = Number(document.getElementById("whichEntryInput").value);
	selectedEntry = whichEntry % (queryResIDs.length);
	document.getElementById("whichEntryInput").value = selectedEntry;
	OutputEntryData(mapSpace.CalculateFullEntryData(queryResIDs[selectedEntry]));
	return false;
}

function OutputEntryData(entryData) {
	
			// baseStats - list
			// moves - list
			// EVs - list
			// name - string
			// type  - string
			// item - string
			// nature - string
	//TODO: Type
	var EntryIDToEntryDataMap = mapSpace.EntryIDToEntryDataMap;
	var DexIDToBaseStatsMap = mapSpace.DexIDToBaseStatsMap;
	var DexIDToNameMap = mapSpace.DexIDToNameMap;
	var DexIDToTypeMap = mapSpace.DexIDToTypeMap;
	var MoveIDToMoveNameMap = mapSpace.MoveIDToMoveNameMap;
	if(entryData == undefined) {
		return false;
	}
	for(var i = 0;i < 6; i++) {
		document.getElementById('baseStatOutput' + String(i)).value = entryData.baseStats[i];
	}
	document.getElementById("nameOutput").value = entryData.name;
	document.getElementById("typeOutput").value = entryData.type;
	document.getElementById("abilityOutput").value = entryData.ability;
	for(var i = 0; i < 4; i++) {
		document.getElementById("moveOutput" + String(i)).value = entryData.moves[i];
	}
	for(var j = 0; j < 6; j++) {
		document.getElementById("EVOutput" + String(j)).value = entryData.EVs[j];
	}
	document.getElementById("itemOutput").value = entryData.item;
	document.getElementById("natureOutput").value = entryData.nature;
	

	return false;
}