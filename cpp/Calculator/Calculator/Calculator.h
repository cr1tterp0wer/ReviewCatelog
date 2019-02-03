#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include "./Stack/Stack.h"
#include "./List/List.h"

class Calculator{

  private:
    Stack< char > inputStack;
    Stack< char > opStack;
    std::string infixInput;
    std::string postfixInput;

  public:
    List<string>  tokenizeString( std::string str);
    int getPrecendence( char op );
    void getInputStatic();
    void getInput();
    void calculateStatic();
    void infixToPostFix();
    string * infixStringBuilder( string str );
    int add( int a, int b );
    int sub( int a, int b );
    int div( int a, int b );
    int mult( int a, int b );
};
#endif
