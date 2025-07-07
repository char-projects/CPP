#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {
    private:
		AForm* createShrubberyForm(const std::string &target);
		AForm* createRobotomyForm(const std::string &target);
		AForm* createPresidentialForm(const std::string &target);

	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern &other);
		AForm* makeForm(const std::string &formName, const std::string &target);
        
		class FormNotFoundException : public std::exception
		{
            public:
            virtual const char* what() const throw();
		};
        ~Intern();
};

#endif