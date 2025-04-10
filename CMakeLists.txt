cmake_minimum_required(VERSION 3.31)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Othello)
add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/Game.cpp
    src/Board.cpp
    src/LegalMoves.cpp
    src/Player.cpp
    src/Int2D.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)