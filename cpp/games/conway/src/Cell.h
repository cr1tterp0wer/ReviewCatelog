#include "Point.h"
#include <cstdlib>

class Cell{

  private:
    Point *pos;
    bool isAlive;

  public:
    Cell( const int& x, const int& y ){
      pos = new Point( x, y );
      isAlive = ( ( rand() % 3 ) == 0 ) ? true : false;
    };

    Cell( const int& x, const int& y, const bool& a){
      pos = new Point( x, y );
      isAlive = a;
    };

    void spawn(){
      isAlive = true;
    }

    void despawn(){
      isAlive = false;
    }

    int getX(){ return pos->x; } const;
    int getY(){ return pos->y; } const;
    bool getIsAlive(){ return isAlive; } const;
};

