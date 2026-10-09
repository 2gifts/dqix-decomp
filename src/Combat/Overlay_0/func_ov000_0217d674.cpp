#include <globaldefs.h>

struct ElemNode {
    char pad0[0x10];
    unsigned char marks[8];
    signed char markIndex;
};

struct MenuState {
    char pad0[0x68];
    int field_0x68;
    char pad6c[0x70 - 0x6c];
    signed char slotIds[0x17c - 0x70];
    int currentId;
    char pad180[0x188 - 0x180];
    char elements[0x1d60 - 0x188];
    unsigned char modeStack[8];
    signed char depth;
    char pad1d69[2];
    signed char activeSum;
    char pad1d6c[2];
    unsigned char field_0x1d6e;
    char pad1d6f[3];
    unsigned short flags;
};

struct Obj0205eaa0;
struct TableEntry0217f8c0;

extern struct Obj0205eaa0 data_02108760;

extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(void* elements);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(void* elements, int flag);
extern "C" struct TableEntry0217f8c0* _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0(MenuState* menu);
extern "C" int _Z35CheckFlagsOrField_0217c5f4_0217c5f4Pv(MenuState* menu);
extern "C" int _Z22CountSetBitsLow12_0x68Pv(MenuState* menu);
extern "C" void _Z29SetElementStateIfLess0217a9d0iiiP15Struct_0205d81c(int key, int count, int state, void* elements);
extern "C" void _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(void* elements, int clear, int key);
extern "C" int func_020dd3cc(int combatantId);
extern "C" int func_ov000_0217c594(MenuState* menu, int limit);
extern "C" int func_ov000_0217c514(int id, int value);
extern "C" ElemNode* func_ov000_02161318(MenuState* menu, int id);
extern "C" void func_ov000_02175258(MenuState* menu);
extern "C" void func_ov000_02176634(MenuState* menu, void* entry, int mode, int arg1, int arg2);
extern "C" void func_ov000_0217c638(MenuState* menu, int arg1, int arg2);

// USA: func_ov000_0217d674
extern "C" ARM void func_ov000_0217d674(MenuState* menu, int arg1, int arg2) {
    menu->flags |= 0x100;
    menu->activeSum = _Z26GetActiveScaledSum0205d794P15Struct_0205c570(menu->elements);
    if (func_ov000_0217c594(menu, 0) != 0) {
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
        int id = menu->slotIds[menu->activeSum];
        menu->field_0x1d6e = 0;
        menu->field_0x68 = func_020dd3cc(id);
        menu->field_0x68 = func_ov000_0217c514(id, menu->field_0x68);
        if (menu->field_0x68 == 0) {
            menu->depth = menu->depth + 1;
            menu->modeStack[menu->depth] = 0x2b;
            func_ov000_02176634(menu, func_ov000_02161318(menu, menu->currentId), 0x2b, arg1, arg2);
            return;
        }
        menu->currentId = id;
        ElemNode* node = func_ov000_02161318(menu, id);
        if (node == NULL) {
            return;
        }
        node->marks[node->markIndex] = 1;
        func_ov000_02175258(menu);
        menu->depth = menu->depth + 1;
        menu->modeStack[menu->depth] = 6;
        func_ov000_02176634(menu, _Z30FindMatchingTableEntry0217f8c0P14Struct0217f8c0(menu), 6, arg1, arg2);
        _Z29SetElementStateIfLess0217a9d0iiiP15Struct_0205d81c(6, _Z22CountSetBitsLow12_0x68Pv(menu), 4, menu->elements);
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(menu->elements, 0, 1);
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(menu->elements, 0, 2);
        _Z31SetElementFlag0x20ByKey0205def8P15Struct_0205def8ii(menu->elements, 0, 5);
    } else if (_Z35CheckFlagsOrField_0217c5f4_0217c5f4Pv(menu) != 0) {
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(menu->elements, 0);
        menu->modeStack[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        func_ov000_0217c638(menu, arg1, arg2);
    }
}
