#include "PmergeMe.hpp"

// STILL NEED TO FIX THE PROCESSING TIME CALCULATION

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive integers>" << std::endl;
        return 1;
    }
    PmergeMe pmerge;
    bool valid = pmerge.validateInput(argc, argv);
    if (valid == false) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<int> vec;
    
    std::cout << "Before: ";
    for (int i = 1; i < argc; ++i) {
        int value = std::atoi(argv[i]);
        vec.push_back(value);
        std::cout << value << " ";
    }
    std::cout << std::endl;

    std::clock_t start = std::clock();
    pmerge.mergeSortVec(vec, 0, vec.size() - 1);
    std::clock_t stop = std::clock();
    double timeVec = static_cast<double>(stop - start) / CLOCKS_PER_SEC * 100;

    std::deque<int> deq(vec.begin(), vec.end());
    std::clock_t beginning = std::clock();
    pmerge.mergeSortDeq(deq, 0, deq.size() - 1);
    std::clock_t end = std::clock();
    double timeDeq = static_cast<double>(end - beginning) / CLOCKS_PER_SEC * 100;

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