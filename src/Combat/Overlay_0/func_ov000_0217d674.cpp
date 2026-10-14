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
#if defined(jpn)
    char elements[0x1f98 - 0x188];
#else
    char elements[0x1d60 - 0x188];
#endif
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

struct Struct_0205c570;
int GetActiveScaledSum0205d794(Struct_0205c570*);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
struct Entry_0205d6a0;
void ResetEntryList0205d6a0(Entry_0205d6a0*, int);
struct Struct0217f8c0;
struct TableEntry0217f8c0* FindMatchingTableEntry0217f8c0(Struct0217f8c0*);
int CheckFlagsOrField_0217c5f4_0217c5f4(void*);
int CountSetBitsLow12_0x68(void*);
struct Struct_0205d81c;
void SetElementStateIfLess0217a9d0(int, int, int, Struct_0205d81c*);
struct Struct_0205def8;
void SetElementFlag0x20ByKey0205def8(Struct_0205def8*, int, int);
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
    menu->activeSum = GetActiveScaledSum0205d794((Struct_0205c570*)menu->elements);
    if (func_ov000_0217c594(menu, 0) != 0) {
        DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
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
        func_ov000_02176634(menu, FindMatchingTableEntry0217f8c0((Struct0217f8c0*)menu), 6, arg1, arg2);
        SetElementStateIfLess0217a9d0(6, CountSetBitsLow12_0x68(menu), 4, (Struct_0205d81c*)menu->elements);
        SetElementFlag0x20ByKey0205def8((Struct_0205def8*)menu->elements, 0, 1);
        SetElementFlag0x20ByKey0205def8((Struct_0205def8*)menu->elements, 0, 2);
        SetElementFlag0x20ByKey0205def8((Struct_0205def8*)menu->elements, 0, 5);
    } else if (CheckFlagsOrField_0217c5f4_0217c5f4(menu) != 0) {
        ResetEntryList0205d6a0((Entry_0205d6a0*)menu->elements, 0);
        menu->modeStack[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        func_ov000_0217c638(menu, arg1, arg2);
    }
}
