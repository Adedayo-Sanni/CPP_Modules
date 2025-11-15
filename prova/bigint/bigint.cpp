#include "bigint.hpp"

bigint::bigint(void){
  this->num = "0";
}

bigint::bigint(std::string num){
  this->num = num;
}

bigint::bigint(const bigint& other){
  this->num = other.num;
}

bigint::~bigint(void){}

bigint& bigint::operator=(const bigint& other){
  this->num = other.num;
  return *this;
}

bigint bigint::operator+(const bigint& other) const{
    std::string nb1 = this->num;
    std::string nb2 = other.num;

    std::string result;
    int carry = 0;

    std::string::reverse_iterator counter1 = nb1.rbegin();
    std::string::reverse_iterator counter2 = nb2.rbegin();

    // Somar enquanto ambos têm dígitos
    for (; counter1 != nb1.rend() && counter2 != nb2.rend(); counter1++, counter2++) {
        int d1 = (*counter1) - '0';
        int d2 = (*counter2) - '0';

        int temp = d1 + d2 + carry;
        carry = temp / 10;

        result.insert(result.begin(), (temp % 10) + '0');
    }

    // Se nb1 ainda tem dígitos
    while (counter1 != nb1.rend()) {
        int d1 = (*counter1) - '0';
        int temp = d1 + carry;

        carry = temp / 10;
        result.insert(result.begin(), (temp % 10) + '0');

        counter1++;
    }

    // Se nb2 ainda tem dígitos
    while (counter2 != nb2.rend()) {
        int d2 = (*counter2) - '0';
        int temp = d2 + carry;

        carry = temp / 10;
        result.insert(result.begin(), (temp % 10) + '0');

        counter2++;
    }

    // Se sobrou carry
    if (carry != 0) {
        result.insert(result.begin(), carry + '0');
    }

    return bigint(result);
}

bigint& bigint::operator+=(const bigint& other){

}

bool bigint::operator>(const bigint& other) const{
  if (this->num > other.num)
    return true;
  else
    return false;
}

bool bigint::operator<(const bigint& other) const{
  if (this->num < other.num)
    return true;
  else
    return false;
}

bool bigint::operator<=(const bigint& other) const{
  if (this->num <= other.num)
    return true;
  else
    return false;
}

bool bigint::operator>=(const bigint& other) const{
  if (this->num >= other.num)
    return true;
  else
    return false;
}

bool bigint::operator==(const bigint& other) const{
  if (this->num == other.num)
    return true;
  else
    return false;
}

bool bigint::operator!=(const bigint& other) const{
  if (this->num != other.num)
    return true;
  else
    return false;
}



bigint& bigint::operator>>=(const bigint& other){

}

bigint& bigint::operator<<=(const bigint& other){

}


bigint& bigint::operator>>=(int i){

}

bigint& bigint::operator<<=(int i){

}



bigint& bigint::operator++(){

}

bigint& bigint::operator++(int){

}



std::ostream& operator<<(std::ostream& os, const bigint& var){
  os << 
  return os;
}
