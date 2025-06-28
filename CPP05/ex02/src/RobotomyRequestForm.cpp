#include "../include/RobotomyRequestForm.hpp"
#include "../include/Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _name(""), _signGrade(72), _executeGrade(45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), 
      _executeGrade(other._executeGrade) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

const char* RobotomyRequestForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* RobotomyRequestForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form) {
    os << "Form: " << form.getName()
    << ", Signed: " << (form.isSigned() ? "Yes" : "No")
    << ", Sign Grade: " << form.getSignGrade()
    << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

void RobotomyRequestForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

const std::string &RobotomyRequestForm::getName() const {
    return _name;
}

bool RobotomyRequestForm::isSigned() const {
    return _signed;
}

int RobotomyRequestForm::getSignGrade() const {
    return _signGrade;
}

int RobotomyRequestForm::getExecuteGrade() const {
    return _executeGrade;
}

RobotomyRequestForm::~RobotomyRequestForm() {}