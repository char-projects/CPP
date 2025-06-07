#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _rawBits(0) {
    // Default constructor
}

Fixed::Fixed(const Fixed &other) : _rawBits(other.getRawBits()) {
    // Copy constructor
}

Fixed::Fixed(const int value) {
    _rawBits = value << _fractionalBits; // Convert integer to fixed-point
}

Fixed::Fixed(const float value) {
    _rawBits = static_cast<int>(value * (1 << _fractionalBits)); // Convert float to fixed-point
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _rawBits = other.getRawBits();
    }
    return *this;
}

Fixed::~Fixed() {
    // Destructor
}

int Fixed::getRawBits(void) const {
    return _rawBits;
}

void Fixed::setRawBits(int const raw) {
    _rawBits = raw;
}

float Fixed::toFloat(void) const {
    return static_cast<float>(_rawBits) / (1 << _fractionalBits); // Convert fixed-point to float
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits; // Convert fixed-point to integer
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
    os << fixed.toFloat(); // Output the floating-point representation
    return os;
}
