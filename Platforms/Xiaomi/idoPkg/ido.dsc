##
#  Copyright (c) 2011 - 2022, ARM Limited. All rights reserved.
#  Copyright (c) 2014, Linaro Limited. All rights reserved.
#  Copyright (c) 2015 - 2020, Intel Corporation. All rights reserved.
#  Copyright (c) 2018, Bingxing Wang. All rights reserved.
#  Copyright (c) Microsoft Corporation.
#
#  SPDX-License-Identifier: BSD-2-Clause-Patent
##

################################################################################
#
# Defines Section - statements that will be processed to create a Makefile.
#
################################################################################
[Defines]
  PLATFORM_NAME                  = ido
  PLATFORM_GUID                  = 7004A90E-23E3-409F-887E-26CFFF6E4AE5
  PLATFORM_VERSION               = 0.1
  DSC_SPECIFICATION              = 0x00010005
  OUTPUT_DIRECTORY               = Build/idoPkg
  SUPPORTED_ARCHITECTURES        = AARCH64
  BUILD_TARGETS                  = RELEASE|DEBUG
  SKUID_IDENTIFIER               = DEFAULT
  FLASH_DEFINITION               = idoPkg/ido.fdf
  USE_CUSTOM_DISPLAY_DRIVER      = 0
  HAS_BUILD_IN_KEYBOARD          = 0

[BuildOptions]
  *_*_*_CC_FLAGS = -DHAS_BUILD_IN_KEYBOARD=$(HAS_BUILD_IN_KEYBOARD)

[LibraryClasses]
  DeviceMemoryMapLib|idoPkg/Library/DeviceMemoryMapLib/DeviceMemoryMapLib.inf
  DeviceConfigurationMapLib|idoPkg/Library/DeviceConfigurationMapLib/DeviceConfigurationMapLib.inf
  DevicePrePiLib|idoPkg/Library/DevicePrePiLib/DevicePrePiLib.inf

[PcdsFixedAtBuild]
  # DDR Start Address
  gArmTokenSpaceGuid.PcdSystemMemoryBase|0x83000000

  # Device Maintainer
  gSiliciumPkgTokenSpaceGuid.PcdDeviceMaintainer|"Daniel224455,RadGoodNow"

  # CPU Vector Address
  #gArmTokenSpaceGuid.PcdCpuVectorBaseAddress|0x5FF8C000

  # UEFI Stack Addresses
  gEmbeddedTokenSpaceGuid.PcdPrePiStackBase|0x94700000
  gEmbeddedTokenSpaceGuid.PcdPrePiStackSize|0x00041000

  # SmBios
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemVendor|"Xiaomi Inc"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemModel|"Redmi 3"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailModel|"ido"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosSystemRetailSku|"Redmi_3_ido"
  gSiliciumPkgTokenSpaceGuid.PcdSmbiosBoardModel|"Redmi 3"

  # Simple FrameBuffer
  gSiliciumPkgTokenSpaceGuid.PcdMipiFrameBufferWidth|720
  gSiliciumPkgTokenSpaceGuid.PcdMipiFrameBufferHeight|1280
  gSiliciumPkgTokenSpaceGuid.PcdMipiFrameBufferColorDepth|24

  # Platform Pei
  gQcomPkgTokenSpaceGuid.PcdPlatformType|"LA"

  # Dynamic RAM Start Address
  gQcomPkgTokenSpaceGuid.PcdRamPartitionBase|0x94741000

  # SD Card Slot
  gQcomPkgTokenSpaceGuid.PcdInitCardSlot|TRUE

  # USB Controller
  gQcomPkgTokenSpaceGuid.PcdStartUsbController|TRUE

[PcdsDynamicDefault]
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoHorizontalResolution|720
  gEfiMdeModulePkgTokenSpaceGuid.PcdVideoVerticalResolution|1280
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoHorizontalResolution|720
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupVideoVerticalResolution|1280
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutColumn|90
  gEfiMdeModulePkgTokenSpaceGuid.PcdSetupConOutRow|67
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutColumn|90
  gEfiMdeModulePkgTokenSpaceGuid.PcdConOutRow|67

!include MSM8939v2Pkg/MSM8939v2Pkg.dsc.inc
