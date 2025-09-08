#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <cctype>
#include <cstdlib>

class RPN {
    public:
        RPN();
        ~RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        float evaluate(const std::string &expression);
        
    private:
        float applyOperation(float a, float b, char op);
};

#endif
