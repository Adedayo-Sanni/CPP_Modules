#ifndef VECT2_HPP
#define VECT2_HPP

#include<iostrem>

class vect2{

	private:
	int x;
	int y;

	public:
	vect2(void);
	vect2(int x, int y);
	vect2(const vect2& var);
	~vect2(void);
	vect2& operator=(const vect2& var);

	++, -- pre e pós 
	vect2& operator++();
	vect2& operator--();
	vect2 operator++(int);
	vect2 operator--(int);

	+-* int e vect retorna temp e final const
	vect2 operator+(int var)const;
	vect2 operator-(int var)const;
	vect2 operator*(int var)const;
	vect2 operator+(const vect2& var)const;
	vect2 operator-(const vect2& var)const;
	vect2 operator*(const vect2& var)const;

	-=+=*= int e vect retorna *this sem const
	vect2& operator+=(int var);
	vect2& operator-=(int var);
	vect2& operator*=(int var);
	vect2& operator+=(const vect2 var);
	vect2& operator-=(const vect2 var);
	vect2& operator*=(const vect2 var);

	bool operator==(const vect2& var) const;
	bool operator!=(const vect2& var) const;

	int& operator[](int index);
	const int& operator[](int index);
	vect2 operator-(void); //negativo


};

vect2& operator*(vect2& var);
std::ostream& operator<<(std::ostream& os, const vect2& var);

#endif
