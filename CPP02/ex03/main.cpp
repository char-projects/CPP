#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
	bool res;

	// Point is inside the triangle
	Point x(0, 0);
	Point y(3, 0);
	Point z(2, 3);
	Point pt(2, 1);
    std::cout << "Triangle: (" << x << ", " << y << ", " << z << "), Point: " << pt << " -> ";
	res = bsp(x, y, z, pt);
	std::cout << (res ? "INSIDE" : "OUTSIDE") << std::endl;

	// Point is outside the triangle
	Point a(0, 0);
	Point b(3, 0);
	Point c(2, 3);
	Point pt2(4, 4);
	std::cout << "Triangle: (" << a << ", " << b << ", " << c << "), Point: " << pt2 << " -> ";
	res = bsp(a, b, c, pt2);
	std::cout << (res ? "INSIDE" : "OUTSIDE") << std::endl;

	// Point is on the edge of the triangle
	Point p1(0, 0);
	Point p2(3, 0);
	Point p3(2, 3);
	Point p4(1, 0);
	std::cout << "Triangle: (" << p1 << ", " << p2 << ", " << p3 << "), Point: " << p4 << " -> ";
	res = bsp(p1, p2, p3, p4);
	std::cout << (res ? "INSIDE" : "OUTSIDE") << std::endl;
}
