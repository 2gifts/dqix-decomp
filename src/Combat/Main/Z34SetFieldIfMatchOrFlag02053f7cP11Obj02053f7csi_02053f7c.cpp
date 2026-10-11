#include <globaldefs.h>
#if defined(jpn)
enum { kFieldOffset = 0xa6 };
#else
enum { kFieldOffset = 0xb2 };
#endif

#include "GameState/GameState.h"

struct Obj02086aec {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Sub02053f7c {
    char pad[kFieldOffset];
    short fieldb2;
};

struct Obj02053f7c {
    char pad[4];
    short field4;
    char pad2[0x100 - 6];
    struct Sub02053f7c sub;
};

void* GetPtrField0x2a04(GameState* gs);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02053f7c
extern "C" ARM void _Z34SetField0x1b2IfMatchOrFlag02053f7cP11Obj02053f7csi(struct Obj02053f7c* obj, short a, int b) {
    struct Obj02086aec* p = (struct Obj02086aec*)GetPtrField0x2a04(GameState::GetInstance());
    int found = 0;
    int i;
    if (p != NULL) {
        for (i = 0; i < p->count; i++) {
            unsigned char id = p->ids[i];
            if (id == obj->field4) {
                found = 1;
                break;
            }
        }
    }
    if (b != 0 || found != 0) {
        obj->sub.fieldb2 = a;
    }
}