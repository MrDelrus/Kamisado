cmake_minimum_required(VERSION 3.16)

project(Kamisado)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES src/main.cpp
        src/model/match/piece.cpp
        src/model/match/board.cpp
        src/view/match/board_viewer.cpp
        src/view/match/arbiter_viewer.cpp
        src/view/match/asset_manager.cpp
        src/view/match/piece_viewer.cpp
        src/control/match/board_controller.cpp
        src/control/match/arbiter.cpp
        src/control/match/game_arbiter.cpp
        src/view/match/square_filler.cpp
        src/control/states/game_state.h
        src/control/states/test_match_scenery.cpp
        src/control/states/state_machine.cpp
        src/control/states/title_screen_scenery.cpp
        src/control/states/state.h
)

find_package(SDL2 REQUIRED)

if (NOT SDL2_FOUND)
    message(FATAL_ERROR "SDL2 not found. Please install SDL2 and its development libraries.")
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2_image REQUIRED)

if (NOT SDL2IMAGE_FOUND)
    message(FATAL_ERROR "SDL2_image not found. Please install SDL2_image and its development libraries.")
endif()

add_executable(Kamisado ${SOURCES})

target_include_directories(Kamisado PRIVATE ${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR})

target_link_libraries(Kamisado PRIVATE ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARY})

file(COPY ${ASSETS_DIR} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
