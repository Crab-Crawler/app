cmake_minimum_required(VERSION 4.1.1)

project(CrabCrawler VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
find_package(CURL REQUIRED)

qt_standard_project_setup()

set(SOURCES
    src/main.cpp

    src/ui/navbar.cpp
    src/ui/content.cpp
)

if(WIN32)
    add_executable(CrabCrawler WIN32 ${SOURCES})
else()
    add_executable(CrabCrawler ${SOURCES})
endif()

target_link_libraries(CrabCrawler
    PRIVATE Qt6::Widgets
    ${CURL_LIBRARIES}
)

target_link_libraries(CrabCrawler
    PRIVATE Qt6::Widgets
)
