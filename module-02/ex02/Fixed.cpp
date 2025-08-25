#include "Fixed.hpp"
#include <cmath>

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

Fixed::Fixed(const int &value)
{
  this->_value = value <<  _fracbits;
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float &value)
{
  this->_value = (int)roundf(value * (1 << _fracbits));
  std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const
{

  return (float)_value / (1 << _fracbits);
}

int Fixed::toInt() const
{
  return _value >> _fracbits;
}

std::ostream &operator<<(std::ostream &out , const Fixed &op)
{
  out << op.toFloat();
  return out;
}

// arithmetic operators
Fixed Fixed::operator*(const Fixed &op)
{
  Fixed tmp ;
  tmp._value = (this->_value * op._value) / ( 1 << this->_fracbits);
  return tmp;
}

Fixed Fixed::operator/(const Fixed &op)
{
  Fixed tmp ;
  tmp._value = (this->_value << this->_fracbits) / op._value;
  return tmp;
}

Fixed Fixed::operator+(const Fixed &op)
{
  Fixed tmp ;
  tmp._value = this->_value + op._value;
  return tmp;
}

Fixed Fixed::operator-(const Fixed &op)
{
  Fixed tmp ;
  tmp._value = this->_value - op._value;
  return tmp ;
}

// comparision
bool Fixed::operator<(const Fixed &op) const { return _value < op._value; }
bool Fixed::operator>(const Fixed &op) const { return _value > op._value; }
bool Fixed::operator<=(const Fixed &op) const { return _value <= op._value; }
bool Fixed::operator>=(const Fixed &op) const { return _value >= op._value; }
bool Fixed::operator==(const Fixed &op) const { return _value == op._value; }
bool Fixed::operator!=(const Fixed &op) const { return _value != op._value; }
// incrementation and decrementation ( pre ...)

Fixed &Fixed::operator++()
{
  ++this->_value;
  return *this;
}

Fixed Fixed::operator++(int)
{
  Fixed tmp(*this);
  ++this->_value;
  return tmp;
}

Fixed Fixed::operator--(int)
{
  Fixed &tmp(*this);
  ++this->_value;
  return tmp;
}

Fixed &Fixed::operator--()
{
  --this->_value;
  return *this;
}

const Fixed &Fixed::max(const Fixed &a , const Fixed &b)
{
  if(a > b )
    return a;
  return b;
}

const Fixed &Fixed::max(Fixed &a , Fixed &b)
{
  if(a > b )
    return a;
  return b;
}

const Fixed &Fixed::min(const Fixed &a , const Fixed &b)
{
  if (a < b)
    return a;
  return b;
}
const Fixed &Fixed::min(Fixed &a , Fixed &b)
{
  if (a < b)
    return a;
  return b;
}
