#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
  private:
		int _rawBits;
    static const int _fractionalBits;
    
  public:  
    Fixed();
    Fixed(const Fixed &other);
    Fixed(const int value);
    Fixed(const float value);

    float toFloat(void) const;
    int toInt(void) const;

    int getRawBits(void) const;
    void setRawBits(int const raw);
    
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    Fixed &operator=(const Fixed &other);
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;
    Fixed operator++(); // pre-increment
    Fixed operator++(int); // post-increment
    Fixed &operator--(); // pre-decrement
    Fixed operator--(int); // post-decrement

    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);

    ~Fixed();
};

std::ostream &operator<<(std::ostream &output, const Fixed &value);

#endif