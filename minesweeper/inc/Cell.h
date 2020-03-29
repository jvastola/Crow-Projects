class Cell {

public:

Cell();
int mine;
bool visit;
int neighbors;
int flag;
void setNeighbors(int x);
void setMine();
void changeFlag();
void visited();
void unvisit();
bool getVisit();
int checkMine();
int getNeighbors();
bool getFlag();
};
