
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
var MoveNameToMoveIDMap = {};
var DexIDToTypeMap = {};
var DexIDToEntryIDMap = {};
var EntryIDToEntryDataMap = {};



function loadDoc(url,doFunc) {
	var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function() {
		if(this.readyState == 4 && this.status == 200) {
			doFunc(xhttp);
		}
	}
	xhttp.open("GET",url,true);
	xhttp.send();
	
}

function LoadNameToDexIDMap(xhttp) {
	var newText = xhttp.responseText.split("\n");
	for(var i = 0; i < newText.length; i++) {
		var value = newText[i];
		i++;
		var key = newText[i];
		NameToDexIDMap[key] = value;
	}
	//TODO: Rid console log
	for(var e in NameToDexIDMap) {
		console.log(e + ' ' NameToDexIDMap[e]);
	}
}

function LoadMoveNameToMoveIDMap(xhttp) {

}

function LoadDexIDToTypeMap(xhttp) {

}

function LoadEntryIDToEntryDataMap(xhttp) {

}

function CalculateNameToEntryIDMap() {

}


function ff(xhttp) {
	var newText = xhttp.responseText.split("\n");
	for(var e in newText) {
		if(newText[e] != "")
			console.log(newText[e]);
	}
}


loadDoc("BASE/NAME/Names.txt",LoadNameToDexIDMap);
