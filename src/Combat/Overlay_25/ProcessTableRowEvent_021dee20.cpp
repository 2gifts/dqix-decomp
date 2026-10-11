// JPN: func_ov025_021df730
#if defined(jpn)
enum { RegionOffset770c = 0x78fc };
#else
enum { RegionOffset770c = 0x770c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct ThreeShorts021ded84 {
    unsigned short a;
    unsigned short b;
    unsigned short c;
};

struct Table_021deda0;
struct Struct0215fef0;

int ShiftRowsDown_021deda0(struct Table_021deda0* table, struct ThreeShorts021ded84* out);
void InitStruct02160030(void* obj);
void ResetBlockAndSetField0x1cToNeg1(void* p);
void ResetStruct0215fef0(struct Struct0215fef0* obj);

struct Record1_021dee20 {
    unsigned short field0x0;
    unsigned char pad1[0x8 - 0x2];
    unsigned char flags0x8;
    unsigned char flags0x9;
    unsigned char pad2[0xb - 0xa];
    unsigned char flags0xb;
    unsigned char pad3[0x10 - 0xc];
    void* sub0x10;
    void* sub0x14;
    unsigned short field0x18;
};

struct Record2_021dee20 {
    unsigned char pad0[0x20];
    unsigned short field0x20;
    unsigned short field0x22;
    unsigned short field0x24;
    unsigned char pad1[0x30 - 0x26];
    int field0x30;
};

struct Record3_021dee20 {
    unsigned char pad0[0xe];
    unsigned short field0xe;
    unsigned char pad1[0x20 - 0x10];
    int field0x20;
};

// USA: func_ov025_021dee20  (semantic: ProcessTableRowEvent_021dee20)
extern "C" ARM void func_ov025_021dee20(void* obj) {
    struct ThreeShorts021ded84 row;
    if (!ShiftRowsDown_021deda0((struct Table_021deda0*)obj, &row)) {
        return;
    }

    SafeAllocator* alloc = (SafeAllocator*)((char*)obj + 0x30);
    struct Record1_021dee20* rec = (struct Record1_021dee20*)alloc->Allocate(0x28);
    if (!rec) {
        return;
    }
    InitStruct02160030(rec);
    rec->field0x0 = row.b;

    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetCombatantByIndex(row.a);
    if (!combatant) {
        return;
    }

    rec->flags0x8 = 1;
    rec->sub0x10 = alloc->Allocate(0x34);
    void* rec2 = rec->sub0x10;
    if (!rec2) {
        return;
    }
    ResetBlockAndSetField0x1cToNeg1(rec2);
    ((struct Record2_021dee20*)rec2)->field0x30 = 0;
    ((struct Record2_021dee20*)rec->sub0x10)->field0x20 = row.a;
    ((struct Record2_021dee20*)rec->sub0x10)->field0x22 = combatant->currentStats_->primaryStats.currHP;
    ((struct Record2_021dee20*)rec->sub0x10)->field0x24 = combatant->currentStats_->primaryStats.currMP;
    rec->flags0x9 = 1;

    rec->sub0x14 = alloc->Allocate(0x24);
    void* rec3 = rec->sub0x14;
    if (!rec3) {
        return;
    }
    ResetStruct0215fef0((struct Struct0215fef0*)rec3);
    ((struct Record3_021dee20*)rec3)->field0x20 = 0;
    ((struct Record3_021dee20*)rec->sub0x14)->field0xe = row.a;
    rec->field0x18 = row.c;
    rec->flags0xb |= 4;

    *(void**)((char*)obj + RegionOffset770c) = rec;
}
