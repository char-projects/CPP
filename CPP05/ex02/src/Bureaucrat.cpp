#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

Bureaucrat::Bureaucrat() : name(""), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

const std::string &Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::incrementGrade() {
    if (grade - 1 < 1)
        throw GradeTooHighException();
    --grade;
}

void Bureaucrat::decrementGrade() {
    if (grade + 1 > 150)
        throw GradeTooLowException();
    ++grade;
}

void Bureaucrat::signForm(AForm &form) {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << "." << std::endl;
    } 
    catch (const AForm::GradeTooLowException &e) {
        std::cout << name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << "." << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

void Bureaucrat::executeForm(const AForm &form) {
    try {
        form.execute(*this);
        std::cout << name << " executed " << form.getName() << "." << std::endl;
    } 
    catch (const AForm::GradeTooLowException &e) {
        std::cout << name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << "." << std::endl;
    } 
    catch (const AForm::FormNotSignedException &e) {
        std::cout << name << " couldn't execute " << form.getName() 
                  << " because it is not signed." << std::endl;
    }
}

Bureaucrat::~Bureaucrat() {}
