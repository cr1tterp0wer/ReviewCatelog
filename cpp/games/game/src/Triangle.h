#pragma once
#include "Line.h"

class Tiangle {

  private:
    Line line_top;
    Line line_bottom;
    Line line_adjacent;

    Point p1;
    Point p2;
    Point p3;

  public:
    Triangle( const Point& p1, const Point& p2, const Point& p3 ){
      this->p1 = p1;
      this->p2 = p2;
      this->p3 = p3;

      //Point 1
      line_top.x1 = p1.x;
      line_top.y1 = p1.y;

    }
    
};











