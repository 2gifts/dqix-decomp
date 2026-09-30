#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};
struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
extern "C" struct BattleStruct* _ZN9GameState11GetInstanceEv();

struct Bits8_021eb5d0 {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char b4 : 1;
    unsigned char b5 : 1;
    unsigned char b6 : 1;
    unsigned char b7 : 1;
};

struct Id12_021eb5d0 {
    unsigned int id : 12;
    unsigned int rest : 20;
};

struct Cost8_021eb5d0 {
    unsigned int cost : 8;
    unsigned int pair : 2;
    unsigned int gap : 4;
    unsigned int elem : 8;
    unsigned int gap2 : 6;
    unsigned int noMp : 1;
    unsigned int gap3 : 3;
};

struct Kind7_021eb5d0 {
    unsigned int gap : 5;
    unsigned int kind : 7;
    unsigned int sub : 4;
    unsigned int rest : 16;
};

struct Group5_021eb5d0 {
    unsigned int gap : 19;
    unsigned int group : 5;
    unsigned int rest : 8;
};

struct Pack10_021eb5d0 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Pack7_021eb5d0 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 7;
    unsigned int hi : 5;
};

struct Rec_021eb5d0 {
    char pad0[4];
    struct Id12_021eb5d0 f4;
    struct Cost8_021eb5d0 f8;
    char pad1[4];
    unsigned int f10;
    char pad2[4];
    struct Kind7_021eb5d0 f18;
    struct Group5_021eb5d0 f1c;
    char pad3[8];
    struct Pack10_021eb5d0 f28;
    struct Pack7_021eb5d0 f2c;
};

struct Node_021eb5d0 {
    char pad0[0xe];
    short f0e;
    unsigned short f10;
    char pad1[5];
    unsigned char f17;
    char pad2[4];
    struct Bits8_021eb5d0 f1c;
    unsigned char f1d;
    char pad3[2];
    int f20;
};


struct Entry_021eb5d0 {
    unsigned long long flags;
    void* f8;
    char pad0[0x13];
    unsigned char f1f;
};

struct Chain_021eb5d0 {
    char pad0[0x18];
    int f18;
    short f1c;
    short f1e;
    short f20;
    unsigned short f22;
    unsigned short f24;
};

struct Depth_021eb5d0 {
    char pad0[0x10];
    unsigned short f10;
};

struct List_021eb5d0 {
    short f0;
    unsigned short f2;
    char pad0[4];
    unsigned char f8;
    char pad1;
    unsigned char fa;
    struct Bits8_021eb5d0 fb;
    struct Bits8_021eb5d0 fc;
    char pad2[3];
    struct Chain_021eb5d0* f10;
    char pad3[4];
    unsigned short f18;
    char pad4[8];
    unsigned short f22;
    unsigned short f24;
};

struct Src_021eb5d0 {
    short f0;
    unsigned short f2;
    char pad0[5];
    unsigned char f9;
};

struct Act_021eb5d0 {
    int f0;
    struct List_021eb5d0* f4;
    struct Chain_021eb5d0* f8;
    struct Node_021eb5d0* fc;
    struct World_021eb5d0* f10;
    int f14;
    int f18;
    int f1c;
    unsigned char f20[8];
    unsigned char f28[0x10];
    unsigned char f38[4];
    unsigned char f3c[8];
    short f44;
    char pad0;
    unsigned char f47;
    char pad1[0x20];
    struct Entry_021eb5d0* f68;
    unsigned char f6c;
    unsigned char f6d;
    unsigned char f6e;
    unsigned char f6f;
    unsigned char f70;
    unsigned char f71;
    unsigned char f72;
    unsigned char f73;
    unsigned char f74;
    unsigned char f75;
    unsigned char f76;
    unsigned char f77;
    unsigned char f78;
    unsigned char f79;
};

struct Entry_021eb5d0;
typedef struct Entry_021eb5d0* (Act_021eb5d0::*Handler_021eb5d0)(short a, short b, struct Rec_021eb5d0* rec, int dmg, int* flags, int cnt);

struct Stats_021eb5d0 {
    unsigned short f0;
    unsigned short f2;
    char pad0[0x10];
    unsigned int f14;
    char pad1[0xa];
    unsigned short f22;
    char pad2[0x17];
    struct Bits8_021eb5d0 f3b;
    struct Bits8_021eb5d0 f3c;
};

struct Fighter_021eb5d0 {
    char pad0[0x138];
    struct Stats_021eb5d0* f138;
    char pad1[0x14];
    unsigned char* f150;
};

struct World_021eb5d0 {
    char pad0[0x8e01];
    unsigned char fe01;
    unsigned char fe02;
    char pad1;
    short fe04;
    signed char fe06;
    char pad2[0x31];
    int fe38;
    int fe3c;
    int fe40;
    char pad3[0x10];
    short fe54;
    char pad4[0x18];
    unsigned short fe6e;
    char pad5[0x24];
    unsigned char fe94;
};

struct Scratch_021eb5d0 {
    unsigned char f0;
    char pad0;
    short f2;
    short f4;
    short f6;
};

struct Res_021eb5d0 {
    int f0;
    int f4;
};

struct Bit2_021eb5d0 {
    unsigned int b0 : 1;
    unsigned int b1 : 1;
    unsigned int rest : 30;
};

struct Slot_021eb5d0 {
    char pad0[0x22];
    signed char f22;
};

#define IN_RANGE_021eb5d0(x) (((x) >= 0 && (x) <= 3) ? 1 : 0)

extern "C" Handler_021eb5d0 data_ov024_021ff508[0x51];
extern "C" Handler_021eb5d0 data_020e6d5c;
extern "C" int data_ov024_02200144;
struct Ids8_021eb5d0 {
    short v[8];
};
extern "C" struct Ids8_021eb5d0 data_ov024_021fe718;
extern "C" int data_ov024_021fe738[4];
extern "C" struct Ids8_021eb5d0 data_ov024_021fe788;
struct Targets_021eb5d0 {
    short v[32];
};
extern "C" struct Targets_021eb5d0 data_ov024_021fe8f0;

