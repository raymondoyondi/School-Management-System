#include <fstream>
#include <iostream>
#include <algorithm>
#include <nlohmann/json.hpp>
#include "query_system.h"

using json = nlohmann::json;

QuerySystem::QuerySystem(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }
    file >> data;
}

void QuerySystem::searchSchools(const std::string& searchTerm) const {
    std::cout << "Schools containing '" << searchTerm << "':\n";
    for (const auto& school : data) {
        std::string schoolName = school["schoolName"];
        if (schoolName.find(searchTerm) != std::string::npos) {
            std::cout << "  " << schoolName << "\n";
        }
    }
    std::cout << std::endl;
}

void QuerySystem::showSchoolData(const std::string& schoolName) const {
    for (const auto& school : data) {
        if (school["schoolName"] == schoolName) {
            std::cout << "School Name: " << school["schoolName"] << "\n";
            std::cout << "Number of Classes: " << school["classes"].size() << "\n";
            std::cout << "Classes:\n";
            for (const auto& cls : school["classes"]) {
                std::cout << "  Class " << cls["classNumber"] << ":\n";
                std::cout << "    Teacher: " << cls["classTeacher"] << "\n";
                std::cout << "    Students: " << cls["students"].size() << "\n";
            }
            std::cout << std::endl;
            return;
        }
    }
    std::cout << "School not found." << std::endl;
}

void QuerySystem::compareClasses(const std::string& school1, const std::string& school2) const {
    auto findSchool = [this](const std::string& name) -> json {
        auto it = std::find_if(data.begin(), data.end(), 
            [&name](const json& school) { return school["schoolName"] == name; });
        return (it != data.end()) ? *it : json();
    };

    json s1 = findSchool(school1);
    json s2 = findSchool(school2);

    if (s1.empty() || s2.empty()) {
        std::cout << "One or both schools not found." << std::endl;
        return;
    }

    std::cout << "Comparing " << school1 << " and " << school2 << ":\n";
    std::cout << school1 << " has " << s1["classes"].size() << " classes.\n";
    std::cout << school2 << " has " << s2["classes"].size() << " classes.\n";

    int students1 = 0, students2 = 0;
    for (const auto& cls : s1["classes"]) students1 += cls["students"].size();
    for (const auto& cls : s2["classes"]) students2 += cls["students"].size();

    std::cout << school1 << " has " << students1 << " total students.\n";
    std::cout << school2 << " has " << students2 << " total students.\n";
    std::cout << std::endl;
}

int QuerySystem::countStudents() const {
    int totalStudents = 0;
    for (const auto& school : data) {
        for (const auto& cls : school["classes"]) {
            totalStudents += cls["students"].size();
        }
    }
    return totalStudents;
}

int QuerySystem::countClassesStartingWith(const std::string& prefix) const {
    int count = 0;
    for (const auto& school : data) {
        for (const auto& cls : school["classes"]) {
            std::string teacherName = cls["classTeacher"];
            if (teacherName.substr(0, prefix.length()) == prefix) {
                count++;
            }
        }
    }
    return count;
}
