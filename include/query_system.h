#pragma once

#include <string>
#include <nlohmann/json.hpp>

class QuerySystem {
private:
    nlohmann::json data;

public:
    QuerySystem(const std::string& filename);

    void searchSchools(const std::string& searchTerm) const;
    void showSchoolData(const std::string& schoolName) const;
    void compareClasses(const std::string& school1, const std::string& school2) const;
    int countStudents() const;
    int countClassesStartingWith(const std::string& prefix) const;
};
