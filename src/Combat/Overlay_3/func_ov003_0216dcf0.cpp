#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { kRegionValue2C0_150 = 0x150 };
enum { kRegionValue2A8_138 = 0x138 };
enum { kRegionValue126C_10FC = 0x10fc };
#else
enum { kRegionValue2C0_150 = 0x2c0 };
enum { kRegionValue2A8_138 = 0x2a8 };
enum { kRegionValue126C_10FC = 0x126c };
#endif


struct Elem_0205d81c {
    char pad0[0xac];
    short posX;
    short posY;
};

struct Struct_0205d81c;
struct Elem_0205d81c* FindElementForFieldB0(struct Struct_0205d81c* s);
int CheckField0x9cSetWhenField0xd4Present(unsigned char* obj);

struct Struct_0205c570;
extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570* s);

struct Container0205a3d0;
struct Elem0205a3d0;
extern "C" void _Z26SetEntryFlag2ByKey0205a370P17Container0205a3d0i(struct Container0205a3d0* c, int key);
extern "C" struct Elem0205a3d0* _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(struct Container0205a3d0* c, int key);
void SetEntryPosition(struct Container0205a3d0* c, int key, short a, short b);

struct Container0205a330;
extern "C" void _Z22IterateEntries0205a330P17Container0205a330i(struct Container0205a330* c, int arg);

extern "C" void func_0205ae8c(void* obj);

// USA: func_ov003_0216dcf0
// JPN: func_ov003_0216d688
extern "C" ARM void func_ov003_0216dcf0(char* obj) {
    GameState* battle = GameState::GetInstance();
    struct Elem_0205d81c* elem = FindElementForFieldB0(*(struct Struct_0205d81c**)(obj + 0x1000 + kRegionValue2C0_150));
    if (elem != 0 && CheckField0x9cSetWhenField0xd4Present((unsigned char*)elem) != 0) {
        short y = elem->posY << 3;
        short x = elem->posX;
        short sum = _Z26GetActiveScaledSum0205d794P15Struct_0205c570(*(struct Struct_0205c570**)(obj + 0x1000 + kRegionValue2C0_150));
        short row = y + sum * 12;
        struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0x1000 + kRegionValue2A8_138);
        if (cont == 0) return;
        _Z26SetEntryFlag2ByKey0205a370P17Container0205a3d0i(cont, 0);
        struct Elem0205a3d0* e = _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(cont, 0);
        if (e != 0) {
            *(unsigned char*)((char*)e + 0x15) |= 8;
        }
        _Z22IterateEntries0205a330P17Container0205a330i((struct Container0205a330*)cont, battle->GetTickCount());
        SetEntryPosition(cont, 0, (short)(x * 8) - 4, row + 2);
        func_0205ae8c(obj + kRegionValue126C_10FC);
        return;
    }

    struct Container0205a3d0* cont = *(struct Container0205a3d0**)(obj + 0x1000 + kRegionValue2A8_138);
    if (cont == 0) return;
    struct Elem0205a3d0* e = _Z27FindEntryByHalfword0205a3d0P17Container0205a3d0i(cont, 0);
    if (e != 0) {
        *(unsigned char*)((char*)e + 0x15) &= ~8;
    }
}
