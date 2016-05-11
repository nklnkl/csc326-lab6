#include "Kew.cpp"
#include <iostream>
using namespace std;

int kew (int m);

int main () {
  bool success = false;
  int input;

  while (!success) {
    // Decide which problem set to use.
    cout << "0. Exit." << endl;
    cout << "1. Non-circular Array-based queue." << endl;
    cout << "2. Circular Array-based queue." << endl;
    cout << "3. Circular Pointer-based queue." << endl;
    cout << "4. Palidrome" << endl;
    cout << "$: ";
    cin >> input;
    if (input > -1 && input < 5) success = true;
  }



  // Step 1 for problems 1-3.
  if (input > 0 && input < 4 ) {
    kew(input);
  }
  // Problem 4.
  else {
  }

  return 0;
}

int kew (int m) {
  bool success;
  Kew myQueue (m);

  // Step 2.
  Customer newCus ("Tom");
  newCus.setArrival(1);
  // Step 3.
  myQueue.enqueue(newCus, success);

  // Step 4.
  newCus.setName("Bob");
  newCus.setArrival(3);
  // Step 5.
  myQueue.enqueue(newCus, success);

  // Loop step 6.
  for (int i = 0; i < 2; i++) {
    // Request a customer at index i, get success bool and the Customer if possible.
    myQueue.getCustomer(i, success, newCus);
    if (success) {
      cout << "Name: " << newCus.getName() << endl;
    }
  }

  // Loop steps 7-9.
  for (int i = 0; i < 3; i++) {
    myQueue.dequeue(newCus, success);
    if (success) {
      cout << newCus.getName() << " is leaving." << endl;
    }
    else {
      cout << "The queue is empty." << endl;
    }
  }

  return 0;
}
