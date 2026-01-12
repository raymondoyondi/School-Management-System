#include <iostream>
#include <fstream>
#include <algorithm>
#include <fmt/core.h>
#include <fmt/color.h>
#include "school.h"

// Class members implementation

School::School(const std::string& schoolName) : schoolName(schoolName) {
    classes.reserve(15);
}

void School::reserveClassCapacity(size_t capacity) {
    classes.reserve(capacity);
}

bool School::hasClass(const Class& other) const {
    for (const auto& schoolClass : classes) {
        if (*schoolClass == other) {
            return true;
        }
    }
    return false;
}

void School::addClass(std::unique_ptr<Class> schoolClass) {
    if (hasClass(*schoolClass)) {
        std::cout << "Class " << schoolClass->getClassNumber() << " already exists in the school." << std::endl;
        return;
    }
    classes.push_back(std::move(schoolClass));
}

std::string School::getSchoolName() const {
    return schoolName;
}

const std::vector<std::unique_ptr<Class>>& School::getClasses() const {
    return classes;
}

void School::displaySchoolInfo() const {
    fmt::print(fg(fmt::color::magenta) | fmt::emphasis::bold, "School Information:\n");
    fmt::print("School Name: {}\n", schoolName);
    fmt::print("------------------------\n");

    fmt::print(fg(fmt::color::blue) | fmt::emphasis::bold, "Classes:\n");
    for (const auto& schoolClass : classes) {
        schoolClass->displayClassInfo();
    }
}

nlohmann::json School::toJson() const {
    nlohmann::json jsonData;
    jsonData["schoolName"] = schoolName;
    jsonData["classes"] = nlohmann::json::array();
    for (const auto& schoolClass : classes) {
        jsonData["classes"].push_back(schoolClass->toJson());
    }
    return jsonData;
}

std::string School::generateFilename(const std::string& schoolName) {
    std::string filename = schoolName;
    std::replace(filename.begin(), filename.end(), ' ', '_');
    return "../data/" + filename + ".json";
}

void School::saveToFile() const {
    nlohmann::json jsonData = toJson();
    std::string filename = School::generateFilename(schoolName);

    std::ofstream file(filename);
    if(file.is_open()) {
        file << jsonData.dump(4);
        std::cout << "Data saved to " << filename << std::endl;
        file.close();
    } else {
        std::cerr << "Error: Could not open file." << std::endl;
    }
}

School School::createFromJson(const nlohmann::json& jsonData) {
    School school(jsonData["schoolName"]);
    for (const auto& classJSON : jsonData["classes"]) {
        school.addClass(Class::createFromJson(classJSON));
    }
    return school;
}

std::vector<School> School::loadFromFileJSON(const std::string& filename) {
    std::vector<School> schools;
    schools.reserve(10);
    std::ifstream file("../data/" + filename);
    
    if(file.is_open()) {
        nlohmann::json jsonData;
        file >> jsonData;
        file.close();

        for (const auto& schoolJSON :jsonData){
            schools.push_back(School::createFromJson(schoolJSON));
        }
        std::cout << "Data loaded from " << filename << std::endl;
    }else {
        std::cout << "Error: Could not open file." << std::endl;
    }
    return schools;
}

void School::deleteClass(int classNumber) {
    auto it = std::find_if(classes.begin(), classes.end(),
        [classNumber](const std::unique_ptr<Class>& c) { return c->getClassNumber() == classNumber; });
    
    if (it != classes.end()) {
        classes.erase(it);
        std::cout << "Class " << classNumber << " has been deleted." << std::endl;
    } else {
        std::cout << "Class " << classNumber << " not found." << std::endl;
    }
}

void School::changeSchoolName(const std::string& newName) {
    schoolName = newName;
    std::cout << "School name has been changed to: " << newName << std::endl;
}
