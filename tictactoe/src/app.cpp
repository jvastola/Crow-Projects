#include <server.h>
#include <TicTacToe.h>

using namespace ucm;

int main(int argc, char **argv)
{

    CrowServer server(argc, argv);

    TicTacToe game;

    server.renderHTML("/", "index.html");

    server.route("/init", [&](const request &req, response &res) {
        ucm::json ans = game.getBoard();

        res.sendJSON(ans);
    });

    server.route("/click", [&](const request &req, response &res) {
        if (req.has_params({"x", "y"}))
        {

            std::string xS = req.url_params.get("x");
            std::string yS = req.url_params.get("y");

            int x = stoi(xS);
            int y = stoi(yS);

            ucm::json ans = game.clicked(x, y);

            res.sendJSON(ans);
        }

        else
        {
            res.sendError400();
        }
    });

    server.route("/reset", [&](const request &req, response &res) {
        TicTacToe game2;
        game = game2;
        ucm::json ans = game.getBoard();

        res.sendJSON(ans);
    });

    server.run();
}
