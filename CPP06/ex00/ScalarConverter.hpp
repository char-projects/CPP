#ifndef SCALARCONVERTER
#define SCALARCONVERTER

#include <iostream>

class ScalarConverter {
    public:
        static void convert(std::string literal);

        void convertInt(const std::string &literal);
        void convertChar(const std::string &literal);
        void convertFloat(const std::string &literal);
        void convertDouble(const std::string &literal);
};

#endif