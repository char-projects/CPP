#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/Intern.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat bureaucrat1("Manager", 50);
    Bureaucrat bureaucrat2("President", 1);
    AForm* rrf;    

    std::cout << "────────────────────────────────────────────────" << std::endl;
    std::cout << "Test 1: Intern" << std::endl;
    std::cout << "────────────────────────────────────────────────" << std::endl;
	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;

		rrf = someRandomIntern.makeForm("shrubbery creation", "Home");
		delete rrf;

		rrf = someRandomIntern.makeForm("presidential pardon", "Batman");
		delete rrf;

		rrf = someRandomIntern.makeForm("unknown form", "Pam");
		delete rrf;
	} catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

    std::cout << std::endl << "────────────────────────────────────────────────" << std::endl;
    std::cout << "Test 2: Manager (should not work)" << std::endl;
    std::cout << "────────────────────────────────────────────────" << std::endl;
    rrf = someRandomIntern.makeForm("presidential pardon", "Fred");
	try {
		rrf->beSigned(bureaucrat1);
		bureaucrat1.executeForm(*rrf);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	delete rrf;

    std::cout << std::endl << "────────────────────────────────────────────────" << std::endl;
    std::cout << "Test 3: President (should work)" << std::endl;
    std::cout << "────────────────────────────────────────────────" << std::endl;
    rrf = someRandomIntern.makeForm("presidential pardon", "Betty");
	try {
		rrf->beSigned(bureaucrat2);
		bureaucrat2.executeForm(*rrf);
	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	delete rrf;
    std::cout << "────────────────────────────────────────────────" << std::endl;
}
