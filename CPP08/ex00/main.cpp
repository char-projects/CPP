#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    std::cout << "Vector:" << std::endl;
    for (int i = 1; i <= 5; ++i) {
        vec.push_back(i);
    }
    try {
        easyfind(vec, 3);
        std::cout << "Found 3 in the vector at position " << std::distance(vec.begin(), easyfind(vec, 3)) << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        easyfind(vec, 6);
        std::cout << "Found 6 in the vector" << std::endl; // Should not happen
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "───────────────────────────────────────────" << std::endl;

    std::cout << "List:" << std::endl;
    std::list<int> lst;
    for (int i = 1; i <= 5; ++i) {
        lst.push_back(i);
    }
    try {
        easyfind(lst, 2);
        std::cout << "Found 2 in the list at position " << std::distance(lst.begin(), easyfind(lst, 2)) << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        easyfind(lst, 99);
        std::cout << "Found 99 in the list" << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "Deque:" << std::endl;
    std::deque<int> deq;
    for (int i = 1; i <= 5; ++i) {
        deq.push_back(i);
    }
    try {
        easyfind(deq, 1);
        std::cout << "Found 1 in the deque at position " << std::distance(deq.begin(), easyfind(deq, 1)) << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        easyfind(deq, 8);
        std::cout << "Found 8 in the deque" << std::endl;
    } catch (const NotFoundException& e) {
        std::cerr << e.what() << std::endl;
    }
}