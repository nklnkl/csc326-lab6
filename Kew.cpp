#include "Kew.h"
Kew::Kew (int m) {

  max = 100;
  length = 0;

  memoryType = m;
  switch (memoryType) {
    // non circular array
    case 1:
      break;
    // circular array
    case 2:
      front = rear = -1;
      break;
    // circular pointer
    case 3:
      front = rear = -1;
      pList = new Customer [max];
      break;
    default:
      break;
  }
}

Kew::~Kew () {
  // If we're using pointer based.
  if (memoryType == 3) {
    delete [] pList;
  }
}

bool Kew::isEmpty () const {
  if (length == 0) return true;
  else return false;
}

int Kew::getLength () const {
  return length;
}

void Kew::enqueue (Customer cus, bool & success) {
  // If the line is full.
  if (length == max) {
    // Set success to false and return.
    success = false;
  }
  // Else, we have room.
  else {

    switch (memoryType) {
      // non circular array
      case 1:
        aList [length] = cus;
        break;
      // circular array
      case 2:
        rear = (rear + 1) % max;
        aList [rear] = cus;
        break;
      // circular pointer
      case 3:
        rear = (rear + 1) % max;
        * (pList + rear) = cus;
        break;
      default:
        break;
    }

    // Set success to true.
    success = true;
    // Increment length.
    length += 1;
  }
  return;
}

void Kew::dequeue (Customer & cus, bool & success) {
  // If there is nothing to dequeue.
  if (isEmpty()) {
    // Set success to false and return;
    success = false;
  }
  // Else, we do have something to dequeue.
  else {
    switch (memoryType) {
      // non circular array
      case 1:
        // assign
        cus = aList[0];
        // loop down to remove front element
        for (int i = 0; i < length - 1; i++) {
          aList[i] = aList[i+1];
        }
        break;
      // circular array
      case 2:
        // move front forward.
        front = (front + 1) % max;
        // assign
        cus = aList[front];
        break;
      // circular pointer
      case 3:
        // move front forward
        front = (front + 1) % max;
        // assign
        cus = *( pList + front );
        break;
      default:
        break;
    }

    // Set success to true.
    success = true;
    // Increment length.
    length -= 1;
  }
  return;
}

void Kew::getCustomer (int n, bool & success, Customer & cus) const {
  if (isEmpty() || n >= length) {
    success = false;
  }
  else {
    success = true;
    switch (memoryType) {
      // non circular array
      case 1:
        cus = aList [n];
        break;
      // circular array
      case 2:
        cus = aList [n];
        break;
      // circular pointer
      case 3:
        cus = * (pList + n);
        break;
      default:
        break;
    }
  }
  return;
}
