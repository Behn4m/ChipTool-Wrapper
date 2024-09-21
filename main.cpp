#include <iostream>
#include "ChipWrapper.h"

// using namespace ChipWrapper;

int main() 
{
    std::cout << "Hello, World!" << std::endl;

    ChipWrapper chipTool;

    if (chipTool.Initialize())
    {
        std::cout << "chip-tool initialized succesfully\n";
    }
    else
    {
        std::cerr << "failed to initialze chip-tool\n";
    }
    // SendCommand(0x00, "test");
    return 0;
}

