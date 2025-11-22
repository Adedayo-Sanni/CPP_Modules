#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <iostream>
#include <string>
#include <sstream>


class bigint {
private:
    std::string num;
    void normalize();

public:
    bigint();
    bigint(std::string num);
    bigint(int value);
    bigint(const bigint& other);
    ~bigint();
    bigint& operator=(const bigint& other);

    // Soma
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);

    // Comparações
    bool operator<(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>=(const bigint& other) const;
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;

    // Shifts por inteiro
    bigint& operator<<=(int i);
    bigint& operator>>=(int i);

    bigint& operator<<=(const bigint& other);
    bigint& operator>>=(const bigint& other);

    bigint operator<<(int i) const;
    bigint operator>>(int i) const;

    // Incrementos
    bigint& operator++();     // prefixo
    bigint operator++(int);   // pós-incremento (SEM &)

    friend std::ostream& operator<<(std::ostream& os, const bigint& var);
};

#endif
