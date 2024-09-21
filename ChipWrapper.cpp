#include "ChipWrapper.h"
#include <iostream>
#include <string>


ChipWrapper::ChipWrapper()
{

}

ChipWrapper::~ChipWrapper()
{
    
}

bool ChipWrapper::Initialize()
{
    std::cout << "starting initialization ...\n";
    return true;
}

bool ChipWrapper::SendCommand(const int deviceID, const std::string& command)
{

//./chip-tool pairing ble-wifi 0x7283 <ssid> <passphrase> 20202021 3840
}

std::string ChipWrapper::GetDeviceStatus(const int deviceID)
{
    std::cout << "getting " << std::to_string(deviceID) << "deivce status\n";

    std::string status = "connected";
    return status;
}
