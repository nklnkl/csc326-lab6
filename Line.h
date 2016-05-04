#ifndef _LINE
#define _LINE

#include "Customer.cpp"

// A Queue, just called Line.
class Line {

  public:

    // Defaults to a 100 array.
    Line ();

    // Defined with explicit list amount.
    Line (int n);

    ~Line ();

    bool isEmpty () const;
    int getLength () const

    void enqueue (Customer & cus, bool & success);
    void dequeue (Customer & cus, bool & success);

  private:
    Customer * list;
    int length;
}

#endif
