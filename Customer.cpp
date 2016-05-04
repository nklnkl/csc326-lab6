#include "Customer.h"

Customer::Customer () {
  arrival = -1;
  service = -1;
  finish = -1;
}

Customer::Customer (string n) {
  name = n;
  arrival = -1;
  service = -1;
  finish = -1;
}

Customer::~Customer () {

}

string Customer::getName () const {
  if (name.size() != 0) return name;
  else return "no name";
}

int Customer::getArrival () const {
  if (arrival != -1) return arrival;
  else return -1;
}

int Customer::getService () const {
  if (service != -1) return service;
  else return -1;
}

int Customer::getFinish () const {
  if (finish != -1) return finish;
  else return -1;
}

bool Customer::setName (string n) {
  if (name == n) return false;
  name = n;
  return true;
}

bool Customer::setArrival (int a) {
  if (a < 0) return false;
  arrival = a;
  return true;
}

bool Customer::setService (int s) {
  if (s < 0) return false;
  service = s;
  return true;
}

bool Customer::setFinish (int f) {
  if (f < 0) return false;
  finish = f;
  return true;
}
