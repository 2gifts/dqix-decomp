#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"

struct ArrayContainsByteStruct;
struct ListHead02046b60;
struct BitFlags020d805c;
struct StoreStruct;
struct T02053fe4;
struct Obj_021d35f8 { unsigned char b0; unsigned short h2; unsigned char b4; };

struct Val021d2d64 {
    short lo : 11;
    short hi : 5;
};

struct Entry021d2d64 {
    unsigned char kind;
    unsigned char type;
    unsigned char sub;
    signed char f3;
    signed char ids[3];
    signed char count;
    Val021d2d64 vals[3];
    signed char fe;
};

struct Msg021d2d64 {
    char pad0[4];
    Entry021d2d64 entry;
};

struct Leader021d2d64 {
    Object3D obj;
    short fac;
};

struct Reset021d2d64 {
    char pad0[0x150];
    unsigned char state : 6;
};

struct Flags021d2d64 {
    char pad0[0x59f];
    unsigned char flags;
};

struct Owner021d2d64 {
    char pad0[0x1c];
    Flags021d2d64* flags;
};

struct Revive021d2d64 {
    char pad0[0x64];
    int busy;
};

struct Msgs021d2d64 {
    short v[2];
};

struct MsgTable021d2d64 {
    char pad0[0x18];
    Msgs021d2d64 msgs;
};

int GetField0x3acValue(GameState* gs);
void* GetPtrField0x2a04(GameState* gameState);
extern "C" void func_ov017_021d2d00(void* dst, void* src);
void ClearFields0_2_4_021d35f8(Obj_021d35f8* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);
int ArrayContainsByte(ArrayContainsByteStruct* s, int val);
int ListContainsId(ListHead02046b60* list, int id);
void* GetGlobalResetObj020d7a50(void);
int IsField0Null(void** obj);
int CheckSubstructByte0x7cPositive(signed char* obj);
int GetGlobalField0x1c020421a0(void);
int GetByte0x150Bit6(BitFlags020d805c* obj);
extern "C" int _Z31TestFlagBit55dIfActive_0218b628i(signed char bit);
extern "C" void func_ov017_0218b5c0(int set, signed char bit);
extern "C" void _Z32SetIndexedFieldsIfValid_02191ba0Pcit(char* res, int id, int value);
void InitContext020e1154(void* obj);
int TryClearFlags0x130(unsigned char* obj, unsigned short flag);
extern "C" void func_ov017_021c9e00(int id, int a, int b, int c);
extern "C" void __clear(void* dst, unsigned int size);
int ComputeAndApplyWithCounter020e04f4(int p0, void* p1, int p2, int p3, unsigned char p4, int p5);
extern "C" void func_02046380(void* g);
void Clear12Bytes020e46c4(void* p);
void InitObjFromCombatantId020e4bf4(void* obj, int combatantId);
void SetByteInRange(unsigned char* base, int index, unsigned char value);
void StoreInArray0x8b0(StoreStruct* base, int index, int value);
extern "C" void func_02046608(void* g, int mode, char* fmt, char* out, int size, int a, int b);
extern "C" void func_020d7e10(void* receiver, void* input, int style, int flag, int a, int b);
void EnqueueEventTag37_021d2cc0(void* src);
void CallHelperIfFlag_021a5a88(int a, int b, int c, int d, unsigned char e);

extern const MsgTable021d2d64 data_ov017_021d6ce8;
extern char data_ov017_021d8298[];
extern char data_ov017_021d8288[];

