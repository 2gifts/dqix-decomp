#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x218
#else
#define REGION_OFFSET_0 0x29c
#endif


static inline void* GetElem02162864(void* obj, int idx) {
    void* base = *(void**)((char*)obj + REGION_OFFSET_0);
    return (char*)base + 0x21c + 0x8000 + idx * 0x28;
}

// USA: func_ov000_02162864
ARM int FindSlotIndexByShort02162864(void* obj, int target) {
    void* base = *(void**)((char*)obj + REGION_OFFSET_0);
    int count = *(int*)((char*)base + 0x8000 + 0xe24);
    int i;
    for (i = 0; i < count; i++) {
        void* entry = GetElem02162864(obj, i);
        if (entry == 0) continue;
        void* node = *(void**)((char*)entry + 0x10);
        while (node) {
            if (*(unsigned short*)((char*)node + 0x20) == target) return i;
            node = *(void**)((char*)node + 0x30);
        }
    }
    return -1;
}
