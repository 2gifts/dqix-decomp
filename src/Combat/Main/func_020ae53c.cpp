#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* func_0205ec34(void);
extern "C" unsigned short* func_02012fe4(void);
extern "C" void func_020aee04(int mode, int value);

int TestBitInByteArray(int unused, unsigned char* arr, int index);
void ToggleElemKey2FlagInMap2010(int enable);
extern "C" void _Z35SetElemFlag8IfOverlayActive020ae730i(int a);
void SetElemFlag0x4PairAndNotify17(int mode);
void SetElemFlag0x4QuadAndNotify17(int mode);
extern "C" void _Z36NotifyElemAndOverlay17OnFlag020ae990i(int a);
void SyncEightElementFlags(void);
extern "C" void _Z27SetOrClearElemFlag0x4ByKeysiis(int mode, int key1, unsigned short key2);
void SetFlagBitAndNotifyOverlay17(int param0, int param1);

// USA: func_020ae53c
extern "C" ARM void func_020ae53c(int arg) {
    char* res = (char*)func_ov017_0218b5b0();
    unsigned char* f = (unsigned char*)func_0205ec34();
    int key;
    func_02012fe4();
    *(int*)((unsigned char*)res + 0x4458) = arg;

    ToggleElemKey2FlagInMap2010(!TestBitInByteArray((int)f, f + 0x8c, 0x33e));
    _Z35SetElemFlag8IfOverlayActive020ae730i((unsigned char)TestBitInByteArray((int)f, f + 0x8c, 0x344));
    SetElemFlag0x4PairAndNotify17((unsigned char)TestBitInByteArray((int)f, f + 0x8c, 0x347));
    SetElemFlag0x4QuadAndNotify17((unsigned char)TestBitInByteArray((int)f, f + 0x8c, 0x34a));
    _Z36NotifyElemAndOverlay17OnFlag020ae990i((unsigned char)TestBitInByteArray((int)f, f + 0x8c, 0x36c));
    SyncEightElementFlags();

    arg = TestBitInByteArray((int)f, f + 0x8c, 0x385);
    if (*func_02012fe4() == 0x1cea) {
        for (key = 0x4e; key <= 0x58; key++) {
            _Z27SetOrClearElemFlag0x4ByKeysiis((unsigned char)arg, 0, key);
        }
        SetFlagBitAndNotifyOverlay17(0x47, arg != 0);
    }
    func_020aee04(0, TestBitInByteArray((int)f, f + 0x8c, 0x386));
    *(int*)(res + 0x4458) = 1;
}
