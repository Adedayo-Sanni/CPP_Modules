#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(){}
searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag& other): tree_bag(other){}
searchable_tree_bag::searchable_tree_bag operator=(const searchable_tree_bag& other){
	if (this != &other){
		tree_bag::operator=(other);
	}
	return *this;
}
searchable_tree_bag::~searchable_tree_bag(){}

bool searchable_tree_bag::has(int i){
	bool find = false;
	node *n = this->tree;
	while(n)
	{
		if (i == n->value){
			find = true;
			break;
		}
		else if(i < n->value)
			n = n->l;
		else if(i > n->value)
			n = n->r;
	}
	return find;
}
