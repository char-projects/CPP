#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _executeGrade;
    public:
        AForm();
        AForm(const std::string &name, int signGrade, int executeGrade);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool isSigned() const;  
        const std::string &getName() const; 

        void beSigned(const class Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat& executor) const = 0;
        
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        }; 
        class FormNotSignedException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        virtual ~AForm();   
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif