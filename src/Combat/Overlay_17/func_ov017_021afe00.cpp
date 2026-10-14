#include <globaldefs.h>
#include "Combat/SearchEntry.h"
#include "GameState/GameState.h"
#include "Resource/Brightness.h"
#include "System/Graphics.h"

struct SearchStruct;
struct SearchStruct0202c1a4;
struct AxisFloats0203b57c;
struct S_e830;
struct AllocatorUnion;

struct PartyView021afe00 {
    char pad0[0x1b2];
    unsigned short f1b2;
};

struct Alloc021afe00 {
    unsigned char b0;
    char pad1[3];
    char a4[0x190];
    char a194[0x110];
    char a2a4[0x20];
    unsigned int w2c4;
    unsigned int w2c8;
    unsigned int w2cc;
    unsigned short h2d0;
    unsigned short h2d2;
    unsigned char b2d4;
    unsigned char b2d5;
    unsigned short h2d6[4];
};

struct Step021afe00 {
    char unk0[4];
    signed char* ptr4;
    char unk8;
    unsigned char state;
    unsigned char retA;
    unsigned char unkB;
    unsigned char idxC;
    char unkD[0x1b - 0xd];
    unsigned char slots[0x38 - 0x1b];
    unsigned int field4Bits;
    int axis;
    unsigned short clearColor;
    unsigned char restoreDisplay;
    char unk43[0x288 - 0x43];
    Alloc021afe00* alloc;
};

struct Sub021afe00 {
    char pad0[0x1b34];
    unsigned int w34;
    unsigned int w38;
    unsigned int w3c;
    char pad40[0x1b48 - 0x1b40];
    unsigned int w48;
    char pad4c[0x1b62 - 0x1b4c];
    unsigned char b62;
};

struct GrottoHead021afe00 {
    unsigned char flag;
};

extern "C" void* func_0202ae18();
extern "C" void* func_02012fe4();
extern "C" void func_020531f0(void* p);
extern "C" void func_ov017_021cff8c(int a, int b);
extern "C" void func_ov017_021d0b30(int a, int b, int c);

int TestBitBySignedByteIndex_0202c1c0(SearchStruct* obj, int index);
signed char GetSearchStructCurrentArrEntry(SearchStruct0202c1a4* obj);
int GetAxisIntValue(AxisFloats0203b57c* obj, int index);
int IsChannelValueZero0203b5e0(void* obj, int index);
unsigned short GetFieldAt0x7e_0201e830(S_e830* obj);
void Set3DClearColor_020c5588(int a, int b, int c, int d, int e);
unsigned int GetField4_0203b4d0(unsigned int* obj);
void ClearBitsInField4_0203b4e8(unsigned int* obj, unsigned int mask);
void SetBitsInField4_0203b4d8(unsigned int* obj, unsigned int mask);
int CheckSubstructByte0x7cPositive_020535c8(signed char* obj);
int GetField1c_021a193c(int* obj);
int GetField0x3acValue_020100a8(GameState* gs);
void* AllocateAligned4_02012d88(AllocatorUnion* alloc, unsigned int size);
void* GetField0x74deForValidIndex_020120a0(char* gs, unsigned int idx);
unsigned int GetWord0x71f8_02012078(void* gs);
void ClearAllTreasureMapUnknownBits_020116c8(void* gs);
void SetCombatModeFromCase020dc2d0(int v);

extern AllocatorUnion data_02114e20;

