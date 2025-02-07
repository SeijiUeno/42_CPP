/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueno-te <sueno-te@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 21:27:23 by sueno-te          #+#    #+#             */
/*   Updated: 2025/02/07 17:53:18 by sueno-te         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
int Account::_totalAmount = 0;

void Account::_displayTimestamp() {
    std::time_t currentTime = std::time(NULL);
    std::tm* localTime = std::localtime(&currentTime);

    std::cout << "[" << (localTime->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << localTime->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << localTime->tm_hour
              << std::setw(2) << std::setfill('0') << localTime->tm_min
              << std::setw(2) << std::setfill('0') << localTime->tm_sec
              << "] ";
}

Account::Account(int initialDeposit)
    : _accountIndex(_nbAccounts),
      _amount(initialDeposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";created" << std::endl;

    _nbAccounts++;
    _totalAmount += _amount;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";closed" << std::endl;

    _nbAccounts--;
    _totalAmount -= _amount;
}

int Account::getNbAccounts() {
    return (_nbAccounts);
}

int Account::getTotalAmount() {
    return (_totalAmount);
}

int Account::getNbDeposits() {
    return (_totalNbDeposits);
}

int Account::getNbWithdrawals() {
    return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}

void Account::makeDeposit(int deposit) {
    if (deposit <= 0) {
        std::cerr << "Error: Deposit amount must be positive." << std::endl;
        return;
    }

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";deposit:" << deposit;

    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    if (withdrawal <= 0) {
        std::cerr << "Error: Withdrawal amount must be positive." << std::endl;
        return (false);
    }

    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";p_amount:" << _amount
              << ";withdrawal:";

    if (withdrawal > _amount) {
        std::cout << "refused" << std::endl;
        return (false);
    }

    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals
              << std::endl;

    return (true);
}

int Account::checkAmount() const {
    return (_amount);
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}