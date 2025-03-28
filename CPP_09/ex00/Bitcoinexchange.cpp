#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    // Constructs the exchange rates by reading a CSV file (with the given separator)
    BitcoinExchange(const std::string &filePath, char sep);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange& operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    // Returns the exchange rate for the given date (or the most recent rate if not an exact match)
    double operator[](const std::string &date) const;

private:
    // Hidden default constructor to prevent its use
    BitcoinExchange();

    std::map<std::string, double> _data;
};

#endif // BITCOINEXCHANGE_HPP

#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(const std::string &filePath, char sep) {
    std::ifstream file(filePath.c_str());
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    std::string line;
    // Skip header line
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, valueStr;
        if (std::getline(ss, date, sep) && std::getline(ss, valueStr, sep)) {
            double value;
            std::istringstream iss(valueStr);
            iss >> value;
            _data[date] = value;
        }
    }
}

BitcoinExchange::~BitcoinExchange() {
    // No dynamic resources to free.
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        _data = other._data;
    }
    return *this;
}

double BitcoinExchange::operator[](const std::string &date) const {
    std::map<std::string, double>::const_iterator it = _data.upper_bound(date);
    if (it == _data.begin()) {
        throw std::runtime_error("Invalid date: " + date);
    }
    --it;
    return it->second;
}

#ifndef UTILS_HPP
#define UTILS_HPP

#include <string>

namespace Utils {

    // Removes leading and trailing whitespace from a string.
    void trimSpaces(std::string &str);

    // Date validation functions.
    bool isLeapYear(int year);
    bool isValidYear(int year);
    bool isValidMonth(int month);
    bool isValidDay(int year, int month, int day);
    bool checkValidDate(const std::string &date);

} // namespace Utils

#endif // UTILS_HPP

#include "Utils.hpp"
#include <algorithm>
#include <cctype>
#include <cstdlib>

static bool notSpace(char c) {
    return !std::isspace(static_cast<unsigned char>(c));
}

namespace Utils {

    void trimSpaces(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), notSpace));
        s.erase(std::find_if(s.rbegin(), s.rend(), notSpace).base(), s.end());
    }

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    bool isValidYear(int year) {
        return (year > 1000 && year < 3000);
    }

    bool isValidMonth(int month) {
        return (month >= 1 && month <= 12);
    }

    bool isValidDay(int year, int month, int day) {
        if (day < 1 || day > 31)
            return false;
        if (month == 2) {
            if (isLeapYear(year) && day > 29)
                return false;
            else if (!isLeapYear(year) && day > 28)
                return false;
        }
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            return false;
        return true;
    }

    bool checkValidDate(const std::string &date) {
        int year, month, day;
        size_t firstDash = date.find('-');
        size_t secondDash = date.find('-', firstDash + 1);

        if (firstDash == std::string::npos || secondDash == std::string::npos) {
            return false;
        }

        year = std::atoi(date.substr(0, firstDash).c_str());
        month = std::atoi(date.substr(firstDash + 1, secondDash - firstDash - 1).c_str());
        day = std::atoi(date.substr(secondDash + 1).c_str());

        return isValidYear(year) && isValidMonth(month) && isValidDay(year, month, day);
    }

} // namespace Utils

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "BitcoinExchange.hpp"
#include "Utils.hpp"

// ANSI color macros
#define BOLD(text) "\033[1m" text "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

// Processes a single transaction line from the file.
void processTransactionLine(const std::string &line, char sep, const BitcoinExchange &prices) {
    std::istringstream ss(line);
    std::string date;
    std::string valueStr;

    // Extract date and value from the line.
    if (!(std::getline(ss, date, sep) && std::getline(ss, valueStr, sep))) {
        std::cout << BOLD("Error:") << " malformed line => " << line << std::endl;
        return;
    }


    Utils::trimSpaces(date);
    if (!Utils::checkValidDate(date)) {
        std::cout << BOLD("Error:") << " bad input => " << line << std::endl;
        return;
    }
    Utils::trimSpaces(valueStr);
    double value = 0.0;
    std::istringstream iss(valueStr);
    iss >> value;

    if (value < 0.0) {
        std::cout << BOLD("Error:") << " not a positive number." << std::endl;
        return;
    }
    if (value > 1000.0) {
        std::cout << BOLD("Error:") << " too large number." << std::endl;
        return;
    }

    try {
        double rate = prices[date];
        std::cout << BLUE << date << RESET << " => " 
                  << value << " = " 
                  << GREEN << (value * rate) << RESET 
                  << std::endl;
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
    }
}

void inputFileLoop(const BitcoinExchange &prices, const std::string &filePath, char sep) {
    std::ifstream file(filePath.c_str());
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }
    
    std::string line;
    // Skip header line.
    std::getline(file, line);
    while (std::getline(file, line)) {
        processTransactionLine(line, sep, prices);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./btc <file>" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange prices("data.csv", ',');
        inputFileLoop(prices, argv[1], '|');
    } catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

