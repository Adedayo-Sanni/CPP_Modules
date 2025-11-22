#ifndef SET_HPP
#define SET_HPP
#include "searchable_bag.hpp"

class set{
  private:
  searchable_bag *bag;

  public:
  set();
  set(const set& other);
  set(const searchable_bag& other);
  set operator=(const set& other);
  ~set();

  searchable_bag& get_bag();

  void insert(int i);
  void insert(int *arr, int i);
  void clear();
  void print() const;
  bool has(int i) const;

};

#endif