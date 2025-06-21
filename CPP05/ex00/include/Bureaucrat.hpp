#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
    private:
        const std::string name;
        int grade; // From 1 (highest) to 150 (lowest)
    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        
        const std::string &getName() const;
        int getGrade() const;

        void incrementGrade();
        void decrementGrade();

        class GradeTooHighException : public std::runtime_error {
            public:
                GradeTooHighException() : std::runtime_error("Grade too high") {}
        };
        class GradeTooLowException : public std::runtime_error {
            public:
                GradeTooLowException() : std::runtime_error("Grade too low") {}
        };

        ~Bureaucrat();
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif