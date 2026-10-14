#include <globaldefs.h>

extern "C" unsigned short* func_02012fe4(void);
void SetOrClearElemFlag0x4ByKeys(int, int, unsigned short);
void SetFlagBitAndNotifyOverlay17(int param0, int param1);

// USA: func_020aee04  (semantic: SetElemFlagRangeByModeAndNotify_020aee04)
extern "C" ARM void func_020aee04(int mode, int value) {
    if (*func_02012fe4() != 0x1cea) return;
    if (mode == 1) {
        int key = 0x4e;
        for (; key <= 0x58; key++) {
            SetOrClearElemFlag0x4ByKeys((unsigned char)value, 0, key);
        }
        SetFlagBitAndNotifyOverlay17(0x47, value != 0);
    } else if (mode == 0) {
        int key = 0x37;
        for (; key <= 0x4b; key++) {
            SetOrClearElemFlag0x4ByKeys((unsigned char)value, 0, key);
        }
        SetFlagBitAndNotifyOverlay17(0x48, value != 0);
    }
}
