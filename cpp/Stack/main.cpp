#include <iostream>
#include "./List/Stack/Stack.h"

using namespace std;

int main(){

  Stack s;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);

  cout << s.pop() << endl 
    << s.pop() << endl 
    << s.pop() << endl 
    << s.pop() << endl 
    << s.pop() << endl ;

  return 0;
}




