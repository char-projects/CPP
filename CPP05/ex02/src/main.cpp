#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

int main() {
    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;
    Bureaucrat bureaucrat1("Employee", 150);
    Bureaucrat bureaucrat2("Manager", 50);
    Bureaucrat bureaucrat3("President", 1);
    std::cout << bureaucrat1 << std::endl;
    std::cout << bureaucrat2 << std::endl;
    std::cout << bureaucrat3 << std::endl << std::endl;

    RobotomyRequestForm robotomyForm("Bob");
    PresidentialPardonForm pardonForm("Alice");
    ShrubberyCreationForm shrubberyForm("Garden");
    std::cout << shrubberyForm << std::endl;
    std::cout << robotomyForm << std::endl;
    std::cout << pardonForm << std::endl;

    std::cout << std::endl << "──────────────────────────────────────────────────────────────────────────" << std::endl;
	std::cout << "Shrubbery Creation Test:" << std::endl;
    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;
    try {
        shrubberyForm.execute(bureaucrat1);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    bureaucrat1.signForm(shrubberyForm);
    bureaucrat2.signForm(shrubberyForm);
    bureaucrat3.signForm(shrubberyForm);
    std::cout << std::endl;
    try {
        shrubberyForm.execute(bureaucrat3);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "──────────────────────────────────────────────────────────────────────────" << std::endl;
    std::cout << "Robotomy Request Test:" << std::endl;
    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;
    bureaucrat1.signForm(robotomyForm);
    bureaucrat2.signForm(robotomyForm);
    bureaucrat3.signForm(robotomyForm);
    std::cout << std::endl;
    try {
        std::cout << bureaucrat1.getName() << ": Requesting robotomy..." << std::endl;
        robotomyForm.execute(bureaucrat1);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << bureaucrat3.getName() << ": Requesting robotomy..." << std::endl;
        robotomyForm.execute(bureaucrat3);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << std::endl << "──────────────────────────────────────────────────────────────────────────" << std::endl;
    std::cout << "Presidential Pardon Test:" << std::endl;
    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;
    try {
        std::cout << bureaucrat3.getName() << ": Requesting pardon..." << std::endl;
        pardonForm.execute(bureaucrat3);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    bureaucrat1.signForm(pardonForm);
    bureaucrat2.signForm(pardonForm);
    bureaucrat3.signForm(pardonForm);
    std::cout << std::endl;
    try {
        std::cout << bureaucrat3.getName() << ": Requesting pardon..." << std::endl;
        pardonForm.execute(bureaucrat3);
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "──────────────────────────────────────────────────────────────────────────" << std::endl;
}
