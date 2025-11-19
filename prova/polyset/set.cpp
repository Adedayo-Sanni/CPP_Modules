#include "set.hpp"

set::set():bag(){}

set::set(const set &other){
  *this = other;
}
set set::operator=(const set &other){
  this->bag = other.bag;
  return *this;
}

set::~set(){}

set::set(const searchable_bag &other): bag(&other){}

//________________methods___________________________

searchable_bag &set::get_bag(void){
  return *this->bag;
}

void set::insert(int i){
  if (this->bag->has(i))
    return
  this->bag->insert(i);
}

void set::insert(int *arr, int size){
  this->bag->insert(arr, size);
}

void set::print(void) const{
  this->bag->print();
}

void set::clear(void){
  this->bag->clear();
}

bool set::has(int i) const{
  return this->bag->has(i);
}