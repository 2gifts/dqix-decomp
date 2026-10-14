#include <globaldefs.h>
#include "std_library_functions.h"

struct Flags02081b3c {
    unsigned char loNibble : 4;
    unsigned char hiNibble : 4;
};
struct Flags14_02081b3c {
    unsigned char f14lo : 2;
    unsigned char f14pad : 6;
};

ARM int IsValueEqual12_02042190(int x);
ARM int GetGlobalField0x1c020421a0(void);
ARM void CopyTextAndUppercaseIfFlagged0206819c(const char* src, char* dst, int flag);

extern "C" void __clear(void* buf, int n);
extern "C" int func_020420e8(void* p, int flag);
extern "C" void func_02046380(void* global);
extern "C" int func_02046608(int a, int b, void* c, void* d, int e, int f, int g);
extern "C" int func_0204f41c(void* target, int a, int b, void* c, int d, int e, void* f, void* g, int h);

#define F13(e) ((struct Flags02081b3c*)((e) + 0x13))
#define F14(e) ((struct Flags14_02081b3c*)((e) + 0x14))

// USA: func_02081b3c
ARM void ApplyEntryToTargetAndResetGlobal02081b3c(void* worldRaw, void* targetRaw, void* objRaw) {
    char* world = (char*)worldRaw;
    char* target = (char*)targetRaw;
    char* obj = (char*)objRaw;

    int hiNibbleOrFive = F13(obj)->hiNibble;
    if (*(unsigned char*)(obj + 0x2a) & 0x4) {
        hiNibbleOrFive = 5;
    }

    int boolResult = IsValueEqual12_02042190(F13(obj)->loNibble);

    char buf[0x100];
    char* textPtr = *(char**)(obj + 0x0);
    __clear(buf, 0x100);

    if (*(unsigned char*)(obj + 0x2a) & 0x40) {
        CopyTextAndUppercaseIfFlagged0206819c(textPtr, buf, boolResult);
        textPtr = buf;
    }

    if ((*(unsigned char*)(obj + 0x2a) & 0x8) && textPtr != NULL) {
        int scaled = *(short*)(target + 0xa8) << 0x13;
        int adj = func_020420e8(textPtr, boolResult);
        int val = (int)((unsigned int)((scaled >> 0x10) - adj) << 0x10) >> 0x11;
        *(short*)(obj + 0x6) = (short)val;
    }

    int g = GetGlobalField0x1c020421a0();
    memset(*(void**)(world + 0x18), 0, 0x960);
    func_02046380((void*)g);
    func_02046608(g, F13(obj)->loNibble, textPtr, *(void**)(world + 0x18), 0x100, 0, 0);

    int loNibble = F13(obj)->loNibble;
    *(short*)(target + 0xb4) = (short)loNibble;
    *(short*)(target + 0xb6) = (short)(loNibble + 1);

    if (*(unsigned char*)(obj + 0x2a) & 0x10) {
        int loNibble2 = F13(obj)->loNibble;
        if (loNibble2 == 0xc) {
            *(short*)(target + 0xb4) = (short)loNibble2;
            *(short*)(target + 0xb6) = 0x14;
        }
    }

    int r1 = 0;
    if (F14(obj)->f14lo) {
        r1 = func_020420e8(*(void**)(world + 0x18), 0);
    }

    short v6 = *(short*)(obj + 0x6);
    short v28 = *(short*)(obj + 0x28);
    short v8 = *(short*)(obj + 0x8);
    int arg1 = (short)(v6 + v28 - r1);
    func_0204f41c(target, arg1, v8, *(void**)(world + 0x18), F13(obj)->loNibble, hiNibbleOrFive, obj + 0xa, obj + 0xc, 0);
}
