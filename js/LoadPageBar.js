var pageBarItems = [
	['About','pageBarAbout','html/about.html'],
	['Future','pageBarFuture','html/future.html']
];

var linkTemplate = '<a href = "%data%">%text%</a>';
var barItemTemplate = '<div id = "%id%" class = "col-2">' + linkTemplate + '</div>';

var PageBarClass = 'PageBar';

function BuildBarItem(name,id,loc) {
	return barItemTemplate.replace('%data%',loc).replace('%text%',name).replace("%id%",id);
}

function LoadPageBarItems() {
	for(i = 0; i < pageBarItems.length; i++) {
		var barItem = BuildBarItem(pageBarItems[i][0],pageBarItems[i][1],pageBarItems[i][2]);
		$('#' + PageBarClass).append(barItem);
	}
}

LoadPageBarItems();