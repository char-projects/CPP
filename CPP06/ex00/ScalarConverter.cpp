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

    char type = '\0';
    // Check if it's a char
    if (literal.length() == 1 && isprint(literal[0]) && !isdigit(literal[0])) {
        type = 'c';
        std::cout << "char: '" << literal[0] << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(literal[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(literal[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(literal[0]) << std::endl;
    }

    // Check if it's a float
    else if (literal.find('.') != std::string::npos && literal[literal.length() - 1] == 'f') {
        type = 'f';
        std::string floatLiteral = literal.substr(0, literal.length() - 1); // Remove 'f'
        std::istringstream iss(floatLiteral);
        float floatValue;
        if (!(iss >> floatValue) || !iss.eof()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        } else {
            if (floatValue < 0 || floatValue > 127 || std::isnan(floatValue))
                std::cout << "char: impossible" << std::endl;
            else if (!isprint(static_cast<int>(floatValue)))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(floatValue) << "'" << std::endl;
            if (floatValue < static_cast<float>(INT_MIN) || floatValue > static_cast<float>(INT_MAX) || std::isnan(floatValue))
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(floatValue) << std::endl;
            std::cout << "float: " << literal << std::endl;
            std::cout << "double: " << floatLiteral << std::endl;
        }
    }

    // Check if it's a double
    else if (literal.find('.') != std::string::npos) {
        type = 'd';
        std::istringstream iss(literal);
        double doubleValue;
        if (!(iss >> doubleValue) || !iss.eof()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        } else {
            if (doubleValue < 0 || doubleValue > 127 || std::isnan(doubleValue))
                std::cout << "char: impossible" << std::endl;
            else if (!isprint(static_cast<int>(doubleValue)))
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char: '" << static_cast<char>(doubleValue) << "'" << std::endl;
            if (doubleValue < static_cast<double>(INT_MIN) || doubleValue > static_cast<double>(INT_MAX) || std::isnan(doubleValue))
                std::cout << "int: impossible" << std::endl;
            else
                std::cout << "int: " << static_cast<int>(doubleValue) << std::endl;
            if (doubleValue < -std::numeric_limits<float>::max() || doubleValue > std::numeric_limits<float>::max())
                std::cout << "float: impossible" << std::endl;
            else
                std::cout << "float: " << literal << "f" << std::endl;
            std::cout << "double: " << literal << std::endl;
        }
    }

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
    else {
        std::cerr << "Invalid literal: " << literal << std::endl;
        return;
    }
}
