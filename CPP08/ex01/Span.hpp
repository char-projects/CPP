#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <limits>

class Span {
    private:
        unsigned int _size;
        std::vector<int> _numbers;

    public:
        Span(unsigned int size);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        unsigned int shortestSpan() const;
        unsigned int longestSpan() const;

        class FullSpanException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class NoSpanException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif