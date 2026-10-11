#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* func_02012fe4(void);

int GetField0x3b0Value(GameState* battleStruct);

struct Vec3_020406f8 {
    unsigned int v[3];
};
struct Node020406f8;
struct Obj02040adc;
struct StateWithFourPtrs02040910;

extern "C" void _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(struct Vec3_020406f8* dst, struct Node020406f8* n);
extern "C" int _Z27GetField2eOrDefault02040adcP11Obj02040adc(struct Obj02040adc* obj);
int ProcessPendingSubStates(struct StateWithFourPtrs02040910* obj, int arg1);
extern "C" void _Z23SyncBattleState0208f87cPviii(void* self, int b, int c, int d, int e);

struct Ctx02012fe4 {
#if defined(jpn)
    char pad[0x58];
#else
    char pad[0x38];
#endif
    unsigned short f38;
    char pad3a[2];
    int f3c;
};

struct Node0203de84 {
    unsigned int flags;
    char pad4[0x10];
    void* f14;
    Object3D* f18;
};

struct Roster0203de84 {
    char pad0[0xc];
    struct Node0203de84* nodes[0x20];
    char pad8c[0x98 - 0x8c];
    struct StateWithFourPtrs02040910* f98;
};

// USA: func_0203de84
// JPN: func_0203de84
extern "C" ARM void func_0203de84(void* self) {
    struct Roster0203de84* roster = (struct Roster0203de84*)self;
    int v = GetField0x3b0Value(GameState::GetInstance());
    func_ov017_0218b5b0();
    struct Ctx02012fe4* ctx = (struct Ctx02012fe4*)func_02012fe4();
    unsigned short a = ctx->f38;
    int b = ctx->f3c;
    struct Vec3_020406f8 vec;
    int i;
    for (i = 0; i < 0x20; i++) {
        if (roster->nodes[i] == NULL) continue;
        unsigned int fl = roster->nodes[i]->flags;
        if (fl & 0x8000) continue;
        if (roster->f98 != NULL && !(fl & 0x10000)) continue;
        if (!ProcessPendingSubStates((struct StateWithFourPtrs02040910*)roster->nodes[i], v))
            continue;
        if (fl & 0x20) continue;
        if (fl & 0x40) continue;
        Object3D* e = roster->nodes[i]->f18;
        if (e != NULL && e->GetFlag(0x10) != 0) continue;
        _Z29SelectVec3FromSources020406f8P13Vec3_020406f8P12Node020406f8(&vec, (struct Node020406f8*)roster->nodes[i]);
        _Z23SyncBattleState0208f87cPviii(&vec, a, 0x1000, b,
            _Z27GetField2eOrDefault02040adcP11Obj02040adc((struct Obj02040adc*)roster->nodes[i]));
    }
}
