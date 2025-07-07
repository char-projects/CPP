#include "../include/ShrubberyCreationForm.hpp"
#include "../include/Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
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

    std::cout << "Creating shrubbery for " << _target << "..." << std::endl;
    std::ofstream file((_target + "_shrubbery").c_str());
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
    std::cout << "Shrubbery created in " << _target << "_shrubbery" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}