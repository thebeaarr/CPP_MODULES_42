#pragma once

#include <iostream>
#include "Fixed.hpp"


class Point
{
  private:
    Fixed x;
    Fixed y;
  public:
    Point();
    Point(const float & ,const float &);
    Point(const Point &);
    Point &operator=(Point &);
    ~Point();
    const Fixed get_x() const;
    const Fixed get_y() const;
};
Fixed area(Point const x , Point const y,Point  const z);

bool bsp( Point const a, Point const b, Point const c, Point const point);
