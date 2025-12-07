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

    Fixed(const float &value);
    Fixed(const int &value);
    float toFloat(void) const;
    int toInt(void) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &out, Fixed const &op);
