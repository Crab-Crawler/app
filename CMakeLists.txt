cmake_minimum_required(VERSION 4.2.1)

project(CrabCrawler VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_executable(CrabCrawler
    src/main.cpp
    src/ui/navbar.cpp
)

target_link_libraries(CrabCrawler
    PRIVATE Qt6::Widgets
)
