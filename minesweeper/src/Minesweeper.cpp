#include <Minesweeper.h>
#include <random>
Minesweeper::Minesweeper(int x, int y, int z)
{
    std::vector<Cell> temp;
    //call constructor to make board of cells
    for (int i = 0; i < x + 2; i++)
    {
        for (int j = 0; j < y + 2; j++)
        {
            temp.push_back(Cell());
        }
        board.push_back(temp);
        temp.clear();
    }

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distx(1, x);
    std::uniform_int_distribution<std::mt19937::result_type> disty(1, y);
    //random mines
    for (int i = 0; i < 10; i++)
    {
        int i1 = distx(rng);
        int i2 = disty(rng);
        board[i1][i2].setMine();
    }
    //calculate neighbors
    for (int i = 1; i < x + 1; i++)
    {
        for (int j = 1; j < y + 1; j++)
        {
            int neighbors = 0;
            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    if (i != 0 && i != x + 1 && j != 0 && j != y + 1)
                    {
                        if (board[i + k][j + l].checkMine())
                        {
                            neighbors++;
                        }
                    }
                }
            }
            board[i][j].setNeighbors(neighbors);
        }
    }
}
void Minesweeper::reset()
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j].getFlag())
            board[i][j].changeFlag();
            board[i][j].unvisit();
        }
    }
    
}
ucm::json Minesweeper::getBoard()
{
    ucm::json ans;
    ucm::json temp;

    for (int i = 1; i < board.size() - 1; i++)
    {
        for (int j = 1; j < board[i].size() - 1; j++)
        {

            if (board[i][j].getVisit())
            {

                if (board[i][j].getFlag())
                {
                    temp.push_back("F");
                }
                else if (board[i][j].getNeighbors() == 69)
                {
                    temp.push_back("69");
                }
                else
                    temp.push_back(board[i][j].getNeighbors());
            }
            else
                temp.push_back("");
        }
        ans.push_back(temp);
        temp.clear();
    }

    return ans;
}
void Minesweeper::handle(int x, int y, MouseButton click)
{
    if (click == right)
    {
        board[x][y].visited();
        board[x][y].changeFlag();
    }
    if (board[x][y].checkMine())
    {
        board[x][y].visited();
        board[x][y].setNeighbors(69);
    }
    else
    {
        if (!board[x][y].getVisit())
        {
            board[x][y].visited();
            if (board[x][y].getNeighbors() == 0)
            {
                if (x != 0 && y != 0 && x != board.size() - 1 && y != board[0].size() - 1)
                {
                    for (int k = -1; k <= 1; k++)
                    {
                        for (int l = -1; l <= 1; l++)
                        {
                            handle(x + k, y + l, left);
                        }
                    }
                }
            }
        }
    }
}
