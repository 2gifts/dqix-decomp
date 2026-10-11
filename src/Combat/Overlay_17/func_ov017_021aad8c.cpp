// JPN: func_ov017_021ab5ec
#if defined(jpn)
enum { RegionOffset2d8 = 0x228 };
#else
enum { RegionOffset2d8 = 0x2d8 };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct Obj0207fcb8;
void ClearAllBuffers0207fcb8(struct Obj0207fcb8* obj);
struct Obj0207fd00;
void CallFunc0204c8f0OverEntries0207fd00(struct Obj0207fd00* obj);
extern "C" void func_0207fe80(void* obj, int a, int b, int c);
struct Cont0207fd44;
void CallFunc0204b04cOverList0x2c(struct Cont0207fd44* obj);
struct Obj2081;
void* FindElementByByte0xc4(struct Obj2081* obj, int key);
void GetLookAndTurnOffsets020809c4(void* obj, int id, int id2, short* out1, short* out2);
int GetGlobalField0x1c020421a0(void);
struct Container0205a330;
void IterateEntries0205a330(struct Container0205a330* c, int arg);
struct Container0205a3d0;
void SetEntryFlag2ByKey0205a370(struct Container0205a3d0* c, int key);
void* FindEntryByHalfword0205a3d0(struct Container0205a3d0* c, int key);
extern "C" void func_0205ae8c(void* obj);

struct Elem0205a3d0_021aad8c {
    char pad0[4];
    short field4;
    short field6;
    char pad8[0x15 - 8];
    unsigned char flags15;
};

struct Global02d8_021aad8c {
    char pad0[RegionOffset2d8];
    void* f2d8;
    char pad1[4];
    void* f2e0;
    unsigned short f2e4;
};

struct Self021aad8c {
    char pad0[0x14];
    int state;
    void* list18;
    char pad2[0x28];
    short* f44;
    short f48;
};

// USA: func_ov017_021aad8c
extern "C" ARM void func_ov017_021aad8c(struct Self021aad8c* self) {
    if (self->state != 5) return;

    if (self->list18 != NULL) {
        void* list = self->list18;
        ClearAllBuffers0207fcb8((struct Obj0207fcb8*)list);
        CallFunc0204c8f0OverEntries0207fd00((struct Obj0207fd00*)list);
        func_0207fe80(list, 2, 1, 1);
        CallFunc0204b04cOverList0x2c((struct Cont0207fd44*)list);
    }

    if (self->f44 == NULL) return;
    if (self->f48 < 0) return;
    if (FindElementByByte0xc4((struct Obj2081*)self->list18, self->f48) == NULL) return;

    short turnDelta, lookDelta;
    GetLookAndTurnOffsets020809c4(self->list18, self->f48, *self->f44, &turnDelta, &lookDelta);
    turnDelta -= 0x10;
    lookDelta -= 3;

    struct Global02d8_021aad8c* g = (struct Global02d8_021aad8c*)GetGlobalField0x1c020421a0();
    void* cont = g->f2e0;
    int key = g->f2e4;
    void* p2d8 = g->f2d8;
    if (p2d8 != NULL && cont != NULL) {
        GameState* battle = GameState::GetInstance();
        unsigned int scaleCount = battle->GetTickCount();
        IterateEntries0205a330((struct Container0205a330*)cont, scaleCount);
        SetEntryFlag2ByKey0205a370((struct Container0205a3d0*)cont, key);

        struct Elem0205a3d0_021aad8c* e1 = (struct Elem0205a3d0_021aad8c*)FindEntryByHalfword0205a3d0((struct Container0205a3d0*)cont, key);
        if (e1 != NULL) e1->flags15 |= 8;

        short a;
        short b = lookDelta;
        a = turnDelta;
        struct Elem0205a3d0_021aad8c* e2 = (struct Elem0205a3d0_021aad8c*)FindEntryByHalfword0205a3d0((struct Container0205a3d0*)cont, key);
        if (e2 != NULL) {
            e2->field4 = a;
            e2->field6 = b;
        }

        func_0205ae8c(p2d8);
    }
}
