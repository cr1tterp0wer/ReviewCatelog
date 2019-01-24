struct Node{
  Node *next;
  int data;
};

class List{

  private:
    Node *head;

  public:
    List();
    List( int d );
    ~List();

    void add(int d);
    void setAt(int i, int d);
    void removeAt(int i);
    void display();
    int getAt(int i);
};
