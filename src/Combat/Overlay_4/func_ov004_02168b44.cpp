#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"
#include "GameState/GameState.h"

#if defined(jpn)
enum { extensionOffset = 0x144, slotsOffset = 0x7280, contextBytes = 0x24, tableOffset = 0x6fbc, fieldOffset = 0x543c, entryOffset = 0x8c, pointerOffset = 0x3964, flagOffset = 0x1790, firstOffset = 0x1794, secondOffset = 0x17b8 };
#else
enum { extensionOffset = 0x150, slotsOffset = 0x74c0, contextBytes = 0x1a4, tableOffset = 0x71fc, fieldOffset = 0x569c, entryOffset = 0x6c, pointerOffset = 0x3b84, flagOffset = 0x1962, firstOffset = 0x1964, secondOffset = 0x1988 };
#endif

struct S_a0870;
struct S_a08a4;
struct S_a08d8;
struct S_a090c;
struct S_e830;
int GetFieldPercentOver307(struct S_a0870* p);
int GetFieldPercentOver232(struct S_a08a4* p);
int GetFieldPercentOver944(struct S_a08d8* p);
int GetFieldPercentOver448(struct S_a090c* p);
int GetFieldAt0x7e(struct S_e830* p);
int GetFieldAt0x0(int* obj);
extern "C" int _Z24UpdatePlayClocks020ac4f8i(int commit);
extern "C" int _Z23LoadBattleBlock020ac4c0Pv(void* dst);
int CopyOutBattleField0x7ac0(void* dst);
unsigned int GetWord(unsigned int* obj);
unsigned int GetField4(unsigned int* obj);
unsigned int GetField8(unsigned int* obj);
void SetBitsInWord(unsigned int* obj, unsigned int mask);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void Set3DClearColor(int color, int alpha, int depth, int polygonId, int fogEnable);
extern "C" int _Z26GetGlobalField0x1c020421a0v(void);
extern "C" void _Z24ReinitController02043204Pc(char* obj);
void SetFieldsAt0x4And0x8(int* obj, int a, int b);
extern "C" void* _Z24GetNodeIfType11_02168ad4Pvi(void* a, int id);
extern "C" void* func_02012fe4(void);
extern "C" void* func_0202ae18(void);
extern "C" void* func_ov011_021845f8(void* ctx, int v);
extern "C" void func_ov011_021848a0(void* obj, int val);
#if defined(jpn)
extern "C" void* func_ov004_02168f08(void* ctx, int value);
#define NODE_LOOKUP_CALL func_ov004_02168f08
#else
extern "C" void* func_ov023_021f6524(void* ctx, int value);
#define NODE_LOOKUP_CALL func_ov023_021f6524
#endif

// entry of the 3-slot table at battleStruct+slotsOffset
struct Slot3_02168b44 {
    char pad[6];
    signed char state;
    unsigned char f7;
    unsigned char f8;
    signed char f9;
};

// the 0xb0 block filled in by _Z23LoadBattleBlock020ac4c0Pv (same object S_a0870/S_a08a4/... describe)
struct Blk02168b44 {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    unsigned short f04;
    unsigned char f06;
    unsigned char f07;
    unsigned int f08 : 24;
    unsigned int f08hi : 8;
    unsigned int f0cA : 14;
    unsigned int f0cB : 14;
    unsigned int f0cC : 4;
    unsigned int f10A : 9;
    unsigned int f10B : 14;
    unsigned int f10C : 9;
    unsigned int f14A : 9;
    unsigned int f14B : 9;
    unsigned int f14C : 11;
    unsigned int f14D : 3;
    char rest[0xb0 - 0x18];
};

// the 0x18-byte packed record allocated into ctx->f194
struct Packed02168b44 {
    unsigned int w0A : 14;
    unsigned int w0B : 17;
    unsigned int w0C : 1;
    unsigned int w4A : 14;
    unsigned int w4B : 17;
    unsigned int w4C : 1;
    unsigned int w8A : 7;
    unsigned int w8B : 7;
    unsigned int w8C : 7;
    unsigned int w8D : 7;
    unsigned int w8E : 4;
    unsigned int wcA : 10;
    unsigned int wcB : 14;
    unsigned int wcC : 7;
    unsigned int wcD : 1;
    unsigned int w10A : 9;
    unsigned int w10B : 14;
    unsigned int w10C : 7;
    unsigned int w10D : 2;
    short f14;
    unsigned char f16 : 1;
};

struct Ctx02168b44 {
#if !defined(jpn)
    char pad[0x180];
#endif
    unsigned int f180;
    unsigned int f184;
    unsigned int f188;
    unsigned short f18c;
    unsigned short f18e;
    unsigned char* f190;
    struct Packed02168b44* f194;
    unsigned char f198;
    char pad199[3];
    void* f19c;
    unsigned char f1a0;
};

struct Combatant02168b44 { char pad[extensionOffset]; struct Flags02168b44* f150; };
struct Flags02168b44 { char pad[0x49c]; unsigned char bit0 : 1; };
struct Field02168b44 { unsigned int w0; unsigned int lo : 19; signed int val : 11; unsigned int hi : 2; };
struct Triple02168b44 { int a, b, c; };
class Node02168b44 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void Apply(struct Triple02168b44* t);
};

extern struct Ctx02168b44* data_ov004_02171030;
extern struct Triple02168b44 data_ov004_021700d4;

