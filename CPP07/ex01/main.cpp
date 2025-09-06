#include "iter.hpp"

void printInt(const int& n) {
    std::cout << n << " ";
}

void printString(const std::string& str) {
    std::cout << str;
}

void printConstInt(int& n) {
    std::cout << n << " ";
}

void printConstString(std::string& str) {
    std::cout << str;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"Hello ", "World", "!"};
    int i[] = {42};
    std::string s[] = {"Const ", "string"};

    iter(intArray, 5, printInt);
    std::cout << std::endl;
    iter(strArray, 3, printString);
    std::cout << std::endl;
    iter(i, 1, &printConstInt);
    iter(s, 1, &printConstString);
}
