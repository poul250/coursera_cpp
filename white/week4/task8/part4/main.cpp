#include <iostream>
#include <numeric>
#include <sstream>

using namespace std;

class Rational {
public:
  Rational() : p(0), q(1) { }
  Rational(int numerator, int denominator) : p(numerator), q(denominator) {
    Simplify();
  }

  int Numerator() const {
    return p;
  }
  int Denominator() const {
    return q;
  }

  Rational operator+ (const Rational& other) const {
    return {p*other.q + other.p*q, q*other.q};
  }

  Rational operator- (const Rational& other) const {
    return {p*other.q - other.p*q, q*other.q};
  }

  Rational operator* (const Rational& other) const {
    return {p * other.p, q * other.q};
  }

  Rational operator/ (const Rational& other) const {
    return {p * other.q, q * other.p};
  }

  Rational& operator=(const Rational& other) {
    p = other.p;
    q = other.q;
    return *this;
  }

  bool operator==(const Rational& other) const {
    return (p == other.p) && (q == other.q);
  }

private:
  void Simplify() {
    int gcd = std::gcd(p, q);
    p /= gcd;
    q /= gcd;
    if (q < 0) {
      p *= -1;
      q *= -1;
    }
  }
  int p, q;
};

std::ostream& operator<<(std::ostream& output, const Rational& r) {
  output << r.Numerator() << '/' << r.Denominator();
  return output;
}

std::istream& operator>>(std::istream& input, Rational& r) {
  int p, q;
  if (!(input >> p)) return input;
  input.ignore(1);
  if (!(input >> q)) return input;

  r = Rational(p, q);
  return input;
}

// int main() {
//     {
//         ostringstream output;
//         output << Rational(-6, 8);
//         if (output.str() != "-3/4") {
//             cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
//             return 1;
//         }
//     }

//     {
//         istringstream input("5/7");
//         Rational r;
//         input >> r;
//         bool equal = r == Rational(5, 7);
//         if (!equal) {
//             cout << "5/7 is incorrectly read as " << r << endl;
//             return 2;
//         }
//     }

//     {
//         istringstream input("5/7 10/8");
//         Rational r1, r2;
//         input >> r1 >> r2;
//         bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
//         if (!correct) {
//             cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
//             return 3;
//         }

//         input >> r1;
//         input >> r2;
//         correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
//         if (!correct) {
//             cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
//             return 4;
//         }
//     }

//     cout << "OK" << endl;
//     return 0;
// }