#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw std::invalid_argument("Grade too high");
    if (signGrade > 150 || executeGrade > 150)
        throw std::invalid_argument("Grade too low");
}

Form::Form(const Form &other)
    : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {}

Form &Form::operator=(const Form &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

Form::~Form() {}

/*
std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form: " << form._name
       << ", Signed: " << (form._signed ? "Yes" : "No")

       << ", Sign Grade: " << form._signGrade
       << ", Execute Grade: " << form._executeGrade;
    return os;
} */

const std::string &Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getSignGrade() const {
    return _signGrade;
}

int Form::getExecuteGrade() const {
    return _executeGrade;
}
