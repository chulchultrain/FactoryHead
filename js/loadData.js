
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
			console.log("AFTER LOAD DOC");
		}
	}
	xhttp.open("GET",url,true);
	xhttp.send();

}

function LoadNameToDexIDMap(xhttp) {
	console.log(xhttp.responseText);
	/*
	var newText = xhttp.responseText.split("\n");
	console.log("I have started logging Func");
	for(var i = 0; i < newText.length; i++) {
		var value = newText[i];
		i++;
		var key = newText[i];
		if(key != undefined) {
			NameToDexIDMap[key] = value;
			console.log(key + ' ' + value + ' ' + typeof key + ' ' + typeof value);			
		}

		i++;
	}
	console.log("I have finished initializing map");
	*/
	//TODO: Rid console log
	/*
	for(var e in NameToDexIDMap) {
		if(NameToDexIDMap.hasOwnProperty(e) ) {
			//console.log("HI");
			console.log(e + ' ' + NameToDexIDMap[e] + ' ' + typeof e + ' ' + typeof NameToDexIDMap[e]);
		}
	}
	*/
	console.log("I have finished printing map");
	console.log(NameToDexIDMap.Bulbasaur);
	console.log(NameToDexIDMap["Bulbasaur"]);
	return false;
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

function CalculateNameQuery() {
	var nameVal = document.getElementById("nameInput").value;
	console.log(NameToDexIDMap.Ivysaur);
	console.log(nameVal);
	console.log("Function Called");
	/*
	for(var e in NameToDexIDMap) {
		if(e == nameVal) {
			console.log(NameToDexIDMap[e]);
		} else {
			console.log(e + ' ' + typeof e + ' ' + nameVal + ' ' + typeof nameVal );			
		}
	}
	*/
	//document.getElementById("resOutput").value = NameToDexIDMap[nameVal];
	if(NameToDexIDMap.hasOwnProperty(nameVal)) {
		//$("#header").append(NameToDexIDMap[nameVal]);
		//console.log(NameToDexIDMap[nameVal]);
		document.getElementById("resOutput").value = NameToDexIDMap[nameVal];
	} else {
		console.log("CANNOT FIND");
	}
	return false;
}

loadDoc("BASE/NAME/Names.txt",LoadNameToDexIDMap);
console.log("AFTER ALL");

var derpus = {};
var a = "100";
derpus[a] = "200";
var b = "100";
console.log(derpus.b);
console.log(derpus[b]);