// USA: func_ov017_021d2d64
extern "C" ARM void func_ov017_021d2d64(void* unused, Msg021d2d64* msg, GameState* gs, GameResources* res) {
    void* g;
    int v3ac;
    ArrayContainsByteStruct* party;
    Reset021d2d64* reset;
    int saved;
    ListHead02046b60* list;
    short msgId;
    Entry021d2d64* entry = &msg->entry;
    v3ac = GetField0x3acValue(gs);
    party = (ArrayContainsByteStruct*)GetPtrField0x2a04(gs);
    Entry021d2d64 local;
    Obj_021d35f8 slotsA[4];
    Obj_021d35f8 slotsB[4];
    func_ov017_021d2d00(&local, entry);
    unsigned char count = local.count;
    signed char* ids = local.ids;
    for (int i = 0; i < 4; i++) {
        ClearFields0_2_4_021d35f8(&slotsA[i]);
        ClearFields0_2_4_021d35f8(&slotsB[i]);
    }
    int hud = (int)res->unknown_ptr_array_371c[0];

    switch (entry->kind) {
    case 1: {
        local.count = 0;
        memset(local.ids, 0, 3);
        memset(local.vals, 0, 6);
        signed char n = 0;
        for (int i = 0; i < entry->count; i++) {
            int id = entry->ids[i];
            if (ArrayContainsByte(party, id) != 0) {
                local.ids[n] = id;
                Val021d2d64* d = &local.vals[n];
                d->lo = entry->vals[i].lo;
                d->hi = entry->vals[i].hi;
                n++;
            }
        }
        local.count = n;
        if (local.count == 0) {
            return;
        }

        list = (ListHead02046b60*)res->unknown_ptr_array_36fc[0];
        int ok = 1;
        if (ListContainsId(list, 10)) ok = 0;
        if (ListContainsId(list, 3)) ok = 0;
        if (ListContainsId(list, 0x27)) ok = 0;
        if (ListContainsId(list, 0x10) && ((Owner021d2d64*)res->unknown_ptr_array_371c[4])->flags != 0 &&
            (((Owner021d2d64*)res->unknown_ptr_array_371c[4])->flags->flags & 4)) {
            ok = 0;
        }

        if (ok) {
            reset = (Reset021d2d64*)GetGlobalResetObj020d7a50();
            ok = 1;
            if (IsField0Null((void**)list) == 0) ok = 0;
            if (ListContainsId(list, 0x1a)) ok = 1;
            GameObject* leader = gs->GetUnknownGameObject();
            if (leader != 0 && CheckSubstructByte0x7cPositive((signed char*)leader)) ok = 0;
            if (*(int*)(GetGlobalField0x1c020421a0() + 0x998) != 0 && GetByte0x150Bit6((BitFlags020d805c*)reset) == 0) ok = 0;

            for (int i = 0; i < local.count; i++) {
                if (reset->state >= 3) ok = 0;
                int id = local.ids[i];
                Msgs021d2d64 msgs = data_ov017_021d6ce8.msgs;
                GameObject* unit = GetCombatantWithFlag0x100(gs, id);
                if (unit == 0) continue;
                saved = _Z31TestFlagBit55dIfActive_0218b628i(id);
                if (ok) func_ov017_0218b5c0(0, id);
                Val021d2d64* v = &local.vals[i];
                int shown = 0;
                if (local.type == 1) {
                    int max = unit->baseStats_->primaryStats.maxHP;
                    int value = unit->combatFields_.savedState_130_->hp;
                    int sum = value + v->lo;
                    int delta;
                    if (sum >= max) {
                        delta = max - value;
                    } else {
                        delta = sum - value;
                    }
                    unit->combatFields_.savedState_130_->hp = value + delta;
                    v->lo = delta;
                    if (delta > 0) {
                        msgs.v[0] = 0x232c;
                        shown = 1;
                    }
                } else if (local.type == 2) {
                    int max = unit->baseStats_->primaryStats.maxMP;
                    int value = unit->combatFields_.savedState_130_->mp;
                    int sum = value + v->lo;
                    int delta;
                    if (sum >= max) {
                        delta = max - value;
                    } else {
                        delta = sum - value;
                    }
                    unit->combatFields_.savedState_130_->mp = value + delta;
                    v->lo = delta;
                    if (delta > 0) {
                        msgs.v[0] = 0x795f;
                        shown = 1;
                    }
                } else if (local.type == 4) {
                    int canRevive = 1;
                    if (ListContainsId(list, 0x1a) && ((Revive021d2d64*)res->unknown_ptr_array_3afc[4])->busy != 0) {
                        canRevive = 0;
                    }
                    if ((int)unit->combatFields_.savedState_130_->hp > 0 || v->lo == 0 || canRevive == 0) {
                        v->lo = 0;
                    } else {
                        Leader021d2d64* l = (Leader021d2d64*)gs->GetUnknownGameObject();
                        if (l != 0 && (l->fac != 0 || l->obj.GetFlag(0x8000000) != 0)) {
                            _Z32SetIndexedFieldsIfValid_02191ba0Pcit((char*)res, id, v->lo);
                            shown = 0;
                        } else {
                            ClearFieldBit02053fe4(unit, v->lo, 1);
                            if (unit->baseStats_->primaryStats.maxHP < v->lo) {
                                v->lo = unit->baseStats_->primaryStats.maxHP;
                            }
                            shown = 1;
                            if (ListContainsId(list, 0x1a)) {
                                InitContext020e1154((void*)0x1f4);
                            }
                            msgs.v[0] = 0x7955;
                        }
                    }
                } else if (local.type == 3) {
                    if (TryClearFlags0x130((unsigned char*)unit, 2) == 0) {
                        v->lo = 0;
                    } else {
                        v->lo = 1;
                        msgs.v[0] = 0x794b;
                        shown = 1;
                    }
                }
                if (local.sub == 3) {
                    if (TryClearFlags0x130((unsigned char*)unit, 2) == 0) {
                        v->hi = 0;
                    } else {
                        v->hi = 1;
                        msgs.v[1] = 0x794b;
                        shown = 1;
                    }
                }
                if (shown) {
                    func_ov017_021c9e00(id, 0, 0, 1);
                }
                if (ok) {
                    for (int k = 0; k < 2; k++) {
                        if (reset->state >= 3) continue;
                        g = (void*)GetGlobalField0x1c020421a0();
                        msgId = msgs.v[k];
                        if (msgId < 0) continue;
                        char text[0x100];
                        __clear(text, 0x100);
                        ComputeAndApplyWithCounter020e04f4((int)text, data_ov017_021d8288, msgId, 0, 1, (int)data_ov017_021d8298);
                        func_02046380(g);
                        char who[0xc];
                        Clear12Bytes020e46c4(who);
                        InitObjFromCombatantId020e4bf4(who, unit->obj3D_.unknown_4_);
                        *(char**)((char*)g + 0x10) = who;
                        SetByteInRange((unsigned char*)g, 0, 0);
                        StoreInArray0x8b0((StoreStruct*)g, 0, v->lo);
                        SetByteInRange((unsigned char*)g, 9, 0);
                        StoreInArray0x8b0((StoreStruct*)g, 9, unit->obj3D_.unknown_4_);
                        char out[0x80];
                        __clear(out, 0x80);
                        func_02046608(g, 0xc, text, out, 0xe3, 0, 1);
                        func_020d7e10(reset, out, 0, 0, 1, 1);
                    }
                }
                if (!ok || !shown) {
                    func_ov017_0218b5c0(saved, id);
                }
            }
            local.kind = 2;
        } else {
            local.kind = 4;
            Val021d2d64* vals;
            for (int i = 0; i < 3; i++) {
                vals = local.vals;
                vals[i].lo = 0;
                vals[i].hi = 0;
            }
        }
        local.fe = v3ac;
        EnqueueEventTag37_021d2cc0(&local);
        break;
    }
    case 2:
    case 3:
        for (int i = 0; i < count; i++) {
            Val021d2d64* v = &local.vals[i];
            int off = i * sizeof(Obj_021d35f8);
            int lo = v->lo;
            *(unsigned short*)((char*)slotsA + 2 + off) = lo;
            if (lo > 0) {
                *((unsigned char*)slotsA + off) = 3;
            } else {
                *((unsigned char*)slotsA + off) = 0;
            }
            int hi = v->hi;
            *(unsigned short*)((char*)slotsB + 2 + off) = hi;
            if (hi > 0) {
                *((unsigned char*)slotsB + off) = 3;
            } else {
                *((unsigned char*)slotsB + off) = 0;
            }
        }
        CallHelperIfFlag_021a5a88(hud, (int)ids, (int)slotsA, (int)slotsB, count);
        break;
    case 4:
        for (int i = 0; i < count; i++) {
            slotsA[i].h2 = 0;
            slotsA[i].b0 = 2;
            slotsB[i].h2 = 0;
            slotsB[i].b0 = 2;
        }
        CallHelperIfFlag_021a5a88(hud, (int)ids, (int)slotsA, (int)slotsB, count);
        break;
    }
}
