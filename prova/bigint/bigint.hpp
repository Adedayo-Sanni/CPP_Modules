#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <iostream>


class bigint{
  private:
  std::string num;

  public:
  bigint(void);
  bigint(std::string num);
  bigint(const bigint& other);
  ~bigint(void);
  bigint& operator=(const bigint& other);

  bigint operator+(const bigint& other) const;
  bigint& operator+=(const bigint& other);

  bool operator>(const bigint& other) const;
  bool operator<(const bigint& other) const;
  bool operator<=(const bigint& other) const;
  bool operator>=(const bigint& other) const;
  bool operator==(const bigint& other) const;
  bool operator!=(const bigint& other) const;

  bigint& operator>>=(int i);
  bigint& operator<<=(int i);
  bigint& operator>>=(const bigint& other);
  bigint& operator<<=(const bigint& other);


  bigint operator<<(int i);
  bigint operator>>(int i);


  bigint& operator++();
  bigint& operator++(int);
};

std::ostream& operator<<(std::ostream& os, const bigint& var);

#endif
