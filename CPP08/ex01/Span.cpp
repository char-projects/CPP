#include "Span.hpp"

Span::Span(unsigned int size) : _size(size) {}

Span::Span(const Span &other) : _size(other._size), _numbers(other._numbers) {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _size) {
        throw FullSpanException();
    }
    _numbers.push_back(number);
}

unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    unsigned int minSpan = std::numeric_limits<unsigned int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        unsigned int span = sorted[i] - sorted[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator it = begin; it != end; ++it) {
        addNumber(*it);
    }
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        _size = other._size;
        _numbers = other._numbers;
    }
    return *this;
}

const char* Span::FullSpanException::what() const throw() {
    return ("Span is full, cannot add more numbers");
}

const char* Span::NoSpanException::what() const throw() {
    return ("Not enough numbers to calculate a span");
}

Span::~Span() {}
