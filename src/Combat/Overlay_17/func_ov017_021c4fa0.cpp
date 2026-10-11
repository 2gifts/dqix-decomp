#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"
#include "World/ZoneResourceTree.h"

extern "C" void* func_0202ae18(void);
extern "C" unsigned short* func_02012fe4(void);
extern "C" int func_0202c508(void* search);
extern "C" void func_0205e330(void* a, void* b, int c);
extern "C" void* memset(void* dst, int c, unsigned int n);
void* GetData02100044(void);

struct Entry_02028bd0 {
    unsigned short id;
    unsigned short unk2_0 : 4;
    unsigned short value : 12;
    unsigned short value2;
};
struct Entry_02028bd0* GetEntryTableBase(void);
struct Entry_02028bd0* FindInlineEntryById(struct Entry_02028bd0* base, int key);

struct Obj_021bd3a4;
extern "C" int _Z29HasFlag3orFlag2And9a_021bd3a4P12Obj_021bd3a4(Obj_021bd3a4* obj);
int TestBitAt0x34(unsigned char* obj, unsigned int index);
extern "C" void* _Z20GetField6b0_021b8470Pv(void* obj);
extern "C" int _Z28GetField6acThenCall_021b8b94Pv(void* obj);

struct Unit_021c4fa0 {
    char pad0[8];
    unsigned short field8;
    char padA[8];
    unsigned char field12;
    char pad13[5];
    unsigned short field18;
    unsigned short field1a;
    unsigned short field1c;
    char pad1e[0x32];
    unsigned short flags50;
    short field52;
#if defined(jpn)
    char pad54[0xae];
#else
    char pad54[0xb2];
#endif
    unsigned char field106;
};

struct Zone_021c4fa0 {
    char pad0[2];
    unsigned char active;
};

struct Slot_021c4fa0 {
    char pad0[0xc];
    int index;
};

struct IdValue_021c4fa0 {
    unsigned short id;
    unsigned short value;
};

struct Payload_021c4fa0 {
    unsigned char unitIdx;
    unsigned char mode;
    unsigned short field2;
    short field4;
    float time;
    unsigned short fieldC;
    unsigned short fieldE;
};

struct Evt_021c4fa0 {
    unsigned char tag;
    struct Payload_021c4fa0 payload;
};

// JPN: func_ov017_021c546c
// USA: func_ov017_021c4fa0
extern "C" ARM void func_ov017_021c4fa0(int unitIdx, int id) {
    GameState* gs;
    unsigned short* cur;
    void* data;
    char* f6b0;
    GameResources* res;
    Payload_021c4fa0* p;
    Slot_021c4fa0* slot;
    Unit_021c4fa0* unit;
    void* search;
    Zone_021c4fa0* zone;
    int ok;
    Entry_02028bd0* entry;
    IdValue_021c4fa0* iv;
    Evt_021c4fa0 evt;

    gs = GameState::GetInstance();
    search = func_0202ae18();
    cur = func_02012fe4();
    res = func_ov017_0218b5b0();
    unit = (Unit_021c4fa0*)res->unknown_ptr_array_371c[6];
    GetEntryTableBase();
    data = GetData02100044();

    evt.tag = 0x8f;
    p = &evt.payload;
    memset(p, 0, sizeof(*p));
    p->mode = 0;
    p->unitIdx = unitIdx;
    p->time = -1.0f;

    zone = (Zone_021c4fa0*)res->unknown_ptr_3718;
    f6b0 = (char*)_Z20GetField6b0_021b8470Pv(zone);
    slot = (Slot_021c4fa0*)func_ov017_021b8478(zone);

    if (func_0202c508(search)) {
        ok = 1;
        if (unit->field1a != id || (unit->flags50 & 0x800)) {
            if (unit->field1c != id) {
                ok = 0;
            }
        }
        if (_Z29HasFlag3orFlag2And9a_021bd3a4P12Obj_021bd3a4((Obj_021bd3a4*)unit) && unit->field12 != 0 && unit->field106 == 0 && ok) {
            p->mode = 1;
            if (unit->field18 == 0) {
                p->field2 = unit->field8;
                p->field4 = unit->field52;
            } else {
                p->field2 = unit->field18;
                p->field4 = unit->field52;
            }
        } else if (zone->active != 0 && !(f6b0 != NULL && f6b0[0x8e14] != 0) && slot != NULL &&
                   !TestBitAt0x34((unsigned char*)slot, unitIdx & 0xff) && !_Z28GetField6acThenCall_021b8b94Pv(zone) && slot->index >= 0) {
            p->mode = 2;
            p->field2 = slot->index;
            p->field4 = *cur;
        }

        p->time = gs->GetDayTimer();
        entry = FindInlineEntryById(GetEntryTableBase(), id);
        if (entry != NULL) {
            p->fieldC = entry->value;
            p->fieldE = entry->value2;
        } else {
#if defined(jpn)
            iv = (IdValue_021c4fa0*)((char*)res + 0x4204);
#else
            iv = (IdValue_021c4fa0*)((char*)res + 0x44b4);
#endif
            if (iv->id == id) {
                p->fieldC = iv->value;
            } else {
                p->fieldC = 0;
            }
            p->fieldE = 0;
        }
    }
    func_0205e330(data, &evt, 0);
}
