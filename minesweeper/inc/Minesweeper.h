#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <BoardGame.h>
#include <server.h>
#include <Cell.h>
class Minesweeper : public BoardGame{
	std::vector<std::vector<Cell>> board;
	
	
	public:
	Minesweeper(int,int,int);

    void reset();

	void handle(int, int, MouseButton);

	ucm::json getBoard();
};

#endif