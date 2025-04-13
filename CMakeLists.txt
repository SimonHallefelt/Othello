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
    src/players/RandomPlayer.cpp
    src/players/AlphaBetaPlayer.cpp
    src/Int2D.cpp
    src/GUI.cpp
    src/GameInfo.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

set(CMAKE_TOOLCHAIN_FILE "C:/c_and_cpp_developer_tools/vcpkg/scripts/buildsystems/vcpkg.cmake")
find_package(raylib CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)