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
        void parseData();
        std::string extractDate(const std::string &line, size_t pos);
        float extractValue(const std::string &line, size_t pos);
        int validateDate(const std::string &date);
        void printExchangeRate(const std::string &date, float &value);

        ~BitcoinExchange();


    private:
        std::map<std::string, double> exchangeRates;
};

#endif