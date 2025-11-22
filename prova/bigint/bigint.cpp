#include "bigint.hpp"

// Remove zeros à esquerda internamente
void bigint::normalize() {
    std::string::size_type i = 0;
    while (i < num.size() - 1 && num[i] == '0')
        i++;

    num = num.substr(i);
}

bigint::bigint(void){
  this->num = "0";
}

bigint::bigint(std::string num){
  this->num = num;
  normalize();
}

bigint::bigint(int value) {
    std::stringstream ss;
    ss << value;
    this->num = ss.str();
}


bigint::bigint(const bigint& other){
  this->num = other.num;
}

bigint::~bigint(void){}

bigint& bigint::operator=(const bigint& other){
  this->num = other.num;
  normalize();
  return *this;
}
bigint bigint::operator+(const bigint& other) const {
  std::string nb1 = this->num;
  std::string nb2 = other.num;
  std::string result;
  int carry = 0;

  std::string::reverse_iterator it1 = nb1.rbegin(); // o iterador pega de trás pra frente
  std::string::reverse_iterator it2 = nb2.rbegin();

  for ( ; it1 != nb1.rend() && it2 != nb2.rend(); it1++, it2++){
    int last1 = *it1 -'0'; // pega o numero real no lugar do char aponta pro ultimo de tras pra frente
    int last2 = *it2 -'0';
    int temp = last1 + last2 + carry; // soma os ultimos numero + carry
    carry = temp/10;// divide o resultado de temp por 10
    
    result.insert(result.begin(), (temp%10) + '0'); // pega o resto da divisão de tem por 10 , transforma em char e coloca no começo de result
  }
    while (it1 != nb1.rend())
    {
      int last1 = *it1 - '0';
      int temp = last1 + carry;
      carry = temp / 10;
      result.insert(result.begin(), (temp%10) + '0');
      it1++;
    }

    while (it2 != nb2.rend())
    {
      int last2 = *it2 - '0';
      int temp = last2 + carry;
      carry = temp / 10;
      result.insert(result.begin(), (temp%10) + '0');
      it2++;
    }
    if (carry > 0) {
      result.insert(result.begin(), carry + '0');
    }
    return bigint(result);
}

bigint& bigint::operator+=(const bigint& other){
  return *this = *this + other;
}

bool bigint::operator<(const bigint& other) const{
  if (this->num.size() != other.num.size())
    return this->num.size() < other.num.size();
  return this->num < other.num;
}

bool bigint::operator>(const bigint& other) const {
    return other < *this;
}

bool bigint::operator<=(const bigint& other) const {
    return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}

bool bigint::operator==(const bigint& other) const {
    return this->num == other.num;
}

bool bigint::operator!=(const bigint& other) const {
    return !(*this == other);
}

bigint& bigint::operator<<=(int i) {
    // reaproveitar lógica já existente
    this->num.append(i, '0');
    return *this;
}

bigint& bigint::operator>>=(int i) {
    if (i >= (int)this->num.size()) {
        this->num = "0";
        return *this;
    }
    this->num.erase(this->num.size() - i);
    return *this;
}


////////////////////////////////////////////////////

bigint& bigint::operator<<=(const bigint& other) {
    size_t shift = 0;

    for (std::string::size_type i = 0; i < other.num.size(); ++i) {
        char c = other.num[i];
        shift = shift * 10 + (c - '0');
    }

    this->num.append(shift, '0');
    return *this;
}

bigint& bigint::operator>>=(const bigint& other) {
    size_t shift = 0;

    for (std::string::size_type i = 0; i < other.num.size(); ++i) {
        char c = other.num[i];
        shift = shift * 10 + (c - '0');
    }

    if (shift >= this->num.size()) {
        this->num = "0";
    } else {
        this->num.erase(this->num.size() - shift);
    }
    return *this;
}

////////////////////////////////////////////////////////

bigint bigint::operator<<(int i) const{
    bigint tmp(*this);
    tmp <<= i;
    return tmp;
}

bigint bigint::operator>>(int i) const {
    bigint tmp(*this);
    tmp >>= i;
    return tmp;
}

bigint& bigint::operator++() {
    *this = *this + bigint("1");
    return *this;
}

bigint bigint::operator++(int) {
    bigint tmp(*this);
    *this = *this + bigint("1");
    return tmp;
}


std::ostream& operator<<(std::ostream& os, const bigint& var){
    std::string s = var.num;

    // Remove zeros à esquerda
    std::string::size_type i = 0;
    while (i < s.size() - 1 && s[i] == '0')
        ++i;

    os << s.substr(i);
    return os;
}