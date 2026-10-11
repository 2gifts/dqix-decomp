#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_ov011_021845f8(void*, int);
void* FindNodeById0218466c(void* obj, unsigned short id);

struct EncodedSize020e03b8;
int IsEncodedSizeEqual(int unused, struct EncodedSize020e03b8* obj, int val);
void* ResetAndReturnSelf020dfc2c(void* p);
struct Struct020dfc40;
void ResetStruct020dfc40(struct Struct020dfc40* p);
extern "C" void func_020dfec0(void*, void*, void*, unsigned int);
struct Source020e03f0;
struct StructAA8;
int ApplyPtrAndShorts(struct Source020e03f0* self, struct StructAA8* obj);


struct Sub0x150_021fa644 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

int GetField0x3acValue(GameState* battleStruct);

struct List020727d8;
void ResetListHeader020727d8(struct List020727d8* list);

struct StreamHeader;
extern "C" void func_020728ac(int, int, struct StreamHeader*, int, int, unsigned short, unsigned char);

struct Obj021fa644 {
    char pad0[8];
    unsigned short field8;
    unsigned short fieldA;
#if defined(jpn)
    char pad_c[0x28 - 0xc];
#else
    char pad_c[0x2c - 0xc];
#endif

    unsigned char field2c;
};

// JPN: func_ov023_021f9a6c
// USA: func_ov023_021fa644  (semantic: ApplyEncodedSizeOrResetList_021fa644)
extern "C" ARM void func_ov023_021fa644(Obj021fa644* obj, void* ctx, EncodedSize020e03b8* p2, int p3) {
#if defined(jpn)
 enum {regionalOffset0=0x144};
#else
 enum {regionalOffset0=0x150};
#endif
    if (p2 == 0 || p3 == 0) {
        return;
    }
    void* allocBase = func_ov011_021845f8(ctx, obj->field8);
    void* node = FindNodeById0218466c(ctx, obj->fieldA);
    if (allocBase == 0 || node == 0) {
        return;
    }

    char local[0x18];
    ResetAndReturnSelf020dfc2c(local);
    if (IsEncodedSizeEqual((int)local, p2, p3)) {
        ResetStruct020dfc40((Struct020dfc40*)local);
        func_020dfec0(local, (char*)allocBase + 4, p2, (unsigned int)p3);
        ApplyPtrAndShorts((Source020e03f0*)local, (StructAA8*)((char*)obj + 0x20));
        return;
    }

    unsigned char kind = obj->field2c;
    int flag5 = 0;
    if (kind == 1) {
        GameState* bs = GameState::GetInstance();
        int val = GetField0x3acValue(bs);
        GameObject* combatant = bs->GetPartyMemberByIndex(val);
        if (combatant != 0) {
            Sub0x150_021fa644* sub = *(Sub0x150_021fa644**)((char*)combatant + regionalOffset0);
            flag5 = sub->bit0;
        }
    } else if (kind == 2) {
    } else if (kind == 3) {
        flag5 = 1;
    }

    ResetListHeader020727d8((List020727d8*)((char*)obj + 0x20));
    func_020728ac((int)((char*)obj + 0x20), (int)((char*)allocBase + 4), (StreamHeader*)p2, p3, 0, 0, flag5);
}
