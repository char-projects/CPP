#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
}

Fixed::Fixed(const Fixed &other){
    std::cout << "Copy constructor called" << std::endl;
    _rawBits = other.getRawBits();
}

// Convert integer to fixed-point
Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value * 256;
}

// Convert float to fixed-point
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * 256);
}

Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
		this->_rawBits = other.getRawBits();
    }
    return *this;
}

// Output the floating-point representation
std::ostream &operator<<(std::ostream &output, const Fixed &value) {
	return (output << value.toFloat());
}

int Fixed::getRawBits( void ) const {
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
    return ;
}

// Convert fixed-point to float
float Fixed::toFloat(void) const {
    return (float)_rawBits / 256;
}

// Convert fixed-point to integer
int Fixed::toInt(void) const {
    return _rawBits / 256;
}

Fixed::~Fixed() {
    std::cout << "Default destructor called" << std::endl;
}
