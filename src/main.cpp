#include <iostream>
#include "../include/Game.hpp"
#include <crtdbg.h> // look for memory leaks using vs code

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // look for memory leaks using vs code debugger
    
    startGame();
    return 0;
}
