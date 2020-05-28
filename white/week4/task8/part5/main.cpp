#include <iostream>
#include <numeric>
#include <sstream>
#include <set>
#include <map>
#include <vector>

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

// int main() {
//     {
//         const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
//         if (rs.size() != 3) {
//             cout << "Wrong amount of items in the set" << endl;
//             return 1;
//         }

//         vector<Rational> v;
//         for (auto x : rs) {
//             v.push_back(x);
//         }
//         if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
//             cout << "Rationals comparison works incorrectly" << endl;
//             return 2;
//         }
//     }

//     {
//         map<Rational, int> count;
//         ++count[{1, 2}];
//         ++count[{1, 2}];

//         ++count[{2, 3}];

//         if (count.size() != 2) {
//             cout << "Wrong amount of items in the map" << endl;
//             return 3;
//         }
//     }

//     cout << "OK" << endl;
//     return 0;
// }