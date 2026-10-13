#include <globaldefs.h>
#include "std_library_functions.h"

struct State0204166c;
#if defined(jpn)
extern "C" void func_02041bbc(struct State0204166c* s);
#define Forward020416c0 func_02041bbc
enum {
    kClearOffset = 0x21c, kCountOffset = 0x884, kSlotBase = 0x888,
    kSlotFlags = 0x1688, kTailWord = 0x1738, kStateWord = 0x870,
    kFlagA = 0x17e2, kFlagB = 0x17e4, kFirstSlot = 14
};
#else
extern void Forward020416c0(struct State0204166c* s);
enum {
    kClearOffset = 0x2cc, kCountOffset = 0x9b4, kSlotBase = 0x9b8,
    kSlotFlags = 0x17b8, kTailWord = 0x1868, kStateWord = 0x9a0,
    kFlagA = 0x19b2, kFlagB = 0x19b4, kFirstSlot = 0
};
#endif

// USA: func_02043040
ARM void InitCombatSlots02043040(char* obj) {
    int i;

    memset(obj + kClearOffset, 0, 4);
    *(int*)(obj + kCountOffset) = kFirstSlot;

    for (i = kFirstSlot; i < 0x80; i++) {
        Forward020416c0((struct State0204166c*)(obj + kSlotBase + i * 0x1c));
        *(unsigned char*)(obj + i + kSlotFlags) = 0;
    }

    *(int*)(obj + kTailWord) = 0;
    *(int*)(obj + kStateWord) = 0;
    *(unsigned char*)(obj + kFlagA) = 0;
    *(unsigned char*)(obj + kFlagB) = 0;
}
