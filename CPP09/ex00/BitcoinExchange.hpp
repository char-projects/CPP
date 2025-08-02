#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <stack>

template <typename T>
class BitcoinExchange : public std::stack<T> {
    public:
        BitcoinExchange();

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }
        
        void processFile(const std::string &filename);
        void displayExchangeRate(const std::string &date) const;

        ~BitcoinExchange();
};

#endif