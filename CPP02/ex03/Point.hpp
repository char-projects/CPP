#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

class Point {
  private:
    const Fixed _x;
    const Fixed _y;

  public:
    Point();
    Point(Fixed x, Fixed y);
    Point(const Point &other);

    Fixed getX() const;
    Fixed getY() const;

    Point &operator=(const Point &other);

    ~Point();
};

std::ostream& operator<<(std::ostream &output, const Point &value);
Fixed triangleArea(Point const &p1, Point const &p2, Point const &p3);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif