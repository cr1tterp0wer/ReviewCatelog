#include <iostream>
#include "GameOfLife.h"

int main()
{

  char * title = (char *)"HI";
//  Game g( title, 800, 680 );
  GameOfLife f( title, 800, 800 );

  f.start();
}
