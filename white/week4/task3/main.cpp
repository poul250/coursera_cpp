#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class FunctionPart {
public:
  FunctionPart(char op, double value) : op(op), value(value) { }

  double Apply (double source_value) const {
    if (op == '+') return source_value + value;
    if (op == '-') return source_value - value;
    if (op == '*') return source_value * value;
    return source_value / value;
  }

  void Invert() {
    if (op == '+') op = '-';
    else if (op == '-') op = '+';
    else if (op == '*') op = '/';
    else if (op == '/') op = '*';
  }
private:
  char op;
  double value;
};

class Function {
 public:
  void AddPart(char op, double value) {
    operations.emplace_back(op, value);
  }

  double Apply(double value) const {
    for (const auto& op : operations) {
      value = op.Apply(value);
    }
    return value;
  }

  void Invert() {
    for (auto& op : operations) {
      op.Invert();
    }
    std::reverse(operations.begin(), operations.end());
  }

 private:
  std::vector<FunctionPart> operations;
  bool eval_forward = true;
};

// struct Image {
//   double quality;
//   double freshness;
//   double rating;
// };

// struct Params {
//   double a;
//   double b;
//   double c;
// };

// Function MakeWeightFunction(const Params& params,
//                             const Image& image) {
//   Function function;
//   function.AddPart('*', params.a);
//   function.AddPart('-', image.freshness * params.b);
//   function.AddPart('+', image.rating * params.c);
//   return function;
// }

// double ComputeImageWeight(const Params& params, const Image& image) {
//   Function function = MakeWeightFunction(params, image);
//   return function.Apply(image.quality);
// }

// double ComputeQualityByWeight(const Params& params,
//                               const Image& image,
//                               double weight) {
//   Function function = MakeWeightFunction(params, image);
//   function.Invert();
//   return function.Apply(weight);
// }

// int main() {
//   Image image = {10, 2, 6};
//   Params params = {4, 2, 6};
//   cout << ComputeImageWeight(params, image) << endl;
//   cout << ComputeQualityByWeight(params, image, 52) << endl;
//   return 0;
// }
