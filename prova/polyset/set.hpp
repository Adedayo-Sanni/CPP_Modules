#ifndef SET_HPP
#define SET_HPP
#include "searchable_bag.hpp"

class set{
  private:
  searchable_bag *bag;

  public:
  set();
  set(const set &other);
  set operator=(const set &other);
  ~set();

  set(const searchable_bag &other);

  //methods

  searchable_bag &get_bag(void);
  void insert(int i);
  void insert(int *arr, int size);
  void print(void) const;
  void clear(void);
  bool has(int i) const;
};

#endif