#include <iostream>
#include <memory>
#include <crtdbg.h> // look for memory leaks using vs code

extern void startGUI();

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // look for memory leaks using vs code debugger
    
    startGUI();

    return 0;
}