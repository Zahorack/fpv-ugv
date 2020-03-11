cmake_minimum_required(VERSION 3.13)
project(application)

set(SOURCE_FILES "main.cpp")

add_executable(application_exe ${SOURCE_FILES})

#include_directories("../communication")
target_link_libraries(application_exe communication)