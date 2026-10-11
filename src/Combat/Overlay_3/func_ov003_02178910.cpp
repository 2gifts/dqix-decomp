#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#if defined(jpn)
enum { kRegionSelfShift = 0x84, kRegionElementCursor = 0x2a };
#else
enum { kRegionSelfShift = 0, kRegionElementCursor = 0x36 };
#endif

struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};
extern "C" void* _Z17GetPtrField0x2a04P9GameState(struct BattleStruct* battleStruct);
extern "C" struct BattleStruct* _ZN9GameState11GetInstanceEv();

struct Obj2081;
struct Cont0207fdf0;
struct Obj0205eaa0;
struct Obj0208203c;
struct Container020dedd0;
struct Element020de650 { char pad[8]; unsigned int nibble : 4; };
struct Obj021dcae0;
struct KeyMap020a0b3c { short* keys; signed char* values; short count; };

extern "C" struct CombatantStruct* _ZN9GameState21GetPartyMemberByIndexEi(struct BattleStruct* battleStruct, int combatantId);
extern "C" int _ZNK9GameState12GetTickCountEv(struct BattleStruct* battleStruct);
unsigned char* GetFieldAt0x150(unsigned char* combatant);
extern "C" int _Z18GetField0x3acValueP9GameState(struct BattleStruct* battle);

short FindMappedMemberId02080468(void* obj, int id);
void SetEntryLowNibbleAndElement02080c68(void* obj, int id, int value);
void SetElementFlag0x40(struct Obj2081* obj, int id, int value);
void DispatchWithShortB4_0205eaa0(struct Obj0205eaa0* obj, int a, int b);
void ResetWithSub0208203c(struct Obj0208203c* obj);
struct Element020de650* FindElementByKey020dedd0(struct Container020dedd0* c, int key);
void CallFunc0204c804OnMatchingKey(struct Obj2081* obj, int key);
void CallFunc0204c804OnNonMatchingKey(struct Cont0207fdf0* obj, int key);
int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
signed char LookupValueByKey020a0b3c(struct KeyMap020a0b3c* map, int key);
unsigned int ComputeRatio_02175898(char* obj, void* s);
int CheckRatioWithinCap_021758cc(char* self, int cap);
void TrySpendResource_02175924(char* self);
int EvalOrDispatch020de194(void* obj);
int GetGlobalField0x1c020421a0();
void ReinitController02043204(char* obj);
void SetOrClearBitInArray(void* a, unsigned char* b, int c, int d);
void ZeroInitReturn020de824(void* obj);
void InitStruct0207cbe8(char* obj);
extern "C" unsigned int _u32_div_f(unsigned int a, unsigned int b);

extern "C" void func_ov003_02178548(void* self);
extern "C" void func_ov003_021767ec(void* self);
extern "C" void func_ov003_021769ec(void* self);
extern "C" void func_ov003_02176ed4(void* self);
extern "C" void func_ov003_02176f94(void* self);
extern "C" void func_ov003_021748c4(unsigned char* self);
extern "C" void func_ov003_021785d4(unsigned char* obj);
extern "C" void func_ov023_021dcae0(struct Obj021dcae0* obj, int val);
extern "C" void func_ov023_021ddf5c(void* obj, signed char v);
extern "C" int func_ov003_021765b4(void* self);
extern "C" int func_ov003_021766e8(void* self);
extern "C" ARM int func_ov003_021764f4(unsigned char* self);
extern "C" int func_ov003_021784bc(void* self, int key, unsigned int kind, int d);
extern "C" void func_ov003_02176468(unsigned char* self);
extern "C" void func_ov003_02177208(char* obj);
extern "C" void func_ov003_0217726c(char* obj);
extern "C" void func_ov003_02177300(char* self);
extern "C" void func_ov003_02177410(void* self);
extern "C" void func_ov003_02177550(void* self);
extern "C" void func_ov003_02177820(char* self);
extern "C" int func_ov003_02178218(void* unused);
extern "C" int func_ov003_021782a0(struct Obj2081* obj);
extern "C" void func_ov003_02175cb0(char* base, int flag);
extern "C" void func_ov003_0217599c(void* self);
extern "C" int func_020dd4c4(int val, void* elem);
extern "C" int func_ov003_0217839c(int val, void* elem);
extern "C" void* func_ov003_02179cfc(char* base, int combatantId, void* fallback);
extern "C" void* func_0205ec34(void);
extern "C" int func_02081f20(void* obj, int scaleCount);
extern "C" void func_0207ccf0(void* ctx, int key, int cap, int elemId, int a5, int a6, int a7);

