#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
void SetOrClearElemFlag0x4ByKeys_020ae694(int mode, int key1, unsigned short key2);
void SetFlagBitAndNotifyOverlay17_020ae4ec(int param0, int param1);

// USA: func_020ae990
ARM void NotifyElemAndOverlay17OnFlag020ae990(int a) {
    if (*(unsigned short*)func_02012fe4() != 0x1647) return;
    if (a == 0) {
        SetOrClearElemFlag0x4ByKeys_020ae694(1, 0, 4);
    } else {
        SetOrClearElemFlag0x4ByKeys_020ae694(0, 0, 4);
    }
    SetFlagBitAndNotifyOverlay17_020ae4ec(0x2e, a != 0);
}