// USA: func_ov004_02168b44  (semantic: InitBattleSceneContext_02168b44)
extern "C" ARM int func_ov004_02168b44(void* a) {
    GameState* bs = GameState::GetInstance();
    void* obj = func_0202ae18();
    struct Slot3_02168b44* slot = (struct Slot3_02168b44*)((char*)bs + slotsOffset);
    int i;
    for (i = 0; i < 3; i++, slot++) {
        if (slot->state >= 4) {
            if (slot->f7 != 0 || slot->f8 != 0 || slot->f9 >= 0) return 1;
        }
    }
    int kind = GetFieldAt0x0((int*)obj);
    int depth = *((unsigned char*)obj + 0x100d);
    int commit = 0;
    if ((kind == 5 && depth > 1) || kind == 6) commit = 1;
    _Z24UpdatePlayClocks020ac4f8i(commit);

    data_ov004_02171030 = 0;
    void* holder = func_ov011_021845f8(a, 0);
    if (!holder) return 0;
    struct Ctx02168b44* ctx =
        (struct Ctx02168b44*)((SafeAllocator*)((char*)holder + 4))->Allocate(contextBytes);
    data_ov004_02171030 = ctx;
    if (!ctx) return 0;
    ctx->f180 = 0;
    ctx->f184 = 0;
    ctx->f188 = 0;
    ctx->f18c = 0;
    ctx->f198 = 0;
    ctx->f190 = 0;
    ctx->f194 = 0;
    ctx->f19c = 0;
    ctx->f1a0 = 1;
    data_ov004_02171030->f190 = (unsigned char*)bs + tableOffset;

    struct Blk02168b44 blk;
    int ok = _Z23LoadBattleBlock020ac4c0Pv(&blk);
    unsigned int score = 0;
    CopyOutBattleField0x7ac0(&score);
    if (score > 0x1869f) score = 0x1869f;
    int bit = 0;
    struct Combatant02168b44* c =
        (struct Combatant02168b44*)bs->GetProtagonist();
    if (c) bit = c->f150->bit0;
    struct Field02168b44* fld = (struct Field02168b44*)((char*)bs + fieldOffset);
    data_ov004_02171030->f194 =
        (struct Packed02168b44*)((SafeAllocator*)((char*)holder + 4))->Allocate(0x18);
    memset(data_ov004_02171030->f194, 0, 0x18);

    if (ok) {
        data_ov004_02171030->f194->w0A = blk.f00;
        data_ov004_02171030->f194->w8A = blk.f02;
        data_ov004_02171030->f194->w4A = blk.f04;
        data_ov004_02171030->f194->w8B = blk.f06;
        data_ov004_02171030->f194->w4B = blk.f08;
        data_ov004_02171030->f194->w0B = score;
        data_ov004_02171030->f194->wcA = blk.f10A;
        data_ov004_02171030->f194->w10A = blk.f08hi;
        data_ov004_02171030->f194->wcB = blk.f0cB;
        data_ov004_02171030->f194->w10B = blk.f10B;
        data_ov004_02171030->f194->w8C =
            (unsigned char)GetFieldPercentOver307((struct S_a0870*)&blk);
        data_ov004_02171030->f194->w8D =
            (unsigned char)GetFieldPercentOver232((struct S_a08a4*)&blk);
        data_ov004_02171030->f194->wcC =
            (unsigned char)GetFieldPercentOver944((struct S_a08d8*)&blk);
        data_ov004_02171030->f194->w10C =
            (unsigned char)GetFieldPercentOver448((struct S_a090c*)&blk);
        data_ov004_02171030->f194->f14 = fld->val;
        data_ov004_02171030->f194->f16 = bit;
    }

    data_ov004_02171030->f19c = ((SafeAllocator*)((char*)holder + 4))->Allocate(0x800);
    memset(data_ov004_02171030->f19c, 0, 4);

    void* base = func_02012fe4();
    if (!base) return 0;
    struct S_e830* rec = (struct S_e830*)((char*)base + entryOffset);
    if (!rec) return 0;
    data_ov004_02171030->f18c = GetFieldAt0x7e(rec);

    unsigned int* w = (unsigned int*)func_ov017_0218b5b0();
    data_ov004_02171030->f180 = GetWord(w);
    data_ov004_02171030->f184 = GetField4(w);
    data_ov004_02171030->f188 = GetField8(w);
    SetBitsInWord(w, 4);
    SetBitsInField4(w, 0x8de);
    Set3DClearColor(0, 0, 0x7fff, 0, 0);

    struct Node02168b44* node = (struct Node02168b44*)NODE_LOOKUP_CALL(a, 0x64);
    if (data_ov004_02171030->f190[0] <= 8) {
        *(short*)((char*)node + 0x5c) = 0;
        *(short*)((char*)node + 0x5e) = 1;
    } else {
        *(short*)((char*)node + 0x5c) = 0;
        *(short*)((char*)node + 0x5e) = 2;
    }

    unsigned char* tbl = *(unsigned char**)((char*)w + pointerOffset);
    if (data_ov004_02171030->f190[0] == 0) {
        func_ov011_021848a0(a, 0x65);
    } else if (tbl[9] != 0) {
        func_ov011_021848a0(a, 0x67);
        struct Node02168b44* nd = (struct Node02168b44*)_Z24GetNodeIfType11_02168ad4Pvi(a, 2);
        struct Triple02168b44 tmp = data_ov004_021700d4;
        nd->Apply(&tmp);
    } else {
        func_ov011_021848a0(a, 0x64);
    }

    char* g = (char*)_Z26GetGlobalField0x1c020421a0v();
    _Z24ReinitController02043204Pc(g);
    *(unsigned char*)(g + flagOffset) = 1;
    SetFieldsAt0x4And0x8((int*)(g + firstOffset), 9, 1);
    SetFieldsAt0x4And0x8((int*)(g + secondOffset), 0x19, 1);
    return 0;
}
