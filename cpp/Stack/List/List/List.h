struct Node{
  Node *next;
  Node *prev;
  int data;
};

class List{

  private:
    Node *head;
    Node *tail;

  public:
    List();
    List( int d );
    ~List();

    void add( int d );
    void addToTail(int d);
    void setAt(int i, int d);
    void removeAt(int i);
    void resetTail();
    void display();
    int getAt(int i);
};
