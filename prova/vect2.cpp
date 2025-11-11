#include "vect2.hpp"

vect2::vect2(void) {
  this->x = 0;
  this->y = 0;
}

vect2::vect2(int x, int y){
  this->x = x;
  this->y = y;
}

vect2::vect2(const vect2& var){
  this->x = var.x;
  this->y = var.y;
}

vect2::~vect2(void){}

vect2& vect2::operator=(const vect2 var){
  this->x = var.x;
  this->y = var.y;
  return *this;
}


vect2 vect2::operator+(int var) const{
  vect2 temp = *this;
  temp.x = this->x + var;
  temp.y = this->y + var;
  return temp;
}

vect2 vect2::operator-(int var) const{
  vect2 temp = *this;
  temp.x = this->x - var;
  temp.y = this->y - var;
  return temp;
}

vect2 vect2::operator*(int var) const{
  vect2 temp = *this;
  temp.x = this->x * var;
  temp.y = this->y * var;
  return temp;
}

vect2 vect2::operator+(const vect2 var) const{
  vect2 temp = *this;
  temp.x = this->x + var.x;
  temp.y = this->y + var.y;
  return temp;
}

vect2 vect2::operator-(const vect2 var) const{
  vect2 temp = *this;
  temp.x = this->x - var.x;
  temp.y = this->y - var.y;
  return temp;
}

vect2 vect2::operator*(const vect2 var) const{
  vect2 temp = *this;
  temp.x = this->x * var.x;
  temp.y = this->y * var.y;
  return temp;
}

vect2& vect2::operator-=(int var) {
  this->x = this->x - var;
  this->y = this->y - var;
  return *this;
}
vect2& vect2::operator+=(int var) {
  this->x = this->x + var;
  this->y = this->y + var;
  return *this;
}

vect2& vect2::operator*=(int var){
  this->x = this->x * var;
  this->y = this->y * var;
  return *this;
}

vect2& vect2::operator-=(const vect2 var){
  this->x = this->x - var.x;
  this->y = this->y - var.y;
  return *this;
}

vect2& vect2::operator+=(const vect2 var) {
  this->x = this->x + var.x;
  this->y = this->y + var.y;
  return *this;
}
vect2& vect2::operator*=(const vect2 var) {
  this->x = this->x * var.x;
  this->y = this->y * var.y;
  return *this;
}

//pre
vect2& vect2::operator++(){
  ++this->x;
  ++this->y;
  return *this;
  
}
vect2& vect2::operator--(){
  --this->x;
  --this->y;
  return *this;
}

//pos
vect2 vect2::operator--(int){
  vect2 temp = *this;
  --this->x;
  --this->y;
  return temp;
  
}
vect2 vect2::operator++(int){
  vect2 temp = *this;
  ++this->x;
  ++this->y;
  return temp;
}

//negativo
vect2 vect2::operator-(void) const{
  vect2 temp;
  temp.x = -this->x ;
  temp.y = -this->y ;
  return temp;
} 

int& vect2::operator[](int index){
  if (index == 0)
    return(this->x);
  else
    return(this->y);
}
const int vect2::operator[](int index) const{
  if (index == 0)
    return(this->x);
  else
    return(this->y);
}

std::ostream& operator<<(std::ostream& os, const vect2& var){
  os << "{" << var[0] << ", " << var[1] << "}";
  return os;
}


vect2 operator*(int i, const vect2& var) {
   return var * i;
}

bool vect2::operator==(const vect2 var) const{
  if(this->x == var.x && this->y==var.y)
    return true;
  else
    return false;
}

bool vect2::operator!=(const vect2 var) const{
  if(this->x != var.x || this->y!=var.y)
    return true;
  else
    return false;
}