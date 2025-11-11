#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2{
  private:
  int x;
  int y;

  public:
  vect2(void);
  vect2(int x, int y);
  vect2(const vect2& var);
  ~vect2(void);
  vect2& operator=(const vect2 var);


  vect2 operator+(int var) const;
  vect2 operator-(int var) const;
  vect2 operator*(int var) const;
  vect2 operator+(const vect2 var) const;
  vect2 operator-(const vect2 var) const;
  vect2 operator*(const vect2 var) const;

  vect2& operator-=(int var);
  vect2& operator+=(int var);
  vect2& operator*=(int var);
  vect2& operator-=(const vect2 var);
  vect2& operator+=(const vect2 var);
  vect2& operator*=(const vect2 var);

  bool operator==(const vect2 var) const;
  bool operator!=(const vect2 var) const;

  //pre
  vect2& operator++();
  vect2& operator--();
  //pos
  vect2 operator++(int);
  vect2 operator--(int);

 
  vect2 operator-(void) const; //negativo
  int& operator[](int index);
  const int operator[](int index) const;

};

std::ostream& operator<<(std::ostream& os, const vect2& var);
vect2 operator*(int i, const vect2& var);

#endif