#include <globaldefs.h>

struct Obj2081;

extern "C" void* func_0202ae18(void);
int CheckField0NonZero(int* obj);
int HasElementByByte0xc4(struct Obj2081* obj, int key);
extern "C" void _Z30UpdateOffsetsFromEntry02080a6cPvisPsS0_S0_S0_(void* param0, int id, short param2, short* param3, short* param4, short* param5, short* param6);
extern "C" void _Z23SetEntryFields_021604f4Pciish(char* obj, int valA, int valB, short index, unsigned char flag);

struct ElementIds {
    short ids[3];
};

struct ElementIdTable {
    char pad0[0x28];
    struct ElementIds elements;
};

extern struct ElementIdTable data_ov003_0217f3ec;
extern short data_ov003_0217f448[3][2];

struct Combatant0216052c {
    char pad0[0x324];
    struct Obj2081* model;
    char pad328[0x464 - 0x328];
    unsigned int flags;
};

// USA: func_ov003_0216052c
extern "C" ARM void func_ov003_0216052c(struct Combatant0216052c* obj) {
    if (obj->model == NULL) {
        return;
    }
    if (CheckField0NonZero((int*)func_0202ae18()) != 0) {
        return;
    }
    struct Obj2081* model = obj->model;
    if (!(obj->flags & 0x10000)) {
        return;
    }
    struct ElementIds elements = data_ov003_0217f3ec.elements;
    for (int i = 0; i < 3; i++) {
        short id = elements.ids[i];
        if (HasElementByByte0xc4(model, id)) {
            unsigned char slot = 1;
            for (unsigned char j = 0; j < 2; j++) {
                short part = data_ov003_0217f448[i][j];
                if (part >= 0) {
                    short x, y, w, h;
                    _Z30UpdateOffsetsFromEntry02080a6cPvisPsS0_S0_S0_(model, id, part, &x, &y, &w, &h);
                    h = (16 - h) >> 1;
                    short posX = x + w + 6;
                    short posY = y - h + 1;
                    _Z23SetEntryFields_021604f4Pciish((char*)obj, posX, posY, 0, slot++);
                }
            }
            return;
        }
    }
}
