#include <globaldefs.h>

#if defined(jpn)
enum { kMenuPointer = 0xc };
#else
enum { kMenuPointer = 0x14 };
#endif

extern void SetEntryHalfword0xe(void* obj, int id, int value);
extern "C" void func_020813ec(void*, int);

struct Obj0215f348 {
    char pad0[kMenuPointer];
    void* f14;
    char pad1[0x360 - kMenuPointer - 4];
    short f360;
};

// USA: func_ov006_0215f348
ARM void SyncEntries0215f348(struct Obj0215f348* o) {
    short v2 = -1;
    switch (o->f360) {
    case 2:
        v2 = 4;
        break;
    case 3:
        v2 = 7;
        break;
    case 4:
        break;
    }
    short v1 = 5;
    for (unsigned char i = 0; i < 3; i++) {
        SetEntryHalfword0xe(o->f14, v1, v2);
        v1 = (short)(v1 + 1);
        if (v2 >= 0) {
            v2 = (short)(v2 + 1);
        }
    }
    func_020813ec(o->f14, 3);
}
