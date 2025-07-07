#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string literal) {
    std::cout << "Converting: " << literal << std::endl;
    std::cout << "...to char: " << literal << std::endl;
    std::cout << "...to int: " << std::endl;
    std::cout << "...to float: " << std::endl;
    std::cout << "...to double: " << std::endl;
}

bool ScalarConverter::isInt(const std::string &literal) {
    if (literal.empty()) {
        return false;
    }
    for (size_t i = 0; i < literal.length(); ++i) {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+')) {
            continue;
        }
        if (!isdigit(literal[i])) {
            return false;
        }
    }
    return true;
}

bool ScalarConverter::isChar(const std::string &literal) {
    return literal.length() == 1 && isprint(literal[0]);
}

bool ScalarConverter::isFloat(const std::string &literal) {
    if (literal.empty()) {
        return false;
    }
    bool decimalPointFound = false;
    for (size_t i = 0; i < literal.length(); ++i) {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+')) {
            continue;
        }
        if (literal[i] == '.') {
            if (decimalPointFound) {
                return false;
            }
            decimalPointFound = true;
            continue;
        }
        if (!isdigit(literal[i])) {
            return false;
        }
    }
    return decimalPointFound;
}

bool ScalarConverter::isDouble(const std::string &literal) {
    if (literal.empty()) {
        return false;
    }
    bool decimalPointFound = false;
    for (size_t i = 0; i < literal.length(); ++i) {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+')) {
            continue;
        }
        if (literal[i] == '.') {
            if (decimalPointFound) {
                return false;
            }
            decimalPointFound = true;
            continue;
        }
        if (!isdigit(literal[i])) {
            return false;
        }
    }
    return decimalPointFound;
}
