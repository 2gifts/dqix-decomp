#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

int CheckFlag0x14Bit0Clear(unsigned char* obj);
struct StateWrapObj020886dc;
struct StateWrapObj02088724;
struct StateWrapObj0208876c;
struct StateWrapObj020887b4;
void SetCombatantState1(struct StateWrapObj020886dc* obj);
void SetCombatantState2(struct StateWrapObj02088724* obj);
void SetCombatantState3(struct StateWrapObj0208876c* obj);
void SetCombatantState4(struct StateWrapObj020887b4* obj);
void SetFlag0x80AndState5(unsigned char* obj);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" void* func_ov000_0215e958(void* a0);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* objRaw, void* listRaw, int c);
extern "C" void func_ov000_0215cd44(void* a, void* b, void* c, int d, int e, int f, int g);

struct PackedPair_021dff3c {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Flag_021dff3c { unsigned char pad : 7; unsigned char flag : 1; };
struct Obj_021dff3c { char pad0[0xc]; void* field0xc; void* field0x10; };
struct Range_021dff3c {
    char pad[0x20];
    struct PackedPair_021dff3c f20;
    struct PackedPair_021dff3c f24;
    char pad28[0x30 - 0x28];
    short state;
};

// USA: func_ov024_021dff3c
extern "C" ARM void* func_ov024_021dff3c(struct Obj_021dff3c* obj, int unused, int id, struct Range_021dff3c* range, int unused2, int unused3, unsigned char flagArg) {
    GameObject* c = GetCombatantByID((int)obj->field0x10, id);
    if (!c) return 0;
    unsigned short sel;
    if (range->state > 0) {
        if (CheckFlag0x14Bit0Clear((unsigned char*)c->currentStats_) && flagArg != 0) {
            sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f20.c, range->f24.a);
            switch (range->state) {
                case 1:
                    SetCombatantState1((struct StateWrapObj020886dc*)c->currentStats_);
                    break;
                case 2:
                    SetCombatantState2((struct StateWrapObj02088724*)c->currentStats_);
                    break;
                case 3:
                    SetCombatantState3((struct StateWrapObj0208876c*)c->currentStats_);
                    break;
                case 4:
                    SetCombatantState4((struct StateWrapObj020887b4*)c->currentStats_);
                    break;
                case 5:
                    SetFlag0x80AndState5((unsigned char*)c->currentStats_);
                    break;
            }
        } else {
            sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f24.b, range->f24.c);
        }
    } else {
        sel = _Z31SelectByIndexRange0to3_021da644iii(id, range->f24.b, range->f24.c);
    }
    void* entry = func_ov000_0215e958(obj->field0x10);
    if (!entry) return 0;
    _Z33AddEntryAndIncrementCount0215a88cPvS_i(obj->field0x10, entry, sel);
    struct Flag_021dff3c* fl = (struct Flag_021dff3c*)((char*)obj->field0xc + 0x1c);
    func_ov000_0215cd44(obj->field0x10, entry, c, 0, 0, 0, fl->flag != 0);
    return entry;
}
