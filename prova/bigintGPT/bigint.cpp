#include "bigint.hpp"

bigint::bigint() {
    digits.push_back(0);
}

bigint::bigint(int n) {
    if (n <= 0) {
        digits.push_back(0);
        return;
    }
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
}

bigint::bigint(const std::string& s) {
    for (int i = s.size() - 1; i >= 0; --i)
        digits.push_back(s[i] - '0');
    normalize();
}

bigint::bigint(const bigint& other) : digits(other.digits) {}

bigint& bigint::operator=(const bigint& other) {
    digits = other.digits;
    return *this;
}

void bigint::normalize() {
    while (digits.size() > 1 && digits.back() == 0)
        digits.pop_back();
}

bool bigint::operator<(const bigint& other) const {
    if (digits.size() != other.digits.size())
        return digits.size() < other.digits.size();

    for (int i = digits.size() - 1; i >= 0; --i)
        if (digits[i] != other.digits[i])
            return digits[i] < other.digits[i];

    return false;
}

bool bigint::operator>(const bigint& other) const { return other < *this; }
bool bigint::operator==(const bigint& other) const { return digits == other.digits; }
bool bigint::operator!=(const bigint& other) const { return !(*this == other); }

bigint bigint::operator+(const bigint& other) const {
    bigint result;
    result.digits.clear();

    int carry = 0;
    size_t maxlen = (digits.size() > other.digits.size()) ? digits.size() : other.digits.size();

    for (size_t i = 0; i < maxlen || carry; ++i) {
        int a = (i < digits.size()) ? digits[i] : 0;
        int b = (i < other.digits.size()) ? other.digits[i] : 0;

        int sum = a + b + carry;
        result.digits.push_back(sum % 10);
        carry = sum / 10;
    }

    return result;
}

bigint& bigint::operator+=(const bigint& other) {
    *this = *this + other;
    return *this;
}

bigint& bigint::operator<<=(int n) {
    if (n > 0)
        digits.insert(digits.begin(), n, 0);

    return *this;
}

bigint bigint::operator<<(int n) const {
    bigint tmp(*this);
    tmp <<= n;
    return tmp;
}

bigint& bigint::operator>>=(int n) {
    if ((size_t)n >= digits.size())
        digits = std::vector<int>(1, 0);
    else
        digits.erase(digits.begin(), digits.begin() + n);

    return *this;
}

bigint bigint::operator>>(int n) const {
    bigint tmp(*this);
    tmp >>= n;
    return tmp;
}

bigint& bigint::operator++() {
    *this += bigint(1);
    return *this;
}

bigint bigint::operator++(int) {
    bigint tmp(*this);
    *this += 1;
    return tmp;
}

std::ostream& operator<<(std::ostream& os, const bigint& var) {
    for (int i = var.digits.size() - 1; i >= 0; --i)
        os << var.digits[i];
    return os;
}
