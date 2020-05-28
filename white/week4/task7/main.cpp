#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student {
  std::string first_name;
  std::string last_name;

  int day;
  int month;
  int year;
};

int main() {
  int n;
  std::cin >> n;
  std::vector<Student> students;

  for (int i = 0; i < n; ++i) {
    std::string first_name, last_name;
    int day, month, year;
    std::cin >> first_name >> last_name >> day >> month >> year;

    students.push_back({std::move(first_name), std::move(last_name), day, month, year});
  }

  int m;
  std::cin >> m;
  while (m--) {
    std::string command;
    int student_number;
    std::cin >> command >> student_number;

    if (student_number < 1 || student_number > n) {
      std::cout << "bad request\n";
    } else if (command == "name") {
      const auto& student = students[student_number - 1];
      std::cout << student.first_name << ' ' << student.last_name << '\n';
    } else if (command == "date") {
      const auto& student = students[student_number - 1];
      std::cout << student.day << '.' << student.month << '.' << student.year << '\n';
    } else {
      std::cout << "bad request\n";
    }
  }
  return 0;
}