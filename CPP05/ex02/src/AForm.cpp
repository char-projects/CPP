#include "../include/AForm.hpp"
#include "../include/Bureaucrat.hpp"

AForm::AForm() : _name(""), _signGrade(150), _executeGrade(150) {}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
    : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), 
      _executeGrade(other._executeGrade) {}

AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
    os << "Form: " << form.getName()
    << ", Signed: " << (form.isSigned() ? "Yes" : "No")
    << ", Sign Grade: " << form.getSignGrade()
    << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

const std::string &AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getSignGrade() const {
    return _signGrade;
}

int AForm::getExecuteGrade() const {
    return _executeGrade;
}

AForm::~AForm() {}