cmake_minimum_required(VERSION 3.10)
project(SchoolManagementSystem)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt
  GIT_TAG        e69e5f977d458f2650bb346dadf2ad30c5320281) # 10.2.1
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json
    GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

include_directories(include)
include_directories(lib)

file(GLOB SOURCES "src/*.cpp")

add_executable(SchoolManagementSystem ${SOURCES})

target_link_libraries(SchoolManagementSystem fmt::fmt nlohmann_json::nlohmann_json)
