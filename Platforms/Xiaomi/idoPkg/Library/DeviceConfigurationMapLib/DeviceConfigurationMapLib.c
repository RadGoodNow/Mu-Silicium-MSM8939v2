#include <Library/DeviceConfigurationMapLib.h>

STATIC
CONFIGURATION_DESCRIPTOR_EX
gDeviceConfigurationDescriptorEx[] = {
  // Configuration Map
  {"EnableShell", 0x1},

  // Terminator
  {"Terminator", 0xFFFFFFFF}
};

CONFIGURATION_DESCRIPTOR_EX*
GetDeviceConfigurationMap ()
{
  return gDeviceConfigurationDescriptorEx;
}
