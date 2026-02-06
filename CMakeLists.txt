cmake_minimum_required(VERSION 3.28)
project(Klartext LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(cpr CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

add_executable(klartext src/main.cpp src/api_client.cpp)

target_include_directories(klartext PRIVATE include)

target_link_libraries(klartext PRIVATE cpr::cpr nlohmann_json::nlohmann_json)