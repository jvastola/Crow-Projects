var shouldUpdate;

function updateGrid(r, c, state){
	var sel = "#" + r.toString()+ "-" + c.toString();
		$(sel).html(state);
		if (state==69){
			alert("You Lose")
		}
}

function createGrid(data){
	var result = "";

	for (var i in data){
		var cr = "<tr>";

		for (var j in data[i]){
			cr = cr + "<td id=\"" + i.toString()+ "-" + j.toString() + "\"><button>"+i.toString()+ "-" + j.toString()+"</button></td>";
		}

		cr = cr + "</tr>\n";
		result = result + cr;
	}

	$("#grid").html(result);

	for (var i in data){
		var cr = "<tr>";

		for (var j in data[i]){
			var theID = "#" + i.toString()+ "-" + j.toString();

			$(theID).click({row: i, col: j}, function(e){
				var x = e.data.row;
				var y = e.data.col;
				var butn = e.button;
				if(butn!=0)
				butn="right";
				if(butn==0)
				butn="left";
				alert(butn);
				x++;
				y++
				var location = { "x": x, "y": y, "btn": butn };
						$.get("/handle", location, function (response) {
							var data = JSON.parse(response);
							console.log(data);
							for (var row in data){
								for (var col in data[row]){
									updateGrid(row, col, data[row][col]);
								}
							}
						});
				
			});
		}


	}
}


$(document).ready(function(){
	
	$.get("/init", {}, function(response){
		var data = JSON.parse(response);
		createGrid(data);
			for (var row in data){
				for (var col in data[row]){
					updateGrid(row, col, data[row][col]);
				}
			}
	});
	
});
