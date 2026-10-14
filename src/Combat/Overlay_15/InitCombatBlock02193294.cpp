#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct021933ac { int f0; char f4; };
void ZeroTwoFields021933ac(struct Struct021933ac* s);

struct GameResources;
void InitializeBrightnessState(GameResources*);
extern "C" unsigned int func_02029568(void* self);

// USA: func_ov015_02193294  (semantic: InitCombatBlock02193294)
extern "C" ARM void func_ov015_02193294(void* objRaw) {
    char* obj = (char*)objRaw;

    InitializeBrightnessState((GameResources*)objRaw);

    *(int*)(obj + 0x2c) = 0;
    *(int*)(obj + 0x30) = 0;
    *(int*)(obj + 0x34) = 0;

    *(signed char*)(obj + 0x38) = -1;
    *(int*)(obj + 0x194) = -1;
    *(int*)(obj + 0x198) = -1;

    *(unsigned char*)(obj + 0x19c) = 1;
    *(unsigned char*)(obj + 0x19d) = 1;
    *(unsigned char*)(obj + 0x19e) = 1;
    *(unsigned char*)(obj + 0x19f) = 1;
    *(unsigned char*)(obj + 0x1a0) = 0;
    *(unsigned char*)(obj + 0x1a1) = 0;
    *(int*)(obj + 0x1a4) = -1;

    memset(obj + 0x1a8, -1, 0x80);

    *(int*)(obj + 0x228) = 0;
    *(int*)(obj + 0x22c) = 0;
    *(int*)(obj + 0x230) = 0;
    *(int*)(obj + 0x234) = 0;
    *(int*)(obj + 0x238) = 0;
    *(int*)(obj + 0x23c) = 0;
    *(int*)(obj + 0x240) = 0;
    *(int*)(obj + 0x244) = 0;
    *(int*)(obj + 0x248) = 0;
    *(int*)(obj + 0x24c) = 0;
    *(int*)(obj + 0x250) = 0;
    *(int*)(obj + 0x254) = 0;
    *(int*)(obj + 0x258) = 0;
    *(int*)(obj + 0x25c) = 0;
    *(int*)(obj + 0x260) = 0;
    *(int*)(obj + 0x264) = 0;

    memset(obj + 0x268, 0, 0x52);

    *(int*)(obj + 0x348) = 0;
    *(int*)(obj + 0x34c) = 0;
    *(int*)(obj + 0x2bc) = 0x1e;
    *(int*)(obj + 0x2c0) = 0;
    *(int*)(obj + 0x84) = 0;

    func_02029568(obj + 0x2c4);

    *(int*)(obj + 0x304) = 1;
    *(int*)(obj + 0x344) = 0;
    *(unsigned char*)(obj + 0x350) = 0;

    for (int i = 0; i < 4; i++) {
        ZeroTwoFields021933ac((struct Struct021933ac*)(obj + 0xc4) + i);
        ZeroTwoFields021933ac((struct Struct021933ac*)(obj + 0xe4) + i);
        ZeroTwoFields021933ac((struct Struct021933ac*)(obj + 0x104) + i);
    }
}
