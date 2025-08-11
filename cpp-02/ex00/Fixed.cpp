#include "Fixed.hpp"

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(Fixed const &fixed) {
    *this = fixed;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &f) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->_value = f._value;
    return *this;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

void Fixed::setRawBits(int const raw) { _value = raw;

    std::cout << "setRawBits member function called" << std::endl;
}


int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}
