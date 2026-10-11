#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif


int GetGlobalField0x1c020421a0(void);
#if defined(jpn)
extern "C" int func_020469b0(void* g, int value, void* ptr, int flag);
extern "C" int func_02046f80(void* g, int mode, void* ptr, int size);
#else
extern "C" int func_02045d14(void* g, int value, void* ptr, int flag);
extern "C" int func_02046170(void* g, void* ptr, int size, int flag);
#endif

// USA: func_0205cb74
#pragma optimize_for_size off
ARM void ProcessCombatEntry0205cb74(char* obj, int value) {
    if (value == 0) return;

    void* g = (void*)GetGlobalField0x1c020421a0();

    *(unsigned short*)(obj + (IS_JPN ? 0x1b0 : 0x220) + *(unsigned char*)(obj + (IS_JPN ? 0x1c2 : 0x232)) * 2) = *(unsigned short*)(obj + (IS_JPN ? 0x1c0 : 0x230));

#if defined(jpn)
    int ret1 = func_020469b0(g, value, (unsigned short*)(obj + 0x120) + *(unsigned short*)(obj + (IS_JPN ? 0x1c0 : 0x230)), 0xc);
#else
    int ret1 = func_02045d14(g, value, (unsigned short*)(obj + 0x120) + *(unsigned short*)(obj + (IS_JPN ? 0x1c0 : 0x230)), 1);
#endif
    *(unsigned short*)(obj + (IS_JPN ? 0x1c0 : 0x230)) = *(unsigned short*)(obj + (IS_JPN ? 0x1c0 : 0x230)) + ret1;

#if defined(jpn)
    int ret2 = func_02046f80(g, 0xc, (unsigned short*)(obj + 0x120) + *(unsigned short*)(obj + (IS_JPN ? 0x1b0 : 0x220) + *(unsigned char*)(obj + (IS_JPN ? 0x1c2 : 0x232)) * 2), 0x100);
#else
    int ret2 = func_02046170(g, (unsigned short*)(obj + 0x120) + *(unsigned short*)(obj + (IS_JPN ? 0x1b0 : 0x220) + *(unsigned char*)(obj + (IS_JPN ? 0x1c2 : 0x232)) * 2), 0x100, 1);
#endif

    if (*(int*)(obj + 0xd0) < ret2) {
        *(int*)(obj + 0xd0) = ret2;
    }

    *(unsigned char*)(obj + (IS_JPN ? 0x1c2 : 0x232)) = *(unsigned char*)(obj + (IS_JPN ? 0x1c2 : 0x232)) + 1;

    if (*(int*)(obj + 0xdc) >= 8) {
        *(int*)(obj + 0xdc) = 7;
    } else {
        *(unsigned short*)(obj + 0x100 + *(int*)(obj + 0xdc) * 2) = ret2;
        *(unsigned short*)(obj + 0x110 + *(int*)(obj + 0xdc) * 2) = 0xc;
    }

    *(int*)(obj + 0xdc) = *(int*)(obj + 0xdc) + 1;
}
