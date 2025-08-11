#include <iostream>

class Fixed {
private:
    int _value;
    const static int _fract = 8;

public:
    // canonical form
    Fixed();
    Fixed(Fixed const &fixed);
    Fixed &operator=(Fixed const &f);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};
