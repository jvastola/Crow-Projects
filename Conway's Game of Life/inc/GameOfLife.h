#ifndef MYLIB
#define MYLIB

#include <string>
#include <server.h>
#include <Cell.h>

class GameOfLife{


public:
	GameOfLife();
	
	int row;
	int col;
	std::vector<std::vector<Cell>> board;
	
	
	void start();
	void stop();
	void advance();

	ucm::json getBoard();

};

#endif
