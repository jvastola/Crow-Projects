$(document).ready(function(){
		$("#submit").click(function(){
            var band_1 = $("#band_1").val();
            var band_2 = $("#band_2").val();
            var band_3 = $("#band_3").val();
            var band_4 = $("#band_4").val();
            var band_5 = $("#band_5").val();
            $.get("/resistance" , {"band_1":band_1,"band_2":band_2,"band_3":band_3,"band_4":band_4,"band_5":band_5}, function(response){
                var ans = JSON.parse(response);
                console.log(ans);
                $("#Resistance").html( "<h2>Resistance:</h2>" + ans["resistance"]);
                $("#Tolerance").html("<h2>Tolerance:</h2>" +  ans["tolerance"]);

            });
		});
});
