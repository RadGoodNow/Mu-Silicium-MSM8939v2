#ifndef _EFI_GPIO_H_
#define _EFI_GPIO_H_

#define EFI_GPIO_GUID { 0x8054947b, 0x3223, 0x407a, { 0xa1, 0xcc, 0x31, 0x22, 0x2f, 0x80, 0x66, 0x40 } }
typedef struct _EFI_GPIO_PROTOCOL EFI_GPIO_PROTOCOL;

#define GPA_PULL_NONE   0
#define GPA_PULL_DOWN   1
#define GPA_PULL_UP     3

#define GPA_INPUT       0
#define GPA_OUTPUT      1

struct _EFI_GPIO_PROTOCOL {
    func    DirectionInput;
    func    DirectionOutput;
    func    GetDirection;
    func    Get;
    func    Set;

    func    SetFunction;
    func    SetDriveStrength;
    func    SetPull;

    func    tlmm_set_hdrive_ctrl;
    func    tlmm_set_pull_ctrl;
};

#endif