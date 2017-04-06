var resData = [];

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

function RetrieveCutOffInput() {
	var cutOff = parseFloat($('#' + 'cutOffInput').val());
	cutOff = Math.max(0,cutOff);
	return cutOff;
}

function EntryFormSubmit() {
	var entryQuery = RetrieveEntryQueryInput();
	var cutoff = RetrieveCutOffInput();
	selectedEntry = 0;
	resData = predictSpace.ProcessEntryQuery(entryQuery,cutoff);
	OutputResults();
	console.log("REACHED PAST OUTPUT " + resData.length);
	return false;
}

function OutputResults() {
	$('.'+'moveNameOutput').remove();
	$('.'+'moveProbabilityOutput').remove();
	for(var i = 0; i < resData.length; i++) {
		$('#'+'moveNameSpace').append("<p class = 'moveNameOutput' >" + resData[i][0] + '<br>' + "</p>");
		$('#'+'moveProbabilitySpace').append("<p class = 'moveProbabilityOutput' >" + resData[i][1].toFixed(4) + '<br>' + "</p>");
	}
	$('.moveNameSpace').show();
}

