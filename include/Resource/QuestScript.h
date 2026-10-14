#pragma once

class SafeAllocator;
struct Node020958fc;
struct Node02095910;

// Known linked-list prefix of the global Quest script owner.
struct Header020956b8 {
    char unknown0[0xa0];
    Node020958fc* listHead;
    Node02095910* alternateListHead;
};

// Existing 20-byte script state at data_02109404.
struct QuestScriptState {
    unsigned char f0;
    unsigned char skip;
    unsigned char selected;
    unsigned char f3;
    unsigned char f4;
    unsigned char pad5;
    unsigned short index;
    unsigned short f8;
    unsigned char padA[2];
    SafeAllocator* allocator;
    unsigned char* table;
};

extern QuestScriptState data_02109404;

extern "C" void func_020956b8(Header020956b8* header, SafeAllocator* allocator);
extern "C" void func_0209576c(Header020956b8* header, SafeAllocator* allocator,
                             const void* buffer, unsigned int length, unsigned char mode);
