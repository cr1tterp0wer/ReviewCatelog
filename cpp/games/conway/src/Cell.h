#include "Point.h"
#include <cstdlib>

class Cell{

  private:
    Point *pos;
    bool isAlive;

  public:
    Cell( int x, int y ){
      pos = new Point( x, y );
      isAlive = ( ( rand() % 2 ) == 0 ) ? true : false;
    };

    Cell( int x, int y, bool a){
      pos = new Point( x, y );
      isAlive = a;
    };

    void spawn(){
      isAlive = true;
    }

    void despawn(){
      isAlive = false;
    }
    int getX(){ return pos->x; }
    int getY(){ return pos->y; }
    bool getIsAlive(){ return isAlive; }
};

