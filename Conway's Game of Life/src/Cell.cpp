#include <Cell.h>
Cell::Cell(){
    alive = false;
}

void Cell::setLive(){
    alive=true;
}
void Cell::setDie(){
    alive=false;
}
bool Cell::isAlive(){
  return alive;
}