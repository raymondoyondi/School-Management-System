#include <iostream>

#include "school_factory.h"

std::unique_ptr<School> SchoolFactory::createSchool() {
    std::string name;
    std::cout << "Enter the name of the school: ";
    std::getline(std::cin, name);
    return std::make_unique<School>(name);
}

std::unique_ptr<Class> SchoolFactory::createClass() {
    int classNumber;
    std::string teacher;
    std::cout << "Enter the class number: ";
    std::cin >> classNumber;
    std::cin.ignore();
    std::cout << "Enter the name of the class teacher: ";
    std::getline(std::cin, teacher);
    return std::make_unique<Class>(classNumber, teacher);
}

std::unique_ptr<Class> SchoolFactory::createClass(const std::unique_ptr<Class>& existingClass) {
    int classNumber;
    std::string teacher;
    std::cout << "Enter the new class number: ";
    std::cin >> classNumber;
    std::cin.ignore();
    std::cout << "Enter the name of the new class teacher: ";
    std::getline(std::cin, teacher);
    return std::make_unique<Class>(classNumber, teacher, *existingClass);
}

std::unique_ptr<Student> SchoolFactory::createStudent() {
    std::string name, rollno;
    int age;
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    std::cout << "Enter roll number: ";
    std::getline(std::cin, rollno);
    std::cout << "Enter age: ";
    std::cin >> age;
    std::cin.ignore();
    return std::make_unique<Student>(name, rollno, age);
}
