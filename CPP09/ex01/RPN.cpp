#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
        *this = other;
    return *this;
}

float RPN::evaluate(const std::string &expression) {
    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (!std::isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/' && !std::isspace(c)) {
            throw std::invalid_argument("Error");
        }
    }
    std::istringstream iss(expression);
    std::string token;
    std::stack<float> values;
    while (iss >> token) {
        if (std::isdigit(token[0])) {
            values.push(std::atof(token.c_str()));
        } else if (token.length() == 1) {
            if (values.size() < 2) {
                throw std::invalid_argument("Error");
            }
            float b = values.top(); values.pop();
            float a = values.top(); values.pop();
            float result = applyOperation(a, b, token[0]);
            values.push(result);
        } else {
            throw std::invalid_argument("Error");
        }
    }
    return (values.top());
}

float RPN::applyOperation(float a, float b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0)
                throw std::invalid_argument("Error");
            return a / b;
        default:
            throw std::invalid_argument("Error");
    }
}
