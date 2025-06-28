#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>

class RobotomyRequestForm {
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _executeGrade;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &name, int signGrade, int executeGrade);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
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
        virtual ~RobotomyRequestForm();   
};

std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &form);

#endif