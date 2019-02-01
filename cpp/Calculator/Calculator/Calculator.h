#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "./Stack/Stack.h"

class Calculator{

  private:
   Stack< char > inputStack;
  public:
    void getInput();
    void calculate();
    int add( int a, int b );
    int sub(int a, int b);
    int div(int a, int b);
    int mult(int a, int b);
};
#endif
