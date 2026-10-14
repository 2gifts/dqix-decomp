#include <globaldefs.h>

#if defined(jpn)
enum { ResourceFlagOffset = 0x41a8 };
#else
enum { ResourceFlagOffset = 0x4458 };
#endif

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* func_0205ec34(void);
extern "C" unsigned short* func_02012fe4(void);
extern "C" void func_020aee04(int mode, int value);

int TestBitInByteArray_0206dfb0(int unused, unsigned char* arr, int index);
void ToggleElemKey2FlagInMap2010_020ae6e8(int enable);
void SetElemFlag8IfOverlayActive020ae730(int a);
void SetElemFlag0x4PairAndNotify17_020ae7d4(int mode);
void SetElemFlag0x4QuadAndNotify17_020ae880(int mode);
void NotifyElemAndOverlay17OnFlag020ae990(int a);
void SyncEightElementFlags_020ae9f0(void);
void SetOrClearElemFlag0x4ByKeys_020ae694(int, int, unsigned short);
void SetFlagBitAndNotifyOverlay17_020ae4ec(int param0, int param1);

// USA: func_020ae53c
extern "C" ARM void func_020ae53c(int arg) {
    char* res = (char*)func_ov017_0218b5b0();
    unsigned char* f = (unsigned char*)func_0205ec34();
    int key;
    func_02012fe4();
    *(int*)((unsigned char*)res + ResourceFlagOffset) = arg;

    ToggleElemKey2FlagInMap2010_020ae6e8(!TestBitInByteArray_0206dfb0((int)f, f + 0x8c, 0x33e));
    SetElemFlag8IfOverlayActive020ae730((unsigned char)TestBitInByteArray_0206dfb0((int)f, f + 0x8c, 0x344));
    SetElemFlag0x4PairAndNotify17_020ae7d4((unsigned char)TestBitInByteArray_0206dfb0((int)f, f + 0x8c, 0x347));
    SetElemFlag0x4QuadAndNotify17_020ae880((unsigned char)TestBitInByteArray_0206dfb0((int)f, f + 0x8c, 0x34a));
    NotifyElemAndOverlay17OnFlag020ae990((unsigned char)TestBitInByteArray_0206dfb0((int)f, f + 0x8c, 0x36c));
    SyncEightElementFlags_020ae9f0();

    arg = TestBitInByteArray_0206dfb0((int)f, f + 0x8c, 0x385);
    if (*func_02012fe4() == 0x1cea) {
        for (key = 0x4e; key <= 0x58; key++) {
            SetOrClearElemFlag0x4ByKeys_020ae694((unsigned char)arg, 0, key);
        }
        SetFlagBitAndNotifyOverlay17_020ae4ec(0x47, arg != 0);
    }
    func_020aee04(0, TestBitInByteArray_0206dfb0((int)f, f + 0x8c, 0x386));
    *(int*)(res + ResourceFlagOffset) = 1;
}
