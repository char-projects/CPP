#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : _name(""), _signGrade(25), _executeGrade(5) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), 
      _executeGrade(other._executeGrade) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

const char* PresidentialPardonForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* PresidentialPardonForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form) {
    os << "Form: " << form.getName()
    << ", Signed: " << (form.isSigned() ? "Yes" : "No")
    << ", Sign Grade: " << form.getSignGrade()
    << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

void PresidentialPardonForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

const std::string &PresidentialPardonForm::getName() const {
    return _name;
}

bool PresidentialPardonForm::isSigned() const {
    return _signed;
}

int PresidentialPardonForm::getSignGrade() const {
    return _signGrade;
}

int PresidentialPardonForm::getExecuteGrade() const {
    return _executeGrade;
}

PresidentialPardonForm::~PresidentialPardonForm() {}