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