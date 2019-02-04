#ifndef LIST_H
#define LIST_H
struct Node;

template< typename T >
class List{
  private:
     struct Node{
      Node *next = nullptr;
      T data;
    };
    List<T>::Node * head = nullptr;
    int length;

  public:
    List();
    List( T d );
    ~List();

    void push( T d );
    void append( T d );
    T pop();
    T peek();
    T getAt( int i );
    Node * getNodeAt( int i );
    int getLength();
    void removeAt( int i );
    void display();
    bool isEmpty();
};

//IMPLEMENTATION
#include <iostream>

using namespace std;

template <typename T>
List<T>::List(){
  length = 0;
}

template <typename T>
List<T>::List( T d ){
  List<T>::Node *n = new Node;
  n->data = d;
  head = n;
}

template <typename T>
void List<T>::push( T d ){
  List<T>::Node *current = new Node;
  
  if( this->isEmpty() ){
    head->data = d;
    length++;
    return;
  }

  current->data = d;
  current->next = head;
  head = current;
  length++;
}

template <typename T>
void List<T>::append( T d ){
 
  List<T>::Node *current = head;
  List<T>::Node *temp = new Node;
  temp->data = d;

  if( head == nullptr ){
    head = new Node();
    head->data = d;
    length++; 
    return;
  }

  while( current->next != nullptr ){
    current = current->next;
  }
  current->next = temp;
  length++;
}

template <typename T>
T List<T>::peek(){
  return head->data;   
}

//this is lazy
template <typename T>
T List<T>::pop(){

  T d = head->data;
  removeAt(0);
  return d;
}

template <typename T>
typename  List<T>::Node * List<T>::getNodeAt( int i ){
  
  int k = 0;
  Node * current = new Node();
  current = head;
  
  //edge cases
  if( i < 0  || i > length )
    return head;
 
  if( i == 0 ){
    return head;
  }
 
  //move to position
  while( current->next != nullptr ){
    current = current->next;
    if( k == i )
      break;
    k++;
  }  
  return current;
}


template <typename T>
T List<T>::getAt( int i ){
  return getNodeAt( i )->data;
}

template <typename T>
void List<T>::removeAt( int i ){

  if( i < 0 ){
    return;
  }
  if( i == 0 ){
    head = head->next;
    length--;
    return; 
  }

  Node * before = getNodeAt( i-1 );
  Node * target = before->next;

  before->next = target->next;
  length--;
}

template <typename T>
bool List<T>::isEmpty(){
  return ( length <= 0 );
}

template <typename T>
int List<T>::getLength(){
  return length;
}

template <typename T>
void List<T>::display(){
  Node *current = new Node();
  current = head;

  cout << current->data << endl;
  while( current->next != nullptr ){
    current = current->next;  
    cout << current->data << endl;
  }
}

template <typename T>
List<T>::~List(){
  head = nullptr;
}

#endif
