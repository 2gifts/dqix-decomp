#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
#include <std_library_functions.h>

struct S02055080;
struct Track020589b8 { char pad[0xd4]; SignedAllocatorList entries; };
struct Entry020589b8 { unsigned int time; float value0; float value1; float randomRange; };
struct Node020589b8 { Entry020589b8* entry; };
struct Count020589b8 { char pad[9]; unsigned char count; };
struct Obj020589b8 {
    char pad0[4];
    unsigned int time;
    char pad1[0x20];
    Track020589b8* track;
    char pad2[0x18];
    float velocity0;
    float velocity1;
    char pad3[0xc];
    float value0;
    float value1;
    char pad4[8];
    unsigned short index;
};
void* GetField0x4Field0x1cOrNull(S02055080*);

// USA: func_020589b8
extern "C" ARM void func_020589b8(Obj020589b8* self) {
    Count020589b8* counts = (Count020589b8*)GetField0x4Field0x1cOrNull((S02055080*)self->track);
    if (counts->count <= 1 || counts->count <= self->index) return;
    Node020589b8* previous = (Node020589b8*)self->track->entries.GetNthElement(self->index);
    if (!previous || previous->entry->time >= self->time) return;
    self->index++;
    if (self->index >= counts->count) {
        self->velocity0 = 0;
        self->velocity1 = 0;
        return;
    }
    Node020589b8* next = (Node020589b8*)self->track->entries.GetNthElement(self->index);
    if (!next) return;
    Entry020589b8* entry = next->entry;
    int random = rand();
    int range = (int)entry->randomRange;
    float delta = (float)((random & (range << 1)) - (int)entry->randomRange) / 100.0f;
    float prevValue0 = self->value0;
    float prevValue1 = self->value1;
    self->value0 = entry->value0 + entry->value0 * delta;
    self->value1 = next->entry->value1 + next->entry->value1 * delta;
    self->velocity0 = (self->value0 - prevValue0) / (float)(int)(next->entry->time - previous->entry->time);
    self->velocity1 = (self->value1 - prevValue1) / (float)(int)(next->entry->time - previous->entry->time);
}
