#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string literal) {
    if (literal == "nan" || literal == "nanf") {
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
        return;
	}
	else if (literal == "+inf" || literal == "+inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
        return;
	}
	else if (literal == "-inf" || literal == "-inff") {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
        return;
	}

    char type;
    // Check if it's a char
    if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0])) {
        type = 'c';
        std::cout << "char: '" << literal[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(literal[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
    }

    // Check if it's a float or double

    // Check if it's an int
    else if ((literal[0] == '-' && literal.length() > 1) || (literal[0] == '+' && literal.length() > 1) || isdigit(literal[0])) {
        for (size_t i = 1; i < literal.length(); ++i) {
            if (!isdigit(literal[i])) {
                std::cerr << "Invalid literal: " << literal << std::endl;
                return;
            }
        }
        type = 'i';
        std::istringstream iss(literal);
        int intValue;
        if (!(iss >> intValue) || !iss.eof()) {
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
            std::cout << "int: " << intValue << std::endl;
            std::cout << "float: " << static_cast<float>(intValue) << ".0f" << std::endl;
            std::cout << "double: " << static_cast<double>(intValue) << ".0" << std::endl;
        }
    }
    std::cout << "Type: " << type << std::endl;
}

/*
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
*/
