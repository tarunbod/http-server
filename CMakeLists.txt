cmake_minimum_required(VERSION 3.7.1)

project(http-server)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH "bin")

# add_subdirectory(src)

set(SOURCE_FILES "src/server.cpp")
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
