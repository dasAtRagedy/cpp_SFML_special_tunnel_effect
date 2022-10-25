cmake_minimum_required(VERSION 3.23)
project(cpp_SFML_playground)

set(CMAKE_CXX_STANDARD 23)

add_executable(cpp_SFML_playground main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML32/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML32/include)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
