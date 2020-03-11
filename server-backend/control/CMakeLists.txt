cmake_minimum_required(VERSION 3.13)
file(GLOB_RECURSE files "src/*.cpp")

project(control)

add_library(control OBJECT  ${files})
target_include_directories(control PUBLIC include)

target_link_libraries(control PUBLIC communication)