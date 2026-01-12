#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "school.h"
#include "menu.h"

std::string getFileName() {
    std::string response;
    std::cout << "Do you want to load a specific file? (y/n): ";
    std::getline(std::cin, response);
    
    if (response == "y" || response == "Y") {
        std::string fileName;
        std::cout << "Enter the filename to load (or press Enter for default 'schools.json'): ";
        std::getline(std::cin, fileName);
        return fileName.empty() ? "schools.json" : fileName;
    }
    
    return "schools.json";
}

int main() {
    std::vector<std::unique_ptr<School>> schools;
    
    std::string fileName = getFileName();
    
    try {
        auto loadedSchools = School::loadFromFileJSON(fileName);
        for (auto& school : loadedSchools) {
            schools.push_back(std::make_unique<School>(std::move(school)));
        }
        std::cout << "Successfully loaded data from " << fileName << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error loading file: " << e.what() << std::endl;
        std::cout << "Starting with an empty school list." << std::endl;
    }

    while (true) {
        displayMainMenu();
        handleMainMenu(schools);
    }

    return 0;
}
