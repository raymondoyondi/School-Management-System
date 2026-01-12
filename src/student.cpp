#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>

#include "student.h"

Student::Student(const std::string& name, const std::string& rollno, int age) : name(name), rollno(rollno), age(age) {};

void Student::display() const {
    fmt::print(fg(fmt::color::cyan) | fmt::emphasis::bold, "Student Information:\n");
    fmt::print("Name: {}\nRoll No: {}\nAge: {}\n", name, rollno, age);
    fmt::print("------------------------\n");
}

std::string Student::getRollNo() const {
    return rollno;
}

nlohmann::json Student::toJson() const{
    return nlohmann::json {
        {"name", name},
        {"rollno", rollno},
        {"age", age}
    };
}

std::unique_ptr<Student> Student::createFromJson(const nlohmann::json& jsonData) {
    return std::make_unique<Student>(jsonData["name"], jsonData["rollno"], jsonData["age"].get<int>());
}

bool Student::operator == (const Student& other) const {
    return rollno == other.rollno;
}
