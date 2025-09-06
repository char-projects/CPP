#include "Array.hpp"

int main() {
    std::cout << PURPLE "Test in subject:" WHITE << std::endl;
    int *a = new int();
    std::cout << *a << std::endl;
    delete a;
    std::cout << "------------------" << std::endl;

    std::cout << PURPLE "Empty array:" WHITE << std::endl;
    Array<double> emptyArr;
    std::cout << "Array size: " << emptyArr.size() << std::endl;
    try {
        std::cout << emptyArr[0] << std::endl; // This should throw an exception
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------" << std::endl;

    std::cout << PURPLE "Int array with one element:" WHITE << std::endl;
    Array<int> b(1);
    b[0] = 42;
    std::cout << b[0] << std::endl;
    std::cout << "------------------" << std::endl;

    std::cout << PURPLE "Int array with five elements:" WHITE << std::endl;
    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++) {
        arr[i] = i * 2;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Array size: " << arr.size() << std::endl;
    try {
        std::cout << arr[5] << std::endl; // This should throw an exception
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "------------------" << std::endl;

    std::cout << PURPLE "Array with three elements:" WHITE << std::endl;
    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "World";
    strArr[2] = "!";
    for (unsigned int i = 0; i < strArr.size(); i++) {
        std::cout << strArr[i] << " ";
    }
    std::cout << std::endl;
    try {
        std::cout << strArr[3] << std::endl; // This should throw an exception
    } catch (const std::out_of_range& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Array size: " << strArr.size() << std::endl;
    std::cout << "------------------" << std::endl;

    std::cout << PURPLE "Copy and assignment:" WHITE << std::endl;
    Array<int> copyArr = arr; // Copy constructor
    for (unsigned int i = 0; i < copyArr.size(); i++) {
        std::cout << copyArr[i] << " ";
    }
    std::cout << std::endl;
    Array<int> assignArr;
    assignArr = arr; // Assignment operator
    for (unsigned int i = 0; i < assignArr.size(); i++) {
        std::cout << assignArr[i] << " ";
    }
    std::cout << std::endl;
}