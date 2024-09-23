#include <cstdlib> 
#include "ChipWrapper.h"
#include <iostream>
#include <string>

/**
 * @brief Constructor for the ChipWrapper class.
 */
ChipWrapper::ChipWrapper()
{

}

/**
 * @brief Destructor for the ChipWrapper class.
 */
ChipWrapper::~ChipWrapper()
{
    
}

/**
 * @brief Initializes the chip.
 */
bool ChipWrapper::Initialize()
{
    ChipWrapper::CommissionDevice(0x7283);
    return true;
}

/**
 * @brief Sends a command to the specified device.
 */
bool ChipWrapper::CommissionDevice(const int deviceID)
{
    std::cout << "starting initialization ...\n";
    char buffer[128];

    std::string command;
    std::string ssid;
    std::string passphrase;

    command = "~/chip-tool pairing ble-wifi " + std::to_string(deviceID) + " " + getSSID() + " " + getPassphrase() + " " + "20202021 3840";

    std::cout << "command is: " << command << std::endl;

    int result = system(command.c_str());
    
    if (result)
    {
        std::cout << "failed to commision device";
        return false;
    }

    std::cout << "device successfully commisioned";
    return true;
}

/**
 * @brief Gets the status of the specified device.
 */
std::string ChipWrapper::GetDeviceStatus(const int deviceID)
{
    std::cout << "getting " << std::to_string(deviceID) << "deivce status\n";

    std::string status = "connected";
    return status;
}

/**
 * @brief Retrieves the SSID.
 */
std::string ChipWrapper::getSSID()
{
    char buffer[128];

    std::string ssid;
    std::string command = "nmcli -t -f active,ssid dev wifi | grep '^yes' | cut -d: -f2\n";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe)
    {
        std::cerr << "Failed to rread wifi ssid";
        return "NO PASS";    
    }

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
        ssid += buffer;
    }

    if (!ssid.empty() && ssid.back() == '\n') 
    {
        ssid.erase(ssid.size() - 1); // Remove the last character
    }

    return ssid;
}

/**
 * @brief Retrieves the passphrase.
 */
std::string ChipWrapper::getPassphrase()
{
    char buffer[128];
    std::string passphrase;
    std::string command = "sudo nmcli -s -g 802-11-wireless-security.psk connection show preconfigured";
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe)
    {
        std::cerr << "Failed to read wifi ssid";
        return "NO PASSPHRASE";    
    }

    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
        passphrase += buffer;
    }

    std::cout << "pass: " << passphrase << std::endl;
   
    if (!passphrase.empty() && passphrase.back() == '\n') 
    {
        passphrase.erase(passphrase.size() - 1); // Remove the last character

    }
    
    return passphrase;
}
