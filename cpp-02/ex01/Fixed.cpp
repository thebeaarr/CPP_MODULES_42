#include "Fixed.hpp"


Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl ;
}

Fixed::Fixed(const Fixed &f) {
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed &Fixed::operator=(const Fixed &f) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = f._value;
    return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

float Fixed::toFloat() const { return (float)_value / (1 << _fraction); }

int Fixed::toInt() const { return _value; }

float &Fixed::operator<<(const Fixed &f) {
    // return the floiting point of the value.
    return (float)this->_value;
}

Fixed::Fixed(int const &i) {}

Fixed::Fixed(float const &f) {
    std::cout << "Float constructor called" << std::endl;
    // use fixed point. to convert this.
}

Fixed::Fixed(int const &i) {
    std::cout << "Int constructor called" << std::endl;
    // use fixed point. to convert this.
}
