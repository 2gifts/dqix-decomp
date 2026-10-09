#include <globaldefs.h>
#include "std_library_functions.h"

struct Entry_0205d6a0;
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0* a, int flag);
extern "C" int _Z29HasAnyFlags_021719f8_021719f8Pi(int* obj);
void ResetElem2081Entry(void* obj);

struct Combatant02174c14 {
    char pad0[0xc];
    short fieldC;
    char pad1[0x44 - 0xe];
    int posX;
    int posY;
    int field4c;
    char pad2[0x87 - 0x50];
    unsigned char field87;
    char pad3[0x448 - 0x88];
};

struct Elem02174c14 {
    char pad0[0xac];
    short x;
    short y;
    char pad1[0xc2 - 0xb0];
    short fieldC2;
};

// USA: func_ov000_02174c14
extern "C" ARM void func_ov000_02174c14(char* obj) {
    struct Combatant02174c14* c;
    int i;

    _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)(obj + 0x188), 1);
    memset(obj + 0x1d60, 0, 8);
    *(signed char*)(obj + 0x1d68) = 0;
    (obj + *(signed char*)(obj + 0x1d68))[0x1d60] = 1;

    for (i = 0; i < 4; i++) {
        c = (struct Combatant02174c14*)(obj + 0x958) + *(signed char*)(obj + 0x6c + i);
        if (c->field4c < 0) continue;
        if (c->fieldC == 0) continue;
        if (_Z29HasAnyFlags_021719f8_021719f8Pi((int*)c)) continue;
        if (c->field87 == 0) continue;

        struct Elem02174c14* elem = (struct Elem02174c14*)(obj + 0x284);
        int x = c->posX;
        int y = c->posY;
        ResetElem2081Entry(elem);
        elem->x = (x >> 3) + 9;
        elem->y = y >> 3;
        elem->fieldC2 = 0;
        *(unsigned short*)(obj + 0x1d72) |= 2;
        return;
    }
}
