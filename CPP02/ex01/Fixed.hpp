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
    Fixed &operator=(const Fixed &other);
    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
    ~Fixed();
  };

std::ostream &operator<<(std::ostream &output, const Fixed &value);

#endif