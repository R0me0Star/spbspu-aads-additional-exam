#include "transaction-io.hpp"
#include <cctype>
#include <cstddef>
#include <ostream>
#include <string>
#include "array.hpp"
#include "transaction.hpp"

namespace {
  bool isSpace(char symbol)
  {
    return std::isspace(static_cast< unsigned char >(symbol)) != 0;
  }

  bool isDigit(char symbol)
  {
    return std::isdigit(static_cast< unsigned char >(symbol)) != 0;
  }

  void skipSpaces(const std::string & line, std::size_t & position)
  {
    while (position < line.size() && isSpace(line[position])) {
      ++position;
    }
  }

  bool parseInteger(const std::string & line, std::size_t & position, int & result)
  {
    const long base = 10;
    const long max_value = std::numeric_limits< int >::max();
    const long min_value = std::numeric_limits< int >::min();
    skipSpaces(line, position);
    
    result = static_cast< int >(value);
    return true;
  }

  bool parseAccount(const std::string & line, std::size_t & position, int & account)
  { 
  }

}

bool pozdnyakov::parseTransaction(const std::string & line, Transaction & transaction)
{
  std::size_t position = 0;
  Transaction result{0, 0, 0};
  
  transaction = result;
  return true;
}

pozdnyakov::ReadStatistics pozdnyakov::readTransactions(std::istream & in, Array< Transaction > & transactions)
{
  ReadStatistics statistics{0, 0};
  std::string line;
  
  return statistics;
}

std::ostream & pozdnyakov::operator<<(std::ostream & out, const Transaction & transaction)
{
  return out << transaction.from << ' ' << transaction.to << ' ' << transaction.value;
}

void pozdnyakov::writeTransactions(std::ostream & out, const Array< Transaction > & transactions)
{
  for (std::size_t i = 0; i < transactions.size; ++i) {
    out << transactions.data[i] << '\n';
  }
}
