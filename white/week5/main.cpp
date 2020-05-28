#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <iomanip>


class Date {
public:
  Date() : day(1), month(1), year(1) {}
  Date(int day, int month, int year) : day(day), month(month), year(year) {
    if (month < 1 || month > 12) {
      throw std::invalid_argument{"Month value is invalid: " + std::to_string(month)};
    }
    if (day < 1 || day > 31) {
      throw std::invalid_argument{"Day value is invalid: " + std::to_string(day)};
    }
  }
  int GetYear() const {
    return year;
  }
  int GetMonth() const {
    return month;
  }
  int GetDay() const {
    return day;
  }

  bool operator< (const Date& other) const {
    return std::tie(year, month, day) < std::tie(other.year, other.month, other.day);
  }

private:
  int day;
  int month;
  int year;
};

std::ostream& operator<< (std::ostream& output, const Date& date) {
  output << std::setw(4) << std::setfill('0') << date.GetYear()
         << '-'
         << std::setw(2) << std::setfill('0') << date.GetMonth()
         << '-'
         << std::setw(2) << std::setfill('0') << date.GetDay();
  return output;
}

class Database {
public:
  void AddEvent(const Date& date, const std::string& event) {
    events[date].insert(event);
  }

  bool DeleteEvent(const Date& date, const std::string& event) {
    auto erased = events[date].erase(event);
    if (events[date].size() == 0) {
      events.erase(date);
    }

    return erased;
  }

  int DeleteDate(const Date& date) {
    int erased = events[date].size();
    events.erase(date);

    return erased;
  }

  std::set<std::string> Find(const Date& date) const {
    auto it = events.find(date);
    if (it != events.cend()) return it->second;
    return {};
  }
  
  void Print() const {
    for (const auto& [date, events] : events) {
      for (const auto& event : events) {
        std::cout << date << " " << event << std::endl;
      }
    }
  }
private:
  std::map<Date, std::set<std::string>> events;
};

Date ParseDate(const std::string& date) {
  auto error = std::runtime_error{"Wrong date format: " + date};
  
  int d, m, y;
  std::stringstream input{date};
  
  if (!(input >> y)) throw error;
  input.ignore(1);

  if (!(input >> m)) throw error;
  input.ignore(1);

  if (!(input >> d)) throw error;
  
  if (char ch; input >> ch) throw error;
  return {d, m, y};
}

Date GetDate(std::istream& input) {
  std::string string_date;
  input >> string_date;
  return ParseDate(string_date);
}

std::string GetEvent(std::istream& input) {
  std::string event;
  std::getline(input, event);
  return event;
}

int main() {
  Database db;
  
  std::string line;
  while (getline(std::cin, line)) {
    if (line.empty()) continue;

    std::stringstream input{line};
    std::string command;

    input >> command;
    try {
      if (command == "Add") {
        const auto& date = GetDate(input);
        input.ignore(1);
        const auto& event = GetEvent(input);
        db.AddEvent(date, event);
      } else if (command == "Del") {
        const auto& date = GetDate(input);
        input.ignore(1);
        const auto& event = GetEvent(input);
        if (event.empty()) {
          std::cout << "Deleted " << db.DeleteDate(date)<< " events" << std::endl;
        } else {
          if (db.DeleteEvent(date, event)) {
            std::cout << "Deleted successfully" << std::endl;
          } else {
            std::cout << "Event not found" << std::endl;
          }
        }
      } else if (command == "Find") {
        const auto& date = GetDate(input);
        for (const auto& event : db.Find(date)) {
          std::cout << event << std::endl;
        }
      } else if (command == "Print") {
        db.Print();
      } else {
        std::cout << "Unknown command: " << command << std::endl;
      }
    } catch (const std::runtime_error& exc) {
      std::cout << exc.what() << std::endl;
    } catch (const std::invalid_argument& exc) {
      std::cout << exc.what() << std::endl;
    }
  }

  return 0;
}