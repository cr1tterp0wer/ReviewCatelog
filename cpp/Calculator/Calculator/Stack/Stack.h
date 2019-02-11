#ifndef STACK_H
#define STACK_H

template< typename T > class Stack {

  private:
    int size;
    struct node{
      node * next;
      T data;
    };
    node * head;
  
  public:
    Stack();
    
    T pop();
    void push( T d );
    T peek();
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
T Stack<T>::pop(){

  T temp;
  temp = this->head->data;
  this->head = head->next;
  size--;
  return temp;
}

template<typename T>
void Stack<T>::push( T d ){

  node *n = new node();
  n->data = d;
  n->next = head;
  
  head = n;
  size++;
}

template<typename T>
T Stack<T>::peek(){return head->data;}

template<typename T>
int Stack<T>::getSize(){return size;}
#endif
