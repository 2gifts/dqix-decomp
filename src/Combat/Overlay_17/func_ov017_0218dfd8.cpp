#include <globaldefs.h>
#include "Graphics/Vector.h"
#include "Resource/GameResources.h"
#include "World/Object3D.h"

struct Actor0218dfd8 {
    Object3D obj3D;
#if defined(jpn)
    char pad[0x180 - sizeof(Object3D)];
#else
    char pad[0x18c - sizeof(Object3D)];
#endif
    unsigned int flags;
};

struct ActorEntry {
    char pad0[0x2];
    short state;
    char pad4[0x20];
    Vector3fix position;
    char pad30[0x368 - 0x30];
};

struct ActorListManager {
#if defined(jpn)
    char pad0[0x496];
#else
    char pad0[0x476];
#endif
    unsigned char count;
    char pad477[0x1];
    ActorEntry* entries;
};

struct Event0218dfd8 {
    unsigned char tag;
    unsigned char pad1;
    short index;
    unsigned char pad4[4];
    ActorEntry* target;
    int padc;
    short angle;
    unsigned short pad12;
};

struct Header0218dfd8 {
    unsigned char pad0[3];
    unsigned char busy;
};

extern "C" ActorListManager* func_02012fe4(void);
ActorEntry* GetActorEntryByIndex(ActorListManager* manager, int index);
unsigned int IsFlag0x1ceBit0x8Set(unsigned char* obj);
extern "C" short _Z32GetAbsAngleDeltaBetween_021a4754P4Vec3iS0_(Vector3fix* from, int baseAngle, Vector3fix* to);
int IsField0Null(void** obj);
int CheckSubstructByte0x7cPositive(signed char* obj);
extern "C" void _Z15InitObj0219a674Ph(unsigned char* self);
extern "C" void func_ov017_0219b33c(GameResources* res, Event0218dfd8* event);

// JPN: func_ov017_0218ebb8
// USA: func_ov017_0218dfd8
extern "C" ARM int func_ov017_0218dfd8(Actor0218dfd8* self) {
    GameResources* res = func_ov017_0218b5b0();
    if (((Header0218dfd8*)res->unknown_ptr_array_36fc[4])->busy != 0) {
        return 0;
    }
    Vector3fix pos = self->obj3D.position_;
    int moved = 0;
    ActorListManager* manager = func_02012fe4();
    ActorEntry* entry = GetActorEntryByIndex(manager, 0);
    if (entry == NULL) {
        return 0;
    }
    int pushRadius = self->obj3D.GetRadius() / 2 + 0x800;
    int bestAngle = 0x3244;
    int bestIndex = -1;
    ActorEntry* best = NULL;
    for (int i = 0; i < manager->count; entry++, i++) {
        if (entry->state != 0) {
            continue;
        }
        Vector3fix a = pos;
        Vector3fix b = entry->position;
        if (fix32abs(a.y - b.y) >= 0x1000) {
            continue;
        }
        a.y = 0;
        b.y = 0;
        int dist = Vector3fix_Distance(&a, &b);
        if (dist < pushRadius) {
            if (!IsFlag0x1ceBit0x8Set((unsigned char*)self)) {
                Vector3fix dir;
                Vector3fix_Subtract(&a, &b, &dir);
                Vector3fix_Normalize(&dir, &dir);
                Vector3fixMultiplyScalar(&dir, pushRadius, &dir);
                Vector3fix_Add(&b, &dir, &a);
                pos.x = a.x;
                pos.z = a.z;
                self->obj3D.position_ = pos;
            }
            moved = 1;
        }
        if (dist < pushRadius + 0x400) {
            int angle = _Z32GetAbsAngleDeltaBetween_021a4754P4Vec3iS0_(&pos, (short)self->obj3D.rotation_.y, &b);
            if (angle < bestAngle) {
                bestAngle = angle;
                bestIndex = i;
                best = entry;
            }
        }
    }
    void** list = (void**)res->unknown_ptr_array_36fc[0];
    if (best != NULL && IsField0Null(list) != 0 &&
        CheckSubstructByte0x7cPositive((signed char*)self) == 0 && !(self->flags & 0x40) && bestAngle < 0xc91) {
        Event0218dfd8 event;
        _Z15InitObj0219a674Ph((unsigned char*)&event);
        event.tag = 5;
        event.angle = bestAngle;
        event.target = best;
        event.index = bestIndex;
        func_ov017_0219b33c(res, &event);
    }
    return moved;
}
