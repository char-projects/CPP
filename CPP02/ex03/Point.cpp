#include "Point.hpp"

Point::Point() : _x(0.0f), _y(0.0f) {
    // std::cout << "Default constructor called" << std::endl;
}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {
    // std::cout << "Parameterized constructor called" << std::endl;
}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {
    // std::cout << "Copy constructor called" << std::endl;
}

Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}

Point &Point::operator=(const Point &other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        *this = Point(other);
    }
    return *this;
}

std::ostream &operator<<(std::ostream &output, const Point &value) {
    output << "(" << value.getX() << ", " << value.getY() << ")";
    return output;
}

Point::~Point() {
    // std::cout << "Default destructor called" << std::endl;
}
