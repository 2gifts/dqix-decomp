#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
void SetOrClearElemFlag0x4ByKeys_020ae694(int mode, int key1, unsigned short key2);
void SetFlagBitAndNotifyOverlay17_020ae4ec(int id, int flag);

// USA: func_020ae6e8
ARM void ToggleElemKey2FlagInMap2010_020ae6e8(int enable) {
    if (*(unsigned short*)func_02012fe4() != 0x2010) return;
    SetOrClearElemFlag0x4ByKeys_020ae694(enable, 0, 2);
    SetFlagBitAndNotifyOverlay17_020ae4ec(0, enable == 0);
}
