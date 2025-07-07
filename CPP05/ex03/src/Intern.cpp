#include "../include/Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern &Intern::operator=(const Intern &other) {
    (void)other;
    return *this;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string forms[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (Intern::*functions[3])(const std::string&) = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};

	for (int i = 0; i < 3; i++) {
		if (formName == forms[i]) 
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*functions[i])(target);
		}
	};
    throw FormNotFoundException();
}

AForm *Intern::createShrubberyForm(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialForm(const std::string &target) {
    return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}

Intern::~Intern() {}
