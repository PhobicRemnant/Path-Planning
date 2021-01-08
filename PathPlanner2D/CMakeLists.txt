cmake_minimum_required(VERSION 3.0.0)
project(PathPlanner VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories(include)

set(SOURCES src/main.cpp)

find_package(SFML 2.5 COMPONENTS graphics window REQUIRED)

add_executable(PathPlanner ${SOURCES})
target_link_libraries(PathPlanner sfml-graphics sfml-window)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
