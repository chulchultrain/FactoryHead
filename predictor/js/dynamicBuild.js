console.log('REACH DB.js');


var inputTemplate = '<p class = "inputSpace"><span class = "inputDescriptionClass">%description%</span><input id = "%id%" type = "text"> </p>'
var outputTemplate = '<p class = "outputSpace"> <span class = "outputDescriptionClass">%description%: </span><output id = "%id%"></output> </p>'
var linkTemplate = '<a href = "%data%">%text%</a>';

var entryInputFormID = 'entryInputForm';
var inputSubmitButton = '<input type = "submit" value = "submit"> <br>';
var customSubmitButton = '<input type = "submit" value = "%text%"> <br>';
var entryOutputFormID = 'entryOutputForm';
var entryOutputSpaceID = 'entryOutputPart';
var querySizeFormID = 'querySizeForm';
var whichEntryFormID = 'whichEntryForm';
var prevEntryFormID = 'prevEntryForm';
var nextEntryFormID = 'nextEntryForm';

var mapperHelpID = 'mapperHelp';

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

var entryInputFormItems = [
	['nameInput','Name Input'],
	['typeInput','Type Input'],
	['moveInput0','Move Input 0'],
	['moveInput1','Move Input 1'],
	['moveInput2','Move Input 2'],
	['moveInput3','Move Input 3'],
	['cutOffInput','Cut Off Proportion']
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


function BuildEntryInputForm() {
	BuildInputForm(entryInputFormID,entryInputFormItems);
}


BuildEntryInputForm();

$('.moveNameSpace').hide();
