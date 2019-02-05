#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <string>
#include "./Stack/Stack.h"
#include "./List/List.h"

class Calculator{

  private:
    Stack< char > inputStack;
    Stack< char > opStack;
    List< string > postfixTokens;

  public:
    List<string>  tokenizeString( std::string str);
    int getPrecedence( std::string op );
    void getInputStatic();
    string getInput();
    void start();
    int calculate( );
    std::string calc( std::string opCode, std::string A, std::string B );
    void calculateStatic();
    std::string infixToPostFix();
    string * postfixStringBuilder( string str );
    int add( int a, int b );
    int sub( int a, int b );
    int div( int a, int b );
    int mult( int a, int b );
    int pow( int a, int b );
};
#endif
