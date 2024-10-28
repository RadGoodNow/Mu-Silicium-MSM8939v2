/**
  Copyright (C) Samsung Electronics Co. LTD

  This software is proprietary of Samsung Electronics.
  No part of this software, either material or conceptual may be copied or distributed, transmitted,
  transcribed, stored in a retrieval system or translated into any human or computer language in any form by any means,
  electronic, mechanical, manual or otherwise, or disclosed
  to third parties without the express written permission of Samsung Electronics.

  Alternatively, this program is free software in case of open source project
  you can redistribute it and/or modify
  it under the terms of the GNU General Public License version 2 as
  published by the Free Software Foundation.
**/

#ifndef _EFI_IDO_GPIO_H_
#define _EFI_IDO_GPIO_H_

// GPA Pull Modes
#define GPA_PULL_NONE   0
#define GPA_PULL_DOWN   1
#define GPA_PULL_UP     3

// GPA DRV Speed Values
#define GPA_DRV_FAST    0
#define GPA_DRV_SLOW    1

// GPA Directions
#define GPA_INPUT       0
#define GPA_OUTPUT      1

//
// Global GUID for the Exynos Gpio Protocol
//
#define EFI_IDO_GPIO_PROTOCOL_GUID {0x0145CB2C, 0xBB04, 0x4C88, {0x87, 0x7B, 0x2F, 0xCA, 0x7D, 0xF6, 0x22, 0xED} }

//
// Declare forward Reference to the Exynos Gpio Protocol
//
typedef struct _EFI_IDO_GPIO_PROTOCOL EFI_IDO_GPIO_PROTOCOL;

//
// Exynos GPIO Bank Structure
//
typedef struct ido_gpio_bank {
  UINT32 Con;
  UINT32 Dat;
  UINT32 Pull;
  UINT32 Drv;
  UINT32 PdnCon;
  UINT32 PdnPull;
  UINT8  Reserved[8];
} IdoGpioBank;

/**
  This Function Configure the Defined Pin.

  @param[in] Bank               - The Exynos Gpa Bank.
  @param[in] Offset             - The Bank Offset.
  @param[in] Pin                - The Gpa Pin.
  @param[in] Config             - The Configuration.
**/
typedef
VOID
(EFIAPI *EFI_CONFIGURE_PIN) (
  IN IdoGpioBank *Bank,
  IN UINT32         Offset,
  IN INT32          Pin,
  IN INT32          Config
  );

/**
  This Function Sets the Direction to Output on the defined Pin.

  @param[in] Bank               - The Exynos Gpa Bank.
  @param[in] Offset             - The Bank Offset.
  @param[in] Pin                - The Gpa Pin.
  @param[in] Enable             - Enable Output?
**/
typedef
VOID
(EFIAPI *EFI_SET_DIRECTION_OUTPUT) (
  IN IdoGpioBank *Bank,
  IN UINT32         Offset,
  IN INT32          Pin,
  IN BOOLEAN        Enable
  );

/**
  This Function Sets the Direction to Input on the defined Pin.

  @param[in] Bank               - The Exynos Gpa Bank.
  @param[in] Offset             - The Bank Offset.
  @param[in] Pin                - The Gpa Pin.
**/
typedef
VOID
(EFIAPI *EFI_SET_DIRECTION_INPUT) (
  IN IdoGpioBank *Bank,
  IN UINT32         Offset,
  IN INT32          Pin
  );

/**
  This Function Gets the Current State of the defined Pin.

  @param[in] Bank               - The Exynos Gpa Bank.
  @param[in] Offset             - The Bank Offset.
  @param[in] Pin                - The Gpa Pin.

  @return State             - The State of the Pin.
**/
typedef
UINT32
(EFIAPI *EFI_GET_PIN) (
  IN IdoGpioBank *Bank,
  IN UINT32         Offset,
  IN INT32          Pin
  );

/**
  This Function Sets the Pull Mode to the defined Pin.

  @param[in] Bank               - The Exynos Gpa Bank.
  @param[in] Offset             - The Bank Offset.
  @param[in] Pin                - The Gpa Pin.
  @param[in] Mode               - The Mode.
**/
typedef
VOID
(EFIAPI *EFI_SET_PULL) (
  IN IdoGpioBank *Bank,
  IN UINT32         Offset,
  IN INT32          Pin,
  IN INT32          Mode
  );

/**
  This Function Sets the Drv Mode to the defined Pin.

  @param[in] Bank               - The Exynos Gpa Bank.
  @param[in] Offset             - The Bank Offset.
  @param[in] Pin                - The Gpa Pin.
  @param[in] Mode               - The Mode.
**/
typedef
VOID
(EFIAPI *EFI_SET_DRV) (
  IN IdoGpioBank *Bank,
  IN UINT32         Offset,
  IN INT32          Pin,
  IN INT32          Mode
  );

/**
  This Function Sets the Speed of the defined Pin.

  @param[in] Bank               - The Exynos Gpa Bank.
  @param[in] Offset             - The Bank Offset.
  @param[in] Pin                - The Gpa Pin.
  @param[in] Mode               - The Mode.
**/
typedef
VOID
(EFIAPI *EFI_SET_RATE) (
  IN IdoGpioBank *Bank,
  IN UINT32         Offset,
  IN INT32          Pin,
  IN INT32          Mode
  );

//
// Define Protocol Functions
//
struct _EFI_IDO_GPIO_PROTOCOL {
  EFI_CONFIGURE_PIN        ConfigurePin;
  EFI_SET_DIRECTION_OUTPUT SetDirectionOutput;
  EFI_SET_DIRECTION_INPUT  SetDirectionInput;
  EFI_GET_PIN              GetPin;
  EFI_SET_PULL             SetPull;
  EFI_SET_DRV              SetDrv;
  EFI_SET_RATE             SetRate;
};

extern EFI_GUID gEfiIdoGpioProtocolGuid;

#endif /* _EFI_EXYNOS_GPIO_H_ */
