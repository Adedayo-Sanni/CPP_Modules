#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(void){}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &other):tree_bag(other){}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag &other){
  if(this != &other)
    tree_bag::operator=(other);
  return *this;
}

searchable_tree_bag::~searchable_tree_bag(void){}

bool searchable_tree_bag::has(int val) const{
  bool find = false;
  node *n =this->tree;

  while (n){
    if (val == n->value)
      return (find = true);
    else if (val < n->value)
      n = n->l;
    else if (val > n->value)
      n = n->r;
  }
  return find;
}