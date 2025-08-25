#pragma once

#include <iostream>
#include <string>


class Fixed
{
  private:
    int _value;
    static const int _fracbits = 8;
  public:

    Fixed();
    Fixed(const Fixed &);
    Fixed &operator=(const Fixed &op);
    ~Fixed();

    Fixed(const int &value);
    Fixed(const float &value);
    float toFloat(void) const;
    int toInt(void) const;

    Fixed operator*(const Fixed &op) const;
    Fixed operator/(const Fixed &op) const;
    Fixed operator+(const Fixed &op) const;
    Fixed operator-(const Fixed &op) const ;

    bool operator<(const Fixed &op) const ;
    bool operator>(const Fixed &op) const ;
    bool operator<=(const Fixed &op) const;
    bool operator>=(const Fixed &op) const ;
    bool operator==(const Fixed &op) const ;
    bool operator!=(const Fixed &op) const;

    Fixed operator++(int);
    Fixed operator--(int);
    Fixed &operator++();
    Fixed &operator--();

    int getRawBits(void) const;
    void setRawBits(int const raw);

    const static Fixed &min(const Fixed &a, const Fixed &b);
    const static Fixed &min(Fixed &a, Fixed &b);
    const static Fixed &max(const Fixed &a, const Fixed &b);
    const static Fixed &max(Fixed &a, Fixed &b);
};
  
std::ostream &operator<<(std::ostream &out, Fixed const &op);