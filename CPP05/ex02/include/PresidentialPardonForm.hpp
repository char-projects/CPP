#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

class PresidentialPardonForm {
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _executeGrade;
    public:
        PresidentialPardonForm ();
        PresidentialPardonForm (const std::string &name, int signGrade, int executeGrade);
        PresidentialPardonForm (const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool isSigned() const;  
        const std::string &getName() const; 

        void beSigned(const class Bureaucrat &bureaucrat);
        
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        }; 
        virtual ~PresidentialPardonForm ();   
};

std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &form);

#endif