#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x218
#else
#define REGION_OFFSET_0 0x29c
#endif


static inline void* GetElem021628c8(void* obj, int idx) {
    void* base = *(void**)((char*)obj + REGION_OFFSET_0);
    return (char*)base + 0x21c + 0x8000 + idx * 0x28;
}

// USA: func_ov000_021628c8
ARM int CollectListShorts021628c8(void* obj, int idx, int* outArray) {
    void* entry = GetElem021628c8(obj, idx);
    void* node = *(void**)((char*)entry + 0x10);
    int count = 0;
    while (node) {
        outArray[count++] = *(unsigned short*)((char*)node + 0x20);
        node = *(void**)((char*)node + 0x30);
    }
    return count;
}
