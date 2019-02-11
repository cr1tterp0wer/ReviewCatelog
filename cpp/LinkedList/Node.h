
template <class T>
class Node{

  private:
    Node * next;
    Node * prev;
    Node * child;
    T data;

  public:
    Node(){};
    Node( T d ){ data = d; }
    ~Node(){};

    void setNext( Node * n ){ next = n;  }
    void setPrev( Node * n ){ prev = n;  }
    void setChild( Node * n ){ child = n; } 

    Node * getNext() const{ return next; }
    Node * getPrev() const{ return prev; }
    Node * getChild() const{ return child; }

    void setValue( int value ){ data = value; }
    T    getValue(){ return data; }
}; 