// USA: func_ov017_021afe00
extern "C" ARM int func_ov017_021afe00(Step021afe00* self) {
    GameState* gs = GameState::GetInstance();
    SearchStruct* search = (SearchStruct*)func_0202ae18();
    for (int i = 0; i < 4; i++) {
        if (TestBitBySignedByteIndex_0202c1c0(search, i) == 0) {
            continue;
        }
        if (i == GetSearchStructCurrentArrEntry((SearchStruct0202c1a4*)search)) {
            continue;
        }
        SearchEntry0202c178* e = GetEntryBySignedByteIndex_0202c178(search, i);
        if (e == 0) {
            continue;
        }
        if (e->active == 0) {
            return self->retA;
        }
    }
    self->unkB = 1;
    char* g = (char*)func_02012fe4();
    Sub021afe00* sub = (Sub021afe00*)(g + 0x840);
    if (self->state != 2) {
        GameResources* res = func_ov017_0218b5b0();
        if (IsBrightnessTransitionActive(res) != 0) {
            return 1;
        }
        self->axis = GetAxisIntValue((AxisFloats0203b57c*)res, 0);
        if (IsChannelValueZero0203b5e0(res, 0) != 0) {
            self->restoreDisplay = 1;
            DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
            char* info = (char*)func_02012fe4();
            if (info != 0) {
                S_e830* color = (S_e830*)(info + 0x6c);
                if (color != 0) {
                    self->clearColor = GetFieldAt0x7e_0201e830(color);
                }
            }
            int clear = 0;
            if (self->axis == 0x10) {
                clear = 0x7fff;
            }
            Set3DClearColor_020c5588(clear, 0x1f, 0x7fff, 0, 0);
            self->field4Bits = GetField4_0203b4d0((unsigned int*)res);
            ClearBitsInField4_0203b4e8((unsigned int*)res, 0xffffffff);
            SetBitsInField4_0203b4d8((unsigned int*)res, 0x8de);
            SetMainBrightness(res, 0, 2);
        }
        for (int i = 0; i < 4; i++) {
            GameObject* m = gs->GetPartyMemberByIndex(i);
            if (m != 0) {
                if (CheckSubstructByte0x7cPositive_020535c8((signed char*)m) != 0) {
                    func_020531f0(m);
                }
            }
        }
        if (self->ptr4 != 0) {
            if (*self->ptr4 == 2) {
                if (GetField1c_021a193c(*(int**)((char*)func_ov017_0218b5b0() + 0x3708)) != 0) {
                    DISPCNT = (DISPCNT & ~0x1f00) | 0x700;
                }
            } else {
                DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
            }
        } else {
            DISPCNT = (DISPCNT & ~0x1f00) | 0x100;
        }
    }
    if (self->state == 1) {
        func_ov017_021cff8c(GetField0x3acValue_020100a8(gs), 0);
    }
    if (self->state == 2 || self->state == 0) {
        self->alloc = (Alloc021afe00*)AllocateAligned4_02012d88(&data_02114e20, 0x2e0);
    }
    if (self->state == 0) {
        Alloc021afe00* a = self->alloc;
        if (self->alloc != 0) {
            a->b0 = *(unsigned char*)((char*)gs + 0x5cda);
            memcpy(a->a4, (char*)gs + 0x5cdc, 0x190);
            memcpy(a->a194, (char*)gs + 0x5e6c, 0x110);
            memcpy(a->a2a4, GetField0x74deForValidIndex_020120a0((char*)gs, 0), 0x20);
            a->w2c4 = GetWord0x71f8_02012078(gs);
            a->w2c8 = sub->w34;
            a->h2d0 = sub->w38;
            a->h2d2 = sub->w3c;
            a->w2cc = sub->w48;
            a->b2d4 = *(unsigned short*)(g + 0x27b4);
            a->b2d5 = *(unsigned short*)(g + 0x27b6);
            for (int i = 0; i < 4; i++) {
                PartyView021afe00* m = (PartyView021afe00*)gs->GetPartyMemberByIndex(i);
                if (m != 0) {
                    a->h2d6[i] = m->f1b2;
                } else {
                    a->h2d6[i] = 0;
                }
            }
        }
    }
    if (self->state == 0) {
        memset(&self->slots[0], 0, 4);
        for (int i = 0; i < 4; i++) {
            GameObject* o = gs->GetGameObjectByIndex(i);
            if (o != 0) {
                if ((*(unsigned short*)o & 0x200) != 0) {
                    self->slots[i] = 1;
                } else {
                    self->slots[i] = 2;
                }
            }
        }
        self->slots[self->idxC] = 1;
        return 2;
    }
    if (self->state == 2) {
        sub->b62 = 0;
    }
    GrottoHead021afe00* grotto = (GrottoHead021afe00*)gs->GetGrottoStruct();
    if (grotto->flag != 0 && self->state == 2) {
        ClearAllTreasureMapUnknownBits_020116c8(gs);
        SetCombatModeFromCase020dc2d0(0);
    }
    func_ov017_021d0b30(1, 0, 0);
    return 3;
}
