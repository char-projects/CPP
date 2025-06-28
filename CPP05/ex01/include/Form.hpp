#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _executeGrade;
    public:
        Form(const std::string &name, int signGrade, int executeGrade);
        Form(const Form &other);
        Form &operator=(const Form &other);
        virtual ~Form();   
        int getSignGrade() const;
        int getExecuteGrade() const;
        bool isSigned() const;  
        const std::string &getName() const;  
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif