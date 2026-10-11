#include <globaldefs.h>
#if defined(jpn)
enum { kNotifyOffset = 0x41a8 };
#else
enum { kNotifyOffset = 0x4458 };
#endif


extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray(void*, unsigned char*, int, int);
extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_021cdb00(int, int, int, int);

// USA: func_020ae4ec
ARM void SetFlagBitAndNotifyOverlay17(int param0, int param1) {
    void* x = func_0205ec34();
    SetOrClearBitInArray(x, (unsigned char*)x + 0x8c, param0 + 0x33e, param1);
    void* y = func_ov017_0218b5b0();
    if (*(int*)((char*)y + kNotifyOffset) == 0) return;
    func_ov017_021cdb00(7, param0, param1, -1);
}
