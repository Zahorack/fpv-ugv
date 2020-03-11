cmake_minimum_required(VERSION 3.13)
file(GLOB_RECURSE files "src/*.cpp")

project(communication)

add_library(communication OBJECT  ${files})
target_include_directories(communication PUBLIC include)

target_link_libraries(communication ws2_32)
if(WIN32)
    target_link_libraries(communication wsock32 ws2_32)
endif()

