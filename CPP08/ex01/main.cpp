#include "Span.hpp"

int main() {
    std::cout << "Subject:" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl << std::endl;

    std::cout << "My own tests:" << std::endl;
    Span sp2 = Span(15000);
    std::vector<int> numbers(15000);
    try {
        for (int i = 0; i < 15000; ++i) {
            numbers[i] = i;
        }
        sp2.addNumbers(numbers.begin(), numbers.end());
    } catch (const Span::FullSpanException &e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
    } catch (const Span::NoSpanException &e) {
        std::cerr << e.what() << std::endl;
    }
    Span sp3 = Span(2);
    sp3.addNumber(1);
    try {
        std::cout << sp3.shortestSpan() << std::endl;
    } catch (const Span::NoSpanException &e) {
        std::cerr << e.what() << std::endl;
    }
    Span sp4 = Span(1);
    try {
        sp4.addNumber(42);
        sp4.addNumber(43);
    } catch (const Span::FullSpanException &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}