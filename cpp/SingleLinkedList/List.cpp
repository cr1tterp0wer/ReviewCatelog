#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "./List.h"

using namespace std;

List::List(){
  head = NULL;
}
List::List( int d ){
  Node *n = new Node();
  n->data = d;
  n->next = NULL;

  head = n;
}
List::~List(){
  head = NULL;
}
void List::removeAt( int index ){

  Node *current = new Node();
  Node *before  = new Node();
  current = head;

  //edge case
  if( index == 0 ){
    head = head->next;
    return;
  }
  
  //move to position
  for( int i = 0; i < index; i++ ){
    before = current;
    current = current->next;
  }
  before->next = current->next;
}
void List::add( int d ){
  
  Node *current = new Node;
  current = head;

  //go to tail
  while( current->next != nullptr ){
    current = current->next; 
  }  

  //at tail, now add new Node
  current->next = new Node();
  current->next->data = d;
}
void List::display(){
  Node *current = new Node;
  current = head;

  while( current != nullptr ){
    cout << current->data << endl;
    current = current->next;
  }
}
#endif


