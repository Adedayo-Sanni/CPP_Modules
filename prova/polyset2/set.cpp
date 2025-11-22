#include "set.hpp"

set::set():bag(){}
set::set(const set& other){
  *this = other;
}
set::set(const searchable_bag& other):bag(&other){}
set set::operator=(const set& other){
  if (this != other)
    this->bag = other.bag;

}
set::~set(){}

searchable_bag& set::get_bag(){
  return *this->bag;
}

void set::insert(int i){
  this->bag->insert(i);

}
void set::insert(int *arr, int i){
  this->bag->insert(arr, i);
}
void set::clear(){
this->bag->clear();
}
void set::print() const{
this->bag->print();
}
bool set::has(int i)const{
  return this->bag->has(i);
}