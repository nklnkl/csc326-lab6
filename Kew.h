#ifndef _KEW
#define _KEW

#include "Customer.cpp"

// A Queue, just called Kew.
class Kew {

  public:

    Kew (int m = 1);
    ~Kew ();

    bool isEmpty () const;
    int getLength () const;
    void getCustomer (int n, bool & success, Customer & cus) const;

    void enqueue (Customer cus, bool & success);
    void dequeue (Customer & cus, bool & success);

  private:
    // Used to define the memory type used by this class.
    int memoryType;

    // Used by array based instances.
    Customer aList [100];

    // Used by pointer based instances.
    Customer * pList;

    // Used by circlar based instances.
    int front;
    int rear;

    int length;
    int max;
};

#endif
