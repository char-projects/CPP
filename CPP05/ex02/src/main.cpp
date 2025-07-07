#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

int main() {
    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;
    Bureaucrat bureaucrat("Employee", 150);
    Bureaucrat bureaucrat2("Manager", 50);
    Bureaucrat bureaucrat3("President", 1);
    std::cout << bureaucrat << std::endl;
    std::cout << bureaucrat2 << std::endl;
    std::cout << bureaucrat3 << std::endl;
    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;

    RobotomyRequestForm robotomyForm("Bob");
    PresidentialPardonForm pardonForm("Alice");
    ShrubberyCreationForm shrubberyForm("Garden");
    std::cout << shrubberyForm << std::endl;
    std::cout << robotomyForm << std::endl;
    std::cout << pardonForm << std::endl;
    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;

    try {
        shrubberyForm.shrubberyCreation(bureaucrat);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;
    bureaucrat.signForm(shrubberyForm);
    bureaucrat.signForm(robotomyForm);
    bureaucrat.signForm(pardonForm);
    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;

    bureaucrat2.signForm(shrubberyForm);
    bureaucrat2.signForm(robotomyForm);
    bureaucrat2.signForm(pardonForm);
    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;

    bureaucrat3.signForm(shrubberyForm);
    bureaucrat3.signForm(robotomyForm);
    bureaucrat3.signForm(pardonForm);
    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;

    try {
        shrubberyForm.shrubberyCreation(bureaucrat3);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;
}
