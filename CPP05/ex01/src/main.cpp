#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Form form("Form1", 45, 30);

        std::cout << bob << std::endl;
        std::cout << form << std::endl;

        bob.signForm(form);
        std::cout << form << std::endl;

        Bureaucrat alice("Alice", 20);
        std::cout << alice << std::endl;
        
        alice.signForm(form);
        std::cout << form << std::endl;

    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
