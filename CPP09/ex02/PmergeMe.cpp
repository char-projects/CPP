#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

void PmergeMe::sortVec(std::vector<int> &vec) {
    if (vec.empty() || vec.size() == 1)
        throw std::invalid_argument("Error");
    mergeSortVec(vec, 0, vec.size() - 1);
}

void PmergeMe::mergeSortVec(std::vector<int> &vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        mergeSortVec(vec, left, mid);
        mergeSortVec(vec, mid + 1, right);

        // Merge the sorted halves
        mergeVec(vec, left, mid, right);
    }
}

void PmergeMe::mergeVec(std::vector<int> &vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = vec[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void PmergeMe::sortDeq(std::deque<int> &deq) {
    if (deq.empty() || deq.size() == 1)
        throw std::invalid_argument("Error");
    mergeSortDeq(deq, 0, deq.size() - 1);
}

void PmergeMe::mergeSortDeq(std::deque<int> &deq, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortDeq(deq, left, mid);
        mergeSortDeq(deq, mid + 1, right);
        mergeDeq(deq, left, mid, right);
    }
}

void PmergeMe::mergeDeq(std::deque<int> &deq, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::deque<int> L(n1);
    std::deque<int> R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = deq[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = deq[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            deq[k] = L[i];
            i++;
        } else {
            deq[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        deq[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        deq[k] = R[j];
        j++;
        k++;
    }
}

PmergeMe::~PmergeMe() {}