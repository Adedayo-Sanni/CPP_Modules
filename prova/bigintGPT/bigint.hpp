#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <vector>
#include <string>
#include <iostream>

class bigint {
private:
    std::vector<int> digits; // cada dígito (LSB primeiro)

    void normalize(); // remove zeros extras

public:
    bigint();
    bigint(int);
    bigint(const std::string&);
    bigint(const bigint&);

    bigint& operator=(const bigint&);

    // Comparação
    bool operator<(const bigint&) const;
    bool operator>(const bigint&) const;
    bool operator==(const bigint&) const;
    bool operator!=(const bigint&) const;

    // Soma
    bigint operator+(const bigint&) const;
    bigint& operator+=(const bigint&);

    // Shift decimal
    bigint operator<<(int) const;
    bigint& operator<<=(int);
    bigint operator>>(int) const;
    bigint& operator>>=(int);

    // Incremento
    bigint& operator++();
    bigint operator++(int);

    // Print
    friend std::ostream& operator<<(std::ostream&, const bigint&);
};

#endif
