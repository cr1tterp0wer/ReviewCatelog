#ifndef STACK_H
#define STACK_H

template< typename T > class Stack {

  private:
    int size;
    struct node{
      node * next;
      int data;
    };
    node * head;
  
  public:
    Stack();
    
    int pop();
    void push( int d );
    int peek();
    int getSize();
};

template<typename T>
Stack<T>::Stack(){
 
  node n;
  n.next = 0;
  head   = &n;
  size=0;
}

template<typename T>
int Stack<T>::pop(){

  int temp;
  temp = this->head->data;
  this->head = head->next;
  size--;
  return temp;
}

template<typename T>
void Stack<T>::push( int d ){

  node *n = new node();
  n->data = d;
  n->next = head;
  
  head = n;
  size++;
}

template<typename T>
int Stack<T>::peek(){return head->data;}

template<typename T>
int Stack<T>::getSize(){return size;}
#endif
