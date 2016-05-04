#include "Line.h"

Line::Line () {
  list = new Customer [100];
  length = 0;
}

Line::Line (int n) {
  list = new Customer [n];
  length = 0;
}

Line::~Line () {
  delete list;
}

bool Line::isEmpty () const {
  if (length == 0) return true;
  else return false;
}

int Line::getLength () const {
  return length;
}

void Line::enqueue (Customer & cus, bool & success) {
  // If the line is full.
  if (length == 100) {
    // Set success to false and return.
    success = false;
    return;
  }
  // Else, we have room.
  else {
    // Set the next empty spot for the new customer and set success to true.
    list [length] = cus;
    success = true;
    return;
  }
}

void Line::dequeue (Customer & cus, bool & success) {``                               ` `
  // If there is nothing to dequeue.
  if (isEmpty()) {
    // Set success to false and return;
    success = false;
    return;
  }
  // Else, we do have something to dequeue.
  else {
    cus = list [0];
    for (int i = 0; i < length - 1; i++) {
      list[i] = list[i+1];
    }
    // Delete the last element since it was copied down.
    list[length - 1] = NULL;
    // Decrement length.
    length -= 1;
    success = true;
    return;
  }
}
