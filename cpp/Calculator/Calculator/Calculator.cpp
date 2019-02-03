#include "./Stack/Stack.h"
#include "./Calculator.h"
#include <iostream>
#include <string>

using namespace std;

void Calculator::getInputStatic(){
  
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

//  Precendence Order
//  parens (), [], {}
//  exponents ^
//  mult && div  */
//  add && sub  +-

int Calculator::getPrecendence( char op ){
  if( op == '^' ){
    return 3; 
  }else if( op == '*' || op == '/'){
    return 2; 
  }else if( op == '+' || op == '-' ){
    return 1;  
  }
  return 0;
}

List<string>  Calculator::tokenizeString( string str ){
  
  List<string>  tokens; 
  string current;

  for(int i = 0; i < str.length(); i++ ){
    switch(str[i]){
      case '(' :
      case ')' :
      case '{' :
      case '}' :
      case '+' :
      case '-' :
      case '*' :
      case '/' :
      case '^' :{
        tokens.append( current );
        current = str[i];
        tokens.append( current );
        current="";
        break;
      }
      default:{
        current += str[i];
        break;
      }
    } 
  } 
  if(current != "")
    tokens.append(current);
 
  return tokens;
}

string * Calculator::infixStringBuilder(string str){

  List<string> * tokens = tokenizeString( str );
  string result  = new string("");

  while( !tokens.isEmpty() ){
    result += tokens.pop();
  }
  return result;
}

void Calculator::infixToPostFix(){
  cout << "enter equation: ";
  cin >> infixInput;
  
  string postfix = infixStringBuilder( infixInput );
  cout << postfix;
}

void Calculator::getInput(){

}

void Calculator::calculateStatic(){

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




