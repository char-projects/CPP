#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>

class ShrubberyCreationForm {
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _executeGrade;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &name, int signGrade, int executeGrade);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool isSigned() const;  
        const std::string &getName() const; 

        void beSigned(const class Bureaucrat &bureaucrat);
        void shrubberyCreation() const;
        
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        }; 
        virtual ~ShrubberyCreationForm();   
};

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form);

#endif