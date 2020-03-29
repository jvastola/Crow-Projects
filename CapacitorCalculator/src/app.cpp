#include <server.h>
#include <map>

using namespace ucm;

int main(int argc, char** argv){
     CrowServer server(argc, argv);

    
    server.renderHTML("/", "index.html");


    server.route("/resistance", [&](const request& req, response& res){
        if (req.has_params({"band_1", "band_2", "band_3", "band_4", "band_5"})){
            std::string band1 = req.url_params.get("band_1");
            std::string band2 = req.url_params.get("band_2");
            std::string band3 = req.url_params.get("band_3");
            std::string band4 = req.url_params.get("band_4");
            std::string band5 = req.url_params.get("band_5");
        
        std::unordered_map<std::string,double> multiplier = {
                { "0", 1 },{ "1",10 },{ "2", 100 },{ "3", 1000 },{ "4", 10000},{ "5", 100000 },{ "6", 1000000 },{ "7", 10000000 },{ "10", .1 },{ "11", .01 } };
        std::unordered_map<std::string,double> tolerance = {
               { "1", 1 },{ "2", 2 },{ "5", .5 },{ "6", .25 },{ "7", .1 },{ "8", .05 },{ "10", 5 },{ "11", 10 } };
        std::string resis;
        double multipl;
        double tol;
        if(band4=="-1"){
            resis = band1+""+band2;
            tol = tolerance.at(band4);
            multipl = multiplier.at(band3);
        }
        else{
            resis = band1+""+band2+""+band3;
            tol = tolerance.at(band5);
            multipl = multiplier.at(band4);
        }
        double resist= stod(resis);
        
        resist= resist*multipl;
        resist = floor(resist * 100);
        resist=resist/100;
        ucm::json ans;
        ans["resistance"]=resist;
        ans["tolerance"]=tol;

        res.sendJSON(ans);
        }
        else{
            res.sendError400();
        }

    });
    server.run();
}
