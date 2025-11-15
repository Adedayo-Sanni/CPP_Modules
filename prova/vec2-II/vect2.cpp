#include "vect2.hpp"

vect2::vect2(void){
  this->x = 0;
  this->y = 0;
}

vect2::vect2(int x, int y){
  this->x = x;
  this->y = y;
}

vect2::vect2 (const vect2& other){
  this->x = other.x;
  this->y = other.y;
}

vect2::~vect2(void){}

vect2 vect2::operator=(const vect2& other){
  this->x = other.x;
  this->y = other.y;
  return *this;
}

vect2 vect2::operator+(int i) const{
  vect2 temp = *this;
  temp.x = this->x + i;
  temp.y = this->y + i;
  return temp;

} 

vect2 vect2::operator-(int i)const{
  vect2 temp = *this;
  temp.x = this->x - i;
  temp.y = this->y - i;
  return temp;
}

vect2 vect2::operator*(int i)const{
  vect2 temp = *this;
  temp.x = this->x * i;
  temp.y = this->y * i;
  return temp;
}

vect2 vect2::operator+(const vect2& vec)const{
  vect2 temp = *this;
  temp.x = this->x + vec.x;
  temp.y = this->y + vec.y;
  return temp;
}

vect2 vect2::operator-(const vect2& vec)const{
  vect2 temp = *this;
  temp.x = this->x - vec.x;
  temp.y = this->y - vec.y;
  return temp;
}

vect2 vect2::operator*(const vect2& vec) const{
  vect2 temp = *this;
  temp.x = this->x * vec.x;
  temp.y = this->y * vec.y;
  return temp;
}


vect2 vect2::operator+=(int i){
  this->x = this->x + i;
  this->y = this->y + i;
  return *this;
}

vect2 vect2::operator-=(int i){
  this->x = this->x - i;
  this->y = this->y - i;
  return *this;
}

vect2 vect2::operator*=(int i){
  this->x = this->x * i;
  this->y = this->y * i;
  return *this;
}

vect2 vect2::operator+=(const vect2 vec){
  this->x = this->x + vec.x;
  this->y = this->y + vec.y;
  return *this;
}

vect2 vect2::operator-=(const vect2 vec){
  this->x = this->x - vec.x;
  this->y = this->y - vec.y;
  return *this;
}

vect2 vect2::operator*=(const vect2 vec){
  this->x = this->x * vec.x;
  this->y = this->y * vec.y;
  return *this;
}


//pre
vect2& vect2::operator++(){
  ++x;
  ++y;
  return *this;
}

vect2& vect2::operator--(){
  --x;
  --y;
  return *this;
}


//pos
vect2 vect2::operator++(int){
  vect2 temp = *this;
  ++x;
  ++y;
  return temp;
}

vect2 vect2::operator--(int){
  vect2 temp = *this;
  --x;
  --y;
  return temp;
}

bool vect2::operator==(const vect2& vec) const{
  if (this->x == vec.x && this->y == vec.y)
    return true;
  else 
    return false;
}

bool vect2::operator!=(const vect2& vec) const{
    if (this->x != vec.x || this->y != vec.y)
    return true;
  else 
    return false;
}

int& vect2::operator[](int index) {
  if (index == 0)
    return (this->x);
  else
    return (this->y);
}

int vect2::operator[](int index) const{
  if (index == 0)
    return this->x;
  else
    return this->y;
}


vect2 vect2::operator-() const{
  vect2 temp = *this;
  temp.x = -this->x;
  temp.y = -this->y;
  return temp;
} 
//negativo retorna temp


std::ostream& operator<<(std::ostream& os, const vect2 vect){
  os << "{" << vect[0] << ", " << vect[1] << "}";
  return os;
}

vect2 operator*(int i, const vect2& vect){
  return vect * i;
}
