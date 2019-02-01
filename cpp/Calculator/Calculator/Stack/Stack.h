#ifndef STACK_H
#define STACK_H

template< typename T > class Stack {

  private:
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
};

template<typename T>
Stack<T>::Stack(){
 
  node n;
  n.next = 0;
  head   = &n;
}

template<typename T>
int Stack<T>::pop(){

  int temp;
  temp = this->head->data;
  this->head = head->next;
  return temp;
}

template<typename T>
void Stack<T>::push( int d ){

  node *n = new node();
  n->data = d;
  n->next = head;
  
  head = n;
}

template<typename T>
int Stack<T>::peek(){return head->data;}
#endif
