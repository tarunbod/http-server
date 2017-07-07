cmake_minimum_required(VERSION 3.7.1)

project(http-server)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH "bin")

# add_subdirectory(src)

include_directories("include")
set(SOURCE_FILES
    "src/main.cpp" "src/server.cpp" "src/debug.cpp" "src/config.cpp"
    "include/server.h" "include/debug.h" "include/config.h"
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
