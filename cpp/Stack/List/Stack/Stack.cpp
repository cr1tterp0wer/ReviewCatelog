#include "./Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(){
 
  node n;
  n.next = nullptr;
  head   = &n;
}

int Stack::pop(){
  int temp;
  
  temp = this->head->data;
  this->head = head->next;
  return temp;
}

void Stack::push( int d ){
  node *n = new node();
  n->data = d;
  n->next = head;
  
  head = n;
}

int Stack::peek(){
  return head->data;
}
