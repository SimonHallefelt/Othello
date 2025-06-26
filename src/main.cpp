#include <iostream>
#include <memory>
#ifdef _WIN32 // Windows only
    #include <crtdbg.h> // look for memory leaks using vs code
#endif

extern void startGUI();

int main() {
    #ifdef _WIN32 // Windows only
        _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // look for memory leaks using vs code debugger
    #endif

    startGUI();

    return 0;
}