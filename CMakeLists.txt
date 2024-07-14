cmake_minimum_required(VERSION 3.16)

project(Kamisado)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES src/main.cpp
        src/model/match/Piece.cpp
        src/model/match/Board.cpp
        src/view/match/BoardViewer.cpp
        src/view/match/ArbiterViewer.cpp
        src/view/match/AssetManager.cpp
        src/view/match/PieceViewer.cpp
        src/control/match/BoardController.cpp
        src/control/match/Arbiter.cpp
        src/control/match/GameArbiter.cpp
        src/view/match/SquareFiller.cpp
        src/control/states/GameState.h
        src/control/states/TestMatchScenery.cpp
        src/control/states/StateMachine.cpp
        src/control/states/TitleScreenScenery.cpp
        src/control/states/State.h
        src/control/players/fen.cpp
        src/control/players/MatchPlayer.h
        src/control/players/ProjectRunnerPlayer.cpp
        src/control/eventHandlers/SDL_EventHandler.cpp
        src/control/eventHandlers/AppLifeCycleEventHandler.cpp
        src/control/events/AppLifeCycleEvent.h
        src/control/eventHandlers/SceneryEventHandler.h
        src/control/eventHandlers/TestMatchSceneryEventHandler.cpp
        src/control/eventHandlers/BoardClickEventHandler.cpp
        src/control/events/SceneryEvent.h
        src/control/eventTransmitters/SceneryEventTransmitter.cpp
        src/control/eventHandlers/TitleScreenSceneryEventHandler.cpp
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
