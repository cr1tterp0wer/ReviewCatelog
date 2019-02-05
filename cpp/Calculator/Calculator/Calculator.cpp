#include "./Stack/Stack.h"
#include "./Calculator.h"
#include <iostream>
#include <string>

using namespace std;

void Calculator::start(){
  
  cout << "enter equation: ";
  std::string postfix = infixToPostFix();
  
  int result = calculate();
  cout << endl << "RESULT: " << result << endl;
}

string Calculator::getInput(){
  string s;
  cin >> s;
  return s;
}

int Calculator::calculate(){
  
  List<std::string> postList = postfixTokens; 
  List<std::string> stack;
  int opPrec = getPrecedence( postList.peek() );
  std::string A;
  std::string B;

  while( !postList.isEmpty() ){
    opPrec = getPrecedence( postList.peek() );
    if( opPrec == 0 ){
      stack.push( postList.pop() );
    }
    else{
      B = stack.pop();
      A = stack.pop();
      stack.push( calc( postList.pop(), A, B ) );
    }
  }

  return stoi( stack.pop() );
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
  }else if( op == "(" ){
    return -1;
  }else if( op == ")" ){
    return -2;
  }
  return 0;
}

std::string Calculator::infixToPostFix(){

  std::string infixInput = getInput();
  string * postfix = postfixStringBuilder( infixInput );

  cout << "Postfix: " << *postfix << endl;

  return *postfix; 
}

string * Calculator::postfixStringBuilder( string infix ){
  
  int stackPrec;
  int tkPrec; 

  Stack<std::string> ops; 
  List<std::string> tokens = tokenizeString( infix );
  std::string * result     = new string("");

  while( !tokens.isEmpty() ){

    stackPrec = ( ops.getSize() == 0  ) ? 0 : getPrecedence( ops.peek() );
    tkPrec    = getPrecedence( tokens.peek() ); 

    if( tkPrec == 0 ){
      if( tokens.peek() != "" ){
        postfixTokens.append( tokens.peek() );
      }
      *result += tokens.pop();
    }
    else if( tkPrec < 0 ){
      if( tkPrec == -1 ){
        ops.push( tokens.pop() );
      }else if( tkPrec == -2 ){

        while( stackPrec != -1 ){
          postfixTokens.append( ops.peek() );
          *result += ops.pop();
          stackPrec = ( ops.getSize() == 0  ) ? 0 : getPrecedence( ops.peek() );
        }
        ops.pop();
        tokens.pop();
      }
    }
    else if( tkPrec > stackPrec ){
      ops.push(tokens.pop());
    }else{
      while( stackPrec >= tkPrec ){
        postfixTokens.append( ops.peek() );
        *result += ops.pop();
        stackPrec = ( ops.getSize() == 0  ) ? 0 : getPrecedence( ops.peek() );
      } 
      ops.push(tokens.pop());
    }
  }
  while( ops.getSize() > 0 ){
    postfixTokens.append( ops.peek() );
    *result += ops.pop();
  }

  return result;
}

std::string Calculator::calc( std::string opCode, std::string A, std::string B ){

  int res;
  int op_a = stoi( A );
  int op_b = stoi( B );

  switch( opCode[0] ){
    case '+':
      res = add( op_a, op_b );
      break;
    case '-':
      res = sub( op_a, op_b );
      break;
    case '*':
      res = mult( op_a, op_b );
      break;
    case '/':
      res = div( op_a, op_b );
      break;
    case '^':
      res = pow( op_a, op_b );
      break;
    default:
      res = 0;
      break;
  }

  return std::to_string(res);
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
int Calculator::pow( int a, int b ){

  int sum = a;
  for( int i = 0; i < b; i++ ){
    sum *= a;
  }
  return sum;
}

