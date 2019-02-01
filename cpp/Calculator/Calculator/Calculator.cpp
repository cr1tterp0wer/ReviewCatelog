#include "./Stack/Stack.h"
#include "./Calculator.h"
#include <iostream>

using namespace std;

void Calculator::getInput(){
  
  char input;
  char op;

  cout << endl << "Enter operator(+,-,/,*):"; 
  cin >> op;
  inputStack.push(op);

  cout << "Enter first Number:";
  cin >> input;
  
  inputStack.push(input);

  cout << endl << "Enter Second Number:";
  cin >> input;
  inputStack.push(input);
}

void Calculator::calculate(){

  int b = (int)inputStack.pop() - '0';    
  int a = (int)inputStack.pop() - '0';

  switch( inputStack.pop() ){
    case '+':
      inputStack.push(add( a, b ));
      break;
    case '-':
      inputStack.push(sub( a, b ));
      break;
    case '/':
      inputStack.push(div( a, b ));
      break;
    case '*':
      inputStack.push(mult( a, b ));
      break;
    default:
      break;
  }

  cout << "The answer is: " << inputStack.pop();
  cout << endl;
}

int Calculator::add( int a, int b ){
  return a + b;
}

int Calculator::sub( int a, int b ){
  return a - b; 
}

int Calculator::div( int a, int b ){
  return a / b;
}

int Calculator::mult( int a, int b ){
  return a * b;
}




