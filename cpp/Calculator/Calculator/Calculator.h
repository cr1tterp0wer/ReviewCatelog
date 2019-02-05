#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include "./Stack/Stack.h"
#include "./List/List.h"

class Calculator{

  private:
    List< string > postfixTokens;

  public:
    void start();
    string getInput();
    int calculate();
    int getPrecedence( std::string op );
    List<string> tokenizeString( std::string str);
    std::string calc( std::string opCode, std::string A, std::string B );
    std::string infixToPostFix();
    string * postfixStringBuilder( string str );

    int add( int a, int b );
    int sub( int a, int b );
    int div( int a, int b );
    int mult( int a, int b );
    int pow( int a, int b );
};
#endif
