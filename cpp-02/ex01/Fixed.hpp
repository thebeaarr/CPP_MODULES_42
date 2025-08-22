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
    
    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    friend std::ostream &operator<<(std::ostream &out, Fixed const &op);
};