#include <globaldefs.h>
#if defined(jpn)
enum { kManagerPad = 0x496 };
#else
enum { kManagerPad = 0x476 };
#endif
#include "GameState/GameState.h"

struct Vec3 { int x; int y; int z; };
extern "C" void _ZN8Vector3iaSERKS_(int* dst, int* src);

struct Segment0217208 {
    char pad[0x1c];
    struct Vec3 pos;
    char pad2[0x88 - 0x1c - 0xc];
};

struct Entry0217208 {
    short unk0;
    short state;
    short timer;
    char pad1[0x118 - 6];
    struct Segment0217208 segments[4];
    struct Vec3 vel[4];
};

struct EntryList0217208 {
    char pad[kManagerPad];
    unsigned char count;
    char pad2[1];
    struct Entry0217208* entries;
};

// USA: func_02017208  (semantic: AdvanceActiveEntryPhysics_02017208)
extern "C" ARM void func_02017208(struct EntryList0217208* manager) {
    unsigned int scaleCount;
    int i;
    struct Entry0217208* e;
    int j;
    int k;

    scaleCount = GameState::GetInstance()->GetTickCount();

    for (i = 0; i < manager->count; i++) {
        e = &manager->entries[i];
        if (e->state == -1) continue;
        for (j = 0; j < scaleCount; j++) {
            if (e->state == 3) {
                e->timer++;
                if (e->timer > 20) {
                    e->state = -1;
                } else {
                    for (k = 0; k < 4; k++) {
                        struct Vec3 tmp;
                        struct Segment0217208* seg = &e->segments[k];
                        Vector3fix_Add((const Vector3fix*)&seg->pos, (const Vector3fix*)&e->vel[k], (Vector3fix*)&tmp);
                        _ZN8Vector3iaSERKS_((int*)&seg->pos, (int*)&tmp);
                        e->vel[k].y -= 0x40;
                    }
                }
            }
        }
    }
}
