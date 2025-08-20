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
    int getRawBits(void) const;
    void setRawBits(int const raw);
};