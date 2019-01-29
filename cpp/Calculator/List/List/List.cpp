#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "./List.h"

using namespace std;

List::List(){
  head = nullptr;
  tail = nullptr;
}

List::List( int d ){
  Node *n = new Node();
  n->data = d;
  n->next = nullptr;
  n->prev = nullptr;

  head = n;
  tail = head;
}

List::~List(){
  head = nullptr;
  tail = nullptr;
}

void List::add( int d ){
  Node *temp = new Node;
  temp->data = d;

  if( head == nullptr ){
    temp->next = nullptr;
    temp->prev = tail;
  }else{
    temp->next = head;
  }

  head = temp;
}

void List::addToTail( int d ){
  
  Node *temp = new Node;
  temp->data = d;  
  temp->next = nullptr;

  if( tail == nullptr ){
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
  delete current;
  delete current->next;
  delete current->prev;
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


