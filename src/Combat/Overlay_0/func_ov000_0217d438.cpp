#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_0205c570;
struct Obj0205eaa0;
struct Entry_0205d6a0;

struct PartyData0217d438 {
    char pad0[0x94c];
    int field94c;
};

struct Entry0217d438 {
    char pad0[0x24];
    unsigned char field24;
    char pad25[0x4c - 0x25];
    int memberIndex;
    char pad50[0x448 - 0x50];
};

struct Menu0217d438 {
    char pad0[0x188];
    char elements[0x958 - 0x188];
    struct Entry0217d438 entries[4];
    char pad1A78[0x1d60 - 0x1a78];
    unsigned char stack[8];
    signed char depth;
    char pad1D69[0x1d6b - 0x1d69];
    signed char selection;
    signed char field1D6C;
    char pad1D6D[0x1d72 - 0x1d6d];
    unsigned short flags;
    signed char members[4];
};

extern "C" int _Z26GetActiveScaledSum0205d794P15Struct_0205c570(struct Struct_0205c570* s);
extern "C" void _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(struct Obj0205eaa0* obj, int a, int b);
extern "C" void _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i(struct Entry_0205d6a0* a, int flag);
extern "C" int _Z35CheckFlagsOrField_0217c5f4_0217c5f4Pv(void* objRaw);
extern "C" int func_ov000_0217c594(void* objRaw, int limit);
extern "C" void func_ov000_0217c638(void* obj, int arg1, int arg2);
extern "C" void* func_ov000_02161318(void* obj, int index);
struct PartyData0217d438* GetFieldAt0x150(unsigned char* obj);
extern "C" void func_ov000_02170ffc(void* obj);
int ApplyElemFieldsSlot3(void* obj);
extern "C" void func_ov017_021c847c();
extern "C" void func_ov000_0217fa60(void* obj);
extern "C" void func_ov000_02174c14(void* obj);
extern struct Obj0205eaa0 data_02108760;

static inline int IsPartyIndex(signed char index) {
    return index >= 0 && index <= 3;
}

// USA: func_ov000_0217d438
extern "C" ARM void func_ov000_0217d438(struct Menu0217d438* menu, int arg1, int arg2) {
    menu->flags |= 0x100;
    menu->field1D6C = _Z26GetActiveScaledSum0205d794P15Struct_0205c570((struct Struct_0205c570*)menu->elements);
    if (func_ov000_0217c594(menu, 0) != 0) {
        _Z28DispatchWithShortB4_0205eaa0P11Obj0205eaa0ii(&data_02108760, 1, 0);
        GameState* gs = GameState::GetInstance();
        menu->flags |= 0x100;
        signed char member = menu->members[menu->selection];
        if (IsPartyIndex(member)) {
            void* entry = func_ov000_02161318(menu, member);
            if (entry != NULL) {
                GameObject* obj = gs->GetPartyMemberByIndex(member);
                if (obj != NULL) {
                    struct PartyData0217d438* data = GetFieldAt0x150((unsigned char*)obj);
                    if ((signed char)data->field94c != menu->field1D6C) {
                        data->field94c = menu->field1D6C;
                        func_ov000_02170ffc(entry);
                        ApplyElemFieldsSlot3(menu);
                    }
                }
            }
        } else {
            struct Entry0217d438* entry;
            for (int i = 0; i < 4; i++) {
                entry = &menu->entries[i];
                GameObject* obj = gs->GetPartyMemberByIndex(entry->memberIndex);
                if (obj == NULL) {
                    continue;
                }
                if (entry->field24 & 2) {
                    continue;
                }
                if (!(obj->obj3D_.unknown_0_ & 0x1000)) {
                    continue;
                }
                struct PartyData0217d438* data = GetFieldAt0x150((unsigned char*)obj);
                if ((signed char)data->field94c == menu->field1D6C) {
                    continue;
                }
                data->field94c = menu->field1D6C;
                func_ov000_02170ffc(entry);
            }
            func_ov017_021c847c();
            func_ov000_0217fa60(menu);
            func_ov000_02174c14(menu);
            return;
        }
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)menu->elements, 0);
        menu->stack[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        func_ov000_0217c638(menu, arg1, arg2);
        func_ov017_021c847c();
    } else if (_Z35CheckFlagsOrField_0217c5f4_0217c5f4Pv(menu) != 0) {
        _Z22ResetEntryList0205d6a0P14Entry_0205d6a0i((struct Entry_0205d6a0*)menu->elements, 0);
        menu->stack[menu->depth] = 0;
        menu->depth = menu->depth - 1;
        func_ov000_0217c638(menu, arg1, arg2);
    }
}
