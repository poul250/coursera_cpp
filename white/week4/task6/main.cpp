#include <iostream>
#include <fstream>
#include <iomanip>

int GetVal(std::istream& input) {
  int value;
  input >> value;
  return value;
}

int main() {
  std::ifstream input{"input.txt"};
  int N, M;
  input >> N >> M;

  for (int i = 0; i < N; ++i) {
    if (M > 0) {
      int value = GetVal(input);
      std::cout << std::setw(10) << value;
    }

    for (int j = 1; j < M; ++j) {
      input.ignore(1);
      int value = GetVal(input);

      std::cout << ' ' << std::setw(10) << value;
    }

    if (i != N - 1) {
      std::cout << std::endl;
    }
  }

  return 0;
}