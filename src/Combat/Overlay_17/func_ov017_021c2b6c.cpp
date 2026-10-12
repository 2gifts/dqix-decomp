#include <globaldefs.h>

#if defined(jpn)
enum { kCombatantHalfOffset = 0x1a6 };
#else
enum { kCombatantHalfOffset = 0x1b2 };
#endif


#if defined(jpn)
#define data_ov017_021d7f6c data_ov017_021d8814
#endif

#include "Memory/SafeAllocator.h"
#include "Filesystem/FileIO.h"
#include "GameState/GameState.h"

struct Struct02012dd0;
struct State0207dfc8;

extern "C" void* func_02057924(void);
extern "C" void func_020a0cc4(unsigned int);
extern "C" int func_02057e6c(void* list, int p1, SafeAllocator* alloc, int p2, int p3, State0207dfc8* p4);
extern "C" unsigned int _Z19GetMaxAlloc02012dd0P14Struct02012dd0(Struct02012dd0*);
void* AllocateAligned4(AllocatorUnion*, unsigned int);
extern "C" void _Z17CopyState0207dfc8P13State0207dfc8S0_(State0207dfc8*, State0207dfc8*);
extern "C" void _Z26FindNodeAndProcess02057fb4Pvii(void*, int, int);
extern "C" void _Z26EnqueueEventTag30_021d24a8i(int);

extern AllocatorUnion data_02114e20;
extern char data_ov017_021d7f6c[];

struct PartyEntry021c2b6c {
    unsigned char kind;
    unsigned char pad01[0xf];
    unsigned char enabled;
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
    unsigned short s12;
    short s14, s16, s18, s1a, s1c;
    short pad1e;
    int w20[3];
    Vector3fix pos;
    int w38[3];
    Vector3fix scale;
};

struct Obj021c2b6c {
    unsigned char pad[8];
    SafeAllocator alloc;
    unsigned char state[0x70];
    unsigned char mode;
    unsigned char step;
    unsigned char pad8e[2];
    int done;
    unsigned char pad94;
    unsigned char memberIndex;
    unsigned char needsPool;
};

// USA: func_ov017_021c2b6c
extern "C" ARM void func_ov017_021c2b6c(Obj021c2b6c* self) {
    GameState* game = GameState::GetInstance();
    GameResources* res = func_ov017_0218b5b0();
    void* list = func_02057924();
    PartyEntry021c2b6c entries[4];
    unsigned int len;
    if (self->step == 0) {
        if (_Z19GetMaxAlloc02012dd0P14Struct02012dd0((Struct02012dd0*)&data_02114e20) < 0x8000) {
            func_020a0cc4(0x8000);
            self->needsPool = 1;
        }
        void* buf = AllocateAligned4(&data_02114e20, 0x8000);
        self->alloc.CreateTypeA(buf, 0x8000);
        self->alloc.Reset();
        char* pool = res->unknown_2cc;
        _Z17CopyState0207dfc8P13State0207dfc8S0_((State0207dfc8*)(pool + 0xc40), (State0207dfc8*)self->state);
        len = 0;
        void* data = LoadFileIntoNewAllocation(data_ov017_021d7f6c, self->alloc, &len);
        if (data == 0) {
            self->mode = 3;
            return;
        }
        func_02057e6c(list, 0x11, &self->alloc, (int)data, len, (State0207dfc8*)self->state);
        self->step++;
    } else if (self->step == 1) {
        GameObject* leader = game->GetPartyMemberByIndex(self->memberIndex);
        if (leader == 0) {
            self->mode = 3;
            return;
        }
        for (int i = 0; i < 4; i++) {
            GameObject* m = game->GetPartyMemberByIndex(i);
            if (m == 0) continue;
            if (m->obj3D_.GetInheritedAlpha() == 0) continue;
            if (leader->obj3D_.GetField06() != m->obj3D_.GetField06()) continue;
            if (*(unsigned short*)((char*)m + kCombatantHalfOffset) != 0) continue;
            if (**(unsigned int**)((char*)m + 0x130) & 1) continue;
            entries[i].kind = 0;
            entries[i].enabled = 1;
            entries[i].s12 = 0;
            entries[i].s14 = -1;
            entries[i].s16 = -1;
            entries[i].s18 = -1;
            entries[i].s1a = -1;
            entries[i].s1c = -0x1000;
            entries[i].w20[0] = 0;
            entries[i].w20[1] = 0;
            entries[i].w20[2] = 0;
            entries[i].pos.x = 0;
            entries[i].pos.y = 0;
            entries[i].pos.z = 0;
            entries[i].w38[0] = 0;
            entries[i].w38[1] = 0;
            entries[i].w38[2] = 0;
            entries[i].scale.x = 0x1000;
            entries[i].scale.y = 0x1000;
            entries[i].scale.z = 0x1000;
            PartyEntry021c2b6c* e = &entries[i];
            e->bit0 = 0;
            e->bit1 = 0;
            e->bit2 = 1;
            e->bit3 = 0;
            e->bit4 = 0;
            e->bit5 = 0;
            e->bit6 = 0;
            e->bit7 = 0;
            e->pos = m->obj3D_.position_;
            e->scale = m->obj3D_.GetScale();
            _Z26FindNodeAndProcess02057fb4Pvii(list, 0x11, (int)e);
        }
        self->done = 1;
        _Z26EnqueueEventTag30_021d24a8i(self->memberIndex);
    }
}
