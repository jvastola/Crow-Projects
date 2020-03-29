#include <Cell.h>
#include <Player.h>
Cell::Cell()
{
  alive = 0;
}

void Cell::makeMove(int player)
{
  alive = player;
}

int Cell::getVal()
{
  return alive;
}
