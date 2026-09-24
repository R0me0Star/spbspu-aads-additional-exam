#include <fstream>
#include <iostream>
#include <istream>
#include <new>
#include "arguments.hpp"
#include "array.hpp"
#include "transaction-io.hpp"
#include "transaction.hpp"

int main(int argc, char ** argv)
{
  constexpr int invalid_arguments_code = 1;
  constexpr int file_error_code = 2;
  pozdnyakov::Arguments arguments{"", "", false, false};
  if (!pozdnyakov::parseArguments(argc, argv, arguments)) {
    std::cerr << "Invalid command line arguments\n";
    return invalid_arguments_code;
  }

  pozdnyakov::Array< pozdnyakov::Transaction > transactions{nullptr, 0, 0};
  pozdnyakov::ReadStatistics statistics{0, 0};
  std::ifstream file;
  if (arguments.has_input) {
    file.open(arguments.input);
    if (!file.is_open()) {
      std::cerr << "Cannot open input file\n";
      return file_error_code;
    }
  }
  std::istream & input = arguments.has_input ? file : std::cin;
  try {
    statistics = pozdnyakov::readTransactions(input, transactions);
  } catch (const std::bad_alloc & error) {
    pozdnyakov::clear(transactions);
    std::cerr << "Not enough memory: " << error.what() << '\n';
    return file_error_code;
  }
  std::cerr << statistics.accepted << ' ' << statistics.ignored << '\n';

  int code = 0;
  if (arguments.has_output) {
    std::ofstream output(arguments.output);
    if (output.is_open()) {
      pozdnyakov::writeTransactions(output, transactions);
    } else {
      std::cerr << "Cannot open output file\n";
      code = file_error_code;
    }
  } else {
    pozdnyakov::writeTransactions(std::cout, transactions);
  }
  pozdnyakov::clear(transactions);
  return code;
}
