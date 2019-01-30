#ifndef LIST_H
#define LIST_H

template< typename T >
class List{

  public:
    List();
    List( T d );
    ~List();

    void add(T d);
    void removeAt(int i);
    void display();

  private:
    struct Node{
      Node *next;
      T data;
    };
    List<T>::Node * head;
};


//IMPLEMENTATION
#include <iostream>

using namespace std;


template <typename T>
List<T>::List(){
  head = new Node;
  head->data = 0;
  head->next = nullptr;
}

template <typename T>
List<T>::List( T d ){
  List<T>::Node *n = new Node;
  n->data = d;
  n->next = nullptr;
  head = n;
}

template <typename T>
void List<T>::add( T d ){

  List<T>::Node *current = new Node;

  current->data = d;
  current->next = head;

  head = current;
}

template <typename T>
List<T>::~List(){
  head = nullptr;
}

template <typename T>
void List<T>::removeAt( int index ){
  
  int i = 0;
  Node *current = new Node();
  Node *before  = new Node();
  current = head;
  
  //edge cases
  if( index < 0 )
    return;
 
  if( index == 0 ){
    head = head->next;
    return;
  }
 
  //move to position
  while( current->next != nullptr ){
    if(i > index){return;}

    before = current;
    current = current->next;
    i++; 
  }  

  before->next = current->next;
}


template <typename T>
void List<T>::display(){
  Node *current = new Node();
  current = head;

  while( current != nullptr ){
    cout << current->data << endl;
    current = current->next;
  }
}


#endif
