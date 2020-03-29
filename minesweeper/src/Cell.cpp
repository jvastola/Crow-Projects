#include <Cell.h>
Cell::Cell(){
    mine=false;
    visit= false;
    neighbors=0;
    flag=false;
}

void Cell::setNeighbors(int x){
    neighbors=x;
}
void Cell::setMine(){
    mine=true;
}
void Cell::changeFlag(){
    flag=!flag;
}
void Cell::visited(){
    visit=true;
}
void Cell::unvisit(){
    visit=false;
}
bool Cell::getVisit(){
    return visit;
}
int Cell::checkMine(){
  return mine;
}
int Cell::getNeighbors(){
    return neighbors;
}
bool Cell::getFlag(){
    return flag;
}