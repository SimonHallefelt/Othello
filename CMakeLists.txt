cmake_minimum_required(VERSION 3.31)
project(Othello)
add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/Game.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)