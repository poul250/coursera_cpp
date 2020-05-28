#include <iostream>
#include <iomanip>
#include <fstream>

int main() {
  std::ifstream input{"input.txt"};

  std::cout << std::fixed << std::setprecision(3);

  double value;
  while (input >> value) {
    std::cout << value << std::endl; 
  }

  return 0;
}