extern "C" void* _Z15GetData02108e10v();
extern "C" void* _Z25GetCombatantWithFlag0x100P9GameStatei(void* bs, int id);
extern "C" struct Rec_021eb5d0* _Z24SearchBothTables02079e2cPci(void* table, int id);
extern "C" void* _Z26LookupElementByKey02079ee0Pvi(void* table, int key);
extern "C" void* memset(void* dst, int value, unsigned int length);
extern "C" int _Z31DispatchWithFieldLookup021540c8PvS_i(void* world, void* src, void* out);
extern "C" int func_ov000_0215440c(void* world, void* src, void* out);
extern "C" short func_ov024_021eaa50(struct Act_021eb5d0* self, struct Src_021eb5d0* src, struct Rec_021eb5d0* rec, unsigned char noCost);
extern "C" short func_ov000_0215cda0(void* world);
extern "C" int func_ov024_021e8dc0(struct Act_021eb5d0* self, int id, struct Rec_021eb5d0* rec, short* list, int count);
extern "C" int _Z13GetTableValuePv(void* p);
extern "C" int _ffltu(unsigned int v);
extern "C" int _fflt(int v);
extern "C" int _ffix(int v);
extern "C" int _fadd(int a, int b);
extern "C" int _fmul(int a, int b);
extern "C" int _fgr(int a, int b);
extern "C" int _Z21NextRandomFloatScaledP6Randomffi(void* rng, int lo, int hi, int mode);
extern "C" int _Z13NextRandomMaxP6Randomi(void* rng, int max);
extern "C" int _Z32IsCombatantFlag2Mask512_021eadfcP10GameObject(void* c);
extern "C" int _Z17ConsumeMP0215a124Pvii(void* world, int id, int amount);
extern "C" int _Z19TestBitInArray0x8ecPhi(unsigned char* arr, int bit);
extern "C" unsigned int _Z22AdjustValueByFieldFlagPvj(void* obj, unsigned int v);
extern "C" int _Z18GetField0x3acValueP9GameState(void* bs);
extern "C" int _Z27IsValueInShortList_021eb47cii(struct Act_021eb5d0* self, int v);
extern "C" void _Z23LoadBattleBlock020ac4c0Pv(void* p);
extern "C" void _Z26AddClamped16BitFieldAt0x1cP7S_a0530j(void* p, unsigned int v);
extern "C" void _Z29AddClamped12BitFieldTopAt0x14P7S_a01b8j(void* p, unsigned int v);
extern "C" void _Z23CopyInBattleField0x7540Pv(void* p);
extern "C" int _Z28IsSpecialStateValue_02159c58Pvi(void* world, int v);
extern "C" void _Z20AddClamped12BitFieldP7S_a0674j(void* p, unsigned int v);
extern "C" void _Z29AddClamped10BitFieldMidAt0x14P7S_a017cj(void* p, unsigned int v);
extern "C" struct Node_021eb5d0* _Z22GetNodeAtIndex021600f8P12List021600f8i(struct Src_021eb5d0* list, int index);
extern "C" int _Z28CheckStateFlags3or4_021ea4d0iP20CheckStruct_021ea4d0(struct Act_021eb5d0* self, struct Rec_021eb5d0* rec);
extern "C" int func_ov024_021ea500(struct Act_021eb5d0* self, struct Rec_021eb5d0* rec, int id);
extern "C" int func_ov000_02156cc4(void* world, int id, struct Rec_021eb5d0* rec, int n);
extern "C" int _Z14IsFlag10088SetP7S_10088(void* c);
extern "C" int _Z33IsCombatantFlag2Mask8192_021e6798P10GameObject(void* c);
extern "C" struct Node_021eb5d0* _Z28GetTableEntry0x8e01Bound0x88Pv(void* world);
extern "C" void _Z19ResetStruct0215fef0P14Struct0215fef0(struct Node_021eb5d0* n);
extern "C" short func_ov000_02154c68(void* world, int id, struct Rec_021eb5d0* rec);
extern "C" int func_ov024_021e9b74(struct Act_021eb5d0* self, int a, short* b, struct Rec_021eb5d0* rec);
extern "C" int func_ov024_021e9f68(struct Act_021eb5d0* self, short* a, short* b, struct Rec_021eb5d0* rec, unsigned char* flag);
extern "C" int func_ov024_021ea584(struct Act_021eb5d0* self, int a, int b, struct Rec_021eb5d0* rec);
extern "C" void _Z34ZeroFieldsAt0xe58And0xe82And0x8e52Pv(void* world);
extern "C" int func_ov000_02156f98(void* world, int id, struct Rec_021eb5d0* rec);
extern "C" int func_ov000_02156e30(void* world, int a, int b, struct Rec_021eb5d0* rec);
extern "C" int func_ov000_02156648(void* world, int a, int b, struct Node_021eb5d0* n, struct Rec_021eb5d0* rec, struct List_021eb5d0* list, int flag);
extern "C" int _Z19GetAttackBaseDamagePiiiS_S_(struct Act_021eb5d0* self, int a, int b, struct Rec_021eb5d0* rec, void* elem);
extern "C" void _Z24ClearFirstField_021da550Pi(int* p);
extern "C" int func_ov024_021da55c(int* p, void* world, unsigned short a, unsigned short b, int n, struct Rec_021eb5d0* rec, int dmg);
extern "C" unsigned char* _Z15GetFieldAt0x150Ph(void* c);
extern "C" int _Z20LookupTableD0Clampedi(int v);
extern "C" int func_ov024_021e67c8(struct Act_021eb5d0* self, int a, int b);
extern "C" int func_ov024_021e6948(struct Act_021eb5d0* self, int a, int b, int c);
extern "C" int _Z31HandleElementSpecial17_021e6a90Pv(struct Act_021eb5d0* self, int a, int b, struct Rec_021eb5d0* rec, unsigned short dmg);
extern "C" int _Z17ArrayContainsByteP23ArrayContainsByteStructi(void* arr, int v);
extern "C" void _Z39IncrementByteCounterCapped0x63_0215a8d4Phi(void* world, int idx);
extern "C" int _Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(void* c);
extern "C" int _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(void* c);
extern "C" void func_ov000_02159eac(void* world, void* entry, unsigned char kind);
extern "C" void _Z33AddEntryAndIncrementCount0215a88cPvS_i(void* world, void* entry, unsigned short v);
extern "C" void _Z32AppendToChainAndIncCount0215ffc4PvS_i(void* node, void* entry, int v);
extern "C" int func_ov000_021573a8(void* world, int id, int target, int dmg);
extern "C" struct Entry_021eb5d0* func_ov000_0215e958(void* world);
extern "C" void _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(void* world, struct Entry_021eb5d0* e, void* c, short a, short b, int d, unsigned long long f, unsigned char h);
extern "C" struct Depth_021eb5d0* _Z23FindNodeAtDepth0215fff4Pvii(void* node, int a, int b);
extern "C" int func_ov000_02157288(void* world, int id, struct Rec_021eb5d0* rec);
extern "C" void func_ov000_0215cd44(void* world, void* entry, void* c, int a, unsigned long long f, int e);
extern "C" void _Z28SetFirstEmptySlot48_021eb4e4P24SlotArrayStruct_021eb4e4i(struct Act_021eb5d0* self, struct Node_021eb5d0* n);
extern "C" short _Z20ApplyMPDelta0215a1d4PviiPs(void* world, int id, int amount, short* out);
extern "C" unsigned short _Z31SelectByIndexRange0to3_021da644iii(int idx, int a, int b);
extern "C" void _Z32AppendToChainAndIncCount0215fe84PvS_i(void* obj, void* entry, int v);
extern "C" void func_ov024_021e4c04(struct Act_021eb5d0* self, int id, int target, struct Rec_021eb5d0* rec, int dmg);
extern "C" void func_ov024_021e556c(struct Act_021eb5d0* self, int id, int target, struct Rec_021eb5d0* rec, int dmg);
extern "C" void _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(struct List_021eb5d0* list, struct Node_021eb5d0* n);
extern "C" int _Z37CheckAndClearOrEvaluateFlags_021eb1ecPvi(struct Act_021eb5d0* self, int id);
extern "C" int func_ov024_021eb2b4(struct Act_021eb5d0* self);
extern "C" int func_ov024_021eb344(struct Act_021eb5d0* self, int id, int dmg);
extern "C" int _Z19ClassifyField0x81fePc(void* world);
extern "C" void func_ov024_021eb3e0(struct Act_021eb5d0* self, int id);
extern "C" void func_ov000_0215af54(void* world, int id, int v);
extern "C" void _Z27SetField0x32SavingOldTo0x34P16SetField0208978cs(void* stats, short id);
extern "C" int func_ov000_0215eb1c(void* world, short* buf, int count, int flag);
extern "C" int func_ov024_021eb08c(struct Act_021eb5d0* self, int id, int target, int kind);
extern "C" void func_ov000_0215a908(void* world, int id);
extern "C" int func_ov000_02155f9c(void* world, int id, int v);
extern "C" void func_ov024_021e6060(struct Act_021eb5d0* self, int id, struct Rec_021eb5d0* rec, int v);
extern "C" void func_ov024_021e6104(struct Act_021eb5d0* self, int id, struct Rec_021eb5d0* rec);
extern "C" void func_ov024_021e62cc(struct Act_021eb5d0* self, int id, struct Rec_021eb5d0* rec);
extern "C" int _Z19SumField4Bits20To26Pc(unsigned char* p);
extern "C" int func_ov000_02159d24(void* world, int id);
extern "C" struct Chain_021eb5d0* _Z22GetNodeAtIndex02160094P12List02160094i(struct List_021eb5d0* list, int index);
extern "C" void _Z29ClearFlag0x1000000AndByte0x24Pv(void* p);
extern "C" void _Z35ClearFlag0x14Bit0x800000AndByte0x24Pv(void* p);
extern "C" void func_ov024_021e80e4(struct Act_021eb5d0* self, struct List_021eb5d0* list, struct Rec_021eb5d0* rec, int a, int b, struct Rec_021eb5d0* c);
extern "C" unsigned short func_ov024_021e99d8(struct Act_021eb5d0* self, struct List_021eb5d0* list, struct Rec_021eb5d0* rec);
extern "C" void* _Z19GetActiveCombatWorkv();
extern "C" char* _Z20GetOffsetPtr02160f08Pv(void* p);
extern "C" int func_020ddb38(int a, int b, void* slot, void* world);
extern "C" int _Z31IsIdOrEffectMatchTarget0215fd24ii(void* world, int id);
extern "C" void func_ov017_021c3fb4(unsigned short a, int b);
extern "C" void func_ov000_021584e8(void* world, void* a, void* b, void* c, int d, int e);
extern "C" void func_02083e28(unsigned char* p, int v);
extern "C" void _Z19ApplyCombatantBuffsii(void* world, int id);
extern "C" void* _Z17GetPtrField0x2a04P9GameState(void* bs);

