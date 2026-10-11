#include <globaldefs.h>
#if defined(jpn)
#define IS_JPN 1
#else
#define IS_JPN 0
#endif
#include "System/Memory.h"

struct Info02011930 {
    unsigned char b0;
    unsigned char b1;
    unsigned short s0;
};

// JPN: 0x020116a0
// USA: func_02011930
ARM unsigned char GetAndConsumeNameEntries02011930(void* obj, struct Info02011930* info, void* name1, void* name2) {
    unsigned char* base = (unsigned char*)obj;
    if (base[(IS_JPN ? 0x61ec : 0x646c)] != 0) {
        if (info != NULL) {
            info->b0 = base[(IS_JPN ? 0x61f0 : 0x6470)];
            info->b1 = base[(IS_JPN ? 0x61f1 : 0x6471)];
            info->s0 = *(unsigned short*)(base + (IS_JPN ? 0x61f2 : 0x6472));
        }
        if (name1 != NULL) {
            VectorizedInvertedMemcpy(base + (IS_JPN ? 0x629f : 0x64df), name1, 0xa);
            base[(IS_JPN ? 0x629f : 0x64df)] = 0;
        }
        if (name2 != NULL) {
            VectorizedInvertedMemcpy(base + (IS_JPN ? 0x62a9 : 0x64e9), name2, 0xa);
            base[(IS_JPN ? 0x62a9 : 0x64e9)] = 0;
        }
    }
    return base[(IS_JPN ? 0x61ec : 0x646c)];
}
