#include "Fixed.hpp"
int main(void)
{
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));
  Fixed const c(Fixed(10.01f) + Fixed(3.3f));
  Fixed d(Fixed(0.0012f) - Fixed(0.0012f));
  std::cout << c << std::endl ;
  std::cout << d << std::endl;
  std::cout << a << std::endl;
  std::cout << ++a << std::endl;
  std::cout << a << std::endl;
  std::cout << a++ << std::endl;
  std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << Fixed::max(a, b) << std::endl;
  return 0;
}
