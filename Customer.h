#ifndef _CUSTOMER
#define _CUSTOMER

#include <string>
using namespace std;

class Customer {
  public:

    // Blank customer object.
    Customer();
    // Named customer object.
    Customer(string n);

    ~Customer();

    // Getters, times return -1 if not set.
    string getName() const;
    int getArrival() const;
    int getService() const;
    int getFinish() const;

    // To change name of customer, returns true if new name is different.
    bool setName(string n);
    // Sets the arrival time, returns true if value was valid.
    bool setArrival (int a);
    // Sets the service time, returns true if value was valid.
    bool setService (int s);
    // Sets the finish time, returns true if the value was valid.
    bool setFinish (int f);

  private:
    string name;
    int arrival;
    int service;
    int finish;
};

#endif
