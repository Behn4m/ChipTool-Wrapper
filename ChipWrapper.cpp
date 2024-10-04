#include <cstdlib> 
#include "ChipWrapper.h"
#include <iostream>
#include <string>
#include <boost/process.hpp>

namespace bp  = boost::process;


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
    
    return true;
}

/**
 * @brief Sends a command to the specified device.
 */
bool ChipWrapper::CommissionDevice(const int deviceID, int passCode, int discriminator)
{
    std::cout << "starting initialization ...\n";
    
    std::string homeDir = std::getenv("HOME");
    std::string command = homeDir +
                          "/chip-tool pairing ble-wifi " + 
                          std::to_string(deviceID) + " " + 
                          getSSID() + " " + 
                          getPassphrase() + " " + 
                          std::to_string(passCode) + " " + 
                          std::to_string(discriminator);

    std::cout << "command is: " << command << std::endl;

    std::string output;

    bp::ipstream pipe_stream;
    bp::child c(command, bp::std_out > pipe_stream);

    std::string line;

    while (pipe_stream && std::getline(pipe_stream, line) && !line.empty())
    {
        output += line + "\n";
    }

    c.wait();
    std::cout << "command output:\n" << output << std::endl;

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
   
    if (!passphrase.empty() && passphrase.back() == '\n') 
    {
        passphrase.erase(passphrase.size() - 1); // Remove the last character
    }
    
    return passphrase;
}
