#include <string>
#include <vector>
#include <memory>
#include "school.h"

// Function prototypes
void clearScreen();
void printHeader(const std::string& title);
bool updateJson(std::vector<std::unique_ptr<School>>& schools);
void displayMainMenu();
void handleMainMenu(std::vector<std::unique_ptr<School>>& schools);
void displaySchoolMenu(const std::string& schoolName);
void handleSchoolMenu(std::unique_ptr<School>& school, std::vector<std::unique_ptr<School>>& schools, bool (&updateJsonFunc)(std::vector<std::unique_ptr<School>>&));
void displayClassMenu(int classNumber, const std::string& teacherName);
void handleClassMenu(const std::unique_ptr<Class>& selectedClass, std::vector<std::unique_ptr<School>>& schools, bool (&updateJsonFunc)(std::vector<std::unique_ptr<School>>&));
void displayQueryMenu();
void handleQueryMenu();
