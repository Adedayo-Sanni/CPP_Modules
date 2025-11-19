#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(){}

searchable_array_bag::searchable_array_bag(const searchable_array_bag &other):array_bag(other){}

searchable_array_bag& searchable_array_bag::operator=(const searchable_array_bag &other){
  if (this != &other)
    array_bag::operator=(other);
  return *this;
}

searchable_array_bag::~searchable_array_bag(void){}

bool searchable_array_bag::has(int val) const{
  bool find = false;
  int i = 0;
  while (i < this->size)
  {
    if (val == *this->data)
      find = true;
    i++;
  }
  return find;
}