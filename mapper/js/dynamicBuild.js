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

/*
	Form items - User Side Items
	InputForm Items will have IDs that are the first entry in each item of entryInputFormItems
	For example, if an item in entryInputFormItems is ["foo","bar"], then there will be an input form with the document id of foo.
	Current Input Form Items - 03/23/17
	['nameInput','Name Input'],
	['typeInput','Type Input'],
	['moveInput0','Move Input 0'],
	['moveInput1','Move Input 1'],
	['moveInput2','Move Input 2'],
	['moveInput3','Move Input 3']	
*/

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

/*
	OutputForm Items will have IDs that are the first entry of each subitem in each item of entryOutputFormItems
	For example, if an item in entryOutputFormItems is ["foo","bar"], then there will be an output text area with the document id of foo.
	[
	['nameOutput','Name'],
	['typeOutput','Type'],
	['itemOutput','Item'],
	['natureOutput','Nature'],
	['abilityOutput','Ability']
	],
	[
	['moveOutput0','Move 0'],
	['moveOutput1','Move 1'],
	['moveOutput2','Move 2'],
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
	['EVOutput0','HP EV'],
	['EVOutput1','Attack EV'],
	['EVOutput2','Defense EV'],
	['EVOutput3','Special Attack EV'],
	['EVOutput4','Special Defense EV'],
	['EVOutput5','Speed EV']
	]
	*/
var entryOutputItems = [
	[
	['nameOutput','Name'],
	['typeOutput','Type'],
	['itemOutput','Item'],
	['natureOutput','Nature'],
	['abilityOutput','Ability']
	],
	[
	['moveOutput0','Move 0'],
	['moveOutput1','Move 1'],
	['moveOutput2','Move 2'],
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
	['EVOutput0','HP EV'],
	['EVOutput1','Attack EV'],
	['EVOutput2','Defense EV'],
	['EVOutput3','Special Attack EV'],
	['EVOutput4','Special Defense EV'],
	['EVOutput5','Speed EV']
	]
];


//BUILD HIGH-LEVEL ITEMSFUNCTIONS
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


function BuildQuerySizeOutput() {
	BuildOutputItems(querySizeFormID,querySizeFormItems);
}

function BuildWhichEntryInputForm() {
	BuildInputForm(whichEntryFormID,whichEntryFormItems);
}


function BuildEntryOutput() {
	BuildOutputItems(entryOutputFormID,entryOutputFormItems);
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

function BuildEntryOutput() {
	for(var i = 0; i < entryOutputItems.length; i++) {
		BuildOutputItems(entryOutputSpaceID + String(i),entryOutputItems[i]);
	}
}

function BuildMapperHelp() {
	for(i = 0; i < mapperHelpItems.length; i++) {
		$('#' + mapperHelpID).append(BuildLink(mapperHelpItems[i][0],mapperHelpItems[i][1]));		
	}

}


BuildEntryInputForm();
BuildQuerySizeOutput();
BuildWhichEntryInputForm();
BuildEntryOutput();
BuildPrevNextForms();
BuildMapperHelp();
