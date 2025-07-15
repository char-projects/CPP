#include "iter.hpp"

void printInt(const int& n) {
    std::cout << n << " ";
}

void printString(const std::string& str) {
    std::cout << str;
}

// Still need to add support for const elements in iter
int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"Hello ", "World", "!"};

    iter(intArray, 5, printInt);
    std::cout << std::endl;
    iter(strArray, 3, printString);
    std::cout << std::endl;
}