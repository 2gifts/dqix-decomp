#include <globaldefs.h>
#include "GameState/GameState.h"
#include "World/ZoneResourceTree.h"

struct SearchStruct;
struct SearchStruct0202c1a4;
struct Entry0207da94;
struct Entry020e3544;
struct BitEntry020e3b08;
struct Obj0207959c;
struct ClearField0x17dBits0x38Struct;

extern "C" SearchStruct* func_0202ae18(void);
extern "C" void func_0207dba8(void* p);
extern "C" void func_ov017_02190264(void* self, int id);
extern "C" void func_ov000_0215fb04(void* stack, int id);
extern "C" void func_ov017_02192654(int bit, int id, int cond);
extern "C" void* func_ov017_021b8468(void* obj);
extern "C" void VectorizedMemset(void* dst, int value, unsigned int size);

signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);
unsigned char GetField0x397cValue(GameState* battleStruct);
int GetField0x3acValue(GameState* battleStruct);
extern "C" void _Z26ClearSearchFlagBit0202c600P12SearchStructi(SearchStruct* obj, int value);
extern "C" void _Z26ClearSearchFlagBit0202c718P12SearchStructi(SearchStruct* obj, int value);
extern "C" void _Z25RemoveSearchEntry0202c21cP12SearchStructi(SearchStruct* obj, int value);
Entry0207da94* GetData02108ea8(void);
extern "C" void _Z28ClearByteField17201_0218d500Pv(void* obj);
extern "C" void _Z22ProcessEntries0207da94P13Entry0207da94i(Entry0207da94* list, int idx);
Entry020e3544* GetData02153637(void);
extern "C" void _Z28ClearMatchingEntries020e3544P13Entry020e3544i(Entry020e3544* p, int id);
BitEntry020e3b08* GetData02153660(void);
void ClearBitInEntries(BitEntry020e3b08* entries, int bit);
extern "C" int _Z37CheckField0x17dBits4And5Equal0207959cP11Obj0207959ci(Obj0207959c* obj, int mode);
void ClearField0x17dBits0x38(ClearField0x17dBits0x38Struct* s);
extern "C" void* _Z20GetField6b0_021b8470Pv(void* obj);
extern "C" unsigned short _Z20GetField6b4_021b8480Pv(void* obj);

struct Slot_021905b8 {
    char data[6];
    signed char owner;
    unsigned char f7;
    unsigned char f8;
    signed char f9;
};

struct Monster_021905b8 {
    char pad0[0x16a];
    unsigned short id;
};

struct Zone_021905b8 {
    char pad0[2];
    unsigned char active;
};

struct ZoneSlot_021905b8 {
    char pad0[8];
    unsigned short id;
};

struct ZoneState_021905b8 {
#if defined(jpn)
    char pad0[0xe24];
#else
    char pad0[0xea8];
#endif
    int state;
};

// JPN: func_ov017_0219119c
// USA: func_ov017_021905b8
extern "C" ARM void func_ov017_021905b8(GameResources* self, int id, int remove) {
    GameState* gs = GameState::GetInstance();
    SearchStruct* search = func_0202ae18();
    if (id <= 0) {
        return;
    }
    if (id == GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search) || id == GetField0x397cValue(gs) ||
        id == GetField0x3acValue(gs)) {
        _Z26ClearSearchFlagBit0202c600P12SearchStructi(search, id);
        _Z26ClearSearchFlagBit0202c718P12SearchStructi(search, id);
        return;
    }

    Entry0207da94* entries = GetData02108ea8();
    func_0207dba8(entries);
    _Z28ClearByteField17201_0218d500Pv(self);
    _Z26ClearSearchFlagBit0202c600P12SearchStructi(search, id);
    _Z26ClearSearchFlagBit0202c718P12SearchStructi(search, id);
    if (remove) {
        _Z25RemoveSearchEntry0202c21cP12SearchStructi(search, id);
    }
    func_ov017_02190264(self, id);
    _Z22ProcessEntries0207da94P13Entry0207da94i(entries, (unsigned char)id);

#if defined(jpn)
    Slot_021905b8* slot = (Slot_021905b8*)((char*)gs + 0x7280);
#else
    Slot_021905b8* slot = (Slot_021905b8*)((char*)gs + 0x74c0);
#endif
    for (int i = 0; i < 3; i++, slot++) {
        if (slot->owner == id) {
            VectorizedMemset(slot, 0, 6);
            slot->owner = -1;
            slot->f7 = 0;
            slot->f8 = 0;
            slot->f9 = -1;
            break;
        }
    }

    _Z28ClearMatchingEntries020e3544P13Entry020e3544i(GetData02153637(), id);

    Zone_021905b8* zone = (Zone_021905b8*)self->unknown_ptr_3718;
    if (zone->active != 0) {
        void* stack = _Z20GetField6b0_021b8470Pv(zone);
        if (stack != NULL) {
            func_ov000_0215fb04(stack, id);
        }
    }

    for (int i = 0; i < 0x30; i++) {
        Monster_021905b8* mon = (Monster_021905b8*)gs->GetMaybeFieldMonsterByIndex(i + 0x70);
        if (mon != NULL && _Z37CheckField0x17dBits4And5Equal0207959cP11Obj0207959ci((Obj0207959c*)mon, id)) {
            int cond;
            Zone_021905b8* z = (Zone_021905b8*)self->unknown_ptr_3718;
            cond = 1;
            if (z->active != 0 && _Z20GetField6b4_021b8480Pv(z) == 0) {
                ZoneSlot_021905b8* zs = (ZoneSlot_021905b8*)func_ov017_021b8478(z);
                if (zs != NULL && zs->id == mon->id) {
                    ZoneState_021905b8* st = (ZoneState_021905b8*)func_ov017_021b8468(z);
                    if (st != NULL && st->state == 7) {
                        cond = 0;
                    }
                }
            }
            func_ov017_02192654(GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search), mon->id, cond);
            ClearField0x17dBits0x38((ClearField0x17dBits0x38Struct*)mon);
        }
    }

    ClearBitInEntries(GetData02153660(), id);
}
