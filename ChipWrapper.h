#ifndef CHIP_WRAPPER_H
#define CHIP_WRAPPER_H

#include <string>

class ChipWrapper
{
public:
    /**
     * @brief Constructor for the ChipWrapper class.
     */
    ChipWrapper();

    /**
     * @brief Destructor for the ChipWrapper class.
     */
    ~ChipWrapper();

    /**
     * @brief Initializes the chip.
     * @return True if initialization was successful, false otherwise.
     */
    bool Initialize();

    /**
     * @brief Sends a command to the specified device.
     * @param deviceID The ID of the device to send the command to.
     * @param passCode of the target device
     * @param discriminator of the target device
     * @return True if the command was sent successfully, false otherwise.
     */
    bool CommissionDevice(const int deviceID, int passCode, int discriminator);

    /**
     * @brief Gets the status of the specified device.
     * @param deviceID The ID of the device.
     * @return A string representing the device status.
     */
    std::string GetDeviceStatus(const int deviceID);

private:
    /**
     * @brief Retrieves the SSID.
     * @return The SSID as a string.
     */
    std::string getSSID();

    /**
     * @brief Retrieves the passphrase.
     * @return The passphrase as a string.
     */
    std::string getPassphrase();
};

#endif  // CHIP_WRAPPER_H