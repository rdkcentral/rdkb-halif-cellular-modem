/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

/**
 * @file cellular_modem_hal_api.h
 * @brief This file defines an interface for controlling and querying the state of cellular modems.
 *
 * The interface provides functions for:
 *
 * - **Modem Management:**
 *    - Factory reset (`Modem_FactoryReset()`)
 *    - Reboot (`Modem_Reboot()`)
 *    - Firmware version retrieval (`Modem_Firmware_Version()`)
 *
 */


#ifndef __CCSP_HAL_CELL_MAN_H__
#define __CCSP_HAL_CELL_MAN_H__

#define STATUS_SUCCESS 0    //!< Value if successful .
#define STATUS_FAILED -1    //!< Value if failure.

#ifdef __cplusplus
extern "C"{
#endif


/*
* TODO (Enhance Error Reporting):
*   - Replace the generic `RETURN_ERR` with a more descriptive error code enumeration.
*   - Define specific error codes to pinpoint various failure scenarios, including:
*       - Invalid input parameters (e.g., null pointers, out-of-range values)
*       - Resource allocation failures (e.g., out-of-memory)
*       - Communication or timeout issues with external systems (e.g., modem, network)
*       - File system errors (e.g., file not found, permission denied)
*       - Hardware-specific errors (e.g., SIM card not present, eUICC malfunction)
*       - Internal errors within the HAL
*   - Document the new error codes thoroughly in the header file and any relevant guides.
*/

/**
 * @brief Performs a factory reset on the modem.
 *
 * Resets the modem to its default factory settings, erasing any custom configurations and restoring all settings to their original state. This is typically used to resolve software issues or to clean the configuration before a new setup.
 *
 * @returns Status of the operation:
 * @retval STATUS_SUCCESS - On successful factory reset of the modem.
 * @retval STATUS_FAILED - On failure. Potential failure reasons include:
 *                          - Failure to access or modify configuration storage
 *                          - Insufficient permissions to perform the reset
 *                          - Hardware or firmware issues that prevent resetting
 *                          - Interruptions during the reset process
 * 
 */
int Modem_FactoryReset(void);

/**
 * @brief Reboots the modem.
 *
 * Initiates a reboot of the modem hardware. This operation attempts to safely shutdown and restart the modem,
 * ensuring that all services are cleanly restarted. This is typically used to apply new settings or recover from
 * an unstable state.
 *
 * @returns Status of the reboot operation:
 * @retval STATUS_SUCCESS - On successful reboot of the modem.
 * @retval STATUS_FAILED - On failure. Potential failure reasons include:
 *                          - Inability to secure necessary system resources for reboot
 *                          - Failure in initial shutdown phase of the modem
 *                          - Hardware or firmware issues preventing reboot
 *                          - Security or permission restrictions
 * 
 */
int Modem_Reboot(void);

/**
 * @brief Retrieves the current firmware version of the modem.
 *
 * This function retrieves the modem's firmware version and stores it in the provided buffer.
 *
 * @param[out] firmware_version - Buffer (min. 128 bytes) to store the firmware version (e.g., "EM06ALAR04A01M4G_01.003.01.003").
 *
 * @returns Status of the operation:
 * @retval STATUS_SUCCESS - On success.
 * @retval STATUS_FAILED - On failure (e.g., invalid parameter, retrieval error).
 */
int Modem_Firmware_Version(char *firmware_version);

#ifdef __cplusplus
}
#endif

#endif
