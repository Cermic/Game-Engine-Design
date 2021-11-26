cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Game-Engine-Design LANGUAGES CXX)

file(GLOB_RECURSE headerFiles "headers/*.h")
file(GLOB_RECURSE sourceFiles "source/*.cpp")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/headers)

add_executable(${PROJECT_NAME} ${headerFiles} ${sourceFiles})