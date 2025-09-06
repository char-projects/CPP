#include "iter.hpp"

void printInt(const int& n) {
    std::cout << n << " ";
}

void printString(const std::string& str) {
    std::cout << str;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    const int constInt[] = {5, 4, 3, 2, 1};
    std::string strArray[] = {"Hello ", "World", "!"};
    const std::string constStr[] = {"Const ", "String ", "Array"};

    iter(intArray, 5, printInt);
    std::cout << std::endl;
    iter(strArray, 3, printString);
    std::cout << std::endl;
    iter(constInt, 5, printInt);
    std::cout << std::endl;
    iter(constStr, 3, printString);
    std::cout << std::endl;
}
