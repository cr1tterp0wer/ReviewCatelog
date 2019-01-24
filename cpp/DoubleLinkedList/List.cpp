#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "./List.h"

using namespace std;

List::List(){
  head = NULL;
  tail = NULL;
}

List::List( int d ){
  Node *n = new Node();
  n->data = d;
  n->next = NULL;
  n->prev = NULL;

  head = n;
  tail = head;
}

List::~List(){
  head = NULL;
}

void List::add( int d ){
  Node *temp = new Node;
  temp->data = d;

  if( head == NULL ){
    temp->next = NULL;
    temp->prev = tail;
  }else{
    temp->next = head;
  }

  head = temp;
}

void List::addToTail( int d ){
  
  Node *temp = new Node;
  temp->data = d;  
  temp->next = NULL;

  if( tail == NULL ){
    temp->prev = temp;
  }else{
    tail->next = temp;
  }
  tail = temp;
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

void List::resetTail(){
  Node *current = head;

  //go to tail
  while( current->next != nullptr ){
    current = current->next; 
  }  
  tail = current;
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


