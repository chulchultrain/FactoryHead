


function loadDoc(url,doFunc) {
	var xhttp = new XMLHttpRequest();
	xhttp.onreadystatechange = function() {
		if(this.readyState == 4 && this.status == 200) {
			doFunc(xhttp);
		}
	}
	xhttp.open("GET",url,true);
	xhttp.send();
	
}

function ff(xhttp) {
	var newText = xhttp.responseText.split("\n");
	for(var e in newText) {
		if(newText[e] != "")
			console.log(newText[e]);
	}
}

loadDoc("BASE/NAME/Names.txt",ff);