var inputTemplate = '%description%<input id = "%id%" type = "text"> <br>'

var entryInputFormID = 'entryInputForm';
var inputSubmitButton = '<input type = "submit" value = "submit"> <br>';
var entryOutputFormID = 'entryOutputForm';
var querySizeFormID = 'querySizeForm';
var whichEntryFormID = 'whichEntryForm';

function BuildInputString(id,description) {
	return inputTemplate.replace('%id%',id).replace('%description%',description);
}

var entryInputFormItems = [
	['nameInput','Name Input'],
	['typeInput','Type Input'],
	['moveInput0','Move Input 0'],
	['moveInput1','Move Input 1'],
	['moveInput2','Move Input 2'],
	['moveInput3','Move Input 3']
];



var querySizeFormItems = [
	['querySize','Query Size']
];

var whichEntryFormItems = [
	['whichEntryInput','Which Entry Input']
];

var entryOutputFormItems = [
	['typeOutput','Type Output'],
	['moveOutput0','Move Output 0'],
	['moveOutput1','Move Output 1'],
	['moveOutput2','Move Output 2'],
	['moveOutput3','Move Output 3'],
	['itemOutput','Item Output'],
	['natureOutput','Nature Output'],
	['EVOutput0','HP EV Output'],
	['EVOutput1','Attack EV Output'],
	['EVOutput2','Defense EV Output'],
	['EVOutput3','Special Attack EV Output'],
	['EVOutput4','Special Defense EV Output'],
	['EVOutput5','Speed EV Output']
];

function BuildFormItems(formID,formItems) {
	for(var i = 0; i < formItems.length; i++) {
		$('#' + formID).append(BuildInputString(formItems[i][0],formItems[i][1]));
	}	
}


function BuildInputForm(formID,formItems) {
	BuildFormItems(formID,formItems);
	$('#' + formID).append(inputSubmitButton);
}

function BuildOutputForm(formID,formItems) {
	BuildFormItems(formID,formItems);
}



function BuildEntryInputForm() {
	BuildInputForm(entryInputFormID,entryInputFormItems);
}


function BuildQuerySizeForm() {
	BuildOutputForm(querySizeFormID,querySizeFormItems);
}

function BuildWhichEntryInputForm() {
	BuildInputForm(whichEntryFormID,whichEntryFormItems);
}


function BuildEntryOutputForm() {
	BuildOutputForm(entryOutputFormID,entryOutputFormItems);
}
BuildEntryInputForm();
BuildQuerySizeForm();
BuildWhichEntryInputForm();
BuildEntryOutputForm();

//$('#selectForm').val('mercedes');