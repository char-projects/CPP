#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string literal) {
    std::cout << "Converting: " << literal << std::endl;

    if (literal == "nan" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}

    char *type = NULL;
    // Check if it's a char
    if (literal.empty()) {
        type = "i";
    }
    for (size_t i = 0; i < literal.length(); ++i) {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+')) {
            continue;
        }
        if (!isdigit(literal[i])) {
            break ;
        }
    }
    type = "i";

    // Check if it's an int
    if (literal.length() == 1 && isprint(literal[0]))
        type = "c";

    // Check if it's a float
    if (literal.find('.') != std::string::npos) {
        type = "f";
    }

    // Check if it's a double
    bool decimalPointFound = false;
    for (size_t i = 0; i < literal.length(); ++i) {
        if (i == 0 && (literal[i] == '-' || literal[i] == '+')) {
            continue;
        }
        if (literal[i] == '.') {
            if (decimalPointFound) {
                break ;
            }
            decimalPointFound = true;
            continue;
        }
        if (!isdigit(literal[i])) {
            break ;
        }
    }
    type = "d";
}

void ScalarConverter::convertInt(const std::string &literal) {
    int value = std::stoi(literal);
    std::cout << "int: " << value << std::endl;
    std::cout << "int: impossible" << std::endl;
}

void ScalarConverter::convertChar(const std::string &literal) {
    std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::convertDouble(const std::string &literal) {
    std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::convertFloat(const std::string &literal) {
    std::cout << "float: impossible" << std::endl;
}
