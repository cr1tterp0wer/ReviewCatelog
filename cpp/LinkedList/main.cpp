#include "./Node.h"

//loop through list and print all data
void printList( Node<int>  n ){
  

}

int main(){

  Node<int> l(1);
  Node<int> * n = new Node<int>( 2 );


  l.setNext( n );
  n->setValue( 3 );

  l.getNext()->setNext( n );
  n->setValue( 4 );

  l.getNext()->getNext()->setNext( n );

  printList( l );

  return 0;
}
