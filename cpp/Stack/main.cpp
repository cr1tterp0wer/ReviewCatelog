#include <iostream>
#include "./List/Stack/Stack.h"

using namespace std;

int main(){

  Stack s;
  
  s.push(1);
  cout << s.peek() << endl;

  s.push(2);
  cout << s.peek() << endl;

  s.push(3);
  cout << s.peek() << endl;

  s.push(4);
  cout << s.peek() << endl;

  s.pop();
  cout << s.peek() << endl;
  cout << s.peek() << endl;
  cout << s.peek() << endl;
  return 0;
}




