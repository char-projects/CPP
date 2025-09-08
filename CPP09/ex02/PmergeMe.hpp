#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <cstring>

class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        bool validateInput(int argc, char **argv);
        void mergeSortVec(std::vector<int> &vec, int left, int right);
        void mergeVec(std::vector<int> &vec, int left, int mid, int right);
        void mergeSortDeq(std::deque<int> &deq, int left, int right);
        void mergeDeq(std::deque<int> &deq, int left, int mid, int right);
};

#endif
