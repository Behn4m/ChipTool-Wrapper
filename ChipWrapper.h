#ifndef CHIP_WRAPPER_H
#define CHIP_WRAPPER_H

#include <string>

class ChipWrapper
{
public:
    ChipWrapper();
    ~ChipWrapper();

    bool Initialize();

    bool SendCommand(const int deviceID, const std::string& command);

    std::string GetDeviceStatus(const int deviceID);
};

#endif  // CHIP_WRAPPER_H