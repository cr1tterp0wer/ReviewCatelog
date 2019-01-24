#include <iostream>
#include "./List.h"

using namespace std;

int main(){

  List mylist(1);
  mylist.addToTail(5);
  mylist.addToTail(6);

/*  mylist.add(9);
  mylist.add(8);
  mylist.add(7);
  mylist.add(6);
  mylist.add(5);
  mylist.add(4);
  mylist.add(3);
  mylist.add(2);
  mylist.add(1);
  mylist.add(0);
  mylist.removeAt(2);
  */
  mylist.display();



  return 0;

}




