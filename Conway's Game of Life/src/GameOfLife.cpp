#include <GameOfLife.h>
#include <iostream>

GameOfLife::GameOfLife(){
	row=5;
	col=5;

	std::vector<Cell> temp;

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			temp.push_back(Cell());
		}
		board.push_back(temp);
		temp.clear();
	}
	board[1][2].setLive();
	board[2][2].setLive();
	board[3][2].setLive();
}

void GameOfLife::start(){

}

void GameOfLife::stop(){
	
}

void GameOfLife::advance(){
	std::vector<std::vector<Cell>> next=board;

	for(int i=1;i<row-1;i++){
		for(int j=1;j<col-1;j++){
			int neighbors=0;
			for (int k = -1; k <= 1; k++){
				for (int l = -1; l <= 1; l++) {
					if(board[i+k][j+l].isAlive()){
						neighbors++;
					}
				}
			}
			if(board[i][j].isAlive()){
				neighbors--;
				if(neighbors<2 || neighbors>3)
					next[i][j].setDie();
			}
			if(!board[i][j].isAlive() && neighbors==3)
				next[i][j].setLive();
		}
	}
	board=next;
}

ucm::json GameOfLife::getBoard() {
	ucm::json result;

	ucm::json temp;

	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			temp.push_back(board[i][j].isAlive());
		}
		result.push_back(temp);
		temp.clear();
	}
	// result.push_back({false, false, false, false, false});
	// result.push_back({false, false, false, false, false});
	// result.push_back({false, true, true, true, false});
	// result.push_back({false, false, false, false, false});
	// result.push_back({false, false, false, false, false});
	return result;
}


