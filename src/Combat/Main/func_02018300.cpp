#include <globaldefs.h>
#include "GameState/GameState.h"
#include "System/Matrix.h"

struct Param02018b34 {
    char pad_00[0x20];
    short angle;
    char pad_22[0xa];
    unsigned char nodeId;
    unsigned char entryKey;
    unsigned short kind : 4;
    unsigned short flags : 12;
    char pad_30[0x3c];
    int distance;
    Param02018b34* next;
};
struct Entry02018b34 {
    unsigned short id;
    unsigned short flags;
    short unused;
    short angle;
    Vector3i position;
    char pad_14[0x14];
    Entry02018b34* parent;
    char pad_2c[8];
    short destinationAngle;
    short verticalAngle;
    short copiedAngle;
    short duration;
    Vector3i destination;
    Vector3i direction;
};
struct Owner02018b34 {
    unsigned short id;
    char pad_02[0x6a];
    unsigned char list[0x7b8];
    Entry02018b34** entries;
    int unused828;
    int entryCount;
    unsigned char state;
};
struct Entry_02028bd0;
struct Obj02028c64;
struct Obj0205eaa0;
struct Obj020397cc;
struct ProtagonistSpeed {
    char pad_00[0xb2];
    short speed;
};
struct SoundTable { int values[5]; };
struct EventParameter {
    char pad_00[0xc];
    int ownerId;
    char pad_10[0xc];
    unsigned short nodeId;
    unsigned short entryKey;
    char pad_20[8];
    short angle;
    char pad_2a[0xa];
};
Entry02018b34* FindEntryByNodeIdAndKey(Owner02018b34*, Param02018b34*);
extern "C" void* func_0205ec34();
void LookupAndForEachNodeIfMatch02064b24(void*, int, unsigned short, void*);
int fix32ReduceAngle0To2Pi(int);
int fix32cos(int);
int fix32sin(int);
void Vector3fixMultiplyScalar(const Vector3i*, int, Vector3i*);
void* GetPointerFromArray0x3c(unsigned char*, unsigned int);
void DispatchWithShortB4_0205eaa0(Obj0205eaa0*, int, int);
void CancelPendingAction020397cc(Obj020397cc*, int);
int FindMatchingElementIndex02018bc4(unsigned char*, void*);
void EnqueueEventTag175_021d196c(unsigned short, unsigned short, int);
Entry_02028bd0* GetEntryTableBase();
Obj02028c64* FindInlineEntryById(Entry_02028bd0*, int);
void SetFlagBit02028c64(Obj02028c64*, int);
extern const SoundTable data_020e6e74;
extern Obj0205eaa0 data_02108760;

// USA: func_02018300
extern "C" ARM void func_02018300(Owner02018b34* self, Param02018b34* param, int sound, int forced, int notify) {
    Entry02018b34* entry = FindEntryByNodeIdAndKey(self, param);
    if (!entry) return;
    if (!forced && (param->flags & 8)) return;
    if (!forced && (param->flags & 4)) return;
    if (!forced) {
        void* manager = func_0205ec34();
        EventParameter event;
        event.angle = param->angle;
        event.entryKey = param->entryKey;
        event.nodeId = param->nodeId;
        event.ownerId = self->id;
        LookupAndForEachNodeIfMatch02064b24(manager, 17, 108, &event);
        LookupAndForEachNodeIfMatch02064b24(manager, 3, 108, &event);
        if (param->flags & 4) {
            param->flags = (unsigned short)(param->flags & ~4);
            param->flags = (unsigned short)(param->flags & ~1);
            return;
        }
    }
    if (param->flags & 32) {
        short angle = fix32ReduceAngle0To2Pi((short)(param->angle + 0x1922));
        int cosine = fix32cos(angle);
        Vector3i direction;
        direction.x = fix32sin(angle);
        direction.y = 0;
        direction.z = cosine;
        Vector3fix_Normalize(&direction, &direction);
        Vector3fixMultiplyScalar(&direction, param->distance, &direction);
        Vector3i unit;
        Vector3fix_Normalize(&direction, &unit);
        entry->direction = unit;
        Vector3i destination;
        Vector3fix_Add(&entry->position, &direction, &destination);
        entry->destination = destination;
        entry->duration = 0x266;
    } else {
        int delta = (param->flags & 64) ? 0x1922 : 0x141b;
        if (param->flags & 256) {
            if (param->flags & 128) {
                entry->flags |= 16;
                if (param->flags & 2) {
                    entry->destinationAngle = entry->angle - delta;
                    entry->copiedAngle = entry->destinationAngle;
                } else {
                    entry->destinationAngle = entry->angle + delta;
                    entry->copiedAngle = entry->destinationAngle;
                }
            } else entry->flags |= 4;
        } else {
            if (param->flags & 128) entry->flags |= 16;
            if (param->flags & 2) {
                entry->destinationAngle = entry->angle - delta;
            } else {
                entry->destinationAngle = entry->angle + delta;
            }
        }
        entry->verticalAngle = 0x199;
    }
    param->flags = (unsigned short)(param->flags | 1);
    entry->flags |= 1;
    for (int i = 0; i < self->entryCount; i++) {
        Entry02018b34* child = self->entries[i];
        if (child->parent == entry) {
            child->flags |= 1;
            break;
        }
    }
    Param02018b34* current = (Param02018b34*)GetPointerFromArray0x3c(self->list, 2);
    while (current) {
        if (current->nodeId == param->nodeId && current->entryKey == param->entryKey)
            current->flags = (unsigned short)(current->flags | 1);
        current = current->next;
    }
    if (sound) {
        SoundTable sounds = data_020e6e74;
        DispatchWithShortB4_0205eaa0(&data_02108760, sounds.values[param->kind], 0);
    }
    if (forced && (param->flags & 8)) {
        GameObject* protagonist = GameState::GetInstance()->GetProtagonist();
        ((ProtagonistSpeed*)protagonist)->speed = 0;
        CancelPendingAction020397cc((Obj020397cc*)protagonist, 1);
        self->state = 8;
        return;
    }
    int index = FindMatchingElementIndex02018bc4((unsigned char*)self, param);
    if (forced && notify) EnqueueEventTag175_021d196c(self->id, (unsigned short)index, sound);
    Obj02028c64* flags = FindInlineEntryById(GetEntryTableBase(), self->id);
    if (flags && !(param->flags & 512)) SetFlagBit02028c64(flags, index);
}
