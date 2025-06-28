#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("President", 1);
        ShrubberyCreationForm shrubberyForm("Garden", 145, 137);
        PresidentialPardonForm pardonForm("Bob", 25, 5);
        RobotomyRequestForm robotomyForm("Charlie", 72, 45);

        std::cout << bureaucrat << std::endl;
        std::cout << shrubberyForm << std::endl;
        std::cout << pardonForm << std::endl;
        std::cout << robotomyForm << std::endl;

        // bureaucrat.signForm(shrubberyForm);
        // bureaucrat.signForm(pardonForm);
        // bureaucrat.signForm(robotomyForm);

        shrubberyForm.shrubberyCreation();
        
        Bureaucrat bureaucrat2("Employee", 50);
        std::cout << bureaucrat2 << std::endl;
        // bureaucrat2.signForm(shrubberyForm);
        // bureaucrat2.signForm(pardonForm);
        // bureaucrat2.signForm(robotomyForm);

        Bureaucrat bureaucrat3("Intern", 150);
        std::cout << bureaucrat3 << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
