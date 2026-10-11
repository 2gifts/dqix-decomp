#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

#if defined(jpn)
enum { kRegionValue59F_59B = 0x59b };
enum { kRegionValueE4_E0 = 0xe0 };
enum { kRegionValue4D8_4D4 = 0x4d4 };
enum { kRegionValue4DC_4D8 = 0x4d8 };
enum { kRegionValue480_47C = 0x47c };
#else
enum { kRegionValue59F_59B = 0x59f };
enum { kRegionValueE4_E0 = 0xe4 };
enum { kRegionValue4D8_4D4 = 0x4d8 };
enum { kRegionValue4DC_4D8 = 0x4dc };
enum { kRegionValue480_47C = 0x480 };
#endif


struct Struct_0205d81c;
struct Elem_0205d81c;
Elem_0205d81c* FindElementForFieldB0(Struct_0205d81c*);
int CheckField0x9cSetWhenField0xd4Present(unsigned char*);

struct Container0205a3d0;
struct Elem0205a3d0;
void SetEntryFlag2ByKey0205a370(Container0205a3d0*, int);
Elem0205a3d0* FindEntryByHalfword0205a3d0(Container0205a3d0*, int);

struct Container0205a330;
void IterateEntries0205a330(Container0205a330*, int);

extern "C" void func_0205ae8c(void*);

// USA: func_ov003_0216acf0
// JPN: func_ov003_0216a88c
ARM void UpdateEntryPosition_0216acf0(char* base) {
    if (!(*(unsigned char*)(base + kRegionValue59F_59B) & 1)) return;

    Elem_0205d81c* elem = FindElementForFieldB0((Struct_0205d81c*)(base + kRegionValueE4_E0));
    if (elem == NULL) return;
    if (!CheckField0x9cSetWhenField0xd4Present((unsigned char*)elem)) return;
    if (*(unsigned char*)((char*)elem + 0xc5) & 0x20) return;

    short a = *(short*)((char*)elem + 0xac);
    short b = *(short*)((char*)elem + 0xae);
    short d = *(short*)((char*)elem + 0xbc);
    short e = *(short*)((char*)elem + 0xbe);

    short x = (short)(d + (short)(a << 3));
    short y = (short)(e + (short)(b << 3));

    Container0205a3d0* cont = *(Container0205a3d0**)(base + kRegionValue4D8_4D4);
    SetEntryFlag2ByKey0205a370(cont, 0);

    cont = *(Container0205a3d0**)(base + kRegionValue4D8_4D4);
    Elem0205a3d0* entry = FindEntryByHalfword0205a3d0(cont, 0);
    if (entry != NULL) {
        *(unsigned char*)((char*)entry + 0x15) |= 8;
    }

    cont = *(Container0205a3d0**)(base + kRegionValue4D8_4D4);
    int arg = *(int*)(base + kRegionValue4DC_4D8);
    IterateEntries0205a330((Container0205a330*)cont, arg);

    cont = *(Container0205a3d0**)(base + kRegionValue4D8_4D4);
    entry = FindEntryByHalfword0205a3d0(cont, 0);
    if (entry != NULL) {
        *(short*)((char*)entry + 0x4) = (short)(x - 8);
        *(short*)((char*)entry + 0x6) = (short)(y - 2);
    }

    func_0205ae8c(base + kRegionValue480_47C);
}
