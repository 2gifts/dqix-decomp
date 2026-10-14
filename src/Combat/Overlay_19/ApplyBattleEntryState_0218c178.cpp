#include <globaldefs.h>

#if defined(jpn)
enum { kFlagsOffset = 0x3c, kAnimationOffset = 0x44 };
#else
enum { kFlagsOffset = 0x4c, kAnimationOffset = 0x54 };
#endif

#include "GameState/GameState.h"

struct Container0205a3d0;
struct Container0205a330;

struct Entry0205a3d0 {
    char pad0[4];
    unsigned short f4;
    unsigned short f6;
    char pad8[0xd];
    unsigned char f15;
};

struct Obj0218c178 {
    char pad0[kFlagsOffset];
    int flags;
    char pad50[0x40];
    struct Container0205a3d0* container;
};

void SetEntryFlag2ByKey0205a370(struct Container0205a3d0*, int);
struct Entry0205a3d0* FindEntryByHalfword0205a3d0(struct Container0205a3d0*, int);
void IterateEntries0205a330(struct Container0205a330*, int);
void SetEntryByte14ByKey0205a42c(struct Container0205a3d0*, int, int);
extern "C" void func_0205ae8c(void*);

// USA: func_ov019_0218c178  (semantic: ApplyBattleEntryState_0218c178)
extern "C" ARM void func_ov019_0218c178(struct Obj0218c178* obj) {
    GameState* battle = GameState::GetInstance();
    if (obj->flags & 1) {
        struct Container0205a3d0* c = obj->container;
        if (c != NULL) {
            struct Entry0205a3d0* e;
            SetEntryFlag2ByKey0205a370(c, 1);
            e = FindEntryByHalfword0205a3d0(c, 1);
            if (e != NULL) {
                e->f15 = e->f15 | 8;
            }
            IterateEntries0205a330(
                (struct Container0205a330*)c, battle->GetTickCount());
            e = FindEntryByHalfword0205a3d0(c, 1);
            if (e != NULL) {
                e->f4 = 0xd7;
                e->f6 = 0x96;
            }
            SetEntryByte14ByKey0205a42c(c, 1, 0x24);
        }
        func_0205ae8c((char*)obj + kAnimationOffset);
    } else {
        struct Container0205a3d0* c = obj->container;
        if (c != NULL) {
            struct Entry0205a3d0* e = FindEntryByHalfword0205a3d0(c, 1);
            if (e != NULL) {
                e->f15 = e->f15 & ~8;
            }
        }
    }
}
