#include <globaldefs.h>

extern "C" void* func_02057924(void* obj);
extern "C" void func_02057f00(void* self, int code);

// USA: func_020dabd0
ARM int RunCombatFlagStateAction_020dabd0(void* obj) {
    void* self = func_02057924(obj);
    unsigned char sel = *((unsigned char*)obj + 0xe);
    switch (sel) {
    case 1:
        func_02057f00(self, 0x14);
        func_02057f00(self, 0x15);
        break;
    case 2:
        func_02057f00(self, 0x14);
        func_02057f00(self, 0x15);
        break;
    case 3:
        func_02057f00(self, 0x16);
        break;
    }
    return 1;
}
