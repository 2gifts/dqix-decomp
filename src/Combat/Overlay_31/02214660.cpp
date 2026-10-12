#include <globaldefs.h>
#include "System/Memory.h"

struct GroupList_0221474c;
extern "C" int func_ov031_0221474c(GroupList_0221474c*);
extern unsigned char data_ov031_02249abc[12];
extern const unsigned char data_ov031_02245fd8[8];
extern const unsigned char data_ov031_02245fe8[12];

struct NetworkEntry { unsigned char type, count, reserved, size; unsigned char data[0x20]; };
struct NetworkMode { unsigned char mode : 4; unsigned char flags : 4; };

// USA: func_ov031_02214660
extern "C" ARM int func_ov031_02214660(void* object) {
    int index;
    NetworkEntry* entry = (NetworkEntry*)((char*)object + 0x300);
    index = func_ov031_0221474c((GroupList_0221474c*)object);
    unsigned int mode = ((NetworkMode*)((char*)object + 0xd0c))->mode;
    entry += index;
    if (mode == 0 || mode == 4) {
        VectorizedInvertedMemcpy(data_ov031_02249abc, entry->data, 8);
        entry->size = 8;
        entry->count = 6;
        index = (index + 1) & 0xff;
        ++entry;
    }
    mode = ((NetworkMode*)((char*)object + 0xd0c))->mode;
    if (mode == 0 || mode == 7) {
        VectorizedInvertedMemcpy(data_ov031_02245fd8, entry->data, 8);
        entry->size = 8;
        entry->count = 9;
        index = (index + 1) & 0xff;
        ++entry;
    }
    mode = ((NetworkMode*)((char*)object + 0xd0c))->mode;
    if (mode == 0 || mode == 8) {
        VectorizedInvertedMemcpy(data_ov031_02245fe8, entry->data, 11);
        entry->size = 11;
        entry->count = 10;
        index = (index + 1) & 0xff;
    }
    return index;
}
