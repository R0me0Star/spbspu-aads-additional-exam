#include "bank-data.hpp"
#include <cctype>
#include <cstddef>
#include <istream>
#include <string>
#include <array.hpp>
#include <hash-table.hpp>
#include <parsing.hpp>
#include <transaction-io.hpp>
#include <transaction.hpp>

namespace {
  bool isCommandStart(const std::string & line)
  {
    std::size_t position = 0;
    pozdnyakov::skipSpaces(line, position);
    return position < line.size() && std::isalpha(static_cast< unsigned char >(line[position])) != 0;
  }

  bool parseCommission(const std::string & line, pozdnyakov::Commission & commission)
  {
    constexpr int max_percent = 100;
    std::size_t position = 0;
    pozdnyakov::skipSpaces(line, position);
    const bool incoming = position < line.size() && line[position] == '-';
    pozdnyakov::Commission result{0, incoming, 0, 0, 0};
    


    commission = result;
    return true;
  }
}

void pozdnyakov::addTransaction(BankData & data, const Transaction & transaction)
{
  AccountTotals & sender = emplace(data.accounts, transaction.from, AccountTotals{0, 0});
  AccountTotals & receiver = emplace(data.accounts, transaction.to, AccountTotals{0, 0});
  pushBack(data.transactions, transaction);
  sender.outcome += transaction.value;
  receiver.income += transaction.value;
}

bool pozdnyakov::readTransactions(std::istream & in, BankData & data, std::string & first_command)
{
  std::string line;
  while (std::getline(in, line)) {
   
  }
  return true;
}

bool pozdnyakov::readCommissions(std::istream & in, BankData & data)
{
  std::string line;
  while (std::getline(in, line)) {
  
  return true;
}

void pozdnyakov::clear(BankData & data) noexcept
{
  clear(data.transactions);
  clear(data.commissions);
  clear(data.accounts);
}
