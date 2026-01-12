#pragma once
#include <string>
#include <vector>
#include <memory>
#include <nlohmann/json.hpp>

#include "class.h"

class School {
    private:
        std::string schoolName;
        std::vector<std::unique_ptr<Class>> classes;

    public:
        School(const std::string& schoolName);
        
        void addClass(const std::unique_ptr<Class> schoolClass);
        std::string getSchoolName() const;
        const std::vector<std::unique_ptr<Class>>& getClasses() const;
        void deleteClass(int classNumber);
        void changeSchoolName(const std::string& newName);
        void displaySchoolInfo() const;
        nlohmann::json toJson() const;
        void saveToFile() const;
        void reserveClassCapacity(size_t capacity);
        
        static std::vector<School> loadFromFileJSON(const std::string& filename);
        static School createFromJson(const nlohmann::json& jsonData);
        static std::string generateFilename(const std::string& schoolName);

        bool hasClass(const Class& other) const;
};