extern unsigned short data_02114e30;
extern struct Obj0205eaa0 data_02108760;

static inline void SetSelection(unsigned char* self, signed char v) {
    *(signed char*)(self + (0x7b6 - kRegionSelfShift)) = v;
    func_ov023_021ddf5c(self + 0x3c, v);
}

static inline int IsLowKind(struct Element020de650* e) { return e->nibble <= 7; }

// USA: func_ov003_02178910
// JPN: func_ov003_021777d4
extern "C" ARM void func_ov003_02178910(unsigned char* self) {
    struct BattleStruct* battle = _ZN9GameState11GetInstanceEv();
    void* battleSum = _Z17GetPtrField0x2a04P9GameState(battle);
    struct Obj2081* elemObj = *(struct Obj2081**)(self + (0x89c - kRegionSelfShift));
    int state = *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift));

    if (state == 0) {
        CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        return;
    }

    if (state == 1) {
        *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 3;
        if (*(short*)(self + (0x1000 + 6 - kRegionSelfShift)) < 0) {
            short id = FindMappedMemberId02080468(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
            *(short*)(self + (0x1000 + 6 - kRegionSelfShift)) = id;
        }
        *(short*)((char*)elemObj + kRegionElementCursor) = *(short*)(self + (0x1000 + 6 - kRegionSelfShift));
        SetEntryLowNibbleAndElement02080c68(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)), 0);
        SetElementFlag0x40(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)), 0);
        func_ov003_02178548(self);
        func_ov003_021767ec(self);
        func_ov003_021769ec(self);
        func_ov003_02176ed4(self);
        func_ov003_02176f94(self);
        ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        func_ov003_021748c4(self);
        if (*(unsigned char*)(self + (0x1000 + 0x4d - kRegionSelfShift)) != 0) {
            signed char negOne = -1;
            SetSelection(self, negOne);
            *(unsigned char*)(self + (0x1000 + 0x4d - kRegionSelfShift)) = 0;
        }
        return;
    }

    if (state == 2) {
        short key = *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = self + (0x1000 + 6 - kRegionSelfShift);
        func_ov003_021785d4(self);
        signed char negOne = -1;
        *(signed char*)(self + (0x7b6 - kRegionSelfShift)) = negOne;
        func_ov023_021dcae0((struct Obj021dcae0*)(self + 0x3c), *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
        int r = func_ov003_021765b4(self);
        if (r != 0 && key == *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift))) {
            *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) = 1;
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
            *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
            struct Element020de650* elem = FindElementByKey020dedd0((struct Container020dedd0*)(self + (0x874 - kRegionSelfShift)), *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
            *(void**)(self + 8) = elem;
            if (elem == 0) return;
            int kind = elem->nibble;
            int ok = func_ov003_021784bc(battleSum, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)), kind, *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift)));
            if (ok == 0) {
                CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1b;
                *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 4;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                *(short*)(self + (0x1000 + 0 - kRegionSelfShift)) = -1;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }
            int capOk = CheckRatioWithinCap_021758cc((char*)self, *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)));
            if (capOk != 0) {
                struct Element020de650* elem2a = *(struct Element020de650**)(self + 8);
                unsigned short mult = *(unsigned short*)(self + (0x800 + 0x6c - kRegionSelfShift));
                int field30 = *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift));
                int val = EvalOrDispatch020de194(elem2a);
                int product = mult * val;
                void* battleSum2 = _Z17GetPtrField0x2a04P9GameState(_ZN9GameState11GetInstanceEv());
                int kind2 = elem2a->nibble;
                int ok2 = func_ov003_021784bc(battleSum2, *(short*)((char*)elem2a + 0x18), kind2, field30);
                int result;
                if (ok2 == 1) {
                    result = 1;
                } else {
                    unsigned int q = _u32_div_f((unsigned int)product, 100);
                    unsigned int cmpval = *(unsigned int*)((char*)battleSum2 + 0xf6c);
                    result = (cmpval < (q << 1)) ? 1 : 0;
                }
                if (result != 0) {
                    CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
                    *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 2;
                    *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 5;
                    return;
                }
                SetEntryLowNibbleAndElement02080c68(elemObj, 3, 1);
                SetEntryLowNibbleAndElement02080c68(elemObj, 4, 1);
                SetEntryLowNibbleAndElement02080c68(elemObj, 5, 1);
                SetEntryLowNibbleAndElement02080c68(elemObj, 6, 1);
                SetEntryLowNibbleAndElement02080c68(elemObj, 7, 1);
                SetEntryLowNibbleAndElement02080c68(elemObj, 8, 1);
                SetEntryLowNibbleAndElement02080c68(elemObj, 0x19, 1);
                SetEntryLowNibbleAndElement02080c68(elemObj, 0x1a, 1);
                SetEntryLowNibbleAndElement02080c68(elemObj, 0x1b, 1);
                SetEntryLowNibbleAndElement02080c68(elemObj, 0x1c, 1);
                *(short*)(self + (0xf00 + 0xfc - kRegionSelfShift)) = *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift));
                (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
                return;
            }
            CallFunc0204c804OnMatchingKey(elemObj, 3);
            CallFunc0204c804OnMatchingKey(elemObj, 4);
            CallFunc0204c804OnMatchingKey(elemObj, 5);
            CallFunc0204c804OnMatchingKey(elemObj, 6);
            CallFunc0204c804OnMatchingKey(elemObj, 7);
            CallFunc0204c804OnMatchingKey(elemObj, 8);
            CallFunc0204c804OnMatchingKey(elemObj, 0x19);
            CallFunc0204c804OnMatchingKey(elemObj, 0x1a);
            CallFunc0204c804OnMatchingKey(elemObj, 0x1b);
            CallFunc0204c804OnMatchingKey(elemObj, 0x1c);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 7;
            *(unsigned char*)(self + (0x1000 + 0x3e - kRegionSelfShift)) = 1;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x2000;
            return;
        }
        int ok3 = func_ov003_021766e8(self);
        if (ok3 == 0) return;
        ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0xa;
        *(unsigned char*)(self + (0x1000 + 0x3e - kRegionSelfShift)) = 1;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0;
        CallFunc0204c804OnMatchingKey(elemObj, 3);
        CallFunc0204c804OnMatchingKey(elemObj, 4);
        CallFunc0204c804OnMatchingKey(elemObj, 5);
        CallFunc0204c804OnMatchingKey(elemObj, 6);
        CallFunc0204c804OnMatchingKey(elemObj, 7);
        CallFunc0204c804OnMatchingKey(elemObj, 8);
        CallFunc0204c804OnMatchingKey(elemObj, 0x19);
        CallFunc0204c804OnMatchingKey(elemObj, 0x1a);
        CallFunc0204c804OnMatchingKey(elemObj, 0x1b);
        CallFunc0204c804OnMatchingKey(elemObj, 0x1c);
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x2000;
        return;
    }

    if (state == 3) {
        func_ov003_02177208((char*)self);
        func_ov003_0217726c((char*)self);
        ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        *(unsigned char*)(self + (0x1000 + 0x4a - kRegionSelfShift)) = 0;
        return;
    }

    if (state == 4) {
        unsigned char counter = *(unsigned char*)(self + (0x1000 + 0x4a - kRegionSelfShift));
        int delta = 0;
        if (counter < 5) {
            *(unsigned char*)(self + (0x1000 + 0x4a - kRegionSelfShift)) = counter + 1;
        } else {
            delta = func_ov003_02178218(self);
            if (delta != 0) {
                *(unsigned char*)(self + (0x1000 + 0x4a - kRegionSelfShift)) = 0;
            }
        }

        struct BattleStruct* b2 = _ZN9GameState11GetInstanceEv();
        int scaleCount = _ZNK9GameState12GetTickCountEv(b2);
        int ratio = func_02081f20(self + (0x8c + 0x800 - kRegionSelfShift), scaleCount);
        if ((unsigned short)(ratio + 0xffff) <= 1) {
            void* p88c = *(void**)(self + (0x88c - kRegionSelfShift));
            int v = (p88c != 0) ? *(unsigned short*)p88c : 0;
            if (v == 0x40) delta = 1;
            else if (v == 0x80) delta = -1;
            else if (v == 0x20) delta = 0x83;
            else if (v == 0x10) delta = ~0x82;
        }

        if (delta != 0) {
            int newCap = *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) + delta;
            int ratioVal = ComputeRatio_02175898((char*)self, *(void**)(self + 8));
            unsigned int divIn = (ratioVal == 0) ? 1 : ratioVal;
            int q = _u32_div_f(*(unsigned int*)((char*)battleSum + 0xf6c), divIn);
            struct Element020de650* elem = *(struct Element020de650**)(self + 8);
            int kind = 0xa;
            if (elem != 0) kind = elem->nibble;
            int capVal = func_ov003_021784bc(battleSum, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)), kind, *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift)));
            if (q < capVal) capVal = q;
            if (capVal < newCap) newCap = capVal;
            if (newCap <= 1) newCap = 1;
            *(unsigned char*)(self + (0x1000 + 0x4b - kRegionSelfShift)) = (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) < newCap) ? 1 : 0;
            *(unsigned char*)(self + (0x1000 + 0x4c - kRegionSelfShift)) = (newCap < *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift))) ? 1 : 0;
            *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) = newCap;
            func_ov003_02177208((char*)self);
            func_ov003_0217726c((char*)self);
        }

        int hitZone = func_ov003_021782a0((struct Obj2081*)self);
        int flagTest = TestFlag0SetAndFlag1Clear(&data_02114e30, 0x401);
        if (flagTest != 0 || hitZone == 1) {
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1f;
            if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) == 1) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 2;
            }
            (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
            ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
            return;
        }

        int flagTest2 = TestFlag0SetAndFlag1Clear(&data_02114e30, 2);
        if (flagTest2 != 0 || hitZone == -1) {
            CallFunc0204c804OnMatchingKey(elemObj, 9);
            CallFunc0204c804OnMatchingKey(elemObj, 0xa);
            ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        }
        return;
    }

    if (state == 5) {
        func_ov003_02176468(self);
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        return;
    }

    if (state == 6) {
        int res = func_ov003_021764f4(self);
        if (res != -1) {
            if (res != 1) return;

            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) &= ~0x1000;
            TrySpendResource_02175924((char*)self);
            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
            struct Element020de650* elem = *(struct Element020de650**)(self + 8);
            if (IsLowKind(elem)) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 3;
                (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
                if (*(int*)(self + (0x1000 + 0x30 - kRegionSelfShift)) != 1) return;

                int val = _Z18GetField0x3acValueP9GameState(battle);
                *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = val;
                int check = func_020dd4c4(*(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
                if (check == 0) return;

                func_ov003_02175cb0((char*)self, 0);
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 9;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }

            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x15;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0xb;
            short st34 = *(short*)(self + (0x1000 + 0x34 - kRegionSelfShift));
        short key = *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift));
        if (st34 == 0x20 && key == 0x55f0) {
                void* base = func_0205ec34();
                SetOrClearBitInArray(base, (unsigned char*)base + 0x8c, 0x1139, 1);
            }
            return;
        }

        CallFunc0204c804OnMatchingKey(elemObj, 9);
        CallFunc0204c804OnMatchingKey(elemObj, 0xa);
        CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x2f;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        return;
    }

    if (state == 7) {
        func_ov003_02176468(self);
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        return;
    }

    if (state == 8) {
        int res = func_ov003_021764f4(self);
        if (res != -1) {
            if (res != 1) return;

            if (*(int*)(self + (0x1000 + 0x30 - kRegionSelfShift)) == 1) {
                int val = _Z18GetField0x3acValueP9GameState(battle);
                *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = val;
                void* elem2 = func_ov003_02179cfc((char*)self, *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
                int bit18 = (*(unsigned int*)((char*)elem2 + 8) << 0xd) >> 0x1f;
                if (bit18 != 0) {
                    func_ov003_02175cb0((char*)self, 0);
                    *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1e;
                    *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 9;
                } else {
                    int check2 = func_ov003_0217839c(*(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
                    if (check2 != 0) {
                        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x2e;
                        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0x32;
                        return;
                    }
                    func_ov003_0217599c(self);
                    func_ov003_02175cb0((char*)self, 0);
                    *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 8;
                    *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 4;
                }
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }

            ReinitController02043204((char*)GetGlobalField0x1c020421a0());
            (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
            return;
        }

        func_ov003_02175cb0((char*)self, 0);
        CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 9;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        if (*(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) & 0x1000) {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x23;
        }
        return;
    }

    if (state == 9) {
        int field = *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift));
        switch (field) {
        case 2:
            *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0xb;
            break;
        case 3:
            *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0xc;
            break;
        case 4:
            *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0xd;
            break;
        }

        short id1 = FindMappedMemberId02080468(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
        *(short*)(self + (0x1000 + 8 - kRegionSelfShift)) = id1;
        *(short*)((char*)elemObj + kRegionElementCursor) = *(short*)(self + (0x1000 + 8 - kRegionSelfShift));
        short id2 = FindMappedMemberId02080468(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
        short diff = *(short*)(self + (0x1000 + 8 - kRegionSelfShift)) - id2;
        int combatantId = ((int*)(self + (0x1000 + 0x1c - kRegionSelfShift)))[diff];
        *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = combatantId;
        *(unsigned char*)(self + (0x1000 + 0x44 - kRegionSelfShift)) = *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift));
        func_ov003_02177300((char*)self);
        func_ov003_02177410(self);
        func_ov003_02177550(self);
        ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        SetSelection(self, *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)));
        *(unsigned char*)(self + (0x1000 + 0x4d - kRegionSelfShift)) = 1;
        return;
    }

    if (state == 0xa) {
        *(void**)(self + (0xff8 - kRegionSelfShift)) = self + (0x1000 + 8 - kRegionSelfShift);
        short id1 = FindMappedMemberId02080468(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
        short diff = *(short*)(self + (0x1000 + 8 - kRegionSelfShift)) - id1;
        int combatantId = ((int*)(self + (0x1000 + 0x1c - kRegionSelfShift)))[diff];
        *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = combatantId;

        if (*(short*)(self + (0x1000 + 0 - kRegionSelfShift)) == *(short*)(*(void**)(self + (0xff8 - kRegionSelfShift))) &&
            *(signed char*)(self + (0x1000 + 0x44 - kRegionSelfShift)) == *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift))) {
            // matches, skip refresh
        } else {
            *(unsigned char*)(self + (0x1000 + 0x44 - kRegionSelfShift)) = *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift));
            func_ov003_02177410(self);
            func_ov003_02177550(self);
            SetSelection(self, *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)));
        }

        int ok = func_ov003_021765b4(self);
        if (ok != 0) {
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
            *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
            int check = func_020dd4c4(*(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
            if (check != 0) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x19;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 9;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }
            void* elem2 = func_ov003_02179cfc((char*)self, *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
            int bit18 = (*(unsigned int*)((char*)elem2 + 8) << 0xd) >> 0x1f;
            if (bit18 != 0) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x1e;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 9;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }
            int check2 = func_ov003_0217839c(*(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), *(void**)(self + 8));
            if (check2 != 0) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x2e;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 0x32;
                return;
            }
            func_ov003_0217599c(self);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 8;
            *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 0x1d;
            unsigned char st3f = 7;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = st3f;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x1000;
            *(signed char*)(self + (0x7b6 - kRegionSelfShift)) = st3f - 8;
            // the ROM leaves r1 unset here: this site calls with the object only
            ((void (*)(void*))func_ov023_021ddf5c)(self + 0x3c);
            if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) != 0) return;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) &= ~0x1000;
            *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 4;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
            return;
        }

        int ok3 = func_ov003_021766e8(self);
        if (ok3 == 0) return;
        ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
        func_ov003_02175cb0((char*)self, 0);
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 9;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        if (*(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) & 0x1000) {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x23;
        }
        return;
    }

    if (state == 0xb) {
        int field = *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift));
        switch (field) {
        case 1: *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0x11; break;
        case 2: *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0x12; break;
        case 3: *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0x13; break;
        case 4: *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)) = 0x14; break;
        default: break;
        }

        short id = FindMappedMemberId02080468(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
        *(short*)(self + (0x1000 + 0xa - kRegionSelfShift)) = id;
        *(short*)((char*)elemObj + kRegionElementCursor) = *(short*)(self + (0x1000 + 0xa - kRegionSelfShift));
        SetElementFlag0x40(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)), 0);
        SetEntryLowNibbleAndElement02080c68(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)), 0);
        func_ov003_02177820((char*)self);
        short id2 = FindMappedMemberId02080468(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
        short diff = *(short*)(self + (0x1000 + 0xa - kRegionSelfShift)) - id2;
        int combatantId = ((int*)(self + (0x1000 + 0x1c - kRegionSelfShift)))[diff];
        *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = combatantId;
        *(unsigned char*)(self + (0x1000 + 0x44 - kRegionSelfShift)) = *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift));
        ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        return;
    }

    if (state == 0xc) {
        *(void**)(self + (0xff8 - kRegionSelfShift)) = self + (0x1000 + 0xa - kRegionSelfShift);
        int ok = func_ov003_021765b4(self);
        if (ok != 0) {
            DispatchWithShortB4_0205eaa0(&data_02108760, 1, 0);
            ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
            *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
            short id = FindMappedMemberId02080468(elemObj, *(short*)(self + (0xf00 + 0xfe - kRegionSelfShift)));
            short diff = *(short*)(self + (0x1000 + 0xa - kRegionSelfShift)) - id;
            int combatantId = ((int*)(self + (0x1000 + 0x1c - kRegionSelfShift)))[diff];
            *(unsigned char*)(self + (0x1000 + 0x43 - kRegionSelfShift)) = combatantId;
            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);

            struct BattleStruct* battle2 = _ZN9GameState11GetInstanceEv();
            struct CombatantStruct* combatant = _ZN9GameState21GetPartyMemberByIndexEi(battle2, *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)));
            if (combatant != 0) {
                unsigned char* field150 = GetFieldAt0x150((unsigned char*)combatant);
                if (field150 == 0) return;

                short j, count;
                for (count = 0, j = 0; j < 8; j++) {
                    if (*(short*)(field150 + 0x400 + j * 2 + 0x54) <= 0) break;
                    count++;
                }

                if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) <= (8 - count)) {
                    *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x17;
                    *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                    *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                    int* p130 = *(int**)((char*)combatant + 0x130);
                    if (*p130 & 1) {
                        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x2d;
                    }
                } else {
                    *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x21;
                    *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                    *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                    void* ptr2a04 = _Z17GetPtrField0x2a04P9GameState(battle2);
                    int lookupVal = LookupValueByKey020a0b3c((struct KeyMap020a0b3c*)ptr2a04, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
                    if (lookupVal == 0x63) {
                        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x22;
                    } else {
                        int found = 0;
                        short k;
                        for (k = 0; k < 8; k++) {
                            if (*(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)) == *(short*)(field150 + 0x400 + k * 2 + 0x54)) {
                                found = 1;
                                break;
                            }
                        }
                        if (found == 0) {
                            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x16;
                        }
                    }
                }

                unsigned char localCtx[0x38];
                ((SafeAllocator*)localCtx)->ResetAllocatorPointer();
                ZeroInitReturn020de824(localCtx + 0x14);
                InitStruct0207cbe8((char*)localCtx);
                InitStruct0207cbe8((char*)localCtx);
                *(void**)(localCtx + 0x2c) = self + (0x874 - kRegionSelfShift);
                func_0207ccf0(localCtx, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)), *(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)),
                    *(signed char*)(self + (0x1000 + 0x43 - kRegionSelfShift)), 1, 1, 0);
                *(unsigned char*)(self + (0x1000 + 0x4f - kRegionSelfShift)) = 0;
                return;
            }

            CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x18;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
            void* ptr2a04b = _Z17GetPtrField0x2a04P9GameState(battle2);
            int lookupVal2 = LookupValueByKey020a0b3c((struct KeyMap020a0b3c*)ptr2a04b, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
            if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) > (0x63 - lookupVal2)) {
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x37;
            }
            func_ov003_02175cb0((char*)self, 1);
            return;
        }

        int ok3 = func_ov003_021766e8(self);
        if (ok3 == 0) return;
        CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
        ResetWithSub0208203c((struct Obj0208203c*)(self + (0x88c - kRegionSelfShift)));
        *(void**)(self + (0xff8 - kRegionSelfShift)) = 0;
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x18;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        void* ptr2a04c = _Z17GetPtrField0x2a04P9GameState(battle);
        int lookupVal3 = LookupValueByKey020a0b3c((struct KeyMap020a0b3c*)ptr2a04c, *(short*)(self + (0x1000 + 0x3a - kRegionSelfShift)));
        if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) > (0x63 - lookupVal3)) {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x37;
        }
        func_ov003_02175cb0((char*)self, 1);
        return;
    }

    if (state == 0x32) {
        func_ov003_02176468(self);
        (*(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)))++;
        return;
    }

    if (state == 0x33) {
        int res = func_ov003_021764f4(self);
        if (res != -1) {
            if (res != 1) return;

            int field = *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift));
            if (field == 1) {
                func_ov003_0217599c(self);
                func_ov003_02175cb0((char*)self, 0);
                *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 8;
                *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 4;
                *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
                *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
                return;
            }

            func_ov003_0217599c(self);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 8;
            *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 0x1d;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 7;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x1000;
            if (*(unsigned char*)(self + (0x1000 + 0x3c - kRegionSelfShift)) != 0) return;

            *(unsigned char*)(self + (0x1000 + 0x4f - kRegionSelfShift)) = 0;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) &= ~0x1000;
            *(short*)(self + (0x1000 + 0x38 - kRegionSelfShift)) = 4;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
            return;
        }

        int field = *(int*)(self + (0x1000 + 0x30 - kRegionSelfShift));
        if (field == 1) {
            func_ov003_02175cb0((char*)self, 0);
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 9;
            *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
            *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
            return;
        }
        CallFunc0204c804OnNonMatchingKey((struct Cont0207fdf0*)elemObj, 0);
        func_ov003_02175cb0((char*)self, 0);
        *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 9;
        *(unsigned char*)(self + (0x1000 + 0x3f - kRegionSelfShift)) = 1;
        *(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) |= 0x20;
        if (*(unsigned short*)(self + (0x1000 + 0x46 - kRegionSelfShift)) & 0x1000) {
            *(short*)(self + (0x1000 + 0x36 - kRegionSelfShift)) = 0x23;
        }
        return;
    }
}
