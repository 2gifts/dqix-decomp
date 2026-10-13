#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"

struct SearchState021c37a4 {
    char unk0[0x100d];
    unsigned char mode;
    char unk100e[0x1029 - 0x100e];
    unsigned char flags;
};

struct MemberStatus021c37a4 {
    unsigned int flags;
    unsigned short state;
};

struct Member021c37a4 {
    char unk0[0x130];
    MemberStatus021c37a4* status;
    char* name;
    char unk138[0x18c - 0x138];
    unsigned int flags;
};

struct Slot021c37a4 {
    unsigned char data[6];
    signed char first;
    unsigned char a;
    unsigned char b;
    signed char last;
};

struct Battle021c37a4 {
    char unk0[0x5ccc];
    unsigned int flags;
    char unk5cd0[0x74c0 - 0x5cd0];
    Slot021c37a4 slots[3];
    char unk74de[0x7e74 - 0x74de];
    int value;
};

struct Party021c37a4 {
    char unk0[0xf78];
    unsigned char memberIds[4];
    unsigned char memberCount;
    char unkf7d[0x2c94 - 0xf7d];
    int value;
};

struct Swap021c37a4 {
    unsigned char from;
    unsigned char to;
};

struct FieldTimer021c37a4 {
    char unk0[0x64];
    unsigned short value;
};

struct Field021c37a4 {
    char unk0[0x2340];
    FieldTimer021c37a4 timer;
    char unk23a6[0x2820 - 0x23a6];
    unsigned char flag;
    FieldTimer021c37a4* GetTimer() { FieldTimer021c37a4* t = &timer; return t; }
};

struct Actor021c37a4 {
    char unk0[0xc8];
    unsigned char flags;
};

struct Global021c37a4 {
    char unk0[0x1962];
    unsigned char flag;
};

struct Obj02039d84;
struct PackedNibbleArray0206e2dc;
struct PackedNibbleArray0206e2a0;
struct Struct020d9ae8;
struct TailList020469b4;
struct TailNode020469b4;
struct SlotTable020e3004;
struct Bytes020e358c;
struct Entry020e3840;
struct Actor0209c678;
struct Actor0209c20c;
struct FlagWord020466f4;

extern "C" void* func_0202ae18(void);
void* GetData02100044(void);
void* GetData02153637(void);
void* GetData02153634(void);
void* GetData02153660(void);
extern "C" void* _Z27GetDataPtr02114e04_020d6c00v(void);
extern "C" int func_0202c540(void* obj);
int GetFieldAt0x0(int* obj);
extern "C" void _Z24UpdatePlayClocks020ac4f8i(int arg);
extern "C" void __clear(void* buf, int len);
void Clear0x20BytesAt0x74de(unsigned char* obj);
void ClearFieldKeepBit0x10(void* obj);
extern "C" void func_02046a8c(void* a, void* b);
void SetBitsInWord(unsigned int* word, unsigned int bits);
extern "C" void _Z21BlankFunction020d84e0v(void);
extern "C" void func_0202b0f4(void* obj);
extern "C" void func_0205e22c(void* obj);
unsigned char GetField0x3acValue(GameState* gs);
int GetByte0x26c(char* obj);
extern "C" void _Z24ResetObjectState02039d84P11Obj02039d84(Obj02039d84* obj);
GameObject* GetCombatantWithFlag0x1000(GameState* gs, int idx);
int GetSignedByte0x2d0(void* obj);
extern "C" void func_ov017_02190264(void* obj, int idx);
extern "C" void func_ov017_021c32b0(Swap021c37a4* swap, int count);
extern "C" void func_0202c288(void* obj);
void SetField0x3acValue(GameState* gs, int value);
extern "C" void func_020dcd40(void);
extern "C" void func_020dc7e8(int a, int b);
extern "C" void func_ov017_02191234(void* obj);
extern "C" void func_ov017_02191108(void* obj, int a, int b, int c, int d);
void SetField0x2d0(void* obj, unsigned char value);
void SetByte0x1c8(unsigned char* obj, unsigned char value);
extern "C" void _Z30ClearBytesAndZeroBlock02039d24Ph(unsigned char* obj);
void* GetFieldIfFlag4(char* obj);
void SetField0x21c(void* obj, short value);
extern "C" void* func_0205ec34(void);
int GetPackedNibbleFlag0x8(PackedNibbleArray0206e2dc* arr, int idx);
extern "C" void func_020abd20(int arg);
void SetPackedNibbleFlag0x8(PackedNibbleArray0206e2a0* arr, int idx);
extern "C" void _Z12Init020d9ae8P14Struct020d9ae8i(Struct020d9ae8* obj, int arg);
extern "C" void _Z22CopyStringInto020d9dc4PcS_(char* dst, char* src);
void AppendNodeToTail(TailList020469b4* list, TailNode020469b4* node);
extern "C" void _Z30DecrementKeyEverywhere02086d88Phi(unsigned char* obj, int key);
extern "C" void _Z28ClearByteField17201_0218d500Pv(void* obj);
void ClearAllTreasureMapUnknownBits(void* obj);
extern "C" void func_02048150(void* obj, int a, int b);
extern "C" void func_ov017_02191aac(void* obj, int mode, int idx, unsigned char mask);
extern "C" void VectorizedMemset(void* dst, int value, int len);
char* GetGlobal02109030(void);
void ResetEightRegionsAndFlags(char* obj);
extern "C" Field021c37a4* func_02012fe4(void);
extern "C" void _Z29ClearTwoBytesAtField_02195748Ph(unsigned char* obj);
void ApplyVecFromField0x246(char* obj);
extern "C" void _Z21InitSlotTable020e3004P17SlotTable020e3004(SlotTable020e3004* p);
extern "C" void _Z23ClearThreeBytes020e358cP13Bytes020e358c(Bytes020e358c* p);
extern "C" void _Z23ResetEntryArray020e3814P13Entry020e3840(Entry020e3840* p);
extern "C" int _Z20GetField0xcd0209c3acPc(char* obj);
extern "C" void func_0209c2e0(void* obj, int a, int b);
extern "C" void _Z30DispatchContextByState0209c678P13Actor0209c678i(Actor0209c678* obj, int state);
extern "C" void func_020bbd9c(void);
extern "C" int _Z24IsHandleB8Active0209c6bcPv(void* obj);
extern "C" void _Z24InitActorContext0209c20cP13Actor0209c20c(Actor0209c20c* obj);
extern "C" void _Z18ClearFlags020466f4P16FlagWord020466f4j(FlagWord020466f4* obj, unsigned int flags);
extern "C" Global021c37a4* _Z26GetGlobalField0x1c020421a0v(void);

