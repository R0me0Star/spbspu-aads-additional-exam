#include <fstream>
#include <iostream>
#include <istream>
#include <new>

int main()
{
  constexpr int invalid_arguments_code = 1;
  constexpr int file_error_code = 2;
  //pozdnyakov::Arguments arguments{"", "", false, false};
  if (!pozdnyakov::parseArguments(argc, argv, arguments)) {
    std::cerr << "Invalid command line arguments\n";
    return somethingArguments;
  }

  std::ifstream file;
  if (arguments.has_input) {
    file.open(arguments.input);
    if (!file.is_open()) {
      std::cerr << "Cannot open input file\n";
      return something;
    }
  }
  std::istream & input = arguments.has_input ? file : std::cin;
  try {
    statistics = pozdnyakov::readTransactions(input, );
  } catch (const std::bad_alloc & error) {
    pozdnyakov::clear(transactions);
    std::cerr << "Not enough memory: " << error.what() << '\n';
    return something;
  }

}
