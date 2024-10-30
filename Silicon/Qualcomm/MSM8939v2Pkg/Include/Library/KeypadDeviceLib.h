#ifndef __LIBRARY_KEYPAD_DEVICE_H__
#define __LIBRARY_KEYPAD_DEVICE_H__

#include <Protocol/KeypadDevice.h>

EFI_STATUS EFIAPI KeypadDeviceReset (KEYPAD_DEVICE_PROTOCOL *This);
EFI_STATUS KeypadDeviceGetKeys (KEYPAD_DEVICE_PROTOCOL *This, KEYPAD_RETURN_API *KeypadReturnApi, UINT64 Delta);

#endif
