#include <iostream>

class Fixed
{
    private:
        int _value ;
        const static int _fraction;
    public:
        Fixed();
        Fixed(int const &i);
        Fixed(float const &f);
        Fixed(const Fixed &f);
        Fixed &operator=(const Fixed &f);
        ~Fixed();

        float &operator<<(const Fixed &f);
        float toFloat( void ) const;
        int toInt( void ) const;
};
