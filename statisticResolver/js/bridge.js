

function StatisticQToString(SQ) {
	var res = "";
	res += SQ.name + '\n';
	res += SQ.nature + '\n';
	for(var i = 0; i < SQ.stats.length; i++) {
		res += SQ.stats[i] + '\n';
	}
	return res;
}

function RetrieveStatisticQueryInput() {
	/*
	['nameInput','Name Input'],
	['natureInput','Nature Input'],
	['HPInput','HP Input'],
	['AInput','Attack Input'],
	['DInput','Defense Input'],
	['SAInput','Special Attack Input'],
	['SDInput','Special Defense Input'],
	['SInput','Speed Input']	
	*/
	
	var res = {};
	res.name = $('#' + 'nameInput').val();
	res.nature = $('#' + 'natureInput').val();
	res.stats = [];
	var statNames = [
		'HP',
		'A',
		'D',
		'SA',
		'SD',
		'S'
	];
	for(var i = 0; i < statNames.length; i++) {
		res.stats[i] = Number($('#' + statNames[i] + 'Input').val());
	}
	return res;
}

function OutputEVData(EVs) {
	var statNames = [
		'HP',
		'A',
		'D',
		'SA',
		'SD',
		'S'
	];
	for(var i = 0; i < EVs.length; i++) {
		$('#'+statNames[i]+'EVOutput').val(EVs[i]);
	}
}

function StatisticInputFormSubmit() {
	var SQuery = RetrieveStatisticQueryInput();
	console.log(StatisticQToString(SQuery));
	var EVs = CalculateStatisticResolverQuery(SQuery);
	OutputEVData(EVs);
	return false;
}