extern Actor021c37a4 data_02109bf4;

// USA: func_ov017_021c37a4
extern "C" ARM void func_ov017_021c37a4(void) {
    GameState* gs = GameState::GetInstance();
    Battle021c37a4* battle = (Battle021c37a4*)gs;
    SearchState021c37a4* search = (SearchState021c37a4*)func_0202ae18();
    GameResources* res = func_ov017_0218b5b0();
    void* d100044 = GetData02100044();
    void* d153637 = GetData02153637();
    void* d153634 = GetData02153634();
    void* d153660 = GetData02153660();
    void* d114e04 = _Z27GetDataPtr02114e04_020d6c00v();
    int active = func_0202c540(search);
    int state = GetFieldAt0x0((int*)search);
    int mode = search->mode;
    char name[0x30];
    unsigned char bits[0x1a];
    Swap021c37a4 leader;
    Swap021c37a4 swap;

    if ((state == 5 && mode > 1) || state == 6) {
        _Z24UpdatePlayClocks020ac4f8i(1);
    }

    __clear(name, 0x30);
    if (active) {
        char* src = ((Member021c37a4*)gs->GetPartyMemberByIndex(0))->name;
        memcpy(name, src, strlen(src));
        Clear0x20BytesAt0x74de((unsigned char*)gs);
        ClearFieldKeepBit0x10(gs);
        func_02046a8c(res->unknown_ptr_array_36fc[0], res->unknown_ptr_array_3afc[0x14]);
    }

    SetBitsInWord((unsigned int*)res, 2);
    _Z21BlankFunction020d84e0v();
    func_0202b0f4(search);
    func_0205e22c(d100044);
    search->flags &= ~0x10;

    for (int i = 0; i < 4; i++) {
        if (i == GetField0x3acValue(gs)) {
            GameObject* member = gs->GetPartyMemberByIndex(i);
            if (active && member && GetByte0x26c((char*)member)) {
                _Z24ResetObjectState02039d84P11Obj02039d84((Obj02039d84*)member);
            }
        } else {
            GameObject* combatant = GetCombatantWithFlag0x1000(gs, i);
            if (combatant && GetSignedByte0x2d0(combatant) == GetField0x3acValue(gs)) {
                continue;
            }
            func_ov017_02190264(res, i);
        }
    }

    leader.from = GetField0x3acValue(gs);
    leader.to = 0;
    if (leader.from != leader.to) {
        func_ov017_021c32b0(&leader, 1);
    }

    for (int i = 3; i >= 0; i--) {
        GameObject* obj = gs->GetGameObjectByIndex(i);
        if (obj && (obj->obj3D_.unknown_0_ & 0x1000)) {
            int empty = -1;
            for (int j = 3; i < j; j--) {
                if (gs->GetGameObjectByIndex(j) == NULL) {
                    empty = j;
                    break;
                }
            }
            if (empty != -1) {
                swap.from = i;
                swap.to = empty;
                if (swap.from != swap.to) {
                    func_ov017_021c32b0(&swap, 1);
                }
            }
        }
    }

    func_0202c288(search);
    SetField0x3acValue(gs, 0);
    if (active) {
        func_020dcd40();
        func_020dc7e8(6, -1);
        func_020dc7e8(7, -1);
        func_ov017_02191234(res);
        func_ov017_02191108(res, 1, 1, 1, 1);
    }

    for (int i = 0; i < 4; i++) {
        GameObject* combatant = GetCombatantWithFlag0x1000(gs, i);
        if (combatant) {
            SetField0x2d0(combatant, GetField0x3acValue(gs));
            SetByte0x1c8((unsigned char*)combatant, GetField0x3acValue(gs));
            _Z30ClearBytesAndZeroBlock02039d24Ph((unsigned char*)combatant);
        }
    }

    void* follower = GetFieldIfFlag4((char*)gs);
    if (follower) {
        SetField0x21c(follower, 0);
    }
    func_ov017_02191108(res, 1, 0, 1, 1);
    func_ov017_02191234(res);
    battle->flags |= 2;

    Party021c37a4* party = (Party021c37a4*)GetPtrField0x2a04(gs);
    if (active) {
        void* store = func_0205ec34();
        memset(bits, 0, 0x1a);
        unsigned char* p = bits;
        unsigned char bit = 0;
        for (int i = 0; i < 0xcc; i++) {
            if (GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)store, i)) {
                *p |= 1 << bit;
            }
            bit++;
            if (bit == 8) {
                p++;
                bit = 0;
            }
        }
        func_020abd20(0);
        party->value = battle->value;

        bit = 0;
        p = bits;
        bool changed = false;
        for (int i = 0; i < 0xcc; i++) {
            if (*p & (1 << bit)) {
                if (!GetPackedNibbleFlag0x8((PackedNibbleArray0206e2dc*)store, i)) {
                    changed = true;
                }
                SetPackedNibbleFlag0x8((PackedNibbleArray0206e2a0*)store, i);
            }
            bit++;
            if (bit == 8) {
                p++;
                bit = 0;
            }
        }
        if (changed) {
            void* list;
            void* node = res->unknown_ptr_array_3afc[0x31];
            list = res->unknown_ptr_array_36fc[0];
            _Z12Init020d9ae8P14Struct020d9ae8i((Struct020d9ae8*)node, 0);
            _Z22CopyStringInto020d9dc4PcS_((char*)node, name);
            AppendNodeToTail((TailList020469b4*)list, (TailNode020469b4*)node);
        }
    }

    _Z30DecrementKeyEverywhere02086d88Phi((unsigned char*)party, 0x5612);
    _Z28ClearByteField17201_0218d500Pv(res);
    if (active) {
        ClearAllTreasureMapUnknownBits(gs);
    }

    Member021c37a4* hero = (Member021c37a4*)gs->GetPartyMemberByIndex(0);
    if (hero && (hero->status->flags & 1)) {
        func_02048150(hero, 0, 1);
        hero->status->state = 1;
        hero->flags &= ~1;
    }

    Party021c37a4* members = (Party021c37a4*)GetPtrField0x2a04(gs);
    for (int i = 0; i < members->memberCount; i++) {
        unsigned char id = members->memberIds[i];
        if (GetCombatantWithFlag0x100(gs, id)) {
            func_ov017_02191aac(res, 0, id, 2);
        }
    }

    Slot021c37a4* slot = battle->slots;
    for (int i = 0; i < 3; i++, slot++) {
        VectorizedMemset(slot, 0, 6);
        slot->first = -1;
        slot->a = 0;
        slot->b = 0;
        slot->last = -1;
    }

    ResetEightRegionsAndFlags(GetGlobal02109030());
    Field021c37a4* field = func_02012fe4();
    field->GetTimer()->value = 0;
    res->unknown_flag_42e2 = 0;
    _Z29ClearTwoBytesAtField_02195748Ph((unsigned char*)res);
    ApplyVecFromField0x246((char*)follower);
    _Z21InitSlotTable020e3004P17SlotTable020e3004((SlotTable020e3004*)d153637);
    _Z23ClearThreeBytes020e358cP13Bytes020e358c((Bytes020e358c*)d153634);
    _Z23ResetEntryArray020e3814P13Entry020e3840((Entry020e3840*)d153660);
    field->flag = 1;

    if (_Z20GetField0xcd0209c3acPc((char*)&data_02109bf4) != 0x7f) {
        func_0209c2e0(&data_02109bf4, 0x7f, 0);
        _Z30DispatchContextByState0209c678P13Actor0209c678i((Actor0209c678*)&data_02109bf4, 0);
        func_020bbd9c();
    }
    data_02109bf4.flags &= ~4;
    if (!_Z24IsHandleB8Active0209c6bcPv(&data_02109bf4)) {
        _Z24InitActorContext0209c20cP13Actor0209c20c((Actor0209c20c*)&data_02109bf4);
    }
    _Z18ClearFlags020466f4P16FlagWord020466f4j((FlagWord020466f4*)d114e04, 0x800);
    _Z26GetGlobalField0x1c020421a0v()->flag = 0;
}
