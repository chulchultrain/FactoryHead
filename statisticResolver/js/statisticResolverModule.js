
var natureMulMap = {};
var DexIDToBaseStatsMap = {};
var NameToDexIDMap = {};
var loadedMaps = false;
var statNames = [
	'HP',
	'A',
	'D',
	'SA',
	'SD',
	'S'
];

//TODO: Add checking to see if given invalid state and just to test.

/*Assume level 100 and used for battle factory so EVs can only come in 255s or 170s and IVs are the same across all stats*/
function CalculateEVDistribution(baseStats,nature,IVs,workingStats) {
	var res = [0,0,0,0,0,0];
	var EVNeeded = [false,false,false,false,false,false];
	if(CalculateHPWorkingStat(baseStats[0],IVs,0,100) != workingStats[0]) {
		EVNeeded[0] = true;
	}
	for(var i = 1; i < 6; i++) {
		if(CalculateNonHPWorkingStat(statNames[i],baseStats[i],IVs,0,nature,100) != workingStats[i])
			EVNeeded[i] = true;
	}
	var amtNeeded = 0;
	for(var i = 0; i < 6; i++) {
		if(EVNeeded[i] == true)
			amtNeeded++;
	}
	for(var i = 0; i < 6; i++) {
		if(EVNeeded[i] == true) {
			res[i] = 510 / amtNeeded;
		}
	}
	
	return res;
}

function CalculateHPWorkingStat(baseHP,IV,EV,level) {
	var res = Math.floor((2 * baseHP + IV + Math.floor(EV / 4) ) * level / 100);
	res += (level + 10);
	return res;
}

function CalculateNonHPWorkingStat(stat,baseStat,IV,EV,nature,level) {
	var res = Math.floor((2 * baseStat + IV + Math.floor(EV / 4) ) * level / 100);
	res += 5;
	res *= NatureMultiplier(stat,nature);
	res = Math.floor(res);
	return res;
}

function IVMatches(baseStats,nature,workingStats,IV) {
	
	var amtMatch = 0;
	if(CalculateHPWorkingStat(baseStats[0],IV,0,workingStats[0],100) == workingStats[0])
		amtMatch++;

	for(var i = 1; i < 6; i++) {
		if(CalculateNonHPWorkingStat(statNames[i],baseStats[i],IV,0,nature,100) == workingStats[i])
			amtMatch++;
	}
	if(amtMatch > 0)
		return true;
}

function FindIVs(baseStats,nature,workingStats) {
	for(var i = 0; i <= 31; i++) {
		if(IVMatches(baseStats,nature,workingStats,i))
			return i;
	}
	console.log("Couldn't resolve IVs.");
	return -1;
}

function CalculateEVs(name,nature,workingStats) {
	/*  Generate BaseStats from name.
		Find IVs first by testing all possible IVs with 0 EVs against workingStats for matches.
	*/
	if(loadedMaps == false) {
		natureMulMap = mapSpace.natureMulMap;
		DexIDToBaseStatsMap = mapSpace.DexIDToBaseStatsMap;
		NameToDexIDMap = mapSpace.NameToDexIDMap;
		console.log("LOADED UP NOW");
		loadedMaps = true;
	}
	var baseStatsStrings = DexIDToBaseStatsMap[NameToDexIDMap[name]];
	var baseStats = [];
	for(var i = 0; i < baseStatsStrings.length; i++) {
		baseStats.push(Number(baseStatsStrings[i]));
	}
	
	var IVs = FindIVs(baseStats,nature,workingStats);
	var EVDist = CalculateEVDistribution(baseStats,nature,IVs,workingStats);
	// for(var i = 0; i < 6; i++) {
		// console.log(EVDist[i]);
	// }
	return EVDist;
}

function NatureMultiplier(stat,nature) {
	var n = nature.trim();
	var s = stat.trim();
	if(natureMulMap.hasOwnProperty(n) ) {
		if(natureMulMap[n].hasOwnProperty(s) ) {
			return natureMulMap[n][s];
		}
	} else {
		console.log(n + ": This nature doesn't exist.");
	}
	return 1;
}

function afterWait() {
	// console.log(CalculateHPWorkingStat(108,24,74,78));
	// console.log(CalculateNonHPWorkingStat('A',130,12,190,"Adamant",78));	
	var ws = [
		373,
		186,
		238,
		259,
		298,
		86
	];
	var EVs = CalculateEVs('Slowking','Quiet',ws);
	for(var i = 0; i < EVs.length; i++) {
		console.log(EVs[i]);
	}
}

function CalculateStatisticResolverQuery(SRQuery) {
	return CalculateEVs(SRQuery.name,SRQuery.nature,SRQuery.stats);
}

setTimeout(afterWait,1000);

