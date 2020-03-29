var shouldUpdate;

function updateGrid(r, c, state){
	var sel = "#" + r.toString()+ "-" + c.toString();
	if (state){
		$(sel).addClass("alive");
	}
	else {
		$(sel).removeClass("alive");
	}
}

function createGrid(data){
	var result = "";

	for (var i in data){
		var cr = "<tr>";

		for (var j in data[i]){
			cr = cr + "<td id=\"" + i.toString()+ "-" + j.toString() + "\"></td>"
		}

		cr = cr + "</tr>\n";
		result = result + cr;
	}

	$("#grid").html(result);
}

var getBoard = function(){
	$.get("/advance", {}, function(res){
		$.get("/getBoard", {}, function(r){
			var data = JSON.parse(r);
			for (var row in data){
				for (var col in data[row]){
					updateGrid(row, col, data[row][col]);
				}
			}
		});
	});
	if (shouldUpdate){
		setTimeout(getBoard, 300);
	}
};

$(document).ready(function(){
	$.get("/getBoard", {}, function(response){
		var data = JSON.parse(response);
		createGrid(data);
		for (var row in data){
			for (var col in data[row]){
				updateGrid(row, col, data[row][col]);
			}
		}
	});

	$("#startBtn").click(function(){
		shouldUpdate = true;
		$.get("/start", {}, function(response){
			setTimeout(getBoard, 300);
		});
	});

	$("#stopBtn").click(function(){
		shouldUpdate = false;
	});
});
