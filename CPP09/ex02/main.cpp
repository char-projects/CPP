#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
        return 1;
    }

    std::vector<int> vec;
    std::cout << "Before: ";
    for (int i = 1; i < argc; ++i) {
        char *endptr = NULL;
        long val = std::strtol(argv[i], &endptr, 10);
        if (*endptr != '\0' || val <= 0 || val > INT_MAX) {
            std::cerr << "Error: Invalid input '" << argv[i] << "'" << std::endl;
            return 1;
        }
        vec.push_back(static_cast<int>(val));
        std::cout << val << " ";
    }
    std::cout << std::endl;
    
    std::clock_t start = std::clock();
    PmergeMe pmerge;
    pmerge.sortVec(vec);
    std::clock_t stop = std::clock();
    double timeVec = static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1e6;

    std::deque<int> deq(vec.begin(), vec.end());
    std::clock_t beginning = std::clock();
    pmerge.sortDeq(deq);
    std::clock_t end = std::clock();
    double timeDeq = static_cast<double>(end - beginning) / CLOCKS_PER_SEC * 1e6;

    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Time to process a range of " << vec.size()
        << " elements with std::vector: " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << vec.size()
        << " elements with std::deque: " << timeDeq << " us" << std::endl;
}