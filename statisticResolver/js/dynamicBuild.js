var inputTemplate = '<p class = "inputSpace"><span class = "inputDescriptionClass">%description%</span><input id = "%id%" type = "text"> </p>'
var outputTemplate = '<p class = "outputSpace"> <span class = "outputDescriptionClass">%description%: </span><output id = "%id%"></output> </p>'
var linkTemplate = '<a href = "%data%">%text%</a>';


var inputSubmitButton = '<input type = "submit" value = "submit"> <br>';
var customSubmitButton = '<input type = "submit" value = "%text%"> <br>';
var statisticInputFormID = 'statisticInputForm';
var statisticOutputID = 'statisticOutputSpace';

//BUILD LOW-LEVEL ITEMS
function BuildLink(name,loc) {
	return linkTemplate.replace('%data%',loc).replace('%text%',name);
}

function BuildInputString(id,description) {
	return inputTemplate.replace('%id%',id).replace('%description%',description);
}

function BuildOutputString(id,description) {
	return outputTemplate.replace('%id%',id).replace('%description%',description);
}

function BuildCustomSubmitButtonString(val) {
	return customSubmitButton.replace('%text%',val);
}

var statisticInputFormItems = [
	['nameInput','Name Input'],
	['natureInput','Nature Input'],
	['HPInput','HP Input'],
	['AInput','Attack Input'],
	['DInput','Defense Input'],
	['SAInput','Special Attack Input'],
	['SDInput','Special Defense Input'],
	['SInput','Speed Input']

];

var statisticOutputItems = [
	['HPEVOutput','HP EV'],
	['AEVOutput','Attack EV'],
	['DEVOutput','Defense EV'],
	['SAEVOutput','Special Attack EV'],
	['SDEVOutput','Special Defense EV'],
	['SEVOutput','Speed EV']
];

function BuildInputItems(formID,formItems) {
	for(var i = 0; i < formItems.length; i++) {
		$('#' + formID).append(BuildInputString(formItems[i][0],formItems[i][1]));
	}	
}

function BuildOutputItems(elementID,elementItems) {
	for(var i = 0; i < elementItems.length; i++) {
		$('#' + elementID).append(BuildOutputString(elementItems[i][0],elementItems[i][1]));
	}	
}


function BuildInputForm(formID,formItems) {
	BuildInputItems(formID,formItems);
	$('#' + formID).append(inputSubmitButton);
}

function BuildStatisticInputForm() {
	BuildInputForm(statisticInputFormID,statisticInputFormItems);
}

function BuildStatisticOutput() {
	BuildOutputItems(statisticOutputID,statisticOutputItems);
}

BuildStatisticInputForm();
BuildStatisticOutput();