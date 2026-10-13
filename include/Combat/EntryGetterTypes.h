#pragma once

struct StructF0x60_0203cdd0 {
    char pad[0x60];
    int field60;
};

struct S02040538 {
    char pad[0xc];
    void *field0xc;
};

struct Entry_203dce4 {
    int flags;
    unsigned char unknown4[0x10];
    void* child14;
    void* child18;
    void* child1c;
};

void SetValueOnActiveChild02040af0(Entry_203dce4* entry, int value);
int GetDisplayValue020409e0(Entry_203dce4* entry);
int GetOffset0x54FromFallbackChain(Entry_203dce4* entry);

int GetField0x60(StructF0x60_0203cdd0 *obj);
int GetField0x8(int *obj);
void *GetField0xc02040538(S02040538 *p);
