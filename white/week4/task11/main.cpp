#include <iostream>
#include <numeric>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <stdexcept>

class Rational {
public:
  Rational() : p(0), q(1) { }
  Rational(int numerator, int denominator) : p(numerator), q(denominator) {
    if (q == 0) throw std::invalid_argument{""};
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
    if (other.p == 0) throw std::domain_error{""};
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

  bool operator< (const Rational& other) const {
    return p * other.q < other.p * q;
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

Rational Perform(const Rational& lhs, char op, const Rational& rhs) {
  if (op == '+') return lhs + rhs;
  if (op == '-') return lhs - rhs;
  if (op == '*') return lhs * rhs;
  return lhs / rhs;
}

int main() {
  Rational lhs, rhs;
  char op;

  while (true) {
    try {
      if (!(std::cin >> lhs >> op >> rhs)) {
        break;
      }
      std::cout << Perform(lhs, op, rhs);
    } catch (const std::invalid_argument&) {
      std::cout << "Invalid argument";
    } catch (const std::domain_error&) {
      std::cout << "Division by zero";
    }

    std::cout << "\n";
  }

  return 0;
}