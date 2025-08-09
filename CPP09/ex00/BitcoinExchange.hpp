#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <stack>
#include <cstdlib>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        void parseInput(const std::string &input);

        ~BitcoinExchange();

    private:
        std::map<std::string, double> exchangeRates;
};

#endif