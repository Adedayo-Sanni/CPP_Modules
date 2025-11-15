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
  vect2 (const vect2& other);
  ~vect2(void);
  vect2 operator=(const vect2& other);

  vect2 operator+(int i)const; //retornam temp
  vect2 operator-(int i)const;
  vect2 operator*(int i)const;
  vect2 operator+(const vect2& vec)const;
  vect2 operator-(const vect2& vec)const;
  vect2 operator*(const vect2& vec)const;

  vect2 operator+=(int i);
  vect2 operator-=(int i);
  vect2 operator*=(int i);
  vect2 operator+=(const vect2 vec);
  vect2 operator-=(const vect2 vec);
  vect2 operator*=(const vect2 vec);

  //pre
  vect2& operator++();
  vect2& operator--();

  //pos
  vect2 operator++(int);
  vect2 operator--(int);

  bool operator==(const vect2& vec) const;
  bool operator!=(const vect2& vec) const;

  int& operator[](int index);
  int operator[](int index) const;

  vect2 operator-() const; //negativo retorna temp

};

std::ostream& operator<<(std::ostream& os, const vect2 vect);
vect2 operator*(int i, const vect2& vect);

#endif