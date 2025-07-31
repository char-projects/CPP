#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

class NotFoundException : public std::exception {
    public:
        virtual const char* what() const throw() {
		    return ("Integer not found in the container");
        }
};

template <typename T>
typename T::iterator easyfind(T &container, int i) {
    typename T::iterator it = std::find(container.begin(), container.end(), i);
    if (it == container.end())
        throw NotFoundException();
    return it;
}

#endif