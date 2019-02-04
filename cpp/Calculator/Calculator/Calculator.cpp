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

int Calculator::getPrecedence( std::string op ){
  if( op == "^" ){
    return 3; 
  }else if( op == "*" || op == "/"){
    return 2; 
  }else if( op == "+" || op == "-" ){
    return 1;  
  }
  return 0;
}

string * Calculator::postfixStringBuilder( string infix ){
  
  int stackPrec;
  int tkPrec; 

  Stack<std::string> ops; 
  List<std::string> tokens = tokenizeString( infix );
  std::string * result     = new string("");


  while( !tokens.isEmpty() ){
 
//    stackPrec = getPrecedence( ops.peek() ); 
    tkPrec    = getPrecedence( tokens.peek() ); 
    tokens.pop();


//    cout << stackPrec << endl;
    cout << tkPrec << endl; 
  
  }

  /*

  while( !tokens.isEmpty() ){
    cout << tokens.pop();

    if( tkPrec == 0 ){
      cout << tokens.peek();
      *result += tokens.pop();
    } 
    else if( tkPrec > stackPrec ){ 
      cout << tokens.peek();
      ops.push( tokens.pop() ); 
    }else{

      //pop everything
      while( ops.getSize() > 0 ){
        cout << ops.peek();
        *result += ops.pop(); 
      } 
      //put remainder in stack
      ops.push( tokens.pop() );
    }
  }
*/
  
  return result;
}

void Calculator::infixToPostFix(){

  cout << "enter equation: ";
  infixInput = getInput();
  
  std::string * postfix = postfixStringBuilder( infixInput );
  cout << *postfix; 
}

List<std::string> Calculator::tokenizeString( std::string str ){
  
  List<std::string> tokens;
  std::string current = "";

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

string Calculator::getInput(){
  string s;
  cin >> s;
  return s;
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




