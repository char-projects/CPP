#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _name(""), _signGrade(145), _executeGrade(137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), 
      _executeGrade(other._executeGrade) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

const char* ShrubberyCreationForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* ShrubberyCreationForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form) {
    os << "Form: " << form.getName()
    << ", Signed: " << (form.isSigned() ? "Yes" : "No")
    << ", Sign Grade: " << form.getSignGrade()
    << ", Execute Grade: " << form.getExecuteGrade();
    return os;
}

void ShrubberyCreationForm::shrubberyCreation() const {
    // if (!_signed)
    //    throw GradeTooLowException();
    
    std::cout << "Creating shrubbery for " << _name << "..." << std::endl;
    std::ofstream file((_name + "_shrubbery").c_str());
    if (file.is_open()) {
        file << "             ,@@@@@@@," << std::endl;
        file << "     ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
        file << "  ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
        file << " ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
        file << " %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
        file << " %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
        file << " `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
        file << "     |o|        | |         | |" << std::endl;
        file << "     |.|        | |         | |" << std::endl;
        file << "  \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
        file.close();
    }
    std::cout << "Shrubbery created in " << _name << "_shrubbery" << std::endl;
}

void ShrubberyCreationForm::beSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

const std::string &ShrubberyCreationForm::getName() const {
    return _name;
}

bool ShrubberyCreationForm::isSigned() const {
    return _signed;
}

int ShrubberyCreationForm::getSignGrade() const {
    return _signGrade;
}

int ShrubberyCreationForm::getExecuteGrade() const {
    return _executeGrade;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}