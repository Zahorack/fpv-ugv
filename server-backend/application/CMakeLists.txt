cmake_minimum_required(VERSION 3.13)
project(application)

set(SOURCE_FILES "main.cpp")

add_executable(application_exe ${SOURCE_FILES})

#include_directories("../communication")
target_link_libraries(application_exe communication)
target_link_libraries(application_exe control)

add_custom_command(
        TARGET application_exe POST_BUILD VERBATIM
        COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:application_exe>" ${PROJECT_SOURCE_DIR}
)