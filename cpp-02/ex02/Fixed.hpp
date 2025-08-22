#pragma once 

#include <iostream>
#include <string>


class Fixed
{
  private:
    int _value;
    static const int _fracbits = 8;
  public:

    // i think this is the canonical form ( orthodoxal one )
    Fixed();
    Fixed(const Fixed &);
    Fixed &operator=(const Fixed &op);
    ~Fixed();

    Fixed(const int &value);
    Fixed(const float &value);
    float toFloat(void) const;
    int toInt(void) const;
    // // The 4 arithmetic operators
    // float &operator+(const Fixed &op) const;
    // float &operator-(const Fixed &op) const;
    // float &operator*(const Fixed &op) const;
    // float &operator/(const Fixed &op) const;

    // Member operators (encapsulation preserved)
    bool operator<(const Fixed &op) const { return _value < op._value; }
    bool operator>(const Fixed &op) const { return _value > op._value; }
    bool operator<=(const Fixed &op) const { return _value <= op._value; }
    bool operator>=(const Fixed &op) const { return _value >= op._value; }
    bool operator==(const Fixed &op) const { return _value == op._value; }
    bool operator!=(const Fixed &op) const { return _value != op._value; }
    // The 4 increment/decrement ( .resp pre...)
    Fixed operator++(int);
    Fixed operator--(int);
    Fixed operator++();
    Fixed operator--();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    const static Fixed &min(const Fixed &a, const Fixed &b);
    const static Fixed &min(Fixed &a, Fixed &b);
    const static Fixed &max(const Fixed &a, const Fixed &b);
    const static Fixed &max(Fixed &a, Fixed &b);
    friend std::ostream &operator<<(std::ostream &out, Fixed const &op);
};