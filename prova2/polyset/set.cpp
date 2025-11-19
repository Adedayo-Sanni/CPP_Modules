#include "set.hpp"

set(void): bag() {}

set(const set& other){
	*this = other;
}

set operator=(const set& other){
	if (this != &other){
		this->bag = other->bag;
	}
	return *this;
}

~set(void){}

set(searchable_bag &other): bag(&other){}

searchable_bag& get_bag(void){
	return *this->bag;
}

void insert(int i){
	if (!this->bag->has(i))
		this->bag->insert(i);
	return;
}
void insert(int *array, int size){
	this->bag->insert(arr, size);
}
void print(void) const{
	this->bag->print();
}
void clear(void){
	this->bag->clear();
}
bool has(int i) const{
	return this->bag->has();
}
