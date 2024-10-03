#include <iostream>
#include "ChipWrapper.h"

// using namespace ChipWrapper;

int main() 
{
    std::cout << "Hello, World!" << std::endl;

    ChipWrapper chipTool;

    

    if (chipTool.CommissionDevice(0x7283, 20202021, 3840))
    {
        std::cout << "chip-tool initialized succesfully\n";
    }
    else
    {
        std::cerr << "failed to initialze chip-tool\n";
    }
    return 0;
}

