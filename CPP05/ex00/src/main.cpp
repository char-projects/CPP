#include "../include/Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;

        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;

        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;

        Bureaucrat alice("Alice", 1);
        std::cout << alice << std::endl;

        // This will throw an exception
        alice.incrementGrade();
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
