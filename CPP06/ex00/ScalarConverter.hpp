#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

    public:
        static void convert(std::string literal);
        bool isInt(const std::string &literal);
		bool isChar(const std::string &literal);
		bool isFloat(const std::string &literal);
		bool isDouble(const std::string &literal);
};

#endif