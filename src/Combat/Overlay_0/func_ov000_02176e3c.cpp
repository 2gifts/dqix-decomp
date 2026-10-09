#include <globaldefs.h>

struct Struct_0205d81c;

struct Elem_0205d81c {
    char pad0[0xc5];
    unsigned char flags;
};

struct BattleMenu {
    char pad0[0x118];
    int mode;
    char pad11c[0x188 - 0x11c];
    char elements[1];
};

extern "C" Elem_0205d81c* _Z23FindElementByC40205d81cP15Struct_0205d81ci(Struct_0205d81c* list, int key);
extern "C" void _Z20ApplyElemFieldsSlot1Pv(BattleMenu* menu);
extern "C" void _Z20ApplyElemFieldsSlot2Pv(BattleMenu* menu);
extern "C" void _Z20ApplyElemFieldsSlot3Pv(BattleMenu* menu);
extern "C" void _Z20ApplyElemFieldsSlot4Pv(BattleMenu* menu);
extern "C" void _Z20ApplyElemFieldsSlot5Pv(BattleMenu* menu);
extern "C" void _Z20ApplyElemFieldsSlot6Pv(BattleMenu* menu);
extern "C" void _Z29ApplyElemFieldsSlot7_0217819cPv(BattleMenu* menu);
extern "C" void _Z20ApplyElemFieldsSlot8Pv(BattleMenu* menu);
extern "C" int _Z18IsField0x118Equal2Pv(BattleMenu* menu);
extern "C" void _Z38RunElemFieldsIfField_02176498_02176498Pvi(void* obj, int flag);
extern "C" void _Z30ApplyElemFieldsSlot14_021788d8Pvii(BattleMenu* menu, int a, int b);
extern "C" void _Z21ApplyElemFieldsSlot15Pv(BattleMenu* menu, int a, int b);
extern "C" void _Z21ApplyElemFieldsSlot16Pv(BattleMenu* menu, int a, int b);
extern "C" void _Z21ApplyElemFieldsSlot17Pv(BattleMenu* menu, int a, int b);
extern "C" void _Z30ApplyElemFieldsSlot18_02179a14Pvii(BattleMenu* menu, int a, int b);
extern "C" void _Z30ApplyElemFieldsSlot21_02179c6cPvi(BattleMenu* menu, int a);
extern "C" void func_ov000_0217a0a4(BattleMenu* menu, int a);
extern "C" void _Z30ApplyElemFieldsSlot19_0217a628Pvii(BattleMenu* menu, int a, int b);

// USA: func_ov000_02176e3c
extern "C" ARM void func_ov000_02176e3c(BattleMenu* menu, int arg, int slot, int arg2, int arg3, unsigned char highlight) {
    Elem_0205d81c* elem = _Z23FindElementByC40205d81cP15Struct_0205d81ci(
        (Struct_0205d81c*)menu->elements, (unsigned char)slot);
    if (elem == 0) {
        return;
    }
    int savedMode = menu->mode;
    int alt = (elem->flags & 2) ? 1 : 0;
    menu->mode = 1;
    if (alt) {
        menu->mode = 2;
    }
    if (highlight) {
        elem->flags |= 0x40;
    } else {
        elem->flags &= ~0x40;
    }
    switch (slot) {
    case 1:
        _Z20ApplyElemFieldsSlot1Pv(menu);
        break;
    case 2:
        _Z20ApplyElemFieldsSlot2Pv(menu);
        break;
    case 3:
        _Z20ApplyElemFieldsSlot3Pv(menu);
        break;
    case 4:
        _Z20ApplyElemFieldsSlot4Pv(menu);
        break;
    case 5:
        _Z20ApplyElemFieldsSlot5Pv(menu);
        break;
    case 6:
        _Z20ApplyElemFieldsSlot6Pv(menu);
        break;
    case 7:
        _Z29ApplyElemFieldsSlot7_0217819cPv(menu);
        break;
    case 8:
        _Z20ApplyElemFieldsSlot8Pv(menu);
        break;
    case 13:
        if (arg != 0) {
            _Z38RunElemFieldsIfField_02176498_02176498Pvi((void*)arg, _Z18IsField0x118Equal2Pv(menu));
        }
        break;
    case 14:
        _Z30ApplyElemFieldsSlot14_021788d8Pvii(menu, arg, arg3);
        break;
    case 15:
        _Z21ApplyElemFieldsSlot15Pv(menu, arg2, arg3);
        break;
    case 16:
        _Z21ApplyElemFieldsSlot16Pv(menu, arg2, arg3);
        break;
    case 17:
        _Z21ApplyElemFieldsSlot17Pv(menu, arg2, arg3);
        break;
    case 18:
    case 19:
    case 20:
        _Z30ApplyElemFieldsSlot18_02179a14Pvii(menu, arg, arg2);
        break;
    case 21:
        _Z30ApplyElemFieldsSlot21_02179c6cPvi(menu, arg);
        break;
    case 23:
        func_ov000_0217a0a4(menu, arg);
        break;
    case 25:
        _Z30ApplyElemFieldsSlot19_0217a628Pvii(menu, arg, arg3);
        break;
    }
    menu->mode = savedMode;
}
