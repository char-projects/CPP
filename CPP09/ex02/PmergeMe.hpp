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

class PmergeMe {
    public:
        PmergeMe();
        ~PmergeMe();
        void sortVec(std::vector<int> &vec);
        void sortDeq(std::deque<int> &deq);

    private:
        void mergeSortVec(std::vector<int> &vec, int left, int right);
        void mergeVec(std::vector<int> &vec, int left, int mid, int right);
        void mergeSortDeq(std::deque<int> &deq, int left, int right);
        void mergeDeq(std::deque<int> &deq, int left, int mid, int right);
};

#endif
