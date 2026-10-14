#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

struct BufferNode02097054 {
    char pad_0[0xc];
    unsigned char stringCount;
    char pad_d[0x1f];
    union {
        char** strings;
        unsigned int stringIndex;
    };
};
struct BufferBlob02097054 {
    unsigned short count;
    unsigned short stringCount;
    unsigned int byteCount : 31;
    unsigned int ready : 1;
    BufferNode02097054 nodes[1];
};
struct BufferHeader02097054 {
    unsigned short count;
    unsigned short stringCount;
    unsigned int byteCount : 31;
    unsigned int ready : 1;
    BufferNode02097054* nodes;
    unsigned int* strings;
};
struct BufferCopy02097054 {
    unsigned short count;
    char pad_2[6];
    BufferNode02097054* node;
    int field_c;
};
struct ComputeAlignedBufferSizeHeader;
struct ForEachNode02097000Container;
struct ForEachNode02097000Node;
struct BinarySearch020971a8Container;
struct BinarySearch020971a8Node;
int ComputeAlignedBufferSize_02096fd8(ComputeAlignedBufferSizeHeader*);
int ForEachNode02097000(ForEachNode02097000Container*, void (*)(ForEachNode02097000Container*, ForEachNode02097000Node*));
BinarySearch020971a8Node* BinarySearch020971a8(BinarySearch020971a8Container*, int, int (*)(BinarySearch020971a8Node*));
short GetShortAt0x4_02096f78(unsigned char*);
extern "C" char* func_02096f80(BufferHeader02097054*, unsigned int, int);
char* AllocateStringCopy020da150(SafeAllocator*, const char*);

// USA: func_02097054
extern "C" ARM void func_02097054(BufferCopy02097054* dst, SafeAllocator* allocator, BufferBlob02097054* source, int unused, short key) {
    BufferHeader02097054 header;
    memset(dst, 0, 0x10);
    if (key < 0) return;
    if (source != 0) {
        memcpy(&header, source, 8);
        header.nodes = source->nodes;
        header.strings = (unsigned int*)((char*)source + (8 + ComputeAlignedBufferSize_02096fd8((ComputeAlignedBufferSizeHeader*)&header)));
        if (header.ready == 0) {
            ForEachNode02097000((ForEachNode02097000Container*)&header, 0);
            header.ready = 1;
            source->ready = 1;
        }
    }
    BufferNode02097054* found = (BufferNode02097054*)BinarySearch020971a8((BinarySearch020971a8Container*)&header, key, (int (*)(BinarySearch020971a8Node*))GetShortAt0x4_02096f78);
    BufferNode02097054* copy = (BufferNode02097054*)allocator->Allocate(0x30);
    if (found == 0 || copy == 0) return;
    memcpy(copy, found, 0x30);
    short stringCount = copy->stringCount;
    char** output = (char**)allocator->Allocate(stringCount * 4);
    unsigned int* input = (unsigned int*)(header.nodes + header.count) + found->stringIndex;
    copy->strings = output;
    for (int i = 0; i < stringCount; i++) {
        unsigned int stringIndex = *input;
        input++;
        char* text = func_02096f80(&header, stringIndex, 0);
        *output = AllocateStringCopy020da150(allocator, text);
        output++;
    }
    dst->count = 1;
    dst->node = copy;
}
