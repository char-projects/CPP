#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() {
    // std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
}

Fixed::Fixed(const Fixed &other){
    // std::cout << "Copy constructor called" << std::endl;
    _rawBits = other.getRawBits();
}

Fixed::Fixed(const int value) {
    // std::cout << "Int constructor called" << std::endl;
    _rawBits = value * 256;
}

Fixed::Fixed(const float value) {
    // std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * 256);
}

int Fixed::getRawBits( void ) const {
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
    return ;
}

float Fixed::toFloat(void) const {
    return (float)_rawBits / 256;
}

int Fixed::toInt(void) const {
    return _rawBits / 256;
}

Fixed &Fixed::operator=(const Fixed &other) {
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
		this->_rawBits = other.getRawBits();
    }
    return *this;
}

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
    return(Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const {
    return(Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const {
    return(Fixed(this->toFloat() / other.toFloat()));
}

bool Fixed::operator>(const Fixed &other) const {
    return this->_rawBits > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
    return this->_rawBits < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
    return this->_rawBits >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
    return this->_rawBits <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
    return this->_rawBits == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
    return this->_rawBits != other.getRawBits();
}

Fixed Fixed::operator++() { // pre-increment
    this->_rawBits++;
    return *this;
}

Fixed Fixed::operator++(int) { // post-increment
    Fixed temp = *this;
    this->_rawBits++;
    return temp;
}

Fixed &Fixed::operator--() { // pre-decrement
    this->_rawBits--;
    return *this;
}

Fixed Fixed::operator--(int) { // post-decrement
    Fixed temp = *this;
    this->_rawBits--;
    return temp;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a > b ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b ? a : b);
}

std::ostream &operator<<(std::ostream &output, const Fixed &value) {
	return (output << value.toFloat());
}

Fixed::~Fixed() {
    // std::cout << "Default destructor called" << std::endl;
}
