#include <globaldefs.h>
#include <Memory/SignedAllocator.h>
#include <std_library_functions.h>
struct S02055080;
struct Track02058b3c { char pad[0xe0]; SignedAllocatorList entries; };
struct Entry02058b3c { unsigned int time; float value, randomRange; };
struct Node02058b3c { Entry02058b3c* entry; };
struct Count02058b3c { char pad[8]; unsigned char count; };
struct Obj02058b3c { char pad[4]; unsigned int time; char pad2[0x20]; Track02058b3c* track; char pad3[0x20]; float velocity; char pad4[0x10]; float value; char pad5[6]; unsigned short index; };
void* GetField0x4Field0x20OrNull(S02055080*);
// USA: func_02058b3c
extern "C" ARM void func_02058b3c(Obj02058b3c* self) {
    Count02058b3c* counts = (Count02058b3c*)GetField0x4Field0x20OrNull((S02055080*)self->track);
    if (counts->count <= 1 || counts->count <= self->index) return;
    Node02058b3c* previous = (Node02058b3c*)self->track->entries.GetNthElement(self->index);
    if (!previous || previous->entry->time >= self->time) return;
    self->index++;
    if (self->index >= counts->count) { self->velocity = 0; return; }
    Node02058b3c* next = (Node02058b3c*)self->track->entries.GetNthElement(self->index);
    if (!next) return;
    Entry02058b3c* entry = next->entry;
    int random = rand();
    int range = (int)entry->randomRange;
    float delta = (float)((random & (range << 1)) - (int)entry->randomRange) / 100.0f;
    self->value = entry->value + entry->value * delta;
    self->velocity = self->value / (float)(int)(next->entry->time - previous->entry->time);
    if (self->velocity < 0.0f) self->velocity += 360.0f;
    if (self->velocity > 360.0f) self->velocity -= 360.0f;
}
