#include <server.h>
#include <GameOfLife.h>

using namespace ucm;

int main(int argc, char** argv){

    CrowServer server(argc, argv);

    GameOfLife game;

    server.renderHTML("/", "index.html");

    server.route("/start", [&](const request& req, response& res){

        game.start();

        ucm::json response;

        response["message"] = "Game Started";
    
        res.sendJSON(response);
 
    });

    server.route("/stop", [&](const request& req, response& res){

        game.stop();

        ucm::json response;

        response["message"] = "Game Stopped";
    
        res.sendJSON(response);
 
    });

    server.route("/advance", [&](const request& req, response& res){

        game.advance();

        ucm::json response;

        response["message"] = "Game Advanced";
    
        res.sendJSON(response);
 
    });

    server.route("/getBoard", [&](const request& req, response& res){

        ucm::json response = game.getBoard();
    
        res.sendJSON(response);
 
    });

    server.run();
}
