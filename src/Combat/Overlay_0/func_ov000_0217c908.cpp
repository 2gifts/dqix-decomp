#include <globaldefs.h>
#if defined(jpn)
#include "std_library_functions.h"
extern "C" unsigned short data_02114e30[];
int TestFlag0SetAndFlag1Clear(unsigned short*, int);
extern "C" void _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(void*);
extern "C" void _Z28CallFunc0204b04cOverList0x98P12Cont0205d274(void*);
extern "C" void _Z19InitEntries0205d2bcP11Obj0205d2bc(void*);
#define KINDS_OFFSET 0x1f98
#define func_ov000_0217cb5c func_ov000_0217df54
#define func_ov000_0217d438 func_ov000_0217e830
#define func_ov000_0217d674 func_ov000_0217ea6c
#define func_ov000_0217d87c func_ov000_0217ec74
#define func_ov000_0217db4c func_ov000_0217ef30
#define func_ov000_0217dcf0 func_ov000_0217f158
#define func_ov000_0217df08 func_ov000_0217f370
#define func_ov000_0217e558 func_ov000_0217f888
#define func_ov000_0217e870 func_ov000_0217fba0
#define func_ov000_0217eb28 func_ov000_0217fe58
#else
#define KINDS_OFFSET 0x1d60
#endif

struct Entry_0205d6a0;
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0* list, int flag);

struct Battle0217c908;
extern "C" int func_ov000_0217f910(struct Battle0217c908* battle);
extern "C" int func_ov000_0217f3e4(struct Battle0217c908* battle);
extern "C" void func_ov000_0217cb5c(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217ce24(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217d324(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217d438(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217d674(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217d87c(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217db4c(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217dcf0(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217de64(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217df08(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217e46c(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217e558(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217e870(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_0217eb28(struct Battle0217c908* battle, int arg1, int arg2);
extern "C" void func_ov000_02177038(struct Battle0217c908* battle, int mode, int kind, int arg1, int arg2);

struct Battle0217c908 {
    char pad0[0x118];
    int dirty;
    char pad1[0x188 - 0x11c];
    char entryList[KINDS_OFFSET - 0x188];
    signed char kinds[8];
    signed char kindIndex;
#if defined(jpn)
    char pad1fa1[0x1faa - 0x1fa1];
    unsigned short flags;
#endif
};

// USA: func_ov000_0217c908
extern "C" ARM void func_ov000_0217c908(struct Battle0217c908* battle, int arg1, int arg2) {
    if (func_ov000_0217f910(battle) == 0) {
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)battle->entryList, 1);
        return;
    }
    switch (battle->kinds[battle->kindIndex]) {
    case 1:
        func_ov000_0217cb5c(battle, arg1, arg2);
        break;
    case 2:
        func_ov000_0217ce24(battle, arg1, arg2);
        break;
    case 3:
        func_ov000_0217d324(battle, arg1, arg2);
        break;
    case 4:
        func_ov000_0217d438(battle, arg1, arg2);
        break;
    case 5:
        func_ov000_0217d674(battle, arg1, arg2);
        break;
    case 6:
        func_ov000_0217d87c(battle, arg1, arg2);
        break;
    case 7:
        func_ov000_0217db4c(battle, arg1, arg2);
        break;
    case 8:
        func_ov000_0217dcf0(battle, arg1, arg2);
        break;
    case 9:
        func_ov000_0217de64(battle, arg1, arg2);
        break;
    case 10:
        func_ov000_0217df08(battle, arg1, arg2);
        break;
    case 11:
        func_ov000_0217e46c(battle, arg1, arg2);
        break;
    case 23:
        func_ov000_0217e558(battle, arg1, arg2);
        break;
    case 25:
        func_ov000_0217e870(battle, arg1, arg2);
        break;
    case 12:
    case 32:
#if defined(jpn)
    case 31:
#endif
    case 41:
    case 42:
    case 43:
        func_ov000_0217eb28(battle, arg1, arg2);
        break;
    }
    if (func_ov000_0217f3e4(battle) != 0) {
        battle->dirty = 1;
    }
    func_ov000_02177038(battle, 0, battle->kinds[battle->kindIndex], arg1, arg2);
#if defined(jpn)
    if (TestFlag0SetAndFlag1Clear(data_02114e30, 0x2000) && battle->kinds[battle->kindIndex] != 1) {
        memset(battle->kinds, 0, 8);
        battle->kindIndex = 0;
        battle->kinds[battle->kindIndex] = 1;
        _Z32ClearBuffers0204b010OverList0x98P12Cont0205d1e0(battle->entryList);
        _Z28CallFunc0204b04cOverList0x98P12Cont0205d274(battle->entryList);
        _Z19InitEntries0205d2bcP11Obj0205d2bc(battle->entryList);
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)battle->entryList, 1);
        battle->flags |= 2;
    }
#endif
}
