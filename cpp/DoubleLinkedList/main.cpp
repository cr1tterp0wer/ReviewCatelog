#include <iostream>
#include "./List.h"

using namespace std;

int main(){

  List mylist(1);
  mylist.addToTail(5);
  mylist.addToTail(6);

  mylist.removeAt(1);
  mylist.display();

  return 0;
}




