#include <globaldefs.h>

extern "C" unsigned short* func_02012fe4(void);
extern "C" void _Z27SetOrClearElemFlag0x4ByKeysiis(int mode, int key1, unsigned short key2);
void SetFlagBitAndNotifyOverlay17(int param0, int param1);

// USA: func_020aee04  (semantic: SetElemFlagRangeByModeAndNotify_020aee04)
extern "C" ARM void func_020aee04(int mode, int value) {
    if (*func_02012fe4() != 0x1cea) return;
    if (mode == 1) {
        int key = 0x4e;
        for (; key <= 0x58; key++) {
            _Z27SetOrClearElemFlag0x4ByKeysiis((unsigned char)value, 0, key);
        }
        SetFlagBitAndNotifyOverlay17(0x47, value != 0);
    } else if (mode == 0) {
        int key = 0x37;
        for (; key <= 0x4b; key++) {
            _Z27SetOrClearElemFlag0x4ByKeysiis((unsigned char)value, 0, key);
        }
        SetFlagBitAndNotifyOverlay17(0x48, value != 0);
    }
}