// USA: func_ov024_021eb5d0
extern "C" ARM void func_ov024_021eb5d0(struct Act_021eb5d0* self, struct World_021eb5d0* world, struct List_021eb5d0* list, struct Src_021eb5d0* src, unsigned char noCost) {
    struct Res_021eb5d0 res;
    unsigned long long pairA;
    unsigned long long pairB;
    short s6;
    short s4;
    short s2;
    unsigned char c0;
    struct Targets_021eb5d0 tgt32;
    struct Ids8_021eb5d0 ids1;
    struct Ids8_021eb5d0 ids2;
    unsigned char blkA[0xb0];
    unsigned char blkB[0xb0];
    int guard = data_ov024_02200144;
    if ((guard & 1) == 0) {
        data_ov024_021ff508[0x1e] = data_020e6d5c;
        data_ov024_021ff508[0x22] = data_020e6d5c;
        data_ov024_021ff508[0x3b] = data_020e6d5c;
        data_ov024_021ff508[0x3c] = data_020e6d5c;
        data_ov024_02200144 = guard | 1;
    }
    self->f10 = world;
    self->f4 = list;
    self->f8 = list->f10;
    struct BattleStruct* bs = _ZN9GameState11GetInstanceEv();
    void* table = _Z15GetData02108e10v();
    struct Rec_021eb5d0* rec = _Z24SearchBothTables02079e2cPci(table, self->f4->f0);
    if (rec == 0) return;
    self->f6d = 1;
    self->f6e = 0;
    self->f1c = 0x3f800000;
    self->f47 = 0;
    memset(self->f20, -1, 8);
    memset(self->f28, -1, 0x10);
    memset(self->f38, 0, 4);
    memset(self->f3c, 0, 8);
    self->f4->fb.b3 = 1;
    world->fe04 = -1;
    world->fe06 = -1;
    int group = rec->f18.kind;
    if (group >= 0x51) group = 0;
    if (data_ov024_021ff508[group] == 0) group = 0;
    void* w = self->f10;
    const short id = self->f4->f10->f20;
    struct Fighter_021eb5d0* actor = (struct Fighter_021eb5d0*)GetCombatantByID((int)w, id);
    short firstHit = -1;
    if (data_ov024_021ff508[group] == 0) return;
    self->f4->f0 = func_ov024_021eaa50(self, src, rec, noCost);
    self->f4->f2 = src->f2;
    rec = _Z24SearchBothTables02079e2cPci(table, self->f4->f0);
    if (rec == 0) return;
    group = rec->f18.kind;
    if (group >= 0x51) group = 0;
    if (data_ov024_021ff508[group] == 0) group = 0;
    void* elemInfo = _Z26LookupElementByKey02079ee0Pvi(table, rec->f8.elem);
    tgt32 = data_ov024_021fe8f0;
    unsigned char count;
    if (IN_RANGE_021eb5d0(id)) count = _Z31DispatchWithFieldLookup021540c8PvS_i(self->f10, src, tgt32.v);
    else count = func_ov000_0215440c(self->f10, src, tgt32.v);
    if (rec->f4.id == 0xa8 || rec->f4.id == 0x14a) {
        if (id == tgt32.v[0]) {
            src->f0 = 0x3ac;
            src->f9 = 1;
            self->f4->f2 = rec->f4.id;
            self->f4->f0 = 0x3ac;
            rec = _Z24SearchBothTables02079e2cPci(table, self->f4->f0);
            if (rec == 0) return;
            group = rec->f18.kind;
            if (group >= 0x51) group = 0;
            if (data_ov024_021ff508[group] == 0) group = 0;
        }
    }
    if (rec->f4.id == 0xb7 || rec->f4.id == 0xb8) {
        if (id == tgt32.v[0]) {
            src->f0 = 0x3ad;
            src->f9 = 1;
            self->f4->f2 = rec->f4.id;
            self->f4->f0 = 0x3ad;
            rec = _Z24SearchBothTables02079e2cPci(table, self->f4->f0);
            if (rec == 0) return;
            group = rec->f18.kind;
            if (group >= 0x51) group = 0;
            if (data_ov024_021ff508[group] == 0) group = 0;
        }
    }
    if (rec->f4.id == 0x61) {
        count = 2;
        tgt32.v[1] = tgt32.v[0];
    }
    if (rec->f4.id == 0x79) {
        tgt32.v[count] = func_ov000_0215cda0(self->f10);
        count = count + 1;
    }
    self->f78 = 0;
    count = func_ov024_021e8dc0(self, id, rec, tgt32.v, count);
    res.f4 = 0;
    self->f14 = 0;
    self->f44 = -1;
    self->f10->fe38 = 0;
    if (rec->f4.id == 0x200 || rec->f4.id == 0x20c) {
        struct Fighter_021eb5d0* pc = (struct Fighter_021eb5d0*)_Z25GetCombatantWithFlag0x100P9GameStatei(bs, id);
        switch (rec->f4.id) {
        case 0x200:
            if (pc != 0) {
                int lvl = _Z13GetTableValuePv(pc);
                int scale = _fadd(0x3f800000, _fmul(0x3c23d70a, _fadd(0x41300000, _ffltu(lvl))));
                if (_fgr(scale, 0x40000000)) scale = 0x40000000;
                self->f10->fe3c = _Z21NextRandomFloatScaledP6Randomffi(w, 0x3f8ccccd, scale, 1);
                self->f4->f10->f18 = self->f10->fe3c;
            }
            break;
        case 0x20c:
            self->f10->fe3c = _Z21NextRandomFloatScaledP6Randomffi(w, 0x3fc00000, 0x40400000, 1);
            self->f10->fe40 = self->f10->fe3c;
            break;
        }
    }
    self->f6c = 0;
    if (rec->f4.id == 0x1ff || rec->f4.id == 0x20b) {
        int roll = _Z13NextRandomMaxP6Randomi(self->f10, 0x64);
        int thr = 0;
        switch (rec->f4.id) {
        case 0x1ff:
            thr = 0x32;
            break;
        case 0x20b:
            thr = 0x46;
            break;
        }
        if (roll < thr) self->f6c = 1;
    }
    unsigned char mpUsed = 0;
    self->f71 = mpUsed;
    self->f72 = mpUsed;
    self->f73 = mpUsed;
    self->f10->fe54 = mpUsed;
    if (actor != 0) {
        self->f10->fe54 = actor->f138->f2;
        if (!IN_RANGE_021eb5d0(id)) {
            if (actor->f138->f2 >= 0xff) self->f6d = 0;
        }
        if (_Z32IsCombatantFlag2Mask512_021eadfcP10GameObject(actor) != 0) self->f6d = 0;
        if (noCost != 0) self->f6d = 0;
        if (rec->f8.noMp != 0) self->f6d = 0;
        if (self->f6d != 0) {
            mpUsed = 1;
            unsigned int cost = rec->f8.cost;
            if (cost >= 0xff) {
                cost = actor->f138->f2;
                _Z17ConsumeMP0215a124Pvii(self->f10, id, cost);
            } else {
                if (IN_RANGE_021eb5d0(id)) {
                    struct Fighter_021eb5d0* pc = (struct Fighter_021eb5d0*)_Z25GetCombatantWithFlag0x100P9GameStatei(bs, id);
                    if (pc != 0 && _Z19TestBitInArray0x8ecPhi(pc->f150, 0x106) != 0) cost = _Z22AdjustValueByFieldFlagPvj(pc, cost);
                }
                _Z17ConsumeMP0215a124Pvii(self->f10, id, cost);
            }
        }
    }
    if (id == _Z18GetField0x3acValueP9GameState(bs)) {
        if (_Z27IsValueInShortList_021eb47cii(self, rec->f4.id) != 0) {
            _Z23LoadBattleBlock020ac4c0Pv(blkA);
            _Z26AddClamped16BitFieldAt0x1cP7S_a0530j(blkA, 1);
            _Z29AddClamped12BitFieldTopAt0x14P7S_a01b8j(blkA + 0x68, 1);
            _Z23CopyInBattleField0x7540Pv(blkA);
        }
        if (_Z28IsSpecialStateValue_02159c58Pvi(self->f10, (unsigned short)rec->f4.id) != 0) {
            _Z23LoadBattleBlock020ac4c0Pv(blkB);
            _Z20AddClamped12BitFieldP7S_a0674j(blkB, 1);
            _Z29AddClamped10BitFieldMidAt0x14P7S_a017cj(blkB + 0x68, 1);
            _Z23CopyInBattleField0x7540Pv(blkB);
        }
    }
    if (noCost != 0) {
        count = src->f9;
        for (int k = 0; k < src->f9; k++) {
            tgt32.v[k] = _Z22GetNodeAtIndex021600f8P12List021600f8i(src, k)->f0e;
        }
    }
    int totA = 0;
    self->f18 = 0;
    int totB = 0;
    unsigned char okFlag = 1;
    unsigned char flagC = totA;
    int hit = totA;
    struct Rec_021eb5d0* recSaved = rec;
    if (_Z28CheckStateFlags3or4_021ea4d0iP20CheckStruct_021ea4d0(self, rec) != 0) hit = 1;
    if (func_ov024_021ea500(self, rec, id) != 0) hit = 1;
    if (hit != 0) {
        okFlag = 0;
        if (func_ov000_02156cc4(self->f10, id, rec, count) != 0) {
            flagC = 1;
            self->f4->fa |= 1;
        }
    }
    int i;
    short lastTarget;
    unsigned char flagD = 0;
    self->f79 = 0;
    lastTarget = flagD - 1;
    for (i = flagD; i < count; i++, self->f18 = self->f18 + 1) {
        if (_Z14IsFlag10088SetP7S_10088(actor) != 0) break;
        if (_Z33IsCombatantFlag2Mask8192_021e6798P10GameObject(actor) != 0) break;
        if (group == 0x21 && id == tgt32.v[i]) continue;
        self->fc = _Z28GetTableEntry0x8e01Bound0x88Pv(self->f10);
        struct Node_021eb5d0* nd = self->fc;
        if (nd == 0) return;
        _Z19ResetStruct0215fef0P14Struct0215fef0(nd);
        nd->f20 = 0;
        self->fc->f0e = tgt32.v[i];
        int accum = 0;
        self->fc->f17 = self->fc->f17 + 1;
        self->f70 = 1;
        self->f6f = 1;
        self->f74 = 0;
        self->f10->fe6e = _Z13NextRandomMaxP6Randomi(self->f10, 0x64);
        tgt32.v[i] = func_ov000_02154c68(self->f10, tgt32.v[i], rec);
        self->fc->f0e = tgt32.v[i];
        if (rec->f4.id == 0x79 && self->f18 == (count - 1)) {
            struct Fighter_021eb5d0* tc = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, tgt32.v[i]);
            if (tc == 0 || _Z14IsFlag10088SetP7S_10088(tc) != 0 ||
                _Z33IsCombatantFlag2Mask8192_021e6798P10GameObject(tc) != 0) {
                tgt32.v[i] = func_ov000_0215cda0(self->f10);
                if (tgt32.v[i] < 0) continue;
                self->fc->f0e = tgt32.v[i];
            }
        }
        if (group != 0x12 && group != 0x21) {
            struct Fighter_021eb5d0* tc = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, tgt32.v[i]);
            if (tc == 0) continue;
            if (_Z14IsFlag10088SetP7S_10088(tc) != 0) continue;
        }
        int dmg = 0;
        s6 = id;
        s4 = tgt32.v[i];
        if (lastTarget != tgt32.v[i]) {
            self->f79 = 0;
            lastTarget = s4;
        }
        struct Rec_021eb5d0* rec2 = rec;
        int chk = func_ov024_021e9b74(self, s6, &s4, rec);
        if (chk != 0) {
            if (IN_RANGE_021eb5d0(s4)) self->f4->fc.b2 = 1;
            else self->f4->fc.b5 = 1;
        }
        if (self->f79 != 0 && chk == 0) continue;
        self->f76 = 1;
        self->f77 = 0;
        c0 = 0;
        int tgt = s4;
        int alt = func_ov024_021e9f68(self, &s6, &s4, rec, &c0);
        if (alt != 0) flagD = 1;
        if (s6 != id) {
            recSaved = rec;
            if (IN_RANGE_021eb5d0(tgt)) self->f4->fc.b2 = 1;
            else self->f4->fc.b5 = 1;
        }
        if (alt == 0 && self->f77 == 0) func_ov024_021ea584(self, s6, s4, rec);
        else _Z34ZeroFieldsAt0xe58And0xe82And0x8e52Pv(self->f10);
        if (group != 0x12 && group != 0x21) {
            struct Fighter_021eb5d0* tc = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, s4);
            if (tc == 0) continue;
            if (_Z14IsFlag10088SetP7S_10088(tc) != 0) continue;
        }
        if (alt != 0) {
            rec2 = _Z24SearchBothTables02079e2cPci(table, 1);
            recSaved = rec2;
            self->fc->f1d = (self->fc->f1d & ~1u) | 1;
            if (rec2 != 0) elemInfo = _Z26LookupElementByKey02079ee0Pvi(table, rec2->f8.elem);
        }
        if (rec2 == 0) rec2 = rec;
        if (alt != 0 || self->f77 != 0 || c0 != 0) {
            if (okFlag != 0) {
                if (rec->f4.id == 0x70 || rec->f4.id == 0x48) {
                    if (_Z13NextRandomMaxP6Randomi(self->f10, 2) == 0) self->f4->fa |= 1;
                } else {
                    if (func_ov000_02156cc4(self->f10, id, rec, count) != 0) self->f4->fa |= 1;
                }
            } else {
                if (flagC != 0) self->f4->fa |= 1;
            }
            if (func_ov000_02156cc4(self->f10, s6, rec2, count) != 0) {
                self->fc->f1c.b7 = 1;
                if (c0 != 0) self->f4->fa |= 0x40;
                else self->f4->fa |= 0x20;
                if (firstHit < 0) firstHit = s6;
            }
        } else {
            if (okFlag != 0) {
                if (func_ov000_02156cc4(self->f10, s6, rec2, count) != 0) {
                    self->fc->f1c.b7 = 1;
                    self->f4->fa |= 1;
                }
            } else {
                self->fc->f1c.b7 = flagC;
            }
        }
        unsigned char flagE = 0;
        if (func_ov000_02156f98(self->f10, s4, rec2) != 0) {
            self->f4->fa |= 4;
            self->fc->f1c.b1 = 1;
        } else if (func_ov000_02156e30(self->f10, s6, s4, rec2) != 0) {
            self->f4->fa |= 2;
            self->fc->f1c.b2 = 1;
        }
        self->f10->fe94 = 0;
        unsigned char flagF = 0;
        if (rec2->f4.id == 0x61 && self->f18 > 0) {
            flagF = 1;
            self->fc->f1c.b1 = 0;
            self->fc->f1c.b2 = 0;
            self->fc->f1c.b7 = 0;
        }
        unsigned char flagG = 0;
        if (rec2->f4.id == 0x79 && self->f18 == (count - 1)) flagG = 1;
        if (func_ov000_02156648(self->f10, s6, s4, self->fc, rec2, self->f4, flagF) != 0) {
            int base = _Z19GetAttackBaseDamagePiiiS_S_(self, s6, s4, rec2, elemInfo);
            _Z24ClearFirstField_021da550Pi(&res.f0);
            dmg = func_ov024_021da55c(&res.f0, world, s6, s4, count, rec2, base);
            if (rec2->f4.id == 0x70 || rec2->f4.id == 0x48) {
                if (dmg > 0) {
                    if (alt != 0 || self->f77 != 0) self->f4->fa |= 0x20;
                    else self->f4->fa |= 1;
                    if (firstHit < 0) firstHit = s6;
                    self->fc->f1c.b7 = 1;
                    if (IN_RANGE_021eb5d0(s4)) {
                        struct Fighter_021eb5d0* pc = (struct Fighter_021eb5d0*)_Z25GetCombatantWithFlag0x100P9GameStatei(bs, s4);
                        unsigned char* fld = _Z15GetFieldAt0x150Ph(pc);
                        if (pc != 0 && fld != 0) {
                            if (*(short*)(fld + 0x2cc) > 0) {
                                if (_Z19TestBitInArray0x8ecPhi(pc->f150, 0x28) != 0) {
                                    self->f4->fa |= 2;
                                    self->fc->f1c.b2 = 1;
                                }
                            }
                        }
                    }
                } else {
                    dmg = 0;
                }
            }
            if ((rec2->f10 & 0x20000) != 0) {
                unsigned char scaled = 1;
                if (rec2->f4.id == 1 || rec2->f4.id == 2) {
                    if (IN_RANGE_021eb5d0(s6)) {
                        struct Fighter_021eb5d0* pc = (struct Fighter_021eb5d0*)_Z25GetCombatantWithFlag0x100P9GameStatei(bs, s6);
                        if (pc != 0) {
                            struct Bit2_021eb5d0* bp = (struct Bit2_021eb5d0*)(pc->f150 + 0x2f4);
                            if (bp != 0) {
                                if (bp->b1 == 0) {
                                    if (bp->b0 == 0) scaled = 0;
                                }
                            }
                        }
                    } else {
                        scaled = 0;
                    }
                }
                if (scaled != 0) {
                    int mul = _Z20LookupTableD0Clampedi((signed char)i);
                    dmg = _ffix(_fmul(_fflt(dmg), mul));
                }
                if (rec2->f4.id == 0x79) dmg = _ffix(_fmul(0x3f4ccccd, _fflt(dmg)));
            }
            if (flagF != 0) {
                dmg = func_ov024_021e67c8(self, s6, s4);
            } else if (flagG != 0) {
                dmg = func_ov024_021e6948(self, s4, totB, (count - 1));
            } else {
                dmg = _Z31HandleElementSpecial17_021e6a90Pv(self, s6, s4, rec2, (unsigned short)dmg);
            }
            if (rec2->f4.id == 0x79 && self->f18 != (count - 1) && dmg > 0) {
                if (totB <= 0) totB = dmg;
            }
            flagE = 1;
            if (self->fc->f1c.b1 != 0 || self->fc->f1c.b2 != 0) {
                flagE = 0;
                dmg = 0;
                _Z34ZeroFieldsAt0xe58And0xe82And0x8e52Pv(self->f10);
                void* arr = _Z17GetPtrField0x2a04P9GameState(_ZN9GameState11GetInstanceEv());
                if (self->fc->f1c.b2 != 0) {
                    if (_Z17ArrayContainsByteP23ArrayContainsByteStructi(arr, s4) != 0) {
                        _Z39IncrementByteCounterCapped0x63_0215a8d4Phi(self->f10, 6);
                    }
                }
            }
        } else {
            if (self->f76 != 0 && (rec2->f10 & 0x2000) != 0) {
                struct Fighter_021eb5d0* tc = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, s6);
                if (tc != 0) {
                    if (_Z28IsFlagBit8388608Set_021da998P16FlagObj_021da998(tc) != 0 ||
                        _Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(tc) != 0) {
                        self->f47 = 1;
                        if (_Z23IsFlagBit24Set_021dd260P16FlagObj_021dd260(tc) != 0) self->f47 = 2;
                    }
                }
            }
            _Z34ZeroFieldsAt0xe58And0xe82And0x8e52Pv(self->f10);
        }
        self->f75 = 1;
        struct Entry_021eb5d0* ent = (self->*data_ov024_021ff508[group])(s6, s4, rec2, dmg, &res.f4, flagE);
        if (ent != 0) {
            int kind = 0;
            int extra = 0;
            if (self->fc->f1c.b2) { kind = 6; extra = 0x96; }
            if (self->fc->f1c.b6) { kind = 0xc; extra = 0x255; }
            if (self->fc->f1c.b1) { kind = 5; extra = 0x97; }
            if (self->fc->f1c.b4) { kind = 0xa; extra = 0x1b9; }
            if (self->fc->f1c.b5) { kind = 0x26; extra = 0x24d; }
            if (self->fc->f1c.b3) { kind = 9; extra = 0x2b; }
            if (kind > 0) func_ov000_02159eac(self->f10, ent, kind);
            if (extra > 0) _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->f10, ent, extra);
            _Z32AppendToChainAndIncCount0215ffc4PvS_i(self->fc, ent, 0);
            self->f10->fe02 = self->f10->fe02 + 1;
            accum = accum + dmg;
            self->f74 = 1;
            if (alt == 0) totA = totA + dmg;
        }
        if (accum > 0 && alt == 0) {
            struct Fighter_021eb5d0* tc = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, s4);
            if (tc != 0) {
                if (rec2->f18.kind == 1 || rec2->f18.kind == 0x23) {
                    if ((tc->f138->f14 & 0x10000000) != 0) tc->f138->f22 = tc->f138->f22 | 0x4000;
                }
            }
            int mp = 0;
            if (rec2->f4.id == 1 || rec2->f4.id == 2) {
                mp = func_ov000_021573a8(self->f10, id, s4, accum);
                if (mp > 0) {
                    struct Fighter_021eb5d0* tc2 = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, s4);
                    int mpRes = 0;
                    if (tc2 != 0) {
                        if (!IN_RANGE_021eb5d0(s4)) {
                            if (tc2->f138->f2 < 0xff) mpRes = _Z17ConsumeMP0215a124Pvii(self->f10, s4, mp);
                        } else {
                            mpRes = _Z17ConsumeMP0215a124Pvii(self->f10, s4, mp);
                        }
                    }
                    struct Entry_021eb5d0* ent2 = func_ov000_0215e958(self->f10);
                    if (ent2 != 0) {
                        struct Fighter_021eb5d0* tc3 = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, s4);
                        func_ov000_02159eac(self->f10, ent2, 1);
                        func_ov000_02159eac(self->f10, ent2, 0x2a);
                        _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
                            self->f10, ent2, tc3, mp, tc3->f138->f0, mpRes, ent2->flags, 0);
                        _Z32AppendToChainAndIncCount0215ffc4PvS_i(self->fc, ent2, 1);
                        self->f10->fe02 = self->f10->fe02 + 1;
                        if (self->f68 != 0) {
                            ent2->f8 = self->f68->f8;
                            ent2->f1f = self->f68->f1f;
                            self->f68->f8 = 0;
                            self->f68->f1f = 0;
                            self->f68 = ent2;
                        }
                    }
                    struct Depth_021eb5d0* dn = _Z23FindNodeAtDepth0215fff4Pvii(self->fc, 0, 0);
                    if (dn != 0) dn->f10 = mpRes;
                }
            }
            if (self->f70 != 0) {
                int heal = func_ov000_02157288(self->f10, s4, rec2);
                if (heal > 0) {
                    struct Entry_021eb5d0* ent3 = func_ov000_0215e958(self->f10);
                    if (ent3 != 0) {
                        struct Fighter_021eb5d0* tc4 = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, s4);
                        func_ov000_02159eac(self->f10, ent3, 0x10);
                        func_ov000_02159eac(self->f10, ent3, 0x19);
                        func_ov000_0215cd44(self->f10, ent3, tc4, 0, 0, 0);
                        _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->f10, ent3, heal);
                        _Z32AppendToChainAndIncCount0215ffc4PvS_i(self->fc, ent3, 1);
                        self->f10->fe02 = self->f10->fe02 + 1;
                        _Z28SetFirstEmptySlot48_021eb4e4P24SlotArrayStruct_021eb4e4i(self, self->fc);
                    }
                }
            }
            if (mp > 0 && s4 != id) {
                GetCombatantByID((int)self->f10, s4);
                struct Fighter_021eb5d0* me = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, id);
                s2 = 0;
                short delta = _Z20ApplyMPDelta0215a1d4PviiPs(self->f10, id, mp, &s2);
                list->f10->f24 = delta;
                if (!IN_RANGE_021eb5d0(id)) {
                    if (me->f138->f2 >= 0xff) s2 = mp;
                }
                if (s2 > 0) {
                    unsigned short sel = _Z31SelectByIndexRange0to3_021da644iii(id, 0x25f, 0x238);
                    struct Entry_021eb5d0* ent4 = func_ov000_0215e958(self->f10);
                    if (ent4 != 0) {
                        _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->f10, ent4, sel);
                        pairA = 0;
                        func_ov000_02159eac(self->f10, &pairA, 0x22);
                        _Z22PopulateEntry_0215ccbciP17OutStruct0215ccbcP10GameObjectsssiih(
                            self->f10, ent4, me, -s2, me->f138->f0, delta, pairA, 0);
                        _Z32AppendToChainAndIncCount0215fe84PvS_i(self->f8, ent4, 5);
                        self->f8->f1c = s4;
                        self->f8->f1e = 0;
                        self->f10->fe02 = self->f10->fe02 + 1;
                    }
                }
            }
            if (alt == 0) func_ov024_021e4c04(self, id, s4, rec, accum);
        }
        if (alt == 0 && self->f79 == 0) func_ov024_021e556c(self, id, s4, rec, accum);
        if (self->f74 != 0 && self->f6f != 0) {
            _Z18AppendNode021600ccP11Obj021600ccP12Node021600cc(list, self->fc);
            self->f10->fe01 = self->f10->fe01 + 1;
        }
        if (IN_RANGE_021eb5d0(s4)) {
            struct Fighter_021eb5d0* pc = (struct Fighter_021eb5d0*)_Z25GetCombatantWithFlag0x100P9GameStatei(bs, s4);
            if (pc != 0 && _Z37CheckAndClearOrEvaluateFlags_021eb1ecPvi(self, s4) != 0) {
                int val = accum;
                if (rec->f18.kind != 1 && rec->f18.kind != 0x23) val = 0;
                int roll = _Z13NextRandomMaxP6Randomi(self->f10, 0x64);
                unsigned int idx = func_ov024_021eb2b4(self) & 0xff;
                if (idx >= 4) idx = 3;
                int mult = data_ov024_021fe738[idx];
                int thr = _ffix(_fmul(mult, _ffltu(func_ov024_021eb344(self, s4, val) + rec->f2c.c)));
                if (_Z19ClassifyField0x81fePc(self->f10) != 0) thr = 0;
                if (roll < thr) {
                    pc->f138->f3b.b3 = 1;
                    func_ov024_021eb3e0(self, s4);
                    func_ov000_0215af54(self->f10, s4, 1);
                }
            }
        }
        if (!IN_RANGE_021eb5d0(id)) continue;
        if (IN_RANGE_021eb5d0(s4)) continue;
        struct Fighter_021eb5d0* tf = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, s4);
        if (tf == 0) continue;
        _Z27SetField0x32SavingOldTo0x34P16SetField0208978cs(tf->f138, id);
        if (rec->f18.sub == 2) tf->f138->f3c.b1 = 1;
    }
    if (IN_RANGE_021eb5d0(id)) {
        ids1 = data_ov024_021fe788;
        int n = func_ov000_0215eb1c(self->f10, ids1.v, 8, 1);
        for (int j = 0; j < n; j++) {
            unsigned char any = 0;
            if (rec->f1c.group == 5) {
                if (func_ov024_021eb08c(self, id, ids1.v[j], 0x13) != 0) any = 1;
            }
            if (rec->f1c.group == 0xc) {
                if (func_ov024_021eb08c(self, id, ids1.v[j], 0x14) != 0) any = 1;
            }
            if ((list->fa & 1) != 0) {
                if (func_ov024_021eb08c(self, id, ids1.v[j], 0x18) != 0) any = 1;
            }
            if (any != 0) func_ov000_0215a908(self->f10, ids1.v[j]);
        }
    }
    if (GetCombatantByID((int)self->f10, id) != 0 && func_ov000_02155f9c(self->f10, id, 0) == 0) {
        if (flagD == 0) {
            func_ov024_021e6060(self, id, rec, totA);
            func_ov024_021e6104(self, id, rec);
        }
        func_ov024_021e62cc(self, id, rec);
    }
    if (IN_RANGE_021eb5d0(id)) {
        ids2 = data_ov024_021fe718;
        int m = func_ov000_0215eb1c(self->f10, ids2.v, 8, 1);
        struct Fighter_021eb5d0* pc = (struct Fighter_021eb5d0*)_Z25GetCombatantWithFlag0x100P9GameStatei(bs, id);
        if (pc != 0 && m > 0 && _Z37CheckAndClearOrEvaluateFlags_021eb1ecPvi(self, id) != 0) {
            int roll = _Z13NextRandomMaxP6Randomi(self->f10, 0x64);
            unsigned int idx = func_ov024_021eb2b4(self) & 0xff;
            if (idx >= 4) idx = 3;
            int mult = data_ov024_021fe738[idx];
            int bonus = _Z19SumField4Bits20To26Pc(pc->f150);
            int sum = func_ov000_02159d24(self->f10, id) + rec->f2c.c;
            int thr = _ffix(_fmul(mult, _ffltu(sum + bonus)));
            if (_Z19ClassifyField0x81fePc(self->f10) != 0) thr = 0;
            if (roll < thr) {
                pc->f138->f3b.b3 = 1;
                func_ov024_021eb3e0(self, id);
                func_ov000_0215af54(self->f10, id, 1);
            }
        }
    }
    if (_Z27IsValueInShortList_021eb47cii(self, rec->f4.id) != 0) {
        struct Fighter_021eb5d0* me = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, id);
        if (me != 0) me->f138->f3b.b3 = 0;
    }
    if (_Z28IsSpecialStateValue_02159c58Pvi(self->f10, (unsigned short)rec->f4.id) != 0) {
        for (int k = 0; k < list->f8; k++) {
            struct Chain_021eb5d0* nn = _Z22GetNodeAtIndex02160094P12List02160094i(list, k);
            if (nn != 0) {
                struct Fighter_021eb5d0* tc = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, nn->f20);
                if (tc != 0) {
                    tc->f138->f3b.b2 = 1;
                    tc->f138->f3b.b3 = 0;
                }
            }
        }
    }
    if (self->f47 != 0) {
        struct Fighter_021eb5d0* me = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, id);
        if (me != 0) {
            if (_Z14IsFlag10088SetP7S_10088(me) == 0 &&
                _Z33IsCombatantFlag2Mask8192_021e6798P10GameObject(me) == 0) {
                struct Entry_021eb5d0* ent5 = func_ov000_0215e958(self->f10);
                if (ent5 != 0) {
                    _Z33AddEntryAndIncrementCount0215a88cPvS_i(self->f10, ent5, 0x1f1);
                    pairB = 0;
                    if (self->f47 > 1) func_ov000_02159eac(self->f10, &pairB, 8);
                    func_ov000_0215cd44(self->f10, ent5, me, 0, pairB, 0);
                    _Z32AppendToChainAndIncCount0215fe84PvS_i(list->f10, ent5, 1);
                    self->f10->fe02 = self->f10->fe02 + 1;
                }
            }
            _Z29ClearFlag0x1000000AndByte0x24Pv(me->f138);
            _Z35ClearFlag0x14Bit0x800000AndByte0x24Pv(me->f138);
        }
    }
    if (self->f6e == 0) {
        func_ov024_021e80e4(self, list, rec, (res.f4 & 2) != 0, flagD, recSaved);
    }
    list->f18 = func_ov024_021e99d8(self, list, rec);
    if ((list->fa & 1) != 0) {
        list->f22 = _Z31SelectByIndexRange0to3_021da644iii(list->f10->f20, rec->f28.c, rec->f2c.a);
    }
    if ((list->fa & 0x20) != 0) {
        list->f24 = _Z31SelectByIndexRange0to3_021da644iii(firstHit, recSaved->f28.c, recSaved->f2c.a);
    }
    if ((list->fa & 0x40) != 0) {
        list->f24 = _Z31SelectByIndexRange0to3_021da644iii(firstHit, recSaved->f28.c, recSaved->f2c.a);
    }
    struct Fighter_021eb5d0* cur = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, list->f10->f20);
    if (cur != 0) {
        if (self->f6d == 0 && mpUsed != 0) {
            short mpv = self->f10->fe54;
            if (mpv > 0) cur->f138->f2 = mpv;
        }
        for (int k = 0; k < list->f8; k++) {
            struct Chain_021eb5d0* nn = _Z22GetNodeAtIndex02160094P12List02160094i(list, k);
            if (nn != 0) {
                struct Fighter_021eb5d0* tc = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, nn->f20);
                if (tc != 0) {
                    nn->f22 = tc->f138->f0;
                    nn->f24 = tc->f138->f2;
                }
            }
        }
    }
    if (!IN_RANGE_021eb5d0((unsigned short)list->f10->f20)) return;
    if (rec->f18.sub != 3) return;
    unsigned char gate = 1;
    if (rec->f8.pair != 1 && self->f14 <= 0) gate = 0;
    if (gate == 0) return;
    char* wk = _Z20GetOffsetPtr02160f08Pv(_Z19GetActiveCombatWorkv());
    int who = (unsigned short)list->f10->f20;
    struct Slot_021eb5d0* slot;
    if (IN_RANGE_021eb5d0(who)) {
        for (int k = 0; k < 4; k++) {
            if (who == *(int*)(wk + k * 0x448 + 0x9a4)) {
                slot = (struct Slot_021eb5d0*)(wk + 0x158 + 0x800 + k * 0x448);
                goto found;
            }
        }
    }
    slot = 0;
found:
    wk = wk + 0xd0;
    if (wk == 0) return;
    if (func_020ddb38(who, slot->f22, slot, self->f10) != 2) return;
    if (_Z31IsIdOrEffectMatchTarget0215fd24ii(self->f10, list->f10->f20) != 0) {
        func_ov017_021c3fb4(list->f10->f20, 1);
    }
    struct Entry_021eb5d0* last = func_ov000_0215e958(self->f10);
    struct Fighter_021eb5d0* lastc = (struct Fighter_021eb5d0*)GetCombatantByID((int)self->f10, list->f10->f20);
    if (last == 0 || lastc == 0) return;
    func_ov000_021584e8(self->f10, last, lastc, list->f10, 0x258, 0);
    func_02083e28(lastc->f150, 0);
    _Z19ApplyCombatantBuffsii(self->f10, list->f10->f20);
}
