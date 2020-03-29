#include <TicTacToe.h>

TicTacToe::TicTacToe()
{
	for (int i = 0; i < 9; i++)
	{
		board.push_back(Cell()); // make the board empty
	}
}

ucm::json TicTacToe::getBoard()
{
	ucm::json result;
	ucm::json ans;

	for (int i = 0; i < board.size(); i++)
	{
		ans.push_back(board[i].getVal());
	}

	result["board"] = ans;
	return result;
}

ucm::json TicTacToe::clicked(int x, int y)
{
	ucm::json ans;
	int z = (x) + (3 * y);
	if(board[z].getVal()!=0){
		ans = getBoard();
		return ans;
	}
	board[z].makeMove(player.getPlayer());
	player.changePlayer();

	ans = getBoard();
	return ans;
}
