#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    (void)other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        exchangeRates = other.exchangeRates;
    return *this;
}

std::string BitcoinExchange::extractDate(const std::string &line, size_t pos) {
    if (pos == std::string::npos)
        pos = line.find('\n');
    std::string date = line.substr(0, pos);
    date.erase(0, date.find_first_not_of(" \t"));
    date.erase(date.find_last_not_of(" \t") + 1);
    if (date.length() != 10 || date[4] != '-' || date[7] != '-' || validateDate(date) != 0)
        throw std::invalid_argument("bad input => " + date);
    return (date);
}

float BitcoinExchange::extractValue(const std::string &line, size_t pos) {
    if (pos == std::string::npos)
        throw std::invalid_argument("bad input => " + line);
    std::string value = line.substr(pos + 1);
    if (value.empty())
        throw std::invalid_argument("bad input => " + line);
    value.erase(0, value.find_first_not_of(" \t"));
    value.erase(value.find_last_not_of(" \t") + 1);
    if (value.length() > 10 || (value.length() == 10 && value > "2147483647"))
        throw std::invalid_argument("too large a number.");
    float numericValue = std::atof(value.c_str());
    if (numericValue < 0)
        throw std::invalid_argument("not a positive number.");
    if (value.find_first_not_of("0123456789.") != std::string::npos)
        throw std::invalid_argument("bad input => " + value);
    if (value.find('.') != std::string::npos) {
        size_t dotPos = value.find('.');
        if (dotPos == value.length() - 1 || dotPos == 0)
            throw std::invalid_argument("bad input => " + value);
        for (size_t i = dotPos + 1; i < value.length(); ++i) {
            if (!isdigit(value[i]))
                throw std::invalid_argument("bad input => " + value);
        }
    } else {
        for (size_t i = 0; i < value.length(); ++i) {
            if (!isdigit(value[i]))
                throw std::invalid_argument("bad input => " + value);
        }
    }
    return (numericValue);
}

void BitcoinExchange::parseInput(const std::string &input) {
    std::fstream file;
    file.open(input.c_str(), std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find('|');
        if (line == "date | value")
            continue;
        if (line.empty()) {
            std::cerr << "Error: empty line in input file." << std::endl;
            continue;
        }
        try {
            std::string date = extractDate(line, pos);
            if (date.empty()) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            } else {
                float value = extractValue(line, pos);
                printExchangeRate(date, value);
            }
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    file.close();
}

void BitcoinExchange::parseData() {
    std::fstream file;
    file.open("data.csv", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Error: could not open data.csv." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find(',');
        if (line == "date,exchange_rate")
            continue;
        if (line.empty()) {
            std::cerr << "Error: empty line in data.csv." << std::endl;
            continue;
        }
        std::string date = extractDate(line, pos);
        if (date.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
        } else {
            try {
                float rate = extractValue(line, pos);
                exchangeRates.insert(std::make_pair(date, rate));
            } catch (const std::exception &e) {
                std::cerr << "Error: " << e.what() << " => " << line << std::endl;
            }
        }
    }
    file.close();
}

int BitcoinExchange::validateDate(const std::string &date) {
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return -1;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return -1;
    if (month == 2) {
        if (day > 29 || (day == 29 && year % 4 != 0) || (day == 29 && year % 100 == 0 && year % 400 != 0))
            return -1;
    }
    return 0;
}

void BitcoinExchange::printExchangeRate(const std::string &date, float &value) {
    if (exchangeRates.find(date) != exchangeRates.end()) {
        double rate = exchangeRates[date];
        double numericValue = static_cast<double>(value);
        std::cout << date << " => " << value << " = " << numericValue * rate << std::endl;
    } else {
        std::map<std::string, double>::iterator it = exchangeRates.lower_bound(date);
        if (it != exchangeRates.begin()) {
            --it;
            double rate = it->second;
            double numericValue = static_cast<double>(value);
            std::cout << date << " => " << value << " = " << numericValue * rate << std::endl;
        }
    }
}

BitcoinExchange::~BitcoinExchange() {}