#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    (void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    // if (this != &other) {
    //     return *this;
    // }
    (void)other;
    return *this;
}       

void BitcoinExchange::parseInput(const std::string &input) {
    std::fstream file;
    file.open(input.c_str(), std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::string date;
    std::string value;
    while (std::getline(file, line)) {
        if (line == "date | value") 
            continue;
        size_t pos = line.find_last_of('|');
        if (pos != std::string::npos) {
            date = line.substr(0, pos);
        }
        else {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        value = line.substr(pos + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);
        double numericValue = 0.0;
        try {
            numericValue = std::atof(value.c_str());
            if (numericValue < 0) {
                std::cerr << "Error: not a positive number." << std::endl;
                continue;
            }
            if (numericValue > 1000) {
                std::cerr << "Error: too large a number." << std::endl;
                continue;
            }
        } catch (const std::invalid_argument &e) {
            std::cerr << "Error: bad input => " << value << std::endl;
            continue;
        } catch (const std::out_of_range &e) {
            std::cerr << "Error: number out of range." << std::endl;
            continue;
        }
        
        std::cout << date << "=> " << numericValue << " =" << std::endl;
    }
    file.close();
}

BitcoinExchange::~BitcoinExchange() {}