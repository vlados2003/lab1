// Copyright 2021 vlados2003
//

#ifndef INCLUDE_STUDENT_HPP_
#define INCLUDE_STUDENT_HPP_
#include "header.hpp"
#include <vector>
#include <string>
using nlohmann::json;
struct Student {
 public:
  Student();
  Student(std::string _name, std::any _group, std::any _avg, std::any debt);
  bool operator==(Student const & student) const;
  std::string name;
  std::any group;
  std::any avg;
  std::any debt;
};

void from_json(const json& j, Student& s);
void print(Student& student, std::ostream& os);
void print(std::string s1, std::string s2,
           std::string s3, std::string s4, std::ostream& os);
void print(std::vector<Student>& students, std::ostream& os);
std::vector<Student> parseJSON(json& data);
#endif  // INCLUDE_STUDENT_HPP_
