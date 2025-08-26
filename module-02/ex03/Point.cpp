#include "Point.hpp"
#include "Fixed.hpp"
Point::Point() : x(0.0f) , y(0.0f)
{
  // std::cout << "default constructor" << std::endl;
}
Point::Point(const float &a , const float &b): x(a) , y(b)
{
  // std::cout << "paramitrized constructor" << std::endl ;
}

Point::Point(const Point &other)
{
  this->x = other.x;
  this->y = other.y;
  // std::cout << "copy constructor" << std::endl;
}
Point::~Point()
{
  // std::cout << "destructor" << std::endl ;
}
Point &Point::operator=(Point &a)
{
  this->x = a.x;
  this->y  = a.y;
  return *this;
}

const Fixed Point::get_x() const
{
  return x;
}
const Fixed Point::get_y() const
{
  return y;
}

Fixed area(Point const x , Point const y,Point  const z)
{
  Fixed res = x.get_x() * (y.get_y() - z.get_y()) + y.get_x() * (z.get_y() - x.get_y()) + z.get_x() * (x.get_y() - y.get_y()) ;
  res = res  / Fixed(2);
  if(res < Fixed(0))
    return res * Fixed(-1);
  return res;
}
bool bsp( Point const a, Point const b, Point const c, Point const point)
{
  Fixed ABC  = area(a , b, c);
  std::cout << ABC << std::endl ;
  Fixed ABPOINT = area(a , b , point);
  std::cout << ABPOINT << std::endl ;
  Fixed ACPOINT = area(a , c , point );
  std::cout << ACPOINT << std::endl ;
  Fixed CBPOINT = area( c, b , point);
  std::cout << CBPOINT << std::endl ;

  if ((ABC == ABPOINT + ACPOINT + CBPOINT))
    return true;
  return false;
}
