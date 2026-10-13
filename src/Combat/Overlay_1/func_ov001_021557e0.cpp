#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov001_021557e0

extern "C" GameResources* func_ov017_0218b5b0(void);
int IsChannelValueZero0203b5e0(void* obj, int sel);
int InitAndCheckField3c_02153994(void);
extern "C" void* func_0202ae18(void);
extern "C" int func_0202c540(void* obj);
extern "C" int func_0202c508(void* obj);
void* GetData02153637(void);
struct Flags02033fcc;
void SetFlag0x4At0xe0(struct Flags02033fcc* obj);
unsigned char GetByte0x26c(char* obj);
void* GetFieldPtrAt0x26c(void* obj);
extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void* obj, const char* name, int idx);
void ClearBytesAndZeroBlock02039d24(unsigned char* obj);
extern "C" void _ZN8Object3D10EnableFlagEi(void* obj, unsigned int mask);
int GetField0x3acValue(GameState* battleStruct);
struct Base02010834;
void CopyCountedBytesToIntArray02010834(struct Base02010834* base, int index, int* out, int* outCount);
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(void* obj, int v);
void ClearFlag0x1ceBit0x4(unsigned char* obj);
void* GetDataPtr02114e04_020d6c00(void);
void* GetPtrField0x2a04(GameState* battleStruct);
struct ArrayContainsByteStruct;
int ArrayContainsByte(struct ArrayContainsByteStruct* s, int val);
struct T0205420c;
void MaybeCall0205420c(struct T0205420c* obj, int a, int b);
void DispatchOrSetupCombatant_02191f4c(int a, int b);
extern "C" void func_ov017_02192400(int a, int b);
void OrBitsIntoField0(unsigned int* p, unsigned int mask);
int CheckField0NonZero(int* obj);
unsigned char GetField0x397cValue(GameState* battleStruct);
extern "C" void func_ov017_021917f0(int a, int b);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void StoreInFirstEmptySlot(unsigned char* base, unsigned char val);
struct Self02154de4;
int ProcessAndDispatchState_02154de4(struct Self02154de4* self);

extern const char data_ov001_02164bd1[];

struct Combatant021557e0 {
    char pad0[0xc1];
    unsigned char field_c1 : 2;
    char pad1[0x130 - 0xc2];
    unsigned int* stats130;
    char pad2[0x18c - 0x134];
    unsigned int flags18c;
};

struct Self021557e0 {
    char pad0[0xa];
    unsigned short field_a;
    char pad1[0x12 - 0xc];
    unsigned char f12;
    char pad2[0x50 - 0x13];
    unsigned short f50;
    char pad3[0xf8 - 0x52];
    unsigned int flag_f8 : 27;
    unsigned int rsv_f8 : 5;
    char pad4[0x101 - 0xfc];
    unsigned char f101;
    char pad5[0x103 - 0x102];
    unsigned char f103;
    char pad6[0x116 - 0x104];
    signed char f116;
};

extern "C" ARM int func_ov001_021557e0(struct Self021557e0* self) {
    GameResources* res = func_ov017_0218b5b0();
    if (IsChannelValueZero0203b5e0(res, 0) != 0) {
        self->f101 = 1;
    }
    if (InitAndCheckField3c_02153994() != 1) {
        return self->field_a;
    }

    void* search = func_0202ae18();
    GameState* bs = GameState::GetInstance();

    if (self->f12 != 0 && func_0202c540(search) != 0) {
        self->f103 = 1;
        if (self->flag_f8 & 0x10) {
            GameObject* g = GetCombatantWithFlag0x100(bs, 0);
            ((unsigned int*)((char*)g + 0x18c))[0] |= 2;
        }
    }

    if (self->f101 != 0) {
        for (int i = 0; i < 4; i++) {
            GameObject* m = bs->GetPartyMemberByIndex(i);
            if (m == 0) {
                continue;
            }
            SetFlag0x4At0xe0((struct Flags02033fcc*)m);
            if (GetByte0x26c((char*)m) == 0 || ((unsigned char*)GetFieldPtrAt0x26c(m))[1] != 2) {
                _ZN8Object3D24MaybeSetRegularAnimationEPKci(m, data_ov001_02164bd1, 0x10);
            }
            ClearBytesAndZeroBlock02039d24((unsigned char*)m);
            _ZN8Object3D10EnableFlagEi(m, 0x800000);
        }

        int list[4];
        int count;
        CopyCountedBytesToIntArray02010834((struct Base02010834*)bs, GetField0x3acValue(bs), list, &count);
        for (int j = 0; j < count; j++) {
            GameObject* m = bs->GetPartyMemberByIndex(list[j]);
            if (m == 0) {
                continue;
            }
            _ZN8Object3D17SetInheritedAlphaEi(m, 0x1f);
            ClearFlag0x1ceBit0x4((unsigned char*)m);
        }

        unsigned int* data = (unsigned int*)GetDataPtr02114e04_020d6c00();
        void* arr = GetPtrField0x2a04(bs);
        for (int k = 0; k < 4; k++) {
            struct Combatant021557e0* c = (struct Combatant021557e0*)GetCombatantWithFlag0x100(bs, k);
            if (c == 0) {
                continue;
            }
            if (ArrayContainsByte((struct ArrayContainsByteStruct*)arr, k) != 0) {
                MaybeCall0205420c((struct T0205420c*)c, 1, 0);
            }
            DispatchOrSetupCombatant_02191f4c((int)res, k);
            func_ov017_02192400((int)res, k);
        }
        OrBitsIntoField0(data, 0x20000);
    }

    if (CheckField0NonZero((int*)search) != 0 && self->f12 != 0 && self->f116 < 0) {
        if (self->f101 != 0) {
            int limit = GetField0x397cValue(bs);
            for (int n = 0; n < 4; n++) {
                if (n == limit) {
                    continue;
                }
                struct Combatant021557e0* c = (struct Combatant021557e0*)GetCombatantWithFlag0x100(bs, n);
                if (c == 0) {
                    continue;
                }
                c->field_c1 |= 1;
                c->field_c1 |= 2;
                func_ov017_021917f0(n, 0);
                if (!(*c->stats130 & 1)) {
                    c->flags18c |= 2;
                }
            }
        }
    } else if (self->f116 >= 0) {
        struct Combatant021557e0* c = (struct Combatant021557e0*)GetCombatantWithFlag0x100(bs, self->f116);
        if (c != 0) {
            c->field_c1 |= 1;
            c->field_c1 |= 2;
            c->flags18c |= 2;
            func_ov017_021917f0(self->f116, 0);
        }
    }

    SetBitsInField4((unsigned int*)res, 0x1000);

    if (self->f50 & 0x200) {
        volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
        *reg = (*reg & ~0x1f00) | 0x1100;
    }

    if ((self->flag_f8 & 0x10) && func_0202c508(search) != 0) {
        StoreInFirstEmptySlot((unsigned char*)GetData02153637(), 1);
        return 0x12;
    }
    return ProcessAndDispatchState_02154de4((struct Self02154de4*)self);
}
