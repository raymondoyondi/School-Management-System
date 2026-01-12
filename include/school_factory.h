#pragma once

#include <memory>
#include "school.h"
#include "class.h"
#include "student.h"

class SchoolFactory {
    public:
    static std::unique_ptr<School> createSchool();
    static std::unique_ptr<Class> createClass();
    static std::unique_ptr<Class> createClass(const std::unique_ptr<Class>& existingClass);
    static std::unique_ptr<Student> createStudent();
};
