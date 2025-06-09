#include "Fixed.hpp"
#include "Point.hpp"

// Returns the signed area of the triangle formed by three points
Fixed triangleArea(Point const &p1, Point const &p2, Point const &p3) {
    return (p1.getX() * (p2.getY() - p3.getY()) +
            p2.getX() * (p3.getY() - p1.getY()) +
            p3.getX() * (p1.getY() - p2.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    // Main triangle area
    Fixed areaABC = triangleArea(a, b, c);

    // Areas of triangles formed with the point and each edge of the triangle
    Fixed areaPAB = triangleArea(point, a, b); 
    Fixed areaPBC = triangleArea(point, b, c);
    Fixed areaPCA = triangleArea(point, c, a);

    // Returns true if all values are positive or all are negative
    // So the point is inside the triangle if all areas have the same sign
    return ((areaABC > 0 && areaPAB > 0 && areaPBC > 0 && areaPCA > 0) ||
            (areaABC < 0 && areaPAB < 0 && areaPBC < 0 && areaPCA < 0));
}