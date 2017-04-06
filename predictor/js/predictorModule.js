console.log('Reach PM.js');

var queryResIDs = [];
var moveData = {};
var moveDataArray = [];
/*
	Given a query, I wish to know what kind of data I can expect.
	Given my query, certain types are most expected.
	Given my query, certain moves are most expected.
	Given my query, certain species are most expected.
	
	This works because, given my query, I retrieve a list of possible Factory Entries.
	From this list of possible entries, I retrieve the data that is most likely.
	
	Process:
	Use mapper module to retrieve the list of possible entries from the query.
	From list of possible entries, for each of the types of data(moves,species,type,(in future high Stats of certain categories) ),
	
	For each type of data,
		keep a count of each value seen. Then put all of these values and their associated counts into an array and sort it.
		Then, retrieve the top values you want to see. Greater than or equal to a certain %.
		
		
*/

var predictSpace = {
	
	InitNameSpace:function() {
		predictSpace.queryResIDs = [];
		predictSpace.moveData = {};
		predictSpace.moveDataArray = [];
	},
	
	ProcessEntries:function() {
		var moveData = predictSpace.moveData;
		var queryResIDs = predictSpace.queryResIDs;
		var moveDataArray = predictSpace.moveDataArray;
		
		moveData = {};
		for(var i = 0; i < queryResIDs.length; i++) {
			var entryData = mapSpace.CalculateFullEntryData(queryResIDs[i]);
			
			for(var j = 0; j < entryData.moves.length; j++) {
				if(!moveData.hasOwnProperty(entryData.moves[j]) ) {
					moveData[entryData.moves[j]] = 0;
				}
				moveData[entryData.moves[j]]++;
			}
		}
		for(var move in moveData) {
			if(moveData.hasOwnProperty(move)) {
				moveDataArray.push([move, parseFloat(moveData[move]) / queryResIDs.length]);
			}
		}
		moveDataArray.sort(function(a,b) {return b[1]-a[1];});
	},
	
	CutOffFilter:function(cutoff) {
		var moveDataArray = predictSpace.moveDataArray;
		var res = [];
		for(var i = 0; i < moveDataArray.length; i++) {
			if(moveDataArray[i][1] >= cutoff) {
				res.push(moveDataArray[i]);
			}	
		}
		return res;
	},
	
	ProcessEntryQuery:function(entryQuery,cutoff) {
		predictSpace.moveDataArray = [];
		predictSpace.queryResIDs = mapSpace.CalculateEntryIDList(entryQuery);
		predictSpace.ProcessEntries();
		predictSpace.moveDataArray = predictSpace.CutOffFilter(cutoff);
		
		return predictSpace.moveDataArray;
	},
	
	PrintRes:function() {
		var moveDataArray = predictSpace.moveDataArray;
		for(var i = 0; i < moveDataArray.length; i++) {
			console.log(moveDataArray[i][0] + ' ' + moveDataArray[i][1]);
		}
	}
	
};
/*
function moveCountCompare(a,b) {
	return b[1] - a[1];
}*/

function CreateSampleQuery() {
	var entryQuery = {};
	entryQuery.name = '';
	entryQuery.type = '';
	entryQuery.moveList = [];
	entryQuery.moveList.push('Earthquake');
	return entryQuery;
}

predictSpace.InitNameSpace();

function afterWait() {
	var eq = CreateSampleQuery();
	predictSpace.ProcessEntryQuery(eq,.2);
	predictSpace.PrintRes();
}

setTimeout(afterWait,1000);
