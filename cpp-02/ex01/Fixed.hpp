#include <iostream>

class Fixed
{
    private:
        int _value ;
        const static int _fraction;
    public:
        Fixed();
        Fixed(const Fixed &f);
        Fixed &operator=(const Fixed &f);
        ~Fixed();


        Fixed &operator<<(const Fixed &f);
        float toFloat( void ) const;
        int toInt( void ) const;
};
