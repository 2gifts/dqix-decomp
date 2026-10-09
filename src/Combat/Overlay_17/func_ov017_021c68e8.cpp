#include <globaldefs.h>
#include "GameState/GameState.h"

struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);

extern "C" void* func_ov017_021b8478(void* obj);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void* _Z20GetField6b0_021b8470Pv(void* obj);
void SetByteField0x43eOnEntry(void* self, int index, unsigned char value);
GameObject* GetCombatantWithFlag0x1000(GameState* battleStruct, int combatantId);
int GetFieldAt0x150(unsigned char* obj);
void SetBoundedArrayField0x4f4(char* self, int index, int value);

struct StructAt3c_02162aac {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    signed char f4;
    char pad5;
    short f6;
    unsigned short f8;
};

extern "C" void _Z29ProcessCombatantSlot_02162aacPviP19StructAt3c_02162aac(void* self, int a, struct StructAt3c_02162aac* s);

struct Hdr021c68e8 {
    unsigned char pad0[8];
    unsigned short field8;
};

struct Evt021c68e8 {
    unsigned char pad0[4];
    unsigned short field4;
    unsigned short combatantId;
    short field8;
    unsigned short fielda;
    signed char fieldc;
    unsigned char fieldd;
    unsigned char fielde;
    unsigned char fieldf;
    unsigned char field10;
    unsigned char flag0 : 1;
    unsigned char flag1 : 1;
    unsigned char index : 6;
    signed char field12;
};

// USA: func_ov017_021c68e8
extern "C" ARM void func_ov017_021c68e8(int unused0, Evt021c68e8* evt, GameState* battleStruct, unsigned char* base, struct SearchStruct0202c1a4* search) {
    void* table = *(void**)(base + 0x3000 + 0x718);
    Hdr021c68e8* a = (Hdr021c68e8*)func_ov017_021b8478(table);
    if (!a) return;
    void* b = func_ov017_021b8468(table);
    if (!b) return;
    void* work = _Z20GetField6b0_021b8470Pv(table);
    if (!work) return;
    if (a->field8 != evt->field4) return;

    if (evt->field12 > -1 && evt->field12 != GetSearchStructCurrentArrEntry(search)) {
        if (evt->flag1) {
            SetByteField0x43eOnEntry(b, (signed char)evt->combatantId, 1);
        }
        return;
    }

    struct StructAt3c_02162aac s;
    int ok = 1;
    s.f0 = evt->fieldd;
    s.f1 = evt->fielde;
    s.f2 = evt->fieldf;
    s.f3 = evt->field10;
    s.f6 = evt->field8;
    s.f4 = evt->fieldc;
    s.f8 = evt->fielda;

    if (s.f1 != 6 && s.f0 != 0xd) {
        if (GetCombatantWithFlag0x1000(battleStruct, evt->combatantId) != NULL) {
            GameObject* c = GetCombatantWithFlag0x100(battleStruct, evt->combatantId);
            if (c != NULL) {
                int field = GetFieldAt0x150((unsigned char*)c);
                if (field != 0) {
                    ok = (signed char)*(int*)(field + 0x94c) == 5;
                }
            }
        }
    }

    if (ok) {
        _Z29ProcessCombatantSlot_02162aacPviP19StructAt3c_02162aac(b, evt->combatantId, &s);
    }
    SetBoundedArrayField0x4f4((char*)b, (signed char)evt->index, evt->flag0 ? 1 : 0);
    if (evt->flag1) {
        SetByteField0x43eOnEntry(b, (signed char)evt->combatantId, 1);
    }
}
