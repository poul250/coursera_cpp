#include <string>

struct Specialization {
  std::string specialization;
  explicit Specialization(const std::string& specialization) : specialization(specialization) {}
};

struct Course {
  std::string course;
  explicit Course(const std::string& course) : course(course) {}
};

struct Week {
  std::string week;
  explicit Week(const std::string& week) : week(week) {} 
};

struct LectureTitle {
  std::string specialization;
  std::string course;
  std::string week;

  LectureTitle(const Specialization& spec, const Course& course, const Week& week)
      : specialization(spec.specialization), course(course.course), week(week.week) {}
};
/*
int main() {
LectureTitle title("C++", "White belt", "4th");

LectureTitle title(string("C++"), string("White belt"), string("4th"));

LectureTitle title = {"C++", "White belt", "4th"};

LectureTitle title = {{"C++"}, {"White belt"}, {"4th"}};

LectureTitle title(
    Course("White belt"),
    Specialization("C++"),
    Week("4th")
);

LectureTitle title(
    Specialization("C++"),
    Week("4th"),
    Course("White belt")
);


  return 0;
}*/