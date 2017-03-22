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


//HIGH-LEVEL ITEMS
var mapperHelpItems = [
	['Instructions','mapper/instructions']
];

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
	
	[
	['nameOutput','Name Output'],
	['typeOutput','Type Output'],
	['itemOutput','Item Output'],
	['natureOutput','Nature Output'],
	['abilityOutput','Ability Output']
	],
	[
	['moveOutput0','Move Output 0'],
	['moveOutput1','Move Output 1'],
	['moveOutput2','Move Output 2'],
	['moveOutput3','Move Output 3']
	],
	[
	['baseStatOutput0','HP Base Stat'],
	['baseStatOutput1','A Base Stat'],
	['baseStatOutput2','D Base Stat'],
	['baseStatOutput3','SA Base Stat'],
	['baseStatOutput4','SD Base Stat'],
	['baseStatOutput5','S Base Stat']
	],
	[
	['EVOutput0','HP EV Output'],
	['EVOutput1','Attack EV Output'],
	['EVOutput2','Defense EV Output'],
	['EVOutput3','Special Attack EV Output'],
	['EVOutput4','Special Defense EV Output'],
	['EVOutput5','Speed EV Output']
	]
];


//BUILD HIGH-LEVEL ITEMSFUNCTIONS
function BuildInputItems(formID,formItems) {
	for(var i = 0; i < formItems.length; i++) {
		$('#' + formID).append(BuildInputString(formItems[i][0],formItems[i][1]));
	}	
}

function BuildOutputItems(formID,formItems) {
	for(var i = 0; i < formItems.length; i++) {
		$('#' + formID).append(BuildOutputString(formItems[i][0],formItems[i][1]));
	}	
}


function BuildInputForm(formID,formItems) {
	BuildInputItems(formID,formItems);
	$('#' + formID).append(inputSubmitButton);
}

function BuildOutputForm(formID,formItems) {
	BuildOutputItems(formID,formItems);
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

function BuildPrevForm() {
	console.log(BuildCustomSubmitButtonString('prev'));
	$('#' + prevEntryFormID).append(BuildCustomSubmitButtonString('prev'));
}

function BuildNextForm() {
	console.log(BuildCustomSubmitButtonString('next'));
	$('#' + nextEntryFormID).append(BuildCustomSubmitButtonString('next'));
}

function BuildPrevNextForms() {
	BuildPrevForm();
	BuildNextForm();
}

function BuildEntryOutputSpace() {
	for(var i = 0; i < entryOutputFormItems.length; i++) {
		BuildOutputItems(entryOutputSpaceID + String(i),entryOutputFormItems[i]);
	}
}

function BuildMapperHelp() {
	for(i = 0; i < mapperHelpItems.length; i++) {
		$('#' + mapperHelpID).append(BuildLink(mapperHelpItems[i][0],mapperHelpItems[i][1]));		
	}

}


BuildEntryInputForm();
BuildQuerySizeForm();
BuildWhichEntryInputForm();
//BuildEntryOutputForm();
BuildEntryOutputSpace();
BuildPrevNextForms();
BuildMapperHelp();
//$('#selectForm').val('mercedes');
