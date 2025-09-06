#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#define PURPLE "\033[0;35m"
#define WHITE "\033[0;0m"

template <typename T>
class Array {
    private:
        T* elements;
        size_t _size;
    public:
        Array() : elements(NULL), _size(0) {}

        Array(size_t n) : _size(n) {
            if (n > 0) {
                elements = new T[n];
            } else {
                elements = NULL;
            }
        }

        Array(const Array& other) : _size(other._size) {
            if (_size > 0) {
                elements = new T[_size];
                for (size_t i = 0; i < _size; ++i) {
                    elements[i] = other.elements[i];
                }
            } else {
                elements = NULL;
            }
        }

        Array& operator=(const Array& other) {
            if (this != &other) {
                delete[] elements;
                _size = other._size;
                if (_size > 0) {
                    elements = new T[_size];
                    for (size_t i = 0; i < _size; ++i) {
                        elements[i] = other.elements[i];
                    }
                } else {
                    elements = NULL;
                }
            }
            return *this;   
        }

        ~Array() {
            delete[] elements;
        }

        T& operator[](size_t index) {
            if (index >= _size) {
                throw std::out_of_range("Index out of bounds");
            }
            return elements[index];
        }

        const T& operator[](size_t index) const {
            if (index >= _size) {
                throw std::out_of_range("Index out of bounds");
            }
            return elements[index];
        }

        size_t size() const {
            return _size;
        }
};

#endif