#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
  private:
		int _rawBits;
    static const int _fractionalBits;
  public:  
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    Fixed &operator>(const Fixed &other);
    Fixed &operator<(const Fixed &other);
    Fixed &operator>=(const Fixed &other);
    Fixed &operator<=(const Fixed &other);
    Fixed &operator==(const Fixed &other);
    Fixed &operator!=(const Fixed &other);
    Fixed &operator+(const Fixed &other);
    Fixed &operator-(const Fixed &other);
    Fixed &operator*(const Fixed &other);
    Fixed &operator/(const Fixed &other);
    Fixed &operator++(); // pre-increment
    Fixed operator++(int); // post-increment
    Fixed &operator--(); // pre-decrement
    Fixed operator--(int); // post-decrement
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif