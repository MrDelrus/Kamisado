cmake_minimum_required(VERSION 3.16)

project(Kamisado)

set(SOURCES ${SCRIPTS_DIR}/main.cpp)

find_package(SDL2 REQUIRED)

if (NOT SDL2_FOUND)
    message(FATAL_ERROR "SDL2 not found. Please install SDL2 and its development libraries.")
endif()

add_executable(Kamisado ${SOURCES})

target_include_directories(Kamisado PRIVATE ${SDL2_INCLUDE_DIRS})

target_link_libraries(Kamisado PRIVATE ${SDL2_LIBRARIES})

file(COPY ${ASSETS_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})