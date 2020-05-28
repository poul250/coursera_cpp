#include <iostream>
#include <numeric>

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

// int main() {
//     {
//         Rational a(2, 3);
//         Rational b(4, 3);
//         Rational c = a * b;
//         bool equal = c == Rational(8, 9);
//         if (!equal) {
//             cout << "2/3 * 4/3 != 8/9" << endl;
//             return 1;
//         }
//     }

//     {
//         Rational a(5, 4);
//         Rational b(15, 8);
//         Rational c = a / b;
//         bool equal = c == Rational(2, 3);
//         if (!equal) {
//             cout << "5/4 / 15/8 != 2/3" << endl;
//             return 2;
//         }
//     }

//     cout << "OK" << endl;
//     return 0;
// }