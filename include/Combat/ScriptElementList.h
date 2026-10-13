#pragma once

class SafeAllocator;

struct StreamHeader0208d860 {
    void* entries;
    short count;
    short capacity;
    const short* selectedIds;
    short selectedCount;
    unsigned short flags;
};

struct Data02108fc0Type {
    SafeAllocator* allocator;
    StreamHeader0208d860* header;
};

extern Data02108fc0Type data_02108fc0;

void SetupHeaderAndRunBufferedScript0208d860(StreamHeader0208d860* header, SafeAllocator* allocator,
                                           const void* bytecode, unsigned int length,
                                           const short* selectedIds, short selectedCount,
                                           unsigned short flags);
