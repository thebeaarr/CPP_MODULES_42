#include "Fixed.hpp"


Fixed::Fixed() : _value(0)
{
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copyc): _value(copyc._value)
{
  std::cout << "Copy constructor called" << std::endl;
}

int Fixed::getRawBits() const
{
  std::cout << "getRawBits member function called" << std::endl;
  return _value;
}

Fixed &Fixed::operator=(const Fixed &op)
{
  this->_value = op._value;
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

void Fixed::setRawBits(int const raw)
{
  std::cout << "setRawBits member function called" << std::endl;
  this->_value = raw;
}


Fixed::~Fixed()
{
  std::cout << "Destructor called" << std::endl;
}