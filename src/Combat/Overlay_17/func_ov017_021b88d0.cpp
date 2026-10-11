// JPN: func_ov017_021b8dc8
#if defined(jpn)
enum { RegionOffset15c = 0x150 };
#else
enum { RegionOffset15c = 0x15c };
#endif

#include <globaldefs.h>
#include "GameState/GameState.h"

struct RingBuf0215fab0;

struct CombatantSnapshot_021b88d0 {
    GameObject base;
    char pad13c[RegionOffset15c - 0x13c];
    int savedField06;
    Vector3i savedPosition;
    Vector3i savedRotation;
};

struct LocalRing_021b88d0 {
    unsigned char data[3];
    unsigned char count;
};

struct Battle_021b88d0 {
    unsigned char field_0x0;
    unsigned char done;
    char pad02[0x20 - 0x02];
    unsigned char field_0x20;
    char pad21[0x24 - 0x21];
    unsigned short key;
    char pad26[0x4c - 0x26];
    int field_0x4c;
    char pad50[0x6b0 - 0x50];
    struct RingBuf0215fab0* ring;
    unsigned short state;
    char pad6b6[0x6c0 - 0x6b6];
    struct LocalRing_021b88d0 localRing;
};

extern "C" void __clear(void* buf, int n);
int GetField0x3acValue(GameState* gs);
GameObject* GetCombatantWithFlag0x1000(GameState* gs, int id);
int GetSignedByte0x2d0(void* obj);
extern "C" void func_ov000_0215fab0(struct RingBuf0215fab0* ring, unsigned char val);
extern "C" void func_ov017_021b6f9c(struct Battle_021b88d0* self);

// USA: func_ov017_021b88d0
extern "C" ARM void func_ov017_021b88d0(struct Battle_021b88d0* self, int id, int key) {
    if (self->key != key) {
        return;
    }

    GameState* gs = GameState::GetInstance();
    if (id == GetField0x3acValue(gs)) {
        if (self->state == 1) {
            self->field_0x4c = 1;
            self->state = 2;
        }
        return;
    }

    unsigned short state = self->state;
    if (state != 3 && state != 5) {
        int ids[4];
        __clear(ids, sizeof(ids));
        ids[0] = id;
        int count = 1;
        for (int i = 0; i < 4; i++) {
            GameObject* c = GetCombatantWithFlag0x1000(gs, i);
            if (c != 0 && id == GetSignedByte0x2d0(c)) {
                ids[count++] = i;
            }
        }

        for (int j = 0; j < count; j++) {
            if (self->ring != 0) {
                func_ov000_0215fab0(self->ring, ids[j]);
            } else {
                self->localRing.data[self->localRing.count++] = ids[j];
            }
            struct CombatantSnapshot_021b88d0* c =
                (struct CombatantSnapshot_021b88d0*)GetCombatantWithFlag0x100(gs, ids[j]);
            if (c != 0) {
                c->savedPosition = c->base.obj3D_.position_;
                c->savedRotation = c->base.obj3D_.rotation_;
                c->savedField06 = c->base.obj3D_.GetField06();
            }
        }
    } else if (self->field_0x20 == 0) {
        func_ov017_021b6f9c(self);
        self->done = 1;
    }
}
