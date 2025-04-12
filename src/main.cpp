#include <iostream>
#include <memory>
#include <thread>
#include <crtdbg.h> // look for memory leaks using vs code

#include "../include/Game.hpp"
#include "../include/Board.hpp"

extern void startGUI(const std::shared_ptr<Board>& board);

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // look for memory leaks using vs code debugger
    
    std::shared_ptr<Board> board = std::make_shared<Board>();

    std::thread t1([board]() {
        startGUI(board);
    });

    startGame(board);

    t1.join();

    return 0;
}