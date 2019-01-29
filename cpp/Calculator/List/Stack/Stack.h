#ifndef STACK_H
#define STACK_H

struct node{
  node * next;
  int data;
};

class Stack {

  private:
    node * head;
  
  public:
    Stack();
    
    int pop();
    void push( int d );
    int peek();
};


#endif



