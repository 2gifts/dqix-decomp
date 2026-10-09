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
};

int GetField0x60(StructF0x60_0203cdd0 *obj);
int GetField0x8(int *obj);
void *GetField0xc02040538(S02040538 *p);
