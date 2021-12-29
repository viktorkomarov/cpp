#include <string>

struct Specialization {
    explicit Specialization(const std::string& val) {
        value = val;
    }

    std::string value;
};

struct Course {
    explicit Course(const std::string& val) {
        value = val;
    }

    std::string value;
};

struct Week {
    explicit Week(const std::string& val) {
        value = val;
    }

    std::string value;
};

struct LectureTitle {
  LectureTitle(Specialization spec,Course cour,Week w ) {
      specialization = spec.value;
      course = cour.value;
      week = w.value;
  }
  std::string specialization;
  std::string course;
  std::string week;
};
