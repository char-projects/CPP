#include "../include/PresidentialPardonForm.hpp"
#include "../include/Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon", 25, 5), _target("") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (!isSigned()) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > getExecuteGrade()) {
        throw GradeTooLowException();
    }
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {}