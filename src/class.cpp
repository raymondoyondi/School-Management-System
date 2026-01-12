#include <iostream>
#include <fmt/core.h>
#include <fmt/color.h>
#include "class.h"

Class::Class(int classNumber, const std::string& classTeacher) 
    : classNumber(classNumber), classTeacher(classTeacher) {
    students.reserve(50);
}

Class::Class(int classNumber, const std::string& classTeacher, const Class& other) 
    : classNumber(classNumber), classTeacher(classTeacher) {
    students.reserve(50);
    for (const auto& student : other.students) {
        students.push_back(std::make_unique<Student>(*student));
    }
}

void Class::reserveStudentCapacity(size_t capacity){
    students.reserve(capacity);
}

bool Class::hasStudent(const Student& student) const {
    for (const auto& studentPtr : students) {
        if (*studentPtr == student) {
            return true;
        }
    }
    return false;
}

void Class::addStudent(std::unique_ptr<Student> student) {
    if(hasStudent(*student)){
        std::cout << "Student with roll number " << student->getRollNo() << " already exists in the class." << std::endl;
        return;
    }
    students.push_back(std::move(student));
}

int Class::getClassNumber() const {
    return classNumber;
}

std::string Class::getClassTeacher() const {
    return classTeacher;
}

void Class::displayClassInfo() const {
    fmt::print(fg(fmt::color::green) | fmt::emphasis::bold, "\nClass Information:\n");
    fmt::print("Class Number: {}\nClass Teacher: {}\n", classNumber, classTeacher);
    fmt::print("------------------------\n");

    fmt::print(fg(fmt::color::yellow) | fmt::emphasis::bold, "Students:\n");
    for (const auto& student : students) {
        student->display();
    }
}

bool Class::operator == (const Class& other) const {
    return classNumber == other.classNumber && classTeacher == other.classTeacher;
}

bool Class::operator < (const Class& other) const {
    return students.size() < other.students.size();
}

bool Class::operator > (const Class& other) const {
    return students.size() > other.students.size();
}

nlohmann::json Class::toJson() const {
    nlohmann::json jsonData;
    jsonData["classNumber"] = classNumber;
    jsonData["classTeacher"] = classTeacher;
    jsonData["students"] = nlohmann::json::array();
    for (const auto& student : students) {
        jsonData["students"].push_back(student->toJson());
    }
    return jsonData;
}

std::unique_ptr<Class> Class::createFromJson(const nlohmann::json& jsonData) {
    auto classPtr = std::make_unique<Class>(jsonData["classNumber"], jsonData["classTeacher"]);
    for (const auto& studentJSON : jsonData["students"]) {
        classPtr->addStudent(Student::createFromJson(studentJSON));
    }
    return classPtr;
}
