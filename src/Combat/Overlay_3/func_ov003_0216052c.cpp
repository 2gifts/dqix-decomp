#include <globaldefs.h>
#if defined(jpn)
enum { kRegion28 = 0x20 };
enum { kRegion324 = 0x20c };
enum { kRegion328 = 0x210 };
enum { kRegion464 = 0x28c };
#else
enum { kRegion28 = 0x28 };
enum { kRegion324 = 0x324 };
enum { kRegion328 = 0x328 };
enum { kRegion464 = 0x464 };
#endif

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
    char pad0[kRegion28];
    struct ElementIds elements;
};

extern struct ElementIdTable data_ov003_0217f3ec;
extern short data_ov003_0217f448[3][2];

struct Combatant0216052c {
    char pad0[kRegion324];
    struct Obj2081* model;
    char pad328[kRegion464 - kRegion328];
    unsigned int flags;
};

// JPN: func_ov003_021606e4
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
#if !defined(jpn)
                    h = (16 - h) >> 1;
#endif
                    short posX = x + w + 6;
#if defined(jpn)
                    short posY = y - 3;
#else
                    short posY = y - h + 1;
#endif
                    _Z23SetEntryFields_021604f4Pciish((char*)obj, posX, posY, 0, slot++);
                }
            }
            return;
        }
    }
}
