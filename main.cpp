#include "Kew.cpp"
#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int kew (int m);
bool palindrome (string);

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
    // Call kew with the user input as the parameter.
    kew(input);
  }
  // Problem 4.
  else {
    string exp;
    cout << "Enter an expression." << endl;
    cout << "$: ";
    cin >> exp;
    if (palindrome (exp)) {
      cout << "It is palindrome." << endl;
    } else {
      cout << "It is not a palindrome," << endl;
    }
  }

  return 0;
}

int kew (int m) {
  // m will determine the memory type used by this object. check the class
  // implementation for the breakdown of how this works.
  Kew myQueue (m);
  bool success;

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

bool palindrome (string exp) {
  queue<char> q;
  stack<char> s;

  // Loop through the string and push its characters into a stack/queue.
  for(int i = 0; i < exp.length(); i++) {
    q.push(exp.at(i));
    s.push(exp.at(i));
  }

  while ((!s.empty()) && (!q.empty())) {
    if (s.top() != q.front())
      return false;
    s.pop();
    q.pop();
  }

  return true;
}
