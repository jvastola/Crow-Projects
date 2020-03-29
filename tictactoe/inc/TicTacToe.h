#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <server.h>
#include <Cell.h>
#include <Player.h>

class TicTacToe{

	std::vector<Cell> board;
	Player player;
	
public:
	TicTacToe();					// Default constructor
	//TicTacToe(const TicTacToe&);	// Copy Constructor

	ucm::json getBoard();
	ucm::json clicked(int, int);

	//~TicTacToe();					// Destructor

};



#endif
