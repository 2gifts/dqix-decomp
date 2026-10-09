#include <globaldefs.h>

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
    char entryList[0x1d60 - 0x188];
    signed char kinds[8];
    signed char kindIndex;
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